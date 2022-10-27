#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int64_t k;
    cin >> n >> m >> k;

    vector <int> a(n + 1);
    vector <array <int, 2>> e(m);

    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];

    for (int i = 0 ; i < m ; ++ i)
        cin >> e[i][0] >> e[i][1];

    int L = 1, R = 1e9 + 5, ans = -1;

    while (L <= R) {
        int x = L + R >> 1;
        vector <vector <int>> g(n + 1);
        for (const auto &[u, v] : e) {
            if (a[u] <= x && a[v] <= x) {
                g[u].push_back(v);
            }
        }
        vector <bool> vis(n + 1);
        vector <int> l(n + 1, -5);
        vector <bool> in_dfs(n + 1);
        bool found_cyc = false;
        function <void(int)> dfs = [&](int v) {
            vis[v] = true;
            in_dfs[v] = true;
            l[v] = 0;
            for (int to : g[v]) {
                if (in_dfs[to]) {
                    found_cyc = true;
                    return;
                }
                if (!vis[to]) dfs(to);
                l[v] = max(l[v], l[to]);
            }
            l[v] += 1;
            in_dfs[v] = false;
        };

        for (int i = 1 ; i <= n ; ++ i) {
            if (a[i] <= x && !vis[i]) dfs(i);
            if (found_cyc) break;
        }
        int l_max = *max_element(l.begin(), l.end());

        if (found_cyc || l_max >= k) {
            ans = x;
            R = x - 1;
        } else L = x + 1;
    }

    cout << ans << '\n';

}