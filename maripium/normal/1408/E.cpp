#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int M, N; cin >> M >> N;
   vector<int64_t> A(M); for (auto &a : A) cin >> a;
   vector<int64_t> B(N); for (auto &b : B) cin >> b;
   vector<tuple<int64_t, int, int>> edges;
   int64_t tot_cost = 0;
   for (int i = 0; i < M; ++i) {
      int K; cin >> K;
      while (K--) {
         int v; cin >> v; --v;
         tot_cost += A[i] + B[v];
         edges.emplace_back(A[i] + B[v], i, v+M);
      }
   }
   sort(edges.begin(), edges.end());
   reverse(edges.begin(), edges.end());
   vector<int> root(N+M);
   iota(root.begin(), root.end(), 0);
   function<int(int)> getRoot = [&](int v) {
      if (v != root[v]) {
         root[v] = getRoot(root[v]);
      }
      return root[v];
   };
   for (auto e : edges) {
      int v = getRoot(get<1>(e));
      int u = getRoot(get<2>(e));
      if (v != u) {
         tot_cost -= get<0>(e);
         root[u] = v;
      }
   }
   cout << tot_cost << '\n';
   return 0;
}