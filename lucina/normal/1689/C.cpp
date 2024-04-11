#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int sz[nax];
vector <int> g[nax];

int dfs(int v, int par) {
    vector <pair <int, int>> bar;
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == par) continue;
        bar.push_back({to, dfs(to, v)});
        sz[v] += sz[to];
    }
    if (bar.size() == 0) return 0;
    if (bar.size() == 1) return sz[bar[0].first] - 1;
    return max(sz[bar[0].first] - 1 + bar[1].second, sz[bar[1].first]-1 + bar[0].second);
}

void solve() {
    cin >> n;
    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << dfs(1, 0) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        solve();
        for (int i = 1 ; i <= n ; ++ i)
            g[i].clear();
    }
}
/*
    +_+ So bored lately.
*/