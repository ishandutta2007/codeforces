#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long double ld;

const int Maxn = 10001;
const ld sm = 0.00000000001;

int n, x[Maxn], y[Maxn], z[Maxn];
ld vp, vs, xp, yp, zp, xa, ya, za, ta;
bool ans;

ld tim;
int pth;

ld sq(const ld &x) { return x * x; }

ld ds(ld x1, ld x2, ld y1, ld y2, ld z1, ld z2) 
{
    return sqrt(sq(x1 - x2) + sq(y1 - y2) + sq(z1 - z2));
}

void Search()
{
     ld lx = x[pth], ly = y[pth], lz = z[pth];
     ld rx = x[pth+1], ry = y[pth+1], rz = z[pth+1];
     for (int i = 0; i < 60; i++) {
         ld mx = (lx + rx) / ld(2), my = (ly + ry) / ld(2), mz = (lz + rz) / ld(2);
         ld tm = tim + ds(x[pth], mx, y[pth], my, z[pth], mz) / vs;
         if (ds(xp, mx, yp, my, zp, mz) / vp <= tm + sm) {
                    ans = true;
                    xa = mx; ya = my; za = mz; ta = tm;
                    rx = mx; ry = my; rz = mz;
         } else {
                lx = mx; ly = my; lz = mz;
         }
     }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) scanf("%d %d %d", &x[i], &y[i], &z[i]);
    cin >> vp >> vs >> xp >> yp >> zp;
    for (pth = 0; pth < n && !ans; pth++) {
        Search();
        tim += ds(x[pth], x[pth+1], y[pth], y[pth+1], z[pth], z[pth+1]) / vs;
    }
    if (ans) {
            cout << "YES\n";
            cout << fixed << setprecision(10) << ta << endl;
            cout << xa << " " << ya << " " << za << endl;
    } else cout << "NO\n";
    return 0;
}