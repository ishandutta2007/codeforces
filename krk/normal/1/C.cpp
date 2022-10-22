#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 3;
const ld eps = 1e-5;

pair <ld, ld> p[Maxn], c;
ld r;
ld pi = acos(-1.0L);

void getLine(pair <ld, ld> a, pair <ld, ld> b, ld &A, ld &B, ld &C)
{
     A = b.second - a.second;
     B = a.first - b.first;
     C = A * a.first + B * a.second;
}

pair <ld, ld> getCenter(pair <ld, ld> p[])
{
     ld A1, B1, C1; getLine(p[0], p[1], A1, B1, C1);
     ld A2, B2, C2; getLine(p[2], p[1], A2, B2, C2);
     C1 = -B1; B1 = A1; A1 = C1; 
     C1 = A1 * (p[0].first + p[1].first) / 2.0 + B1 * (p[0].second + p[1].second) / 2.0;
     C2 = -B2; B2 = A2; A2 = C2;
     C2 = A2 * (p[2].first + p[1].first) / 2.0 + B2 * (p[2].second + p[1].second) / 2.0;
     ld det = A1 * B2 - A2 * B1;
     ld x = (B2 * C1 - B1 * C2) / det;
     ld y = (A1 * C2 - A2 * C1) / det;
     return make_pair(x, y);
}

bool Less(const pair <ld, ld> &a, const pair <ld, ld> &b)
{
     return atan2(a.second - c.second, a.first - c.first) < 
            atan2(b.second - c.second, b.first - c.first);
}

bool Good(int n, ld r)
{
     ld delta = 2.0L * pi / ld(n);
     ld start = atan2(p[0].second - c.second, p[0].first - c.first);
     bool was1 = false, was2 = false;
     for (int i = 0; i < n; i++) {
         start += delta;
         was1 = was1 || fabs(p[1].first - (c.first + r * cos(start))) < eps &&
                        fabs(p[1].second - (c.second + r * sin(start))) < eps;
         was2 = was2 || fabs(p[2].first - (c.first + r * cos(start))) < eps &&
                        fabs(p[2].second - (c.second + r * sin(start))) < eps;
     }
     return was1 && was2;
}

ld Dist(pair <ld, ld> &a, pair <ld, ld> &b)
{
     return sqrt((a.first - b.first) * (a.first - b.first) + 
                 (a.second - b.second) * (a.second - b.second));
}

ld Area(int n, ld r)
{
    ld delta = 2.0L * pi / ld(n);
    return n * r * r * 0.5L * sin(delta);
}

int main()
{
    for (int i = 0; i < Maxn; i++)
       cin >> p[i].first >> p[i].second;
    c = getCenter(p); r = Dist(c, p[0]);
    sort(p, p + Maxn, Less);
    int n = 3;
    while (!Good(n, r) && n <= 100) n++;
    cout << fixed << setprecision(8) << Area(n, r) << endl;
    return 0;
}