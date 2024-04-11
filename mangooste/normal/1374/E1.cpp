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

int n, k;
vector<array<int, 3>> a;
vector<vector<vector<int>>> want(2, vector<vector<int>>(2));
vector<vector<vector<ll>>> pref(2, vector<vector<ll>>(2));

void Main() {
  cin >> n >> k;
  a.resize(n);
  for (auto &el : a) {
    cin >> el[0] >> el[1] >> el[2];
    want[el[1]][el[2]].push_back(el[0]);
  }
  if ((int)(want[1][0].size() + want[1][1].size()) < k || (int)(want[0][1].size() + want[1][1].size()) < k) {
    cout << "-1\n";
    return;
  }
  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      sort(want[a][b].begin(), want[a][b].end());
      pref[a][b].push_back(0);
      for (int i = 0; i < (int)want[a][b].size(); i++) {
        pref[a][b].push_back(pref[a][b].back() + want[a][b][i]);
      }
    }
  }
  ll ans = 1e18;
  if ((int)want[1][0].size() >= k && (int)want[0][1].size() >= k) {
    ans = min(ans, pref[1][0][k] + pref[0][1][k]);
  }
  for (int i = 1; i <= k && i <= (int)want[1][1].size(); i++) {
    ll cur_ans = 0;
    cur_ans += pref[1][1][i];
    int need = k - i;
    if ((int)want[1][0].size() >= need && (int)want[0][1].size() >= need) {
      cur_ans += pref[1][0][need] + pref[0][1][need];
      ans = min(ans, cur_ans);
    }
  }
  cout << ans << '\n';
}