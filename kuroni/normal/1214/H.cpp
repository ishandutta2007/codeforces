#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 200005;

int n, k, u, v, cnt = 0, in[N], out[N], ans[N];
pair<int, int> f[N][2], g[N];
pair<int, pair<int, int>> dst = {0, {0, 0}};
vector<int> ve, adj[N];

void check(int x, int y, int z)
{
    if (x == 0 || y == 0 || z == 0 || k == 2)
        return;
    if (x + y + z - max(x, max(y, z)) >= k - 1)
    {
        cout << "No\n";
        exit(0);
    }
}

void add(int u, pair<int, int> v)
{
    v.fi++;
    for (int i = 0; i < 2; i++)
        if (f[u][i] < v)
            swap(f[u][i], v);
    check(v.fi, f[u][0].fi, f[u][1].fi);
}

void DFS_1(int u, int p = 0)
{
    ans[u] = ans[p] ^ 1;
    in[u] = ++cnt;
    f[u][0] = {0, u};
    f[u][1] = g[u] = {-N, 0};
    for (int &v : adj[u])
        if (v != p)
        {
            DFS_1(v, u);
            add(u, f[v][0]);
        }
    out[u] = cnt;
    dst = max(dst, {f[u][0].fi + f[u][1].fi, {f[u][0].se, f[u][1].se}});
}

void DFS_2(int u, int p = 0)
{
    g[u] = max(g[u], {-1, u});
    g[u].fi++;
    check(g[u].fi, f[u][0].fi, f[u][1].fi);
    for (int &v : adj[u])
        if (v != p)
        {
            if (in[v] <= in[f[u][0].se] && out[f[u][0].se] <= out[v])
                g[v] = max(g[v], max(g[u], f[u][1]));
            else
                g[v] = max(g[v], max(g[u], f[u][0]));
            DFS_2(v, u);
        }
}

bool DFS_3(int u, int des, int p = 0)
{
    ve.push_back(u);
    if (u == des)
        return true;
    for (int &v : adj[u])
        if (v != p && DFS_3(v, des, u))
            return true;
    ve.pop_back();
    return false;
}

void DFS_4(int u, int p, int col, int inc)
{
    ans[u] = col;
    for (int &v : adj[u])
        if (v != p)
            DFS_4(v, u, (col + inc) % k, inc);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS_1(1);
    if (k > 2)
    {
        DFS_2(1);
        DFS_3(dst.se.fi, dst.se.se);
        int le = ve[ve.size() / 2 - 1], ri = ve[ve.size() / 2];
        DFS_4(le, ri, 0, k - 1); DFS_4(ri, le, 1, 1);
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
        cout << ans[i] + 1 << " ";
}