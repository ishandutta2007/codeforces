#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, w;
  cin >> t;
  while (t--) {
    cin >> n >> w;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    int s = 0, ok = 1;
    for (int i = 0; i < n; ++i) {
      if (s + a[i] != w) {
        s += a[i];
        b[i] = a[i];
      } else if (i != n - 1) {
        swap(a[i], a[i + 1]);
        --i;
      } else {
        ok = 0;
      }
    }
    if (ok) {
      cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
      }
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}