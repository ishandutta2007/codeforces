#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct TQuery
{
    int l, r, i;
} q[200005];

int n, m, i, j, l = 0, a[200005], pos[200005], ans[200005], bit[200005];
vector<pair<int, int>> s;

inline bool operator < (const TQuery &a, const TQuery &b)
{
    return a.l < b.l || (a.l == b.l && a.r < b.r);
}

void upd(int u, int v)
{
    while (u <= n)
    {
        bit[u] += v;
        u += u & -u;
    }
}

int que(int u)
{
    int ret = 0;
    while (u > 0)
    {
        ret += bit[u];
        u -= u & -u;
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        pos[a[i]] = i;
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n / a[i]; j++)
        {
            s.push_back(make_pair(i, pos[a[i] * j]));
            if (s.back().first > s.back().second)
                swap(s.back().first, s.back().second);
            upd(s.back().second, 1);
        }
    sort(s.begin(), s.end());
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].i = i;
    }
    sort(q + 1, q + m + 1);
    for (i = 1; i <= m; i++)
    {
        while (l < s.size() && s[l].first < q[i].l)
            upd(s[l++].second, -1);
        ans[q[i].i] = que(q[i].r);
    }
    for (i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
}