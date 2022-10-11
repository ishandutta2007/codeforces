#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
#include <climits>
#include <functional>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "./Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        v--, u--;
        g[v].emplace_back(u, 1);
        if (c) g[u].emplace_back(v, -1);
        else g[u].emplace_back(v, 1);
    }

    vector<int> col(n, -1);
    function<void(int)> dfs = [&](int v) {
        for (auto [u, c] : g[v]) {
            if (col[u] == -1) {
                col[u] = col[v] ^ 1;
                dfs(u);
            } else if (col[u] != (col[v] ^ 1)) {
                cout << "NO\n";
                exit(0);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            col[i] = 0;
            dfs(i);
        }
    }

    vector<int> ans;
    int best = INT_MIN;
    for (int st = 0; st < n; st++) {
        vector<int> dist(n, INT_MAX);
        dist[st] = 0;

        int rep = 0;
        for (; rep < n; rep++) {
            bool any = false;
            for (int i = 0; i < n; i++) {
                for (auto [j, c] : g[i]) {
                    if (dist[i] == INT_MAX) continue;
                    if (dist[j] <= dist[i] + c) continue;
                    dist[j] = dist[i] + c;
                    any = true;
                }
            }
            if (!any) break;
        }

        if (rep == n) continue;
        if (dist[st] < 0) {
            cout << "NO\n";
            exit(0);
        }

        int mx = *max_element(all(dist));
        if (mx > best) {
            best = mx;
            ans = dist;
        }
    }

    if (best == INT_MIN) {
        cout << "NO\n";
    } else {
        cout << "YES\n" << best << '\n';
        for (auto x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}