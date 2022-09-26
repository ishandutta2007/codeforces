#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<int> A(N), B(N);
   for (int i = 0; i < N; ++i) {
      cin >> A[i] >> B[i];
   }
   auto solve = [&](int sz) {
      int mask = 1 << sz;
      vector<vector<pair<int, int>>> adj(mask);
      for (int i = 0; i < N; ++i) {
         int a = A[i] % mask;
         int b = B[i] % mask;
         adj[a].emplace_back(b, 2 * i);
         adj[b].emplace_back(a, 2 * i + 1);
      }
      for (int i = 0; i < mask; ++i) {
         if (adj[i].size() & 1) {
            return;
         }
      }
      vector<int> walk;
      vector<int> used(N);
      function<void(int, int)> dfs = [&](int v, int pid) {
         while (adj[v].size()) {
            int u = adj[v].back().first;
            int id = adj[v].back().second;
            adj[v].pop_back();
            if (used[id / 2]) continue;
            used[id / 2] = true;
            dfs(u, id);
         }
         if (pid >= 0) {
            walk.emplace_back(pid ^ 1);
            walk.emplace_back(pid);
         }
      };
      dfs(A[0] % mask, -1);
      if (walk.size() != 2 * N) {
         return;
      }
      cout << sz << "\n";
      for (int v : walk) cout << v + 1 << " ";
      exit(0);
   };
   for (int i = 20; i >= 0; --i) solve(i);
}