#include <iostream>

using namespace std;

constexpr int N = 1e3;

int64_t a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++++i) {
      int64_t balance = 0, minbalance = -1ull >> 1;
      for (int j = i; j < n && minbalance >= 0; ++j) {
        if (j & 1) {
          ans += max(0ll, min(a[j], balance) - max(balance - minbalance, 1ll) + 1);
        }
        balance += a[j] * (2 * (~j & 1) - 1);
        minbalance = min(minbalance, balance);
      }
    }
    cout << ans << '\n';
    return 0;
}