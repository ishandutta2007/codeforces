#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 1e-9;
const double Inf = 1e18;
const double delta = 1e-2;

int S;
int a, b, c;
double x, y, z;

void Solve(int a, double &x)
{
    x = S;
}

void Solve(int a, int b, double &x, double &y)
{
    if (a == 0) { x = 0; Solve(b, y); }
    else if (b == 0) { y = 0; Solve(a, x); }
    else {
        x = (double) a * S / (a + b);
        y = (double) b * S / (a + b);
    }
}

void Solve(int a, int b, int c, double &x, double &y, double &z)
{
    if (a == 0) { x = 0; Solve(b, c, y, z); }
    else if (b == 0) { y = 0; Solve(a, c, x, z); }
    else if (c == 0) { z = 0; Solve(a, b, x, y); }
    else {
        x = (double) a * S / (a + b + c);
        y = (double) b * S / (a + b + c);
        z = (double) c * S / (a + b + c);
    }
}

int main()
{
    cin >> S >> a >> b >> c;
    Solve(a, b, c, x, y, z);
    printf("%.20lf %.20lf %.20lf\n", x, y, z);
    return 0;
}