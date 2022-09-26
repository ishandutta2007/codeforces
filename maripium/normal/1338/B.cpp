#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<vector<int>> adj(N);
   for (int i = 0; i < N - 1; ++i) {
      int v, u;
      cin >> v >> u;
      adj[--v].emplace_back(--u);
      adj[u].emplace_back(v);
   }
   int mx = N - 1;
   for (int v = 0; v < N; ++v) {
      int cnt = 0;
      for (int u : adj[v]) cnt += (adj[u].size() == 1);
      mx -= max(cnt - 1, 0);
   }
   int root = 0;
   while (adj[root].size() == 1) root++;
   set<int> st;
   function<void(int, int, int)> dfs = [&](int v, int p, int d) {
      if (adj[v].size() == 1) st.emplace(d);
      for (int u : adj[v]) if (u != p) {
         dfs(u, v, d ^ 1);
      }
   };
   dfs(root, -1, 0);
   int mn = st.size() == 1 ? 1 : 3;
   cout << mn << " " << mx << "\n";
   return 0;
}