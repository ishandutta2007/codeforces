#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const double INF = 1E18 + 7, PI = 3.14159265358979323846;

int n, px, py;
double ma = -INF, mi = 0;

struct SPoint
{
    int x, y;
} ori, a[N];

long long ccw(SPoint &a, SPoint &b, SPoint &c, bool full = false)
{
    long long ar = 1LL * (a.x - b.x) * (a.y + b.y)
                 + 1LL * (b.x - c.x) * (b.y + c.y)
                 + 1LL * (c.x - a.x) * (c.y + a.y);
    if (!full)
        return ar == 0 ? 0 : ar / abs(ar);
    else
        return abs(ar);
}

double dist(SPoint &a, SPoint &b)
{
    double ac = hypot(a.x, a.y), bc = hypot(b.x, b.y), ab = hypot(a.x - b.x, a.y - b.y);
    double mx = max(ac, bc);
    if (2 * mx * mx > ac * ac + bc * bc + ab * ab)
        return min(ac, bc);
    else
        return ccw(ori, a, b, true) / ab;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> px >> py;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].x -= px;
        a[i].y -= py;
    }
    for (int i = 0; i < n; i++)
        if (ccw(ori, a[i], a[(i + 1) % n]) * ccw(ori, a[(i + 1) % n], a[(i + 2) % n]) == -1)
        {
            mi = INF;
            break;
        }
    for (int i = 0; i < n; i++)
    {
        mi = min(mi, dist(a[i], a[(i + 1) % n]));
        ma = max(ma, hypot(a[i].x, a[i].y));
    }
    cout << fixed << setprecision(7) << (ma * ma - mi * mi) * PI;
}