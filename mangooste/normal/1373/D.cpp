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
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &el : a) {
      cin >> el;
    }
    ll ans = 0;
    for (int i = 0; i < n; i += 2) {
      ans += a[i];
    }
    ll max_can = 0;
    vector<ll> pref_even = {0};
    vector<ll> pref_odd = {0};
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        pref_even.push_back(pref_even.back() + a[i]);
      } else {
        pref_odd.push_back(pref_odd.back() + a[i]);
      }
    }
    ll cur_max = 0;
    for (int i = 1; i < (int)min(pref_even.size(), pref_odd.size()); i++) {
      max_can = max(max_can, pref_odd[i] - pref_even[i] + cur_max);
      cur_max = max(cur_max, pref_even[i] - pref_odd[i]);
    }
    cur_max = pref_even[1] - pref_odd[0];
    for (int i = 2; i < (int)min(pref_even.size(), pref_odd.size() + 1); i++) {
      max_can = max(max_can, pref_odd[i - 1] - pref_even[i] + cur_max);
      cur_max = max(cur_max, pref_even[i] - pref_odd[i - 1]);
    }
    cout << ans + max_can << '\n';
  }
}