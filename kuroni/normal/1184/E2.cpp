#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 100005, M = 1E6 + 5, LG = 17;

int n, m, ind[M], h[N], dsu[N], par[N][LG], mx[N][LG];
bool chk[M];
vector<pair<int, int>> adj[N];

struct SEdge
{
    int u, v, w;
} a[M];

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

void DFS(int u, int p = 0, int w = 0)
{
    h[u] = h[p] + 1;
    par[u][0] = p;
    mx[u][0] = w;
    for (int i = 1; i < LG; i++)
    {
        par[u][i] = par[par[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
    }
    for (pair<int, int> &v : adj[u])
        if (v.fi != p)
            DFS(v.fi, u, v.se);
}

int LCA(int u, int v)
{
    int ans = 0;
    if (h[u] < h[v])
        swap(u, v);
    for (int i = LG - 1; i >= 0; i--)
        if ((h[u] - h[v]) >> i & 1)
        {
            ans = max(ans, mx[u][i]);
            u = par[u][i];
        }
    if (u == v)
        return ans;
    for (int i = LG - 1; i >= 0; i--)
        if (par[u][i] != par[v][i])
        {
            ans = max(ans, max(mx[u][i], mx[v][i]));
            u = par[u][i];
            v = par[v][i];
        }
    return max(ans, max(mx[u][0], mx[v][0]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    h[0] = -1;
    cin >> n >> m;
    fill(dsu + 1, dsu + n + 1, -1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
        ind[i] = i;
    }
    sort(ind + 1, ind + m + 1, [](const int &u, const int &v) {
        return a[u].w < a[v].w;
    });
    for (int i = 1; i <= m; i++)
    {
        int cur = ind[i];
        if (connect(a[cur].u, a[cur].v))
        {
            chk[cur] = true;
            adj[a[cur].u].push_back({a[cur].v, a[cur].w});
            adj[a[cur].v].push_back({a[cur].u, a[cur].w});
        }
    }
    DFS(1);
    for (int i = 1; i <= m; i++)
        if (!chk[i])
            cout << LCA(a[i].u, a[i].v) << '\n';
}