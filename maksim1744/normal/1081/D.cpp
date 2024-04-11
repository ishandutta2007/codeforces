/*
    20.12.2018 16:21:07
*/

#include <bits/stdc++.h>

using namespace std;

vector< bool > u;
vector< vector< pair< int, int > > > g;

void dfs(int v, int c) {
    u[v] = true;
    for (auto edge : g[v]) {
        if (edge.second <= c && !u[edge.first]) {
            dfs(edge.first, c);
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector< int > x(k);
    for (int i = 0; i < k; ++i) {
        cin >> x[i];
        --x[i];
    }
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    int l = 0, r = 1e9 + 5;
    while (r - l > 1) {
        int c = l + (r - l) / 2;
        u.assign(n, false);
        dfs(x[0], c);
        bool ok = true;
        for (int i = 0; i < k; ++i) {
            if (!u[x[i]]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            r = c;
        } else {
            l = c;
        }
    }
    for (int i = 0; i < k; ++i) {
        cout << r << ' ';
    }
    cout << '\n';
    return 0;
}