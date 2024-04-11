#include <algorithm>
#include <iostream>

using namespace std;

template<typename... Ts> void print(const Ts&... ts) { ((cout << ts << ' '), ...) << '\n'; }
struct { int operator ()() { return *this; } template <typename T> operator T() { T t; cin >> t; return t; } } $;
template <typename T, typename S> bool mini(T& a, S b) { return b < a? a = b, 1: 0; }
template <typename T, typename S> bool maxi(T& a, S b) { return a < b? a = b, 1: 0; }

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int testcase = $; testcase; --testcase) {
    int a[]{$, $, $}, m = $;
    sort(a, a + 3);
    if (m > a[0] + a[1] + a[2] - 3 || a[2] > m + a[0] + a[1] + 1) {
      cout << "NO\n";
    } else {
      cout << "YEs\n";
    }
  }
  return 0;
}