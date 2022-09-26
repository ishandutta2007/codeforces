#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400400;

#define yes(v) (v << 1)
#define no(v) (v << 1 | 1)

struct TwoSat {
   int N;
   vector<vector<int>> adj;
   vector<int> dfn, low, comp;
   stack<int> st;
   vector<int> ans;
   int ncomp, timer;
   TwoSat(int N = 0): N(N), adj(N), dfn(N, -1), low(N, -1), comp(N, -1), st(), ncomp(0), timer(0), ans(N, -1){
   }
   void ad(int v, int u) {
      adj[v].emplace_back(u);
   }
   void dfs1(int v) {
      st.emplace(v);
      dfn[v] = low[v] = timer++;
      for (int u : adj[v]) {
         if (~dfn[u]) {
            low[v] = min(low[v], dfn[u]);
         } else {
            dfs1(u);
            low[v] = min(low[v], low[u]);
         }
      }
      if (dfn[v] == low[v]) {
         int u;
         do {
            u = st.top(); st.pop();
            dfn[u] = low[u] = MAXN;
            comp[u] = ncomp;
         } while (u != v);
         ncomp++;
      }
   }
   bool solve() {
      for (int i = 0; i < N; ++i) if (dfn[i] == -1) dfs1(i);
      for (int i = 0; i < N; i += 2) {
         if (comp[i] == comp[i ^ 1]) return false;
      }
      return true;
   }
   vector<bool> answer(){
      vector<vector<int>> adj2(ncomp);
      for (int i = 0; i < N; ++i) {
         for (int j : adj[i]) {
            if (comp[i] != comp[j]) {
               adj2[comp[i]].emplace_back(comp[j]);
            }
         }
      }
      vector<bool> visited(ncomp);
      vector<int> order;
      function<void(int)> dfs2 = [&](int v) {
         visited[v] = true;
         for (auto u : adj2[v]) {
            if (!visited[u]) dfs2(u);
         }
         order.emplace_back(v);
      };
      for (int i = 0; i < ncomp; ++i) if (!visited[i]) dfs2(i);
      assert(order.size() == ncomp);
      reverse(order.begin(), order.end());
      vector<bool> ans(N / 2);
      vector<int> loc(ncomp);
      for (int i = 0; i < ncomp; ++i) {
         loc[order[i]] = i;
      }
      for (int i = 0; i < N / 2; ++i) {
         if (loc[comp[i << 1]] > loc[comp[i << 1 | 1]]) {
            ans[i] = true;
         } else {
            ans[i] = false;
         }
      }
      return ans;
   }
} ts;

int main() {
   ios_base::sync_with_stdio(false);
   int N, M;
   cin >> N >> M;
   vector<int> T(M);
   vector<vector<pair<int, int>>> adj(N);
   for (int i = 0; i < M; ++i) {
      int v, u, z;
      cin >> v >> u >> z >> T[i];
      --v, --u;
      adj[v].emplace_back(z, i);
      adj[u].emplace_back(z, i);
   }
   vector<vector<int>> adj2(N);
   for (int v = 0; v < N; ++v) {
      sort(adj[v].begin(), adj[v].end());
      for (int i = 0; i < int(adj[v].size()); ++i) {
         if ((i > 0 && adj[v][i].first == adj[v][i - 1].first) || (i + 1 < int(adj[v].size()) && adj[v][i].first == adj[v][i + 1].first)) {
            adj2[v].emplace_back(adj[v][i].second);
         }
      }
      if (adj2[v].size() > 2) {
         cout << "No\n";
         return 0;
      }
   };
   auto solve = [&](int mid) {
      ts = TwoSat(6 * M);
      int cnt = M;
      for (int v = 0; v < N; ++v) {
         if (adj2[v].size() == 2) {
            ts.ad(no(adj2[v][0]), yes(adj2[v][1]));
            ts.ad(no(adj2[v][1]), yes(adj2[v][0]));
         }
         int cur = -1;
         for (auto e : adj[v]) {
            int id = e.second;
            if (cur == -1) {
               cur = id;
            } else {
               ts.ad(yes(cur), no(id));
               ts.ad(yes(id), no(cur));
               ts.ad(yes(cur), yes(cnt));
               ts.ad(yes(id), yes(cnt));
               ts.ad(no(cnt), no(cur));
               ts.ad(no(cnt), no(id));
               cur = cnt++;
            }
         }
      }
      for (int i = 0; i < M; ++i) {
         if (T[i] > mid) {
            ts.ad(yes(i), no(i));
         }
      }
      return ts.solve();
   };
   int low = 0, high = 1e9 + 22;
   while (low < high) {
      int mid = low + (high - low) / 2;
      if (solve(mid)) high = mid;
      else low = mid + 1;
   }
   if (!solve(low)) return cout << "No\n", 0;
   cout << "Yes\n";
   solve(low);
   vector<bool> ans = ts.answer();
   ans.resize(M);
   cout << low << " " << count(ans.begin(), ans.end(), true) << "\n";
   for (int i = 0; i < M; ++i) {
      if (ans[i]) cout << i + 1 << " ";
   }
}