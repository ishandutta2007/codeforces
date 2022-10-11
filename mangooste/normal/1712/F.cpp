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
#endif // LOCAL

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n, -1), deg(n), dep(n);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i], p[i]--;
        dep[i] = dep[p[i]] + 1;
        deg[i]++, deg[p[i]]++;
        g[p[i]].push_back(i);
        g[i].push_back(p[i]);
    }

    vector<int> closest(n, n);
    queue<int> que;
    for (int v = 0; v < n; v++) {
        if (deg[v] == 1) {
            closest[v] = 0;
            que.push(v);
        }
    }
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto u : g[v]) {
            if (closest[u] == n) {
                closest[u] = closest[v] + 1;
                que.push(u);
            }
        }
    }

    int q;
    cin >> q;
    for (int it = 0; it < q; it++) {
        int x;
        cin >> x;
        vector<vector<int>> dp(n);
        int ans = 1;

        for (int v = n - 1; v >= 0; v--) {
            auto relax_ans = [&](int a, int dp_have) {
                if (dp[v].empty()) return;
                auto relax = [&](int b) {
                    if (b < 0 || b >= len(dp[v])) return;
                    ans = max(ans, min(dp_have + dp[v][b] - 2 * dep[v], a + b + x));
                };
                relax(0);

                int b = max(0, ans - a - x);
                if (b > len(dp[v])) return;
                while (b < len(dp[v])) {
                    int dist = dp[v][b] + dp_have - 2 * dep[v];
                    int res = a + b + x;
                    if (res > dist) break;
                    b++;
                }
                relax(b - 1);
                relax(b);
            };

            for (auto u : g[v]) {
                if (u == p[v]) continue;
                if (len(dp[u]) > len(dp[v])) swap(dp[u], dp[v]);

                for (int a = 0; a < len(dp[u]); a++) {
                    relax_ans(a, dp[u][a]);
                }
                for (int a = 0; a < len(dp[u]); a++) {
                    dp[v][a] = max(dp[v][a], dp[u][a]);
                }
            }
            relax_ans(closest[v], dep[v]);

            assert(closest[v] <= len(dp[v]));
            if (closest[v] == len(dp[v])) dp[v].push_back(dep[v]);
            assert(dp[v][closest[v]] >= dep[v]);
        }
        cout << ans << " \n"[it == q - 1];
    }
}