#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#define int long long
const int mxN = 5e5 + 5, rt = 707;
int n, q, block, arr[mxN], lazy[mxN];
std::vector<std::pair<int, int> > op[rt];
void eat(int x) {
  for (int i = x * block; i <= n && i / block == x; i++) op[x].push_back(std::make_pair(arr[i], i));
  std::sort(op[x].begin(), op[x].end());
}
int32_t main() {
  std::cin >> n >> q;
  block = sqrt(n) + 1;
  for (int i = 1; i <= n; i++) std::cin >> arr[i];
  for (int i = 1; i <= n; i++) op[i / block].push_back(std::make_pair(arr[i], i));
  for (int i = 0; i <= block; i++) std::sort(op[i].begin(), op[i].end());
  while (q--) {
    int t;
    std::cin >> t;
    if (t == 1) {
      int l, r, x;
      std::cin >> l >> r >> x;
      op[l / block].clear();
      op[r / block].clear();
      if (l / block == r / block) {
        for (int i = l; i <= r; i++) arr[i] += x;
        eat(l / block);
      }
      else {
        for (int i = l / block + 1; i < r / block; i++) lazy[i] += x;
        for (int i = l; i <= n && l / block == i / block; i++) arr[i] += x;
        for (int i = r / block * block; i <= r && r / block == i /block; i++) arr[i] += x;
        eat(l / block);
        eat(r / block);
      }
    }
    else{
      int x;
      std::cin >> x;
      int aa = 1e9, bb = 0, cc = -1;
      for (int i = 0; i <= block; i++) {
        if (op[i].empty() || x - lazy[i] < 0) continue;
        auto ee = std::lower_bound(op[i].begin(), op[i].end(), std::make_pair(x - lazy[i], cc)) - op[i].begin();
        if (ee == op[i].size() || op[i][ee].first != x - lazy[i]) continue;
        aa = std::min(aa, op[i][ee].second);
        bb = std::max({bb, op[i][ee].second, op[i][std::upper_bound(op[i].begin(), op[i].end(), std::make_pair(x - lazy[i], n * 2)) - op[i].begin() - 1].second});
      }
      std::cout << (aa == 1e9 ? -1 : bb - aa) << "\n";
    }
  }
}