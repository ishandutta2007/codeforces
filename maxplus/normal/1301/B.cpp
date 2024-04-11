#include <iostream>
#include <algorithm>
#include <vector>

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
    vector<int> b;
    for (int i = 0; i < n; ++i) {
      if (a[i] != -1) {
        continue;
      }
      if (i != 0 && a[i - 1] != -1) {
        b.push_back(a[i - 1]);
      }
      if (i != n - 1 && a[i + 1] != -1) {
        b.push_back(a[i + 1]);
      }
    }
    sort(b.begin(), b.end());
    int k = 0;
    if (!b.empty()) {
      k = (b[0] + b[b.size() - 1]) / 2;
    }
    int m = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == -1) {
        a[i] = k;
      }
      if (i != 0) {
        m = max(m, abs(a[i] - a[i - 1]));
      }
    }
    cout << m << ' ' << k << '\n';
  }
}