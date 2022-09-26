#include <bits/stdc++.h>

using namespace std;

const int N = 300300;

int n;
vector<int> g[N];
int f[N];
int ans;

void dfs(int v, int p) {
   vector<int> fs;
   for (int u : g[v]) {
      if (u != p) {
         dfs(u, v);
         fs.emplace_back(f[u]);
      }
   }
   sort(fs.rbegin(), fs.rend());
   ans = max(ans, 1 + (int) g[v].size());
   if (fs.size() > 1) {
      ans = max(ans, 1 + fs[0] + fs[1] + (int) g[v].size() - 2);
   }
   if (fs.size()) {
      ans = max(ans, 1 + fs[0] + (int) g[v].size() - 1);
      f[v] = 1 + fs[0] + g[v].size() - 2;
   } else {
      f[v] = 1;
   }
}

void solve() {
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      g[i].clear();
   }
   for (int i = 1; i < n; ++i) {
      int v, u;
      cin >> v >> u;
      g[v].emplace_back(u);
      g[u].emplace_back(v);
   }
   ans = 0;
   dfs(1, -1);
   cout << ans << "\n";
}

int main() {
   ios_base::sync_with_stdio(false);
   int tt;
   cin >> tt;
   while (tt--) {
      solve();
   }
}