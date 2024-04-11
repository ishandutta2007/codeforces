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
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (auto &el : a) {
      el = lower_bound(b.begin(), b.end(), el) - b.begin();
    }
    vector<int> max_in(n, -1);
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      dp[i] = 1;
      if (a[i] != 0 && max_in[a[i] - 1] != -1) {
        dp[i] = max(dp[i], max_in[a[i] - 1] + 1);
      }
      if (max_in[a[i]] == -1) {
        max_in[a[i]] = dp[i];
      } else {
        max_in[a[i]] = max(max_in[a[i]], dp[i]);
      }
    }
    cout << n - *max_element(dp.begin(), dp.end()) << '\n';
  }
}