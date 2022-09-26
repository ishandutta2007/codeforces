#include <bits/stdc++.h>

using namespace std;

const int MX = 200200;
const int64_t INF = 1e13;

int N;
int T[MX];
int H[MX];
vector<int> adj[MX];

array<int64_t, 2> dfs(int v, int p) {
   int64_t base_cost = 0;
   vector<int64_t> diff;
   for (int u : adj[v]) {
      if (u == p) continue;
      auto nxt = dfs(u, v);
      base_cost += nxt[0];
      diff.emplace_back(nxt[1] - nxt[0]);
   }
   sort(diff.begin(), diff.end());
   int D = int(diff.size());
   vector<int64_t> pref(D + 1);
   for (int i = 0; i < D; ++i) pref[i + 1] = pref[i] + diff[i];
   array<int64_t, 2> ans = {INF, INF};
   for (int z = 0; z < 2; ++z) {
      for (int i = 0; i <= D; ++i) {
         int cnts[2] = {i, D - i};
         ++cnts[z];
         ans[z] = min(ans[z], base_cost + pref[i] + int64_t(max(cnts[0], cnts[1])) * T[v]);
      }
   }
   if (H[v] > H[p]) {
      ans[0] = INF;
   } else if (H[v] < H[p]) {
      ans[1] = INF;
   }
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   cin >> N;
   for (int i = 1; i <= N; ++i) cin >> T[i];
   for (int i = 1; i <= N; ++i) cin >> H[i];
   for (int i = 0; i < N - 1; ++i) {
      int v, u; cin >> v >> u;
      adj[v].emplace_back(u);
      adj[u].emplace_back(v);
   }
   int root = 1;
   while (adj[root].size() > 1) root++;
   auto ans = dfs(adj[root][0], root);
   cout << min(ans[0], ans[1]) + T[root] << '\n';
   return 0;
}