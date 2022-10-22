#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 1e-8;

int X, Y, Z;
int X1, Y1, Z1;
int a1, a2, a3, a4, a5, a6;
int res;

bool Check(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3)
{
    double ax = x2 - x1, ay = y2 - y1, az = z2 - z1;
    double bx = x3 - x1, by = y3 - y1, bz = z3 - z1;
    return ax * bx + ay * by + az * bz > eps;
}

int main()
{
    scanf("%d %d %d", &X, &Y, &Z);
    scanf("%d %d %d", &X1, &Y1, &Z1);
    scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6);
    if (Check(X1 / 2.0, 0, Z1 / 2.0, X1 / 2.0, -1, Z1 / 2.0, X, Y, Z)) res += a1;
    if (Check(X1 / 2.0, Y1, Z1 / 2.0, X1 / 2.0, Y1 + 1, Z1 / 2.0, X, Y, Z)) res += a2;
    if (Check(X1 / 2.0, Y1 / 2.0, 0, X1 / 2.0, Y1 / 2.0, -1, X, Y, Z)) res += a3;
    if (Check(X1 / 2.0, Y1 / 2.0, Z1, X1 / 2.0, Y1 / 2.0, Z1 + 1, X, Y, Z)) res += a4;
    if (Check(0, Y1 / 2.0, Z1 / 2.0, -1, Y1 / 2.0, Z1 / 2.0, X, Y, Z)) res += a5;
    if (Check(X1, Y1 / 2.0, Z1 / 2.0, X1 + 1, Y1 / 2.0, Z1 / 2.0, X, Y, Z)) res += a6;
    printf("%d\n", res);
    return 0;
}