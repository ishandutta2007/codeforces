#include <iostream>

using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    int64_t n, g, b;
    cin >> n >> g >> b;
    int64_t l = 0, r = int64_t(1e9) * int64_t(1e9) + 2, m;
    while (r - l > 1) {
      m = l + (r - l) / 2;
      int64_t gg = m / (g + b) * g + min(m % (g + b), g);
      int64_t bb = m / (g + b) * b + max(0ll, m % (g + b) - g);
      int64_t res = gg + min(gg, bb);
      if (res >= n) {
        r = m;
      } else {
        l = m;
      }
    }
    cout << r << '\n';
  }
}