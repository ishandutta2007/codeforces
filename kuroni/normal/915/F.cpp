#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1E6 + 5;

struct TEdge
{
    int u, v, w;
} mi[N], ma[N];
int n, a[N], u, v, dsu[N];
long long ans = 0;

int trace(int u)
{
    return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
}

long long unity(int u, int v)
{
    u = trace(u);
    v = trace(v);
    long long ret = 1LL * dsu[u] * dsu[v];
    if (dsu[u] > dsu[v])
        swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        mi[i] = (TEdge){u, v, min(a[u], a[v])};
        ma[i] = (TEdge){u, v, max(a[u], a[v])};
    }
    sort(mi + 1, mi + n, [](const TEdge &a, const TEdge &b) { return a.w > b.w; });
    sort(ma + 1, ma + n, [](const TEdge &a, const TEdge &b) { return a.w < b.w; });

    fill(dsu + 1, dsu + n + 1, -1);
    for (int i = 1; i < n; i++)
        ans -= unity(mi[i].u, mi[i].v) * mi[i].w;

    fill(dsu + 1, dsu + n + 1, -1);
    for (int i = 1; i < n; i++)
        ans += unity(ma[i].u, ma[i].v) * ma[i].w;

    printf("%I64d", ans);
}