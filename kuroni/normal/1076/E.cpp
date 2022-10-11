#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 300005, Q = 300005;

int n, q, u, v, h[N], rem[Q];
long long ans[N], bit[Q];
vector<int> adj[N], add[N];

struct SQuery
{
    int u, v, w;
} que[Q];

void upd(int u, int v)
{
    for (; u <= q; u += u & -u)
        bit[u] += v;
}

long long get(int u)
{
    long long ret = 0;
    for (; u > 0; u -= u & -u)
        ret += bit[u];
    return ret;
}

void DFS(int u, int p = 0)
{
    h[u] = h[p] + 1;
    for (int &v : adj[u])
        if (v != p)
            DFS(v, u);
}

void find_ans(int u, long long sub, int p = 0)
{
    for (int &v : add[u])
        upd(v, que[v].w);
    sub += get(distance(rem + 1, upper_bound(rem + 1, rem + q + 1, h[u]))) - get(distance(rem + 1, lower_bound(rem + 1, rem + q + 1, h[u])));
    ans[u] = get(q) - sub;
    for (int &v : adj[u])
        if (v != p)
            find_ans(v, sub, u);
    for (int &v : add[u])
        upd(v, -que[v].w);
}

int main()
{
    h[0] = -1;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
        scanf("%d%d%d", &que[i].u, &que[i].v, &que[i].w);
    sort(que + 1, que + q + 1, [](const SQuery &a, const SQuery &b) { return h[a.u] + a.v < h[b.u] + b.v; });
    for (int i = 1; i <= q; i++)
    {
        rem[i] = h[que[i].u] + que[i].v + 1;
        add[que[i].u].push_back(i);
    }
    find_ans(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
}