#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
const int mxN = (1ll << 19) + 5; 
struct node {
  int sz;
  std::vector<int> ab, ba, sum, ans;
  node(int x) {
    sz = x;
    ab.assign(sz, 0);
    ba.assign(sz, 0);
    sum.assign(sz, 0);
    ans.assign(sz, 0);
  }
  node(){}
}segtree[mxN << 2];
int arr[mxN << 2];
void build(int idx, int l, int r) {
  if (l == r) {
    segtree[idx] = node(1);
    segtree[idx].sum[0] = arr[l];
    segtree[idx].ab[0] = segtree[idx].ba[0] = segtree[idx].ans[0] = std::max(arr[l], 0ll);
    return;
  }
  int mid = (l + r) >> 1;
  build(idx << 1, l, mid);
  build(idx << 1 | 1, mid + 1, r);
  int n = segtree[idx << 1].sz;
  segtree[idx] = node(n << 1);
  for (int i = 0; i < n; i++) {
    segtree[idx].sum[i] = segtree[idx << 1].sum[i] + segtree[idx << 1 | 1].sum[i];
    segtree[idx].ab[i] = std::max(segtree[idx << 1].ab[i], segtree[idx << 1].sum[i] + segtree[idx << 1 | 1].ab[i]);
    segtree[idx].ba[i] = std::max(segtree[idx << 1 | 1].ba[i], segtree[idx << 1 | 1].sum[i] + segtree[idx << 1].ba[i]);
    segtree[idx].ans[i] = std::max({segtree[idx << 1].ans[i], segtree[idx << 1 | 1].ans[i], segtree[idx << 1].ba[i] + segtree[idx << 1 | 1].ab[i]});
  }
  std::swap(segtree[idx << 1], segtree[idx << 1 | 1]);
  for (int i = 0; i < n; i++) {
    segtree[idx].sum[n + i] = segtree[idx << 1].sum[i] + segtree[idx << 1 | 1].sum[i];
    segtree[idx].ab[n + i] = std::max(segtree[idx << 1].ab[i], segtree[idx << 1].sum[i] + segtree[idx << 1 | 1].ab[i]);
    segtree[idx].ba[n + i] = std::max(segtree[idx << 1 | 1].ba[i], segtree[idx << 1 | 1].sum[i] + segtree[idx << 1].ba[i]);
    segtree[idx].ans[n + i] = std::max({segtree[idx << 1].ans[i], segtree[idx << 1 | 1].ans[i], segtree[idx << 1].ba[i] + segtree[idx << 1 | 1].ab[i]});
  }
}
int32_t main() {
  int n;
  std::cin >> n;
  n = 1ll << n;
  for (int i = 0; i < n; i++) std::cin >> arr[i];
  build(1, 0, n - 1);
  int q, msk = 0;
  std::cin >> q;
  while (q--) {
    int x;
    std::cin >> x;
    msk ^= (1ll << x);
    std::cout << segtree[1].ans[msk] << "\n";
  }
}