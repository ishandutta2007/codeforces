#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  Main();
#ifdef LOCAL
  cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

void Main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a) {
      cin >> el;
    }
    vector<int> ops;
    while (!is_sorted(a.begin(), a.end())) {
      vector<int> used(n + 1, 0);
      for (auto el : a) {
        used[el]++;
      }
      int cur = 0;
      while (used[cur] > 0) {
        cur++;
      }
      if (cur == n) {
        for (int i = 0; i < n; i++) {
          if (a[i] != i) {
            ops.push_back(i);
            a[i] = cur;
            break;
          }
        }
      } else {
        ops.push_back(cur);
        a[cur] = cur;
      }
    }
    assert((int)ops.size() <= 2 * n);
    cout << (int)ops.size() << '\n';
    for (auto el : ops) {
      cout << el + 1 << ' ';
    }
    cout << '\n';
  }
}