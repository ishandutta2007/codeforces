#include <bits/stdc++.h>

using namespace std;

const int N = 500500;
const int mod = 1e9 + 7;

void add(int &x,int y) {
   x += y; if (x >= mod) x -= mod;
}

int mul(int x,int y) {
   return (long long) x * y % mod;
}

struct SegmentTree {
   int t[N << 2];

   void upd(int v,int l,int r,int p, int val) {
      if (p > r || p < l) return;
      if (l == r) {
         add(t[v], val);
         return;
      }
      int md = (l + r) >> 1;
      upd(v << 1, l, md, p, val);
      upd(v << 1 | 1, md + 1, r, p, val);
      t[v] = (t[v << 1] + t[v << 1 | 1]) % mod;
   }

   int get(int v,int l,int r,int L,int R) {
      if (L > r || R < l) return 0;
      if (L <= l && r <= R) return t[v];
      int md = (l + r) >> 1;
      return (get(v << 1, l, md, L, R) + get(v << 1 | 1, md + 1, r, L, R)) % mod;
   }
} pr, sf;

int a[N];
int id[N];

int main() {
   int n; scanf("%d", &n);
   for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      id[i] = i;
   }

   sort(id + 1, id + 1 + n, [&](int u,int v) { return a[u] < a[v]; } );

   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      int id = ::id[i];
      int cur = mul(id, n - id + 1);
      add(cur, mul(n - id + 1, pr.get(1, 1, n, 1, id)));
      add(cur, mul(id, sf.get(1, 1, n, id, n)));
      add(ans, mul(cur, a[id]));
      pr.upd(1, 1, n, id, id);
      sf.upd(1, 1, n, id, n - id + 1);
   }

   printf("%d\n", ans);
}