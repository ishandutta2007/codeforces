#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;
const int MAXV = MAXN * 5;
using ll = long long;
const ll INF = 1e14;

int N, M, P;
vector<int> costA[MAXV];
vector<int> costB[MAXV];
vector<pair<int, int>> monsters[MAXV];
ll tr[MAXV << 2];
ll lazy[MAXV << 2];

void build(int v, int l, int r) {
   if (l == r) {
      if (costB[l].size()) {
         tr[v] = -ll(*min_element(costB[l].begin(), costB[l].end()));
      } else {
         tr[v] = -INF;
      }
      return;
   }
   int md = (l + r) >> 1;
   build(v << 1, l, md);
   build(v << 1 | 1, md + 1, r);
   tr[v] = max(tr[v << 1], tr[v << 1 | 1]);
}

void push(int v, int l, int r) {
   if (lazy[v]) {
      tr[v] += lazy[v];
      if (l < r) {
         lazy[v << 1] += lazy[v];
         lazy[v << 1 | 1] += lazy[v];
      }
      lazy[v] = 0;
   }
}

void modify(int v, int l, int r, int L, int R, int z) {
   push(v, l, r);
   if (L > r || R < l) return;
   if (L <= l && r <= R) {
      lazy[v] += z;
      push(v, l, r);
      return;
   }
   int md = (l + r) >> 1;
   modify(v << 1, l, md, L, R, z);
   modify(v << 1 | 1, md + 1, r, L, R, z);
   tr[v] = max(tr[v << 1], tr[v << 1 | 1]);
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> M >> P;
   for (int i = 0; i < N; ++i) {
      int a, ca;
      cin >> a >> ca;
      costA[a].emplace_back(ca);
   }
   for (int i = 0; i < M; ++i) {
      int b, cb;
      cin >> b >> cb;
      costB[b].emplace_back(cb);
   }
   for (int i = 0; i < P; ++i) {
      int x, y, z;
      cin >> x >> y >> z;
      monsters[x].emplace_back(y, z);
   }
   build(1, 1, MAXV - 1);
   ll ans = -INF;
   for (int a = 1; a < MAXV; ++a) {
      for (auto p : monsters[a - 1]) {
         int y, z;
         tie(y, z) = p;
         modify(1, 1, MAXV - 1, y + 1, MAXV - 1, z);
      }
      for (int ca : costA[a]) {
         ans = max(ans, tr[1] - ca);
      }
   }
   cout << ans << "\n";
   return 0;
}