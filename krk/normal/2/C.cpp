#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair <double, double> dd;

const int Maxs = 3;
const double eps = 1e-7;
const double beps = 1e-5;

int x[Maxs], y[Maxs], r[Maxs];
double d[Maxs];
double curx, cury;

double F(double X, double Y)
{
    double res = 0.0;
    for (int i = 0; i < Maxs; i++) {
        double dx = X - x[i], dy = Y - y[i];
        d[i] = sqrt(dx * dx + dy * dy) / r[i];
    }
    for (int i = 0; i < Maxs; i++) {
        double dd = d[i] - d[(i + 1) % Maxs];
        res += dd * dd;
    }
    return res;
}

int main()
{
    for (int i = 0; i < Maxs; i++) {
        scanf("%d %d %d", &x[i], &y[i], &r[i]);
        curx += x[i] / 3.0, cury += y[i] / 3.0;
    }
    for (double step = 1.0; step > eps; )
        if (F(curx - step, cury) < F(curx, cury)) curx -= step;
        else if (F(curx, cury - step) < F(curx, cury)) cury -= step;
        else if (F(curx + step, cury) < F(curx, cury)) curx += step;
        else if (F(curx, cury + step) < F(curx, cury)) cury += step;
        else step *= 0.7;
    if (F(curx, cury) < eps)
        printf("%.5lf %.5lf\n", curx, cury);
    return 0;
}