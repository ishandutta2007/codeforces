#include <bits/stdc++.h>

using namespace std;

void solve() {
   int n, m;
   cin >> n >> m;
   vector<vector<pair<int, int>>> g(3 * n);
   for (int i = 0; i < m; ++i) {
      int v, u;
      cin >> v >> u;
      --v, --u;
      g[v].emplace_back(u, i);
      g[u].emplace_back(v, i);
   }
   vector<bool> was(3 * n);
   vector<int> es;
   vector<int> vs;
   for (int v = 0; v < 3 * n; ++v) {
      if (!was[v]) {
         for (auto p : g[v]) {
            int u, id;
            tie(u, id) = p;
            if (!was[u]) {
               was[v] = true;
               was[u] = true;
               es.emplace_back(id);
               break;
            }
         }
         if (!was[v]) {
            vs.emplace_back(v);
         }
      }
   }
   assert(es.size() >= n || vs.size() >= n);
   if (es.size() >= n) {
      es.resize(n);
      cout << "Matching\n";
      for (int e : es) {
         cout << e + 1 << " ";
      }
      cout << "\n";
   } else {
      vs.resize(n);
      cout << "IndSet\n";
      for (int v : vs) {
         cout << v + 1 << " ";
      }
      cout << "\n";
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   int tt;
   cin >> tt;
   while (tt--) {
      solve();
   }
}