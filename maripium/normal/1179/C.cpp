#include <bits/stdc++.h>

using namespace std;

const int N = 300300;
const int M = 1000100;

int n, m, q;
int a[N], b[N];
int T[M << 2];
int lz[M << 2];

void push(int v, int l, int r) {
   if (lz[v]) {
      T[v] += lz[v];
      if (l < r) {
         lz[v << 1] += lz[v];
         lz[v << 1 | 1] += lz[v];
      }
      lz[v] = 0;
   }
}

#define mid ((l + r) >> 1)

void add(int v, int l, int r, int L, int R, int val) {
   push(v, l, r);
   if (L > r || R < l) return;
   if (L <= l && r <= R) {
      lz[v] = val;
      push(v, l, r);
      return;
   }
   add(v << 1, l, mid, L, R, val);
   add(v << 1 | 1, mid + 1, r, L, R, val);
   T[v] = min(T[v << 1], T[v << 1 | 1]);
}

int find(int v, int l, int r) {
   push(v, l, r);
   if (T[v] >= 0) return -1;
   if (l == r) return l;
   int ans = find(v << 1 | 1, mid + 1, r);
   if (ans == -1) ans = find(v << 1, l, mid);
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> m;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      add(1, 0, M - 1, 0, a[i], -1);
   }
   for (int i = 1; i <= m; ++i) {
      cin >> b[i];
      add(1, 0, M - 1, 0, b[i], 1);
   }
   cin >> q;
   while (q--) {
      int op, pos, val;
      cin >> op >> pos >> val;
      if (op == 1) {
         add(1, 0, M - 1, 0, a[pos], 1);
         a[pos] = val;
         add(1, 0, M - 1, 0, a[pos], -1);
      } else {
         add(1, 0, M - 1, 0, b[pos], -1);
         b[pos] = val;
         add(1, 0, M - 1, 0, b[pos], 1);
      }
      cout << find(1, 0, M - 1) << "\n";
   }
}