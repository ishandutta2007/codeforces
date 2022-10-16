#include <iostream>

using namespace std;

int a[100000];

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int64_t bs = -1e9;
    int64_t mis = 0, out = 1, s = 0;
    for (int i = 0; i < n; ++i) {
      s += a[i];
      if (i == n - 1 && out) {
        break;
      }
      bs = max(bs, s - mis);
      if (s <= mis) {
        out = 0;
      }
      mis = min(mis, s);
    }
    cout << (s > bs? "YES": "NO") << '\n';
  }
}