#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int N;
vector<int> adj[MAXN];
int dp[MAXN][2];
int ans;

void dfs(int v, int p) {
   if (v != 1) {
      auto it = find(adj[v].begin(), adj[v].end(), p);
      adj[v].erase(it);
   }
   for (int u : adj[v]) {
      dfs(u, v);
   }
   vector<int> nxts;
   for (int u : adj[v]) {
      int val = max(dp[u][0], dp[u][1]);
      dp[v][0] = max(dp[v][0], val);
   }
   dp[v][0] += max(0, int(adj[v].size()) - 1);
   dp[v][0] = max(dp[v][0], int(adj[v].size()));
   int cur = 0;
   int mx = 0;
   for (int u : adj[v]) {
      int val = max(dp[u][0], dp[u][1]);
      cur = max(cur, mx + val);
      mx = max(mx, val);
   }
   cur += max(0, int(adj[v].size() - 2)) + (v != 1);
   ans = max(ans, cur);
   for (int u : adj[v]) {
      int val = max(dp[u][0], dp[u][1]);
      ans = max(ans, val + max(int(adj[v].size()) - 1, 0) + (v != 1));
   }
   dp[v][1] = 1;
   for (int u : adj[v]) {
      dp[v][1] = max(dp[v][1], dp[u][0] + 1);
   }
   cur = 0;
   mx = 0;
   for (int u : adj[v]) {
      int val = dp[u][0];
      cur = max(cur, val + mx);
      mx = max(mx, val);
   }
   ans = max(ans, cur + 1);
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   cin >> N;
   for (int i = 0; i < N - 1; ++i) {
      int v, u;
      cin >> v >> u;
      adj[v].emplace_back(u);
      adj[u].emplace_back(v);
   }
   dfs(1, -1);
   cout << ans << "\n";
   return 0;
}