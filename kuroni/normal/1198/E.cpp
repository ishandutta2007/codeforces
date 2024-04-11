#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 105, INF = 1E9 + 7;

int n, m, st, en, it = 1, ans = 0, tr[2 * N], vis[2 * N], fl[2 * N][2 * N];
pair<int, int> x[N], y[N];
vector<int> vx, vy, adj[2 * N];

void add_edge(int u, int v, int w)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
    fl[u][v] = w;
}

bool DFS(int u)
{
    vis[u] = it;
    if (u == en)
        return true;
    for (int &v : adj[u])
        if (fl[u][v] > 0 && vis[v] < it)
        {
            tr[v] = u;
            if (DFS(v))
                return true;
        }
    return false;
}

int trace()
{
    int v = en, add = INF;
    while (v != st)
    {
        int u = tr[v];
        add = min(add, fl[u][v]);
        v = u;
    }
    v = en;
    while (v != st)
    {
        int u = tr[v];
        fl[u][v] -= add;
        fl[v][u] += add;
        v = u;
    }
    return add;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i].fi >> y[i].fi >> x[i].se >> y[i].se;
        vx.push_back(x[i].fi); vx.push_back(++x[i].se);
        vy.push_back(y[i].fi); vy.push_back(++y[i].se);
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < (int)vx.size() - 1; j++)
            for (int k = 0; k < (int)vy.size() - 1; k++)
                if (vx[j] >= x[i].fi && vx[j] < x[i].se && vy[k] >= y[i].fi && vy[k] < y[i].se)
                    add_edge(j + 1, k + N, INF);
    st = 0; en = 2 * N - 1;
    for (int i = 0; i < (int)vx.size() - 1; i++)
        add_edge(st, i + 1, vx[i + 1] - vx[i]);
    for (int i = 0; i < (int)vy.size() - 1; i++)
        add_edge(i + N, en, vy[i + 1] - vy[i]);
    while (DFS(st))
    {
        it++;
        ans += trace();
    }
    cout << ans;
}