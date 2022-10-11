#include <bits/stdc++.h>
using namespace std;

const int N = 100005, INF = 1E9 + 7;

int n;

struct SPoint
{
    int x, y, ind;

    inline bool line(const SPoint &oth) const
    {
        return 1LL * x * oth.y == 1LL * y * oth.x;
    }

    inline bool operator<(const SPoint &oth) const
    {
        if (1LL * x * oth.y != 1LL * y * oth.x)
            return 1LL * x * oth.y > 1LL * y * oth.x;
        else
            return x < oth.x;
    }
} a[N];

long long S(SPoint a, SPoint b, SPoint c)
{
    b.x -= a.x; b.y -= a.y;
    c.x -= a.x; c.y -= a.y;
    return abs(1LL * b.x * c.y - 1LL * b.y * c.x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].x += INF; a[i].y += INF;
        a[i].ind = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n - 2; i++)
        if ((!a[i].line(a[i + 1]) || !a[i].line(a[i + 2])) && S(a[i], a[i + 1], a[i + 2]) > 0)
            return cout << a[i].ind << " " << a[i + 1].ind << " " << a[i + 2].ind, 0;
}