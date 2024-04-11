#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
    #define dprint(...)
#endif // LOCAL

void solve(int test_num) {
    int n, m;
    cin >> n >> m;

    vector removed(n, vector<bool>(n));
    constexpr ll INF = 1e17;
    vector g(n, vector<ll>(n, INF)), dist = g, dd = g;
    for (int i = 0; i < n; i++) g[i][i] = dd[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        for (int rot = 0; rot < 2; rot++, swap(v, u)) {
            g[v][u] = min<ll>(g[v][u], w);
            dd[v][u] = 1;
        }
    }

    for (int m = 0; m < n; m++) {
        for (int v = 0; v < n; v++) {
            for (int u = 0; u < n; u++) {
                dd[v][u] = min(dd[v][u], dd[v][m] + dd[m][u]);
            }
        }
    }

    vector<pair<ll, int>> min_row(n);
    auto calc_row = [&](int row) {
        min_row[row] = {INF, -1};
        for (int i = 0; i < n; i++) {
            if (removed[row][i]) continue;
            min_row[row] = min(min_row[row], pair{dist[row][i], i});
        }
    };

    dist[0][n - 1] = dist[n - 1][0] = 1;
    for (int row = 0; row < n; row++) {
        calc_row(row);
    }

    while (true) {
        int v = min_element(all(min_row)) - min_row.begin();
        if (min_row[v].first == INF) break;
        int u = min_row[v].second;
        ll cur_dist = min_row[v].first;

        for (int rot = 0; rot < 2; rot++, swap(v, u)) {
            for (int w = 0; w < n; w++) {
                if (g[u][w] != INF) {
                    dist[v][w] = min(dist[v][w], cur_dist + 1);
                    dist[w][v] = min(dist[w][v], cur_dist + 1);
                }
            }
        }

        removed[v][u] = removed[u][v] = true;
        calc_row(v);
        calc_row(u);
    }

    ll ans = 1e18;
    for (int v = 0; v < n; v++) {
        for (int u = 0; u < n; u++) {
            if (g[v][u] != INF && v != u) {
                ans = min(ans, g[v][u] * dist[v][u]);
                for (int w = 0; w < n; w++) {
                    if (dd[u][w] != INF) {
                        ans = min(ans, g[v][u] * (dist[w][w] + dd[u][w] + 1));
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}