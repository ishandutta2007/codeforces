#include <bits/stdc++.h>

using namespace std;

void solve() {
   int N, M; cin >> N >> M;
   vector<vector<int>> adj(N);
   for (int i = 0; i < M; ++i) {
      int x, y; cin >> x >> y;
      adj[--y].emplace_back(--x);
   }
   vector<int> dp(N);
   vector<int> ans;
   for (int v = 0; v < N; ++v) {
      for (int u : adj[v]) dp[v] = max(dp[v], dp[u] + 1);
      if (dp[v] == 2) {
         dp[v] = -1;
         ans.emplace_back(v);
      }
   }
   cout << int(ans.size()) << "\n";
   for (int v : ans) cout << v + 1 << " "; cout << "\n";
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) solve();
}