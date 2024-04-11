#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 100005, M = 100005, D = 150;

int n, m, q, u, v, c;
bool vis[N];
vector<pair<int, int>> ed[M];
vector<int> ve, tmp, adj[N];
vector<vector<int>> dsu;
map<pair<int, int>, int> ma;

int trace(vector<int> &dsu, int u)
{
    return dsu[u] < 0 ? u : dsu[u] = trace(dsu, dsu[u]);
}

void connect(vector<int> &dsu, int u, int v)
{
    if ((u = trace(dsu, u)) == (v = trace(dsu, v)))
        return;
    if (dsu[u] > dsu[v])
        swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
}

void build_big(vector<pair<int, int>> &ed)
{
    dsu.push_back(vector<int>(n + 1, -1));
    vector<int> &cur = dsu.back();
    for (pair<int, int> &u : ed)
        connect(cur, u.fi, u.se);
}

void DFS(int u)
{
    vis[u] = true;
    tmp.push_back(u);
    for (int &v : adj[u])
        if (!vis[v])
            DFS(v);
}

void build_small(vector<pair<int, int>> &ed)
{
    for (pair<int, int> &u : ed)
    {
        ve.push_back(u.fi);
        ve.push_back(u.se);
        adj[u.fi].push_back(u.se);
        adj[u.se].push_back(u.fi);
    }
    sort(ve.begin(), ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    for (int &u : ve)
        if (!vis[u])
        {
            DFS(u);
            for (int &x : tmp)
                for (int &y : tmp)
                    ma[{x, y}]++;
            tmp.clear();
        }
    for (int &v : ve)
    {
        vis[v] = false;
        adj[v].clear();
    }
    ve.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> c;
        ed[c].push_back({u, v});
    }
    for (int i = 1; i <= m; i++)
        if (ed[i].size() >= D)
            build_big(ed[i]);
        else
            build_small(ed[i]);
    cin >> q;
    while (q--)
    {
        cin >> u >> v;
        int ans = ma[{u, v}];
        for (vector<int> &ve : dsu)
            if (trace(ve, u) == trace(ve, v))
                ans++;
        cout << ans << '\n';
    }
}