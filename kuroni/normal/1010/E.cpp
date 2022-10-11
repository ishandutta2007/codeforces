#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005, Q  = 100005, INF = 100005;

int n, m, q, sz, a[3], l[3] = {INF, INF, INF}, r[3] = {0, 0, 0}, bit[N], pos[N], ans[Q];

struct STime
{
    int a[3], ind;
};
vector<STime> ve[8], qu[8];

void upd(int u, int v)
{
    for (; u <= sz; u += u & -u)
        bit[u] = min(bit[u], v);
}

int que(int u)
{
    int ret = INF;
    for (; u > 0; u -= u & -u)
        ret = min(ret, bit[u]);
    return ret;
}

void add(const int &mask)
{
    STime tmp;
    for (int i = 0; i < 3; i++)
        if (mask >> i & 1)
        {
            if (a[i] < l[i])
                return;
            tmp.a[i] = max(0, a[i] - r[i]);
        }
        else
        {
            if (a[i] > r[i])
                return;
            tmp.a[i] = max(0, l[i] - a[i]);
        }
    ve[mask].push_back(tmp);
}

void solve(const int &mask)
{
    sz = ve[mask].size();
    fill(bit + 1, bit + sz + 1, INF);
    sort(ve[mask].begin(), ve[mask].end(), [](const STime &u, const STime &v) { return u.a[1] < v.a[1]; });
    for (int i = 0; i < sz; i++)
    {
        ve[mask][i].ind = i;
        pos[i] = ve[mask][i].a[1];
    }
    sort(ve[mask].begin(), ve[mask].end(), [](const STime &u, const STime &v) { return u.a[0] < v.a[0]; });
    sort(qu[mask].begin(), qu[mask].end(), [](const STime &u, const STime &v) { return u.a[0] < v.a[0]; });
    int pt = 0;
    for (STime &v : qu[mask])
    {
        for (; pt < sz && ve[mask][pt].a[0] <= v.a[0]; pt++)
            upd(ve[mask][pt].ind + 1, ve[mask][pt].a[2]);
        ans[v.ind] = (que(distance(pos, upper_bound(pos, pos + sz, v.a[1]))) > v.a[2] ? 1 : 2);
    }
}

int main()
{
    scanf("%d%d%d%d%d%d", a, a + 1, a + 2, &n, &m, &q);
    while (n--)
    {
        scanf("%d%d%d", a, a + 1, a + 2);
        for (int i = 0; i < 3; i++)
        {
            l[i] = min(l[i], a[i]);
            r[i] = max(r[i], a[i]);
        }
    }
    while (m--)
    {
        scanf("%d%d%d", a, a + 1, a + 2);
        if (l[0] <= a[0] && a[0] <= r[0]
        &&  l[1] <= a[1] && a[1] <= r[1]
        &&  l[2] <= a[2] && a[2] <= r[2])
        {
            printf("INCORRECT\n");
            return 0;
        }
        for (int mask = 0; mask < 8; mask++)
            add(mask);
    }
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d%d", a, a + 1, a + 2);
        if (l[0] <= a[0] && a[0] <= r[0]
        &&  l[1] <= a[1] && a[1] <= r[1]
        &&  l[2] <= a[2] && a[2] <= r[2])
            continue;
        int mask = 0; STime tmp;
        tmp.ind = i;
        for (int i = 0; i < 3; i++)
            if (a[i] > r[i])
            {
                mask |= (1 << i);
                tmp.a[i] = a[i] - r[i];
            }
            else
                tmp.a[i] = max(0, l[i] - a[i]);
        qu[mask].push_back(tmp);
    }
    for (int mask = 0; mask < 8; mask++)
        solve(mask);
    printf("CORRECT\n");
    for (int i = 1; i <= q; i++)
        if (ans[i] == 0)
            printf("OPEN\n");
        else if (ans[i] == 1)
            printf("UNKNOWN\n");
        else
            printf("CLOSED\n");
}