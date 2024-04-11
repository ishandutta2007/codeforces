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
    vector<vector<int>> inds(n);
    for (int i = 0; i < n; i++) {
      inds[a[i]].push_back(i);
    }
    vector<int> dp(n);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
      dp[i] = 1;
      auto it = upper_bound(inds[a[i]].begin(), inds[a[i]].end(), i);
      if (it != inds[a[i]].end()) {
        dp[i] = max(dp[i], dp[*it] + 1);
      }
      if (a[i] != n - 1 && !inds[a[i] + 1].empty()) {
        int cnt_right = (int)inds[a[i] + 1].size() - (int)(lower_bound(inds[a[i] + 1].begin(), inds[a[i] + 1].end(), i) - inds[a[i] + 1].begin());
        dp[i] = max(dp[i], 1 + cnt_right);
        if (inds[a[i] + 1][0] > i) {
          dp[i] = max(dp[i], cnt_right + dp[inds[a[i] + 1].back()]);
        }
      }
    }
    cout << n - *max_element(dp.begin(), dp.end()) << '\n';
  }
}