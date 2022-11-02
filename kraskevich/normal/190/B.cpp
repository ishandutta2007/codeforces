#include <iostream>
#include <cmath>
using namespace std;

double sqr(double a)
{
    return a * a;
}

double dist(double x, double y)
{
    return sqrt(sqr(x) + sqr(y));
}

int main()
{
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    
    double d = dist(x1 - x2, y1 - y2);
    
    cout.setf(ios::fixed);
    cout.precision(10);
    if(d >= r1 + r2)
    {
        cout << (d - r1 - r2) / 2;
        return 0;
    }
    if(d + r2 < r1 || d + r1 < r2)
    {
        cout << (fabs(r1 - r2) - d) / 2;
        return 0;
    }
    cout << 0.0;
    return 0;
}