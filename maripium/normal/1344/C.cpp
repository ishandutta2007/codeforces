#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, M;
   cin >> N >> M;
   vector<vector<int>> adj(N), radj(N);
   for (int i = 0; i < M; ++i) {
      int v, u;
      cin >> v >> u;
      adj[--v].emplace_back(--u);
      radj[u].emplace_back(v);
   }
   vector<bool> visited(N);
   vector<int> ord;
   function<void(int)> dfs = [&](int v) {
      visited[v] = true;
      for (int u : adj[v]) if (!visited[u]) dfs(u);
      ord.emplace_back(v);
   };
   for (int i = 0; i < N; ++i) if (!visited[i]) dfs(i);
   reverse(ord.begin(), ord.end());
   vector<int> ps(N);
   int cur = 0;
   for (int v : ord) ps[v] = cur++;
   for (int v = 0; v < N; ++v) {
      for (int u : adj[v]) if (ps[v] > ps[u]) {
         cout << "-1\n";
         exit(0);
      }
   }
   fill(visited.begin(), visited.end(), false);
   vector<bool> U(N), D(N);
   function<void(int)> up = [&](int v) {
      U[v] = true;
      for (int u : radj[v]) if (!U[u]) up(u);
   };
   function<void(int)> down = [&](int v) {
      D[v] = true;
      for (int u : adj[v]) if (!D[u]) down(u);
   };
   vector<bool> ans(N);
   for (int i = 0; i < N; ++i) {
      if (!U[i] && !D[i]) 
         ans[i] = true;
         if (!U[i]) up(i);
         if (!D[i]) down(i);
   }
   cout << count(ans.begin(), ans.end(), true) << "\n";
   for (int i = 0; i < N; ++i) {
      cout << "EA"[ans[i]];
   }
}