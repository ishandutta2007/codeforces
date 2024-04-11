#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  // freopen("#.in", "r", stdin); // @
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long double p;
  cin >> n >> p;
  int l = -1, r = n;
  i64 sum = i64(n) * (n - 1) * (n - 2) / 3;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    i64 x = i64(mid) * (mid - 1) * (mid - 2) / 3 + i64(mid) * (mid - 1) * (n - mid) + i64(mid) * (n - mid) * (n - mid - 1) / 2;
    // cout << mid << ' ' << x << " / " << sum << '\n'; // @
    if (x >= sum * p) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << '\n';
  return 0;
}