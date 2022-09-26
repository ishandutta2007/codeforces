#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T;
   cin >> T;
   int z = 0;
   while (T--) {
      int N, M;
      cin >> N >> M;
      vector<vector<int>> adj(N);
      for (int i = 0; i < M; ++i) {
         int v, u;
         cin >> v >> u;
         adj[--v].emplace_back(--u);
      }
      vector<int> perm(N);
      iota(perm.begin(), perm.end(), 0);
      shuffle(perm.begin(), perm.end(), rng);
      int root = -1;
      auto ok = [&](int root) {
         vector<char> visited(N);
         bool good = true;
         function<void(int)> dfs = [&](int v) {
            visited[v] = 1;
            for (int u : adj[v]) {
               if (visited[u] == 0) dfs(u);
               else if (visited[u] == 2) good = false;
            }
            visited[v] = 2;
         };
         dfs(root);
         return good;
      };
      for (int i = 0; i < min(143, N); ++i) {
         if (ok(perm[i])) {
            root = perm[i];
            break;
         }
      }
      if (root == -1) {
         cout << "-1\n";
         continue;
      }
      vector<int> where(N);
      vector<int> preorder;
      vector<bool> visited(N);
      vector<int> level(N);
      function<void(int)> dfs = [&](int v) {
         where[v] = preorder.size();
         preorder.emplace_back(v);
         visited[v] = true;
         for (int u : adj[v]) {
            if (!visited[u]) {
               level[u] = level[v] + 1;
               dfs(u);
            }
         }
      };
      dfs(root);
      vector<int> cnt(N);
      vector<int> go(N);
      vector<bool> fail(N);
      for (int i = N - 1; i >= 0; --i) {
         int v = preorder[i];
         go[v] = v;
         for (int u : adj[v]) {
            if (where[v] < where[u]) {
               cnt[v] += cnt[u];
               if (level[go[v]] > level[go[u]]) {
                  go[v] = go[u];
               }
            } else {
               ++cnt[v];
               --cnt[u];
               if (level[go[v]] > level[u]) {
                  go[v] = u;
               }
            }
         }
         if (cnt[v] >= 2) fail[v] = true;
      }
      for (int i = 0; i < N; ++i) {
         int v = preorder[i];
         if (fail[go[v]]) fail[v] = true;
      }
      vector<int> ans;
      for (int i = 0; i < N; ++i) {
         if (!fail[i]) ans.emplace_back(i + 1);
      }
      if (ans.size() * 5 < N) ans = {-1};
      for (int v : ans) cout << v << " "; cout << "\n";
   }
}