#include <bits/stdc++.h>

using namespace std;

const int MX = 100100;

int N;
vector<int> adj[MX];
int ans[MX];
int tot = 0;

void dfs(int v, int p) {
   for (int u : adj[v]) if (u != p) {
      dfs(u, v);
      if (!ans[v] && !ans[u]) {
         ans[v] = u;
         ans[u] = v;
         tot += 2;
      } else if (!ans[u]) {
         ans[u] = ans[v];
         ans[v] = u;
         tot += 2;
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   cin >> N;
   for (int i = 1; i < N; ++i) {
      int v, u; cin >> v >> u;
      adj[v].emplace_back(u);
      adj[u].emplace_back(v);
   }
   dfs(1, -1);
   if (!ans[1]) {
      int v = adj[1].back();
      ans[1] = ans[v];
      ans[v] = 1;
      tot += 2;
   }
   cout << tot << '\n';
   for (int i = 1; i <= N; ++i) cout << ans[i] << ' '; cout << '\n';
   return 0;
}