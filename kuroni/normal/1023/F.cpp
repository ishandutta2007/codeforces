#include <bits/stdc++.h>
using namespace std;

const int N = 500005, K = 500005, M = 500005, LG = 20, INF = 1E9 + 7;

int n, k, m, dsu[N], h[N], par[N][LG], mi[N][LG];
long long ans = 0;
vector<int> adj[N];

struct SEdge
{
    int u, v, w;
} a[K], b[M];

int trace(int u)
{
    return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
}

bool connect(int u, int v)
{
    if ((u = trace(u)) == (v = trace(v)))
        return false;
    if (dsu[u] > dsu[v])
        swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
    return true;
}

void add_edge(int u, int v)
{
    if (!connect(u, v))
        return;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(int u, int p = 0)
{
    if (p != 0)
    {
        h[u] = h[p] + 1;
        par[u][0] = p;
        for (int i = 1; i < LG; i++)
            par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (int &v : adj[u])
        if (v != p)
            DFS(v, u);
}

void update(int u, int v, int w)
{
    if (h[u] < h[v])
        swap(u, v);
    for (int i = LG - 1; i >= 0; i--)
        if ((h[u] - h[v]) >> i & 1)
        {
            mi[u][i] = w;
            u = par[u][i];
        }
    if (u == v)
        return;
    for (int i = LG - 1; i >= 0; i--)
        if ((1 << i) <= h[u] && par[u][i] != par[v][i])
        {
            mi[u][i] = mi[v][i] = w;
            u = par[u][i]; v = par[v][i];
        }
    mi[u][0] = mi[v][0] = w;
}

void recompute()
{
    for (int j = LG - 1; j > 0; j--)
        for (int i = 1; i <= n; i++)
        {
            mi[i][j - 1] = min(mi[i][j - 1], mi[i][j]);
            mi[par[i][j - 1]][j - 1] = min(mi[par[i][j - 1]][j - 1], mi[i][j]);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++)
        cin >> a[i].u >> a[i].v;
    for (int i = 1; i <= m; i++)
        cin >> b[i].u >> b[i].v >> b[i].w;
    sort(b + 1, b + m + 1, [](const SEdge &u, const SEdge &v) {
        return u.w < v.w;
    });
    for (int i = 1; i <= n; i++)
    {
        fill(mi[i], mi[i] + LG, INF);
        dsu[i] = -1;
    }
    for (int i = 1; i <= k; i++)
        add_edge(a[i].u, a[i].v);
    for (int i = 1; i <= m; i++)
        add_edge(b[i].u, b[i].v);
    DFS(1);
    for (int i = m; i >= 1; i--)
        update(b[i].u, b[i].v, b[i].w);
    recompute();
    for (int i = 1; i <= k; i++)
    {
        if (h[a[i].u] < h[a[i].v])
            swap(a[i].u, a[i].v);
        if (mi[a[i].u][0] == INF)
            return cout << -1, 0;
        else
            ans += mi[a[i].u][0];
    }
    cout << ans;
}