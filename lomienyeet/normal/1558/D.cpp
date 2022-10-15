#include <iostream>
#include <utility>
#define int long long
const int mxN = 4e5+5, mod = 998244353;
int fact[mxN], inv[mxN], x[mxN], y[mxN], a[mxN], b[mxN];
struct node {
  int lazy;
  std::pair<int, int> val;
} segtree[mxN << 2];
int bm(int b, int p, int m = mod) {
  int ans = 1;
  b %= m;
  while (p) {
    if (p & 1) (ans *= b) %= m;
    (b *= b) %= m;
    p >>= 1;
  }
  return ans;
}
void pushup(int idx) {
  segtree[idx].val = (segtree[idx << 1].val.first < segtree[idx << 1 | 1].val.first ? segtree[idx << 1].val : segtree[idx << 1 | 1].val);
}
void build(int idx, int l, int r) {
  segtree[idx].lazy = 0;
  if (l == r) {
    segtree[idx].val = std::make_pair(y[l], l);
    return;
  }
  int mid = (l + r) >> 1;
  build(idx << 1, l, mid);
  build(idx << 1 | 1, mid + 1, r);
  pushup(idx);
}
void pushdown(int idx) {
  segtree[idx << 1].lazy += segtree[idx].lazy;
  segtree[idx << 1 | 1].lazy += segtree[idx].lazy;
  segtree[idx << 1].val.first += segtree[idx].lazy;
  segtree[idx << 1 | 1].val.first += segtree[idx].lazy;
  segtree[idx].lazy = 0;
}
void upd(int idx, int l, int r, int x, int y, int v) {
  if (l > y || r < x)return;
  if (x <= l && r <= y) {
    segtree[idx].val.first += v;
    segtree[idx].lazy += v;
    return;
  }
  pushdown(idx);
  int mid = (l + r) >> 1;
  upd(idx << 1, l, mid, x, y, v);
  upd(idx << 1 | 1, mid + 1, r, x, y, v);
  pushup(idx);
}
int ncr(int a, int b) {
  if (a < b) return 0;
  return ((fact[a] * inv[b]) % mod * inv[a - b]) % mod;
}
void eat() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) std::cin >> x[i] >> y[i];
  int weeee = 0;
  if (m) {
    build(1, 1, m);
    for (int i = 1; i <= m; i++) {
      int z = segtree[1].val.second;
      b[z] = segtree[1].val.first;
      a[b[z]] = x[z];
      upd(1, 1, m, 1, z, 1);
      upd(1, 1, m, z, z, 1e9);
    }
    for (int i = 1; i <= m; i++) weeee += (a[b[i] + 1] < a[b[i]]);
    for (int i = 1; i <= m; i++) {
        a[b[i]] = 0;
        b[i] = 0;
    }
  }
  std::cout << ncr(n * 2 - weeee - 1, n) << "\n";
}
int32_t main() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i < mxN; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv[i] = bm(fact[i], mod - 2);
  }
  int t;
  std::cin >> t;
  while (t--) eat();
}