#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N; cin >> N;
   vector<vector<int>> G(N, vector<int>(N));
   vector<tuple<int, int, int>> edges;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         cin >> G[i][j];
         edges.emplace_back(G[i][j], i, j);
      }
   }
   sort(edges.begin(), edges.end());
   vector<int> root(N); iota(root.begin(), root.end(), 0);
   vector<int> szv(N, 1);
   vector<int> sze(N, 0);
   vector<vector<int>> dp(N, vector<int>(2));
   function<int(int)> getRoot = [&](int v) {
      if (root[v] != v) {
         root[v] = getRoot(root[v]);
      }
      return root[v];
   };
   for (auto e : edges) {
      int v = getRoot(get<1>(e));
      int u = getRoot(get<2>(e));
      if (v != u) {
         vector<int> ndp(szv[v]+szv[u]+1, 0);
         for (int sv = 1; sv <= szv[v]; ++sv) {
            for (int su = 1; su <= szv[u]; ++su) {
               ndp[sv+su] = (ndp[sv+su] + int64_t(dp[v][sv]) * dp[u][su]) % MOD;
            }
         }
         dp[v] = ndp;
         root[u] = v;
         szv[v] += szv[u];
         sze[v] += sze[u];
      }
      if (++sze[v] == szv[v] * szv[v]) dp[v][1] = 1;
   }
   int r = getRoot(0);
   for (int i = 1; i <= N; ++i) cout << dp[r][i] << ' '; cout << '\n';
}