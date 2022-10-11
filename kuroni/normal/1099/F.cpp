#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;

int n, u, w, ind[N];
long long t, f[N], cnt[N], sum[N];
vector<pair<int, int>> adj[N];

struct SNode
{
    int x, t, ind;
} a[N];

void upd(int u, int t, int x)
{
    for (; u <= n; u += u & -u)
    {
        cnt[u] += x;
        sum[u] += 1LL * t * x;
    }
}

long long calc(long long lim)
{
    if (lim < 0)
        return 0;
    int pos = 0;
    long long ret = 0;
    for (int i = 31 - __builtin_clz(n); i >= 0; i--)
        if (pos + (1 << i) <= n && sum[pos + (1 << i)] <= lim)
        {
            pos += (1 << i);
            lim -= sum[pos];
            ret += cnt[pos];
        }
    return pos == n ? ret : ret + lim / a[pos + 1].t;
}

void DFS(int u, long long t)
{
    upd(ind[u], a[ind[u]].t, a[ind[u]].x);
    f[u] = calc(t);
    long long fi = 0, se = 0;
    for (pair<int, int> &v : adj[u])
    {
        DFS(v.first, t - 2 * v.second);
        if (f[v.first] > fi)
        {
            se = fi;
            fi = f[v.first];
        }
        else if (f[v.first] > se)
            se = f[v.first];
    }
    f[u] = max(f[u], u == 1 ? fi : se);
    upd(ind[u], a[ind[u]].t, -a[ind[u]].x);
}

int main()
{
    scanf("%d%lld", &n, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].x);
        a[i].ind = i;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].t);
    sort(a + 1, a + n + 1, [](const SNode &a, const SNode &b) { return a.t < b.t; });
    for (int i = 1; i <= n; i++)
        ind[a[i].ind] = i;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d%d", &u, &w);
        adj[u].push_back(make_pair(i, w));
    }
    DFS(1, t);
    printf("%lld\n", f[1]);
}