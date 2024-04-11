#include <algorithm>
#include <iostream>

using namespace std;

constexpr int N = 2e5, mod = 998244353;

int a[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    int64_t ans = 1, ansskip = 1;
    int skip = 0;
    if (a[n - 1] > a[n - 2] + 1) {
      ans = ansskip = 0;
    } else if (a[n - 1] == a[n - 2] + 1) {
      skip = count(a, a + n, a[n - 2]) + 1;
    } else {
      ansskip = 0;
    }
    for (int i = 1; i <= n; ++i) {
      (ans *= i) %= mod;
      if (i != skip) {
        (ansskip *= i) %= mod;
      }
    }
    cout << (ans + mod - ansskip) % mod << '\n';
  }
  return 0;
}