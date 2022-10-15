// stupid QD wasted me so much time while being fruitless...
// probably a symbolism of my non-existent oi career
#include <iostream>
#include <algorithm>
#define int long long
const int mxN = 1e5 + 5;
int a[mxN], b[mxN], ps[mxN], segtree[2][mxN << 2];
void build(int op, int idx, int l, int r) {
  if (l == r) {
    segtree[op][idx] = ps[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(op, idx << 1, l, mid);
  build(op, idx << 1 | 1, mid + 1, r);
  if (!op) segtree[op][idx] = std::min(segtree[op][idx << 1], segtree[op][idx << 1 | 1]);
  else segtree[op][idx] = std::max(segtree[op][idx << 1], segtree[op][idx << 1 | 1]);
}
int qry(int op,int idx,int l,int r,int x,int y) {
  if (l > y || r < x || l > r) return (op ? -1e18 : 1e18);
  if (x <= l && r <= y) return segtree[op][idx];
  int mid = (l + r) >> 1;
  if (!op) return std::min(qry(op, idx << 1, l, mid, x, y), qry(op, idx << 1 | 1, mid + 1, r, x, y));
  else return std::max(qry(op, idx << 1, l, mid, x, y), qry(op, idx << 1 | 1, mid + 1, r, x, y));
}
void eat() {
  int n, q;
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    ps[i] = ps[i - 1] + a[i] - b[i];
  }
  for (int i = 0; i < 2; i++) build(i, 1, 0, n);
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (ps[r] - ps[l - 1] != 0) std::cout << "-1\n";
    else {
      l--;
      int oo = qry(0, 1, 0, n, l, r), ee = qry(1, 1, 0, n, l, r);
      if (ps[r] == ee) std::cout << ee - oo << "\n";
      else std::cout << "-1\n";
    }
  }
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) eat();
}