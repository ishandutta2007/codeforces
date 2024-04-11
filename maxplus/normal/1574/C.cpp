#include <algorithm>
#include <iostream>

using namespace std;

template<typename... Ts> void print(const Ts&... ts) { ((cout << ts << ' '), ...) << '\n'; }
struct { int operator ()() { return *this; } template <typename T> operator T() { T t; cin >> t; return t; } } $;
template <typename T, typename S> bool mini(T& a, S b) { return b < a? a = b, 1: 0; }
template <typename T, typename S> bool maxi(T& a, S b) { return a < b? a = b, 1: 0; }
template <typename T> T unz(T a) { return max(T{}, a); }

constexpr int N = 2e5;

int64_t a[N], s;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n = $;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s += a[i];
  }
  sort(a, a + n);
  for (int m = $; m--; ) {
    int64_t x = $, y = $, ans = 5e18;
    int p = upper_bound(a, a + n, x) - a;
    if (p != n) {
      mini(ans, unz(y - s + a[p]));
    }
    if (p) {
      mini(ans, unz(y - s + a[p - 1]) + x - a[p - 1]);
    }
    cout << ans << '\n';
  }
  return 0;
}