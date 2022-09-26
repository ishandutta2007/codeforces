#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 200200;

int n, m, q;
vector<int> g[N];
vector<int> bigger[N];
ll ans;

ll get(int v) {
   return (ll) bigger[v].size() * (g[v].size() - bigger[v].size());
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 0; i < m; ++i) {
      int v, u;
      cin >> v >> u;
      g[v].emplace_back(u);
      g[u].emplace_back(v);
      if (v > u) swap(v, u);
      bigger[v].emplace_back(u);
   }
   for (int i = 1; i <= n; ++i) {
      ans += get(i);
   }
   cout << ans << "\n";
   cin >> q;
   for (int i = 1; i <= q; ++i) {
      int v;
      cin >> v;
      for (int u : bigger[v]) {
         ans -= get(u);
         bigger[u].emplace_back(v);
         ans += get(u);
      }
      ans -= get(v);
      bigger[v].clear();
      cout << ans << "\n";
   }
}