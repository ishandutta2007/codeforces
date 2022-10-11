#include <bits/stdc++.h>
using namespace std;

const int N = 200005, M = 200005, Q = 200005, LG = 18;

int n, m, q, u, l, r, a[N], pos[N], lst[N], par[M][LG];
char ans[Q];
vector<int> adj[M];
vector<pair<int, int>> que[M];

void DFS(int u, int p = 0)
{
    par[u][0] = p;
    for (int i = 1; i < LG; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];
    for (int &v : adj[u])
        DFS(v, u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u;
        u = pos[u];
        int prv = (u == 1 ? n : u - 1);
        adj[lst[prv]].push_back(i);
        lst[u] = i;
    }
    DFS(0);
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r;
        que[r].push_back({l, i});
    }
    for (int i = 1, mx = 0; i <= m; i++)
    {
        int u = i;
        for (int j = 0; j < LG; j++)
            if ((n - 1) >> j & 1)
                u = par[u][j];
        mx = max(mx, u);
        for (pair<int, int> &v : que[i])
            ans[v.second] = ('0' + (v.first <= mx));
    }
    cout << (ans + 1);
}