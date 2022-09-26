#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAXN = 300300;

int N, M;
ll A[MAXN];
ll B[MAXN];

int main() {
   ios_base::sync_with_stdio(false);
   int N, M;
   cin >> N >> M;
   for (int i = 0; i < M; ++i) {
      int v, u;
      ll d;
      cin >> v >> u >> d;
      A[v] += d;
      B[u] += d;
   }
   for (int i = 1; i <= N; ++i) {
      ll C = min(A[i], B[i]);
      A[i] -= C;
      B[i] -= C;
   }
   vector<int> goods;
   deque<int> bads;
   for (int i = 1; i <= N; ++i) {
      if (A[i]) {
         bads.emplace_back(i);
      } else if (B[i]) {
         goods.emplace_back(i);
      }
   }
   vector<tuple<int, int, ll>> edges;
   for (int v : goods) {
      while (B[v]) {
         int u = bads.front();
         ll C = min(A[u], B[v]);
         A[u] -= C;
         B[v] -= C;
         edges.emplace_back(u, v, C);
         if (A[u] == 0) {
            bads.pop_front();
         }
      }
   }
   cout << int(edges.size()) << "\n";
   for (auto e : edges) {
      cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << "\n";
   }
   return 0;
}