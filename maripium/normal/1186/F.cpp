#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int deg[N];
int cdeg[N];

int main() {
   int n, m;
   scanf("%d %d", &n, &m);
   vector<pair<int, int>> edges;
   for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      ++deg[u], ++deg[v];
      edges.emplace_back(u, v);
   }
   for (int i = 1; i <= n; ++i) {
      cdeg[i] = deg[i];
   }
   sort(edges.begin(), edges.end(), [&](pair<int, int> x, pair<int, int> y) {
      int dx = min(deg[x.first], deg[x.second]);
      int dy = min(deg[y.first], deg[y.second]);
      return dx < dy;
   });
   vector<pair<int, int>> ans;
   for (auto e : edges){
      int u, v;
      tie(u, v) = e;
      if (deg[u] <= 2 * (cdeg[u] - 1) && deg[v] <= 2 * (cdeg[v] - 1)) {
         cdeg[u]--;
         cdeg[v]--;
      } else {
         ans.push_back(e);
      }
   }
   printf("%d\n", (int) ans.size());
   for (auto e : ans) {
      printf("%d %d\n", e.first, e.second);
   }
}