#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int tt;
   cin >> tt;
   while (tt--) {
      int n, k;
      cin >> n >> k;
      vector<vector<pair<int, int>>> g(n);
      for (int i = 0; i < n - 1; ++i) {
         int v, u, c;
         cin >> v >> u >> c;
         --v, --u;
         g[v].emplace_back(u, c);
         g[u].emplace_back(v, c);
      }
      vector<array<ll, 2>> dp(n);
      function<void(int, int)> dfs = [&](int v, int p) {
         vector<ll> vals;
         ll cur = 0;
         for (auto e : g[v]) {
            int u, w;
            tie(u, w) = e;
            if (u != p) {
               dfs(u, v);
               cur += dp[u][0];
               vals.emplace_back(dp[u][1] + w - dp[u][0]);
            }
         }
         sort(vals.rbegin(), vals.rend());
         for (int z = 0; z < 2; ++z) {
            dp[v][z] = cur;
            for (int i = 0; i < vals.size() && i + z < k; ++i) {
               dp[v][z] += max(0LL, vals[i]);
            }
         }
      };
      dfs(0, -1);
      cout << max(dp[0][0], dp[0][1]) << "\n";
   }
}