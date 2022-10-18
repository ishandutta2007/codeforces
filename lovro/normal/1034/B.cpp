#define NDEBUG
#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>

// <lib>
typedef int64_t i64;
template <typename T, typename Compare = std::less<T>>
void sort2(T& a, T& b, Compare comp = Compare()) {
  if (comp(b, a)) {
    std::swap(a, b);
  }
}
// </lib>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  i64 a, b;
  cin >> a >> b;
  sort2(a, b);
  i64 ans = 0;
  if (a == 1) {
    ans += b / 6 * 6;
    ans += max<i64>(b%6 - 3, 0) * 2;
  } else if (a == 2) {
    switch (b) {
    case 0: case 1: case 2: ans = 0; break;
    case 3: ans = 4; break;
    case 7: ans = 12; break;
    default: ans = a*b; break;
    }
  } else {
    ans = a * b - (a * b) % 2;
  }
  cout << ans << '\n';
}