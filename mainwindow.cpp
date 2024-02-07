#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

/*
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
db.setHostName("your_host_name");
db.setDatabaseName("postgres");
db.setUserName("root");
db.setPassword("root");

if (!db.open()) {
    qDebug() << "Database connection error:" << db.lastError().text();
    return;
}

// Function to retrieve data from the database
QVector<QPointF> getDataFromDatabase()
{
    QVector<QPointF> dataPoints;

    QSqlQuery query("SELECT x, y FROM emp");
    while (query.next())
    {
        double x = query.value(0).toDouble();
        double y = query.value(1).toDouble();
        dataPoints.append(QPointF(x, y));
    }

    return dataPoints;
}


// Inside a function or constructor
QChartView *chartView = new QChartView(this);
QChart *chart = new QChart();

QVector<QPointF> data = getDataFromDatabase();

QLineSeries *series = new QLineSeries();
for (const QPointF& point : data)
{
    series->append(point);
}

chart->addSeries(series);
chartView->setChart(chart);


// Example slot connected to a button click
connect(ui->yourButton, &QPushButton::clicked, this, [=]()
        {
    QVector<QPointF> data = getDataFromDatabase();
    // Plot the data or update existing chart here
});



}
MainWindow::~MainWindow()
{
    delete ui;
}
*/


QT_USE_NAMESPACE

        // Define the function to retrieve data from the database
  QVector<QPointF> getDataFromDatabase()
{
    QVector<QPointF> dataPoints;

    QSqlQuery query("SELECT customname,salery FROM emp");
    while (query.next())
    {
        double customname = query.value(0).toDouble();
        double salery = query.value(1).toDouble();
        dataPoints.append(QPointF(customname, salery));
    }

    return dataPoints;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost:5432");
    db.setDatabaseName("postgres");
    db.setUserName("root");
    db.setPassword("root");

    if (!db.open()) {
        qDebug() << "Database connection error:" << db.lastError().text();
        return;
    }

    // Create chart and series
    QChartView *chartView = new QChartView(this);
    QChart *chart = new QChart();

    // Retrieve data from the database
    QVector<QPointF> data = getDataFromDatabase();

    // Populate the series with data
    QLineSeries *series = new QLineSeries();
    for (const QPointF& point : data)
    {
        series->append(point);
    }

    // Add series to the chart
    chart->addSeries(series);

    // Set up chart properties if needed

    // Set the chart for the chartView
    chartView->setChart(chart);

    // Example slot connected to a button click
    connect(ui->button1, &QPushButton::clicked, this, [=]()
            {
                QVector<QPointF> data = getDataFromDatabase();
                // Plot the data or update the existing chart here
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}
