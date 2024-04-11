#include <iostream>
#include <algorithm>
#define int long long
const int mxN = 6e5 + 5, aaa = -1e18;
int a[mxN], b[mxN];
bool cmp(int u, int v) {
  return a[u] - b[u] > a[v] - b[v];
}
int eat(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int g = eat(b, a % b, y, x);
  y -= (a / b) * x;
  return g;
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int n, s = 0;
  std::cin >> n;
  int idx[n + 1];
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
    s += b[i];
    idx[i] = i;
  }
  std::sort(idx + 1, idx + n + 1, cmp);
  int ans[n + 1];
  ans[0] = s;
  for (int i = 1; i <= n; i++) ans[i] = (s += a[idx[i]] - b[idx[i]]);
  std::reverse(ans, ans + n + 1);
  int ptr = 0;
  for (int i = 1; i <= n; i++) {
    if (ans[i] > ans[ptr]) ptr = i;
  }
  int q;
  std::cin >> q;
  while (q--) {
    int x, y, u, v;
    std::cin >> x >> y;
    int g = eat(x, y, u, v), xx = x / g, yy = y / g;
    if (!(n % g)) {
      u *= n / g;
      v *= n / g;
      int z;
      if (u < 0) {
        z = (yy - u - 1) / yy;
        u += yy * z;
        v -= xx * z;
      }
      if (v < 0) {
        z = (xx - v - 1) / xx;
        u -= yy * z;
        v += xx * z;
      }
      if (u < 0 || v < 0) std::cout << "-1\n";
      else if (y * v == ptr) std::cout << ans[ptr] << "\n";
      else if (y * v < ptr) {
        z = std::min(u / yy, (ptr - y * v) / (xx * y));
        std::cout << std::max(ans[(v + z * xx) * y], (u / yy == z ? aaa : ans[(v + (z + 1) * xx) * y])) << "\n";
      }
      else {
        z = (y * v - ptr) / (xx * y);
        std::cout << std::max(ans[(v - z * xx) * y], (v - (z + 1) * xx < 0 ? aaa : ans[(v - (z + 1) * xx) * y])) << "\n";
      }
    }
    else std::cout << "-1\n";
  }
}