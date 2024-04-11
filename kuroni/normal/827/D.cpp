#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005, M = 200005, LG = 20, INF = 1E9 + 7;

int n, m, u, v, h[N], dsu[N], ind[N], par[N][LG], mx[N][LG], ove[N][LG], wgt[M], ans[M];
bool spa[M];
vector<pair<int, int>> adj[N];

struct SEdge
{
    int u, v, w, ind;
};
vector<SEdge> edg;

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
    if (p != 0)
    {
        h[u] = h[p] + 1;
        par[u][0] = p;
        mx[u][0] = w;
        ove[u][0] = INF;
        for (int i = 1; i < LG; i++)
        {
            par[u][i] = par[par[u][i - 1]][i - 1];
            mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
            ove[u][i] = INF;
        }
    }
    for (pair<int, int> &v : adj[u])
        if (v.first != p)
        {
            ind[v.first] = v.second;
            DFS(v.first, u, wgt[v.second]);
        }
}

int get(int u, int v, int w)
{
    int ret = 0;
    if (h[u] < h[v])
        swap(u, v);
    for (int i = LG - 1; i >= 0; i--)
        if ((h[u] - h[v]) >> i & 1)
        {
            ove[u][i] = w;
            ret = max(ret, mx[u][i]);
            u = par[u][i];
        }
    if (u == v)
        return ret;
    for (int i = LG - 1; i >= 0; i--)
        if ((1 << i) <= h[u] && par[u][i] != par[v][i])
        {
            ret = max(ret, max(mx[u][i], mx[v][i]));
            ove[u][i] = ove[v][i] = w;
            u = par[u][i];
            v = par[v][i];
        }
    ove[u][0] = ove[v][0] = w;
    return max(ret, max(mx[u][0], mx[v][0]));
}

void solve()
{
    for (int j = LG - 1; j > 0; j--)
        for (int i = 1; i <= n; i++)
        {
            ove[i][j - 1] = min(ove[i][j - 1], ove[i][j]);
            ove[par[i][j - 1]][j - 1] = min(ove[par[i][j - 1]][j - 1], ove[i][j]);
        }
    for (int i = 2; i <= n; i++)
        ans[ind[i]] = ove[i][0];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, wgt + i);
        edg.push_back((SEdge){u, v, wgt[i], i});
    }
    sort(edg.begin(), edg.end(), [](const SEdge &a, const SEdge &b) {
        return a.w < b.w;
    });
    fill(dsu + 1, dsu + n + 1, -1);
    for (SEdge &cur : edg)
        if (connect(cur.u, cur.v))
        {
            // printf("%d %d %d\n", cur.u, cur.v, cur.w);
            spa[cur.ind] = true;
            adj[cur.u].push_back(make_pair(cur.v, cur.ind));
            adj[cur.v].push_back(make_pair(cur.u, cur.ind));
        }
    DFS(1);
    reverse(edg.begin(), edg.end());
    for (SEdge &cur : edg)
        if (!spa[cur.ind])
            ans[cur.ind] = get(cur.u, cur.v, cur.w);
    solve();
    for (int i = 1; i <= m; i++)
        printf("%d ", ans[i] == INF ? -1 : ans[i] - 1);
}