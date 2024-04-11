#include <iostream>

using namespace std;

constexpr int N = 1e5;

int a[N];

int main() {
//  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int ans = 0;
    for (int c: {0, 1}) if (cin.ignore())
    for (int i = 0; i < n; ++i) {
      a[i] = a[i] * c + cin.get() - '0';
      if (!c) {
        continue;
      }
      if (a[i] == 1) {
        ans += 2;
      } else if (i && a[i - 1] + a[i] == 2) {
        ans += 2 - (a[i - 1] == 0);
        a[i] = -1;
      } else if (a[i] == 0) {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}