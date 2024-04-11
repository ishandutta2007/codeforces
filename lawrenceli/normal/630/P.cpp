#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;

#define A first
#define B second

typedef long double ld;
typedef pair<ld, ld> pnt;
typedef pair<pnt, pnt> line;

const ld PI = acos(-1.0);

int n, r;

pnt newpnt(int k) {
    ld arg = 2 * PI * k / n;
    return pnt(r * cos(arg), r * sin(arg));
}

pnt inter(line l1, line l2) {
    pnt a = l1.A, b = l1.B, c = l2.A, d = l2.B;
    ld i;
    if (c.A == d.A)
        i = (c.A - a.A) / (b.A - a.A);
    else if (c.B == d.B)
        i = (c.B - a.B) / (b.B - a.B);
    else
        i = ((a.B - c.B) / (d.B - c.B) - (a.A - c.A) / (d.A - c.A)) / ((b.A - a.A) / (d.A - c.A) - (b.B - a.B) / (d.B - c.B));

    return pnt(a.A + (b.A - a.A) * i, a.B + (b.B - a.B) * i);
}

ld area(pnt a, pnt b, pnt c) {
    return abs(a.A * b.B + b.A * c.B + c.A * a.B - a.B * b.A - b.B * c.A - c.B * a.A) / 2;
}

int main() {
    cin >> n >> r;
    assert(n & 1);
    int k = n / 2;
    line l = line(newpnt(n - 1), newpnt(n - 1 + k));
    pnt a = inter(l, line(newpnt(0), newpnt(k + 1)));
    pnt b = inter(l, line(newpnt(n - 2), newpnt(n - 2 + k)));
    pnt c = inter(l, line(newpnt(0), newpnt(k)));

    if (n == 5) b = a;

    ld ans = area(newpnt(0), a, c) + area(pnt(0, 0), b, c);
    cout << fixed << setprecision(15) << ans * n << '\n';
}