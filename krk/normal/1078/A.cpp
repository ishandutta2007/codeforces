#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int a, b, c;
int X1, Y1, X2, Y2;

ld Dist(ld ax, ld ay, ld bx, ld by) { return fabs(ax - bx) + fabs(ay - by); }

ld sDist(ld ax, ld ay, ld bx, ld by) { return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by)); }

int main()
{
    cin >> a >> b >> c;
    cin >> X1 >> Y1 >> X2 >> Y2;
    ld res = Dist(X1, Y1, X2, Y2);
    if (a && b) {
        ld gx1 = (-ld(c) - ld(b) * Y1) / ld(a);
        ld gy1 = (-ld(c) - ld(a) * X1) / ld(b);
        ld gx2 = (-ld(c) - ld(b) * Y2) / ld(a);
        ld gy2 = (-ld(c) - ld(a) * X2) / ld(b);
        res = min(res, Dist(X1, Y1, gx1, Y1) + Dist(X2, Y2, gx2, Y2) + sDist(gx1, Y1, gx2, Y2));
        res = min(res, Dist(X1, Y1, gx1, Y1) + Dist(X2, Y2, X2, gy2) + sDist(gx1, Y1, X2, gy2));
        res = min(res, Dist(X1, Y1, X1, gy1) + Dist(X2, Y2, gx2, Y2) + sDist(X1, gy1, gx2, Y2));
        res = min(res, Dist(X1, Y1, X1, gy1) + Dist(X2, Y2, X2, gy2) + sDist(X1, gy1, X2, gy2));
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}