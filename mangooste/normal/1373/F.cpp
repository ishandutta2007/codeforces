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

void solve_case() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &el : a) {
    cin >> el;
  }
  for (auto &el : b) {
    cin >> el;
  }
  if (accumulate(b.begin(), b.end(), 0ll) < accumulate(a.begin(), a.end(), 0ll)) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    a.push_back(a[i]);
    b.push_back(b[i]);
  }
  ll min_sub = 1e18;
  ll sum_a = 0, sum_b = 0;
  for (int i = 0; i < 2 * n; i++) {
    sum_a += a[i];
    sum_b += b[i];
    if (sum_a - sum_b - min_sub > 0) {
      cout << "NO\n";
      return;
    }
    min_sub = min(min_sub, sum_a - sum_b + b[i]);
  }
  cout << "YES\n";
}

void Main() {
  int t;
  cin >> t;
  while (t--) {
    solve_case();
  }
}