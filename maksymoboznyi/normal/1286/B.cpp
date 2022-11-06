#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e3 + 3;

int tt = 0, root, c[N], n, tin[N], tout[N], ans[N];
vector<int> g[N];

bool is_son(int u, int v) {
    return (tin[u] > tin[v] && tout[u] < tout[v]);
}

void dfs1(int v, int par) {
    tt++;
    tin[v] = tt;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != par)
            dfs1(g[v][i], v);
    tt++;
    tout[v] = tt;
}

void dfs2(int v, int par) {
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != par)
            dfs2(g[v][i], v);
    vector<pair<int, int> > p;
    for (int i = 1; i <= n; i++)
        if (is_son(i, v))
            p.pb({ans[i], i});
    sort(p.begin(), p.end());
    if (c[v] > p.size()) {
        cout << "NO";
        exit(0);
    }
    for (int i = c[v]; i < p.size(); i++)
        ans[p[i].second] += 2, p[i].first += 2;
    if (c[v] == p.size())
        if (p.size() == 0)
            ans[v] = 1;
        else
            ans[v] = p.back().first + 1;
    else
        ans[v] = p[c[v]].first - 1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p >> c[i];
        if (p == 0)
            root = i;
        else
            g[p].pb(i);
    }
    dfs1(root, -1);
    dfs2(root, -1);
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}