#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, K;
   cin >> N >> K;
   vector<vector<int>> adj(N);
   for (int i = 0; i < N - 1; ++i) {
      int v, u;
      cin >> v >> u;
      adj[--v].emplace_back(--u);
      adj[u].emplace_back(v);
   }
   vector<int> sz(N);
   vector<int> par(N);
   vector<int> dist(N);
   function<void(int, int)> dfs = [&](int v, int p) {
      sz[v] = 1;
      for (int u : adj[v]) if (u != p) {
         par[u] = v;
         dist[u] = dist[v] + 1;
         dfs(u, v);
         sz[v] += sz[u];
      }
   };
   dfs(0, -1);
   for (int i = 0; i < N; ++i) {
      sz[i] -= dist[i] + 1;
   }
   sort(sz.rbegin(), sz.rend());
   long long ans = 0;
   for (int i = 0; i < N - K; ++i) ans += sz[i];
   cout << ans;
}