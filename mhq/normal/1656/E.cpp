#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
vector<int> g[maxN];
int h[maxN];
int deg[maxN];
void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) continue;
        h[to] = h[v] ^ 1;
        dfs(to, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
      int n;
      cin >> n;
      for (int i = 1; i <= n; i++) {
          g[i].clear();
          deg[i] = 0;
      }
      for (int i = 1; i < n; i++) {
          int u, v;
          cin >> u >> v;
          g[u].emplace_back(v);
          g[v].emplace_back(u);
          deg[u]++;
          deg[v]++;
      }
      dfs(1, -1);
      for (int i = 1; i <= n; i++) {
          if (h[i] % 2 == 0) cout << deg[i] << " ";
          else cout << -deg[i] << " ";
      }
      cout << '\n';
    }
    return 0;
}