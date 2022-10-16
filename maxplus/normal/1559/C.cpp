#include <iostream>

using namespace std;

constexpr int N = 1e4;

int a[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int sw = -1;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (i && a[i] && !a[i - 1]) {
        sw = i;
      }
    }
    if (!a[n - 1]) {
      sw = n;
    }
    if (sw == -1) {
      cout << n + 1 << ' ';
    }
    for (int i = 0; i < n; ++i) {
      cout << i + 1 << ' ';
      if (sw == i + 1) {
        cout << n + 1 << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}