#include<bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 3e5 + 5;

struct edge {
    int t, u, v;
};

int n, m, s, used[N];
vector<pair<int, int> > g[N], gt[N];
vector<edge> e;
pair<int, int> orient[N];

int ans = 0;

void dfs(int v) {
    ans++;
    used[v] = 1;
    for (auto [u, id] : g[v])
        if (!used[u]) {
            orient[id] = {v, u};
            dfs(u);
        }
}

int anst = 0;

void dfst(int v) {
    used[v] = 1;
    anst++;
    for (auto [u, id] : g[v])
        if (!used[u]) {
            if (e[id].t == 2) {
                orient[id] = {u, v};
            } else
                dfst(u);
        }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    e.pb({-1, -1, -1});
    for (int i = 1; i <= m; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        e.pb({t, u,  v});
        g[u].pb({v, i});
        if (t == 2) {
            g[v].pb({u, i});
        }
    }
    dfs(s);
    cout << ans << "\n";
    for (int i = 1; i <= m; i++)
        if (e[i].t == 2)
            if (orient[i].first == e[i].u)
                cout << '+';
            else
                cout << '-';
    cout << "\n";

    for (int i = 1; i <= n; i++)
        used[i] = 0;
    dfst(s);


    cout << anst << "\n";
    for (int i = 1; i <= m; i++)
        if (e[i].t == 2)
            if (orient[i].first == e[i].u)
                cout << '+';
            else
                cout << '-';
    cout << "\n";

    return 0;
}