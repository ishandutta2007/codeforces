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
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> bal(n + 1);
    bal[0] = 0;
    for (int i = 0; i < n; i++) {
      bal[i + 1] = bal[i];
      if (s[i] == '+') {
        bal[i + 1]++;
      } else {
        bal[i + 1]--;
      }
    }
    vector<pair<int, int>> vals;
    for (int i = 1; i <= n; i++) {
      vals.emplace_back(bal[i], i);
    }
    sort(vals.begin(), vals.end());
    vector<int> pref(n + 1);
    pref[0] = 1e9;
    for (int i = 0; i < n; i++) {
      pref[i + 1] = min(pref[i], vals[i].second);
    }
    ll ans = 0;
    for (int init = 0;; init++) {
      int L = -1, R = n;
      while (R - L > 1) {
        int mid = (L + R) / 2;
        if (init + vals[mid].first >= 0) {
          R = mid;
        } else {
          L = mid;
        }
      }
      if (R == 0) {
        ans += n;
        break;
      }
      ans += pref[R];
    }
    cout << ans << '\n';
  }
}