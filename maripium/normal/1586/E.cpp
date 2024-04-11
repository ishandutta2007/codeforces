#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, M; cin >> N >> M;
   vector<int> par(N);
   iota(par.begin(), par.end(), 0);
   auto get_par = [&](int v) {
      while (v != par[v]) {
         v = par[v] = par[par[v]];
      }
      return v;
   };
   auto merge = [&](int v, int u) {
      v = get_par(v);
      u = get_par(u);
      if (v != u) {
         par[u] = v;
         return true;
      }
      return false;
   };

   vector<vector<int>> adj(N);
   for (int i = 0; i < M; ++i) {
      int v, u; cin >> v >> u;
      --v, --u;
      if (merge(v, u)) {
         adj[v].push_back(u);
         adj[u].push_back(v);
      }
   }

   par.assign(N, -1);
   vector<int> dist(N);
   function<void(int)> dfs = [&](int v) {
      for (int u : adj[v]) if (u != par[v]) {
         par[u] = v;
         dist[u] = dist[v] + 1;
         dfs(u);
      }
   };
   dfs(0);
   vector<int> freq(N);
   int Q; cin >> Q;
   vector<vector<int>> ans(Q);
   for (int q = 0; q < Q; ++q) {
      int v, u; cin >> v >> u;
      ++freq[--v], ++freq[--u];
      vector<int> fromV{v};
      vector<int> fromU{u};
      while (v != u) {
         if (dist[v] > dist[u]) {
            v = par[v];
            fromV.push_back(v);
         } else {
            u = par[u];
            fromU.push_back(u);
         }
      }
      for (int i = int(fromU.size()) - 2; i >= 0; --i) fromV.push_back(fromU[i]);
      ans[q] = fromV;
   }
   int cnt = 0;
   for (int i = 0; i < N; ++i) if (freq[i] & 1) cnt++;
   if (cnt > 0) {
      cout << "NO\n" << cnt/2 << '\n';
   } else {
      cout << "YES\n";
      for (int q = 0; q < Q; ++q) {
         cout << int(ans[q].size()) << '\n';
         for (int i : ans[q]) cout << i+1 << ' '; cout << '\n';
      }
   }
}