#define NDEBUG
#include <cassert>
#include <cstdint>
#include <iostream>

// <lib>
typedef int64_t i64;
#define repeat(n) for (int _repc = (n); _repc > 0; --_repc)
// </lib>
using namespace std;

bool solve(i64 a, i64 b) {
  assert(a < b);
  if (b - a != 1) {
    return false;
  }
  i64 c = a + b;
  for (i64 i=2; i*i<=c; ++i) {
    if (c % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  repeat (T) {
    i64 a, b;
    cin >> b >> a;
    cout << (solve(a, b) ? "YES\n" : "NO\n");
  }
}