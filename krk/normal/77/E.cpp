#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;

int T;
int R, r, k;

ld Len(ld x, ld y) { return sqrt(x * x + y * y); }

ldld Invert(ld x, ld y)
{
    ld d = Len(x, y);
    ld coef = 1 / d / d;
    return ldld(coef * x, coef * y);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &R, &r, &k);
        ld ax = 1.0l / (2.0l * R);
        ld bx = 1.0l / (2.0l * r);
        ld c = (bx - ax) / 2;
        ld d = (ax + bx) / 2;
        ld Cx = d;
        ld Cy = k * 2 * c;
        ld len = Len(Cx, Cy);
        ld mult = (len - c) / len;
        ldld fir = ldld(Cx * mult, Cy * mult);
        mult = (len + c) / len;
        ldld sec = ldld(Cx * mult, Cy * mult);
        fir = Invert(fir.first, fir.second), sec = Invert(sec.first, sec.second);
        cout << fixed << setprecision(15) << Len(fir.first - sec.first, fir.second - sec.second) / 2.0l << endl;
    }
    return 0;
}