#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, M; cin >> N >> M;
   vector<ll> C(N);
   for (int i = 0; i < N; ++i) cin >> C[i];
   vector<array<int, 2>> edges(M);
   vector<vector<int>> adj(N);
   for (int i = 0; i < M; ++i) {
      int v, u; cin >> v >> u;
      edges[i] = {--v, --u};
      adj[v].emplace_back(i);
      adj[u].emplace_back(i);
   }
   int e = -1;
   vector<int> dist(N, -1);
   vector<vector<int>> tree(N);
   function<void(int)> dfs = [&](int v) {
      for (int i : adj[v]) {
         int u = edges[i][0] ^ edges[i][1] ^ v;
         if (dist[u] >= 0) {
            if ((dist[v] + dist[u] + 1) & 1) e = i;
         } else {
            tree[v].emplace_back(i);
            dist[u] = dist[v] + 1;
            dfs(u);
         }
      }
   };
   dist[0] = 0;
   dfs(0);
   array<ll, 2> sum{};
   for (int i = 0; i < N; ++i) sum[dist[i] & 1] += C[i];
   if (e == -1 && sum[0] != sum[1]) {
      cout << "NO\n";
      return 0;
   }
   vector<ll> ans(M);
   if (e != -1) {
      int v = edges[e][0];
      int u = edges[e][1];
      assert((dist[v] & 1) == (dist[u] & 1));
      int p = dist[v] & 1;
      ans[e] = (sum[p] - sum[p ^ 1]) >> 1;
      C[v] -= ans[e];
      C[u] -= ans[e];
   }
   function<void(int)> solve = [&](int v) {
      for (int i : tree[v]) {
         int u = edges[i][0] ^ edges[i][1] ^ v;
         solve(u);
         ans[i] = C[u];
         C[u] -= ans[i];
         C[v] -= ans[i];
      }
   };
   solve(0);
   cout << "YES\n";
   for (int i = 0; i < M; ++i) {
      cout << ans[i] << "\n";
   }
}