#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 1E6 + 5, INF = 1E9;

int n, m, dsu[N];

struct SEdge
{
    int u, v, w;
} a[M];

int trace(int u)
{
    return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
}

void connect(int u, int v)
{
    if ((u = trace(u)) == (v = trace(v)))
        return;
    if (dsu[u] > dsu[v])
        swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    fill(dsu + 1, dsu + n + 1, -1);
    for (int i = 1; i <= m; i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
    sort(a + 2, a + m + 1, [](const SEdge &u, const SEdge &v) {
        return u.w < v.w;
    });
    for (int i = 2; i <= m; i++)
    {
        connect(a[i].u, a[i].v);
        if (trace(a[1].u) == trace(a[1].v))
            return cout << a[i].w, 0;
    }
    cout << INF;
}