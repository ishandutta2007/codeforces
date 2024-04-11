#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N, M;
   cin >> N >> M;
   vector<vector<int>> adj(N);
   for (int i = 0; i < M; ++i) {
      int v, u;
      cin >> v >> u;
      --v, --u;
      adj[v].emplace_back(u);
      adj[u].emplace_back(v);
   }
   vector<int> T(N);
   for (int i = 0; i < N; ++i) cin >> T[i], --T[i];
   vector<int> ord(N);
   iota(ord.begin(), ord.end(), 0);
   sort(ord.begin(), ord.end(), [&](int v, int u) {
      return T[v] < T[u];
   });
   // for (int v : ord) cerr << v << "\n"; cerr << "\n";
   vector<bool> used(N);
   for (int v : ord) {
      int mx = -1;
      set<int> st;
      for (int u : adj[v]) if (used[u]) st.emplace(T[u]); //= max(mx, T[u]);
      int z = 0;
      while (st.count(z)) z++;
      if (z != T[v]) {
         cout << "-1\n";
         return 0;
      }
      // cerr << "DONE " << v << "\n";
      used[v] = true;
   }
   for (int v : ord) cout << v + 1 << " ";
}