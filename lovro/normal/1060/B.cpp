#define NDEBUG
#include <cstdint>
#include <iostream>

// <lib>
typedef uint64_t u64;
template <typename T, typename U> inline bool makemax(T& res, const U& x) {
  if (x > res) {
    res = x;
    return true;
  }
  return false;
}
// </lib>
using namespace std;

int digitsum(u64 x) {
  int ret = 0;
  while (x > 0) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  u64 n;
  cin >> n;
  int ans = 0;
  for (u64 p10 = 1; p10 <= n; p10 *= 10) {
    for (int first = 1; first <= 9; ++first) {
      u64 a = first * p10 + p10 - 1;
      if (a <= n) {
        makemax(ans, digitsum(a) + digitsum(n-a));
      }
    }
  }
  cout << ans << '\n';
}