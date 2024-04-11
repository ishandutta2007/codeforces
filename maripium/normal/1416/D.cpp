#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N, M, Q; cin >> N >> M >> Q;
   vector<int> P(N); for (int &p : P) cin >> p;
   vector<pair<int, int>> edges(M);
   for (int i = 0; i < M; ++i) {
      cin >> edges[i].first >> edges[i].second;
      --edges[i].first;
      --edges[i].second;
   }
   vector<int> op(Q), who(Q); for (int q = 0; q < Q; ++q) cin >> op[q] >> who[q], --who[q];
   vector<int> last(N+M, Q);
   for (int q = 0; q < Q; ++q) if (op[q] == 2) last[who[q]+N] = q;
   vector<int> root(N+M);
   iota(root.begin(), root.end(), 0);
   function<int(int)> getRoot = [&](int v) {
      if (root[v] != v) {
         root[v] = getRoot(root[v]);
      }
      return root[v];
   };
   vector<vector<int>> adj(N+M);
   vector<int> ord(N);
   for (int i = 0; i < M; ++i) if (last[N+i] == Q) {
      ord.emplace_back(i+N);
      int v = getRoot(edges[i].first);
      int u = getRoot(edges[i].second);
      adj[i+N].emplace_back(v);
      if (v != u) adj[i+N].emplace_back(u);
      root[v] = root[u] = i+N;
   }
   for (int q = Q-1; q >= 0; --q) if (op[q] == 2) {
      int i = who[q];
      ord.emplace_back(i+N);
      int v = getRoot(edges[i].first);
      int u = getRoot(edges[i].second);
      adj[i+N].emplace_back(v);
      if (v != u) adj[i+N].emplace_back(u);
      root[v] = root[u] = i+N;
   }
   vector<array<int, 20>> anc(N+M);
   vector<int> L(N+M, -1), R(N+M, -1);
   int idx = 0;
   function<void(int)> dfs = [&](int v) {
      if (v < N) {
         L[v] = R[v] = idx++;
         return;
      }
      for (int u : adj[v]) {
         anc[u][0] = v;
         dfs(u);
         if (L[v] == -1) L[v] = L[u];
         R[v] = R[u];
      }
   };
   reverse(ord.begin(), ord.end());
   for (int i : ord) {
      if (L[i] == -1) {
         anc[i][0] = i;
         dfs(i);
      }
   }
   for (int i = 0; i < N; ++i) if (L[i] == -1) {
      anc[i][0] = i;
      L[i] = R[i] = idx++;
   }
   int NN = 1;
   while (NN < N) NN <<= 1;
   vector<pair<int, int>> seg(NN << 1);
   auto modify = [&](int p, pair<int, int> v) {
      p += NN;
      seg[p] = v;
      for (p >>= 1; p > 0; p >>= 1) {
         seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
      }
   };
   auto query = [&](int l, int r) {
      pair<int, int> ans{0, 0};
      for (l += NN, r += NN; l <= r; l >>= 1, r >>= 1) {
         if (l & 1) ans = max(ans, seg[l++]);
         if (!(r & 1)) ans = max(ans, seg[r--]);
      }
      return ans;
   };
   for (int i = 0; i < N; ++i) modify(L[i],pair<int, int>(P[i], i));
   for (int z = 1; z < 20; ++z) {
      for (int v = 0; v < N+M; ++v) {
         anc[v][z] = anc[anc[v][z-1]][z-1];
      }
   }
   for (int q = 0; q < Q; ++q) {
      if (op[q] == 1) {
         int v = who[q];
         for (int z = 19; z >= 0; --z) if (last[anc[v][z]] > q) v = anc[v][z];
         auto f = query(L[v], R[v]);
         cout << f.first << '\n';
         modify(L[f.second], pair<int, int>(0, f.second));
      }
   }
}