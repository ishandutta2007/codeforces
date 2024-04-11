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

const int INF = 1e9;
int n, p;
vector<int> a;

void Main() {
  cin >> n >> p;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  sort(a.begin(), a.end());
  /*-----------------------precalc cnt-------------------------------*/
  vector<int> suf_cnt_max(n + 1, 0);
  for (int i = n - 1, cur = 0; i >= 0; i--) {
    if (i != n - 1 && a[i] != a[i + 1]) {
      cur = 1;
    } else {
      cur++;
    }
    suf_cnt_max[i] = max(suf_cnt_max[i + 1], cur);
  }
  /*----------------------precalc values--------------------------------*/
  vector<int> cnt(n + 1);
  int first_value = max(a[0], a.back() - n + 1) - 1;
  for (int i = 0; i < n; i++) {
    cnt[max(0, a[i] - first_value)]++;
  }
  vector<int> suf_cnt_sum(n + 2, 0);
  for (int i = n; i >= 0; i--) {
    suf_cnt_sum[i] = suf_cnt_sum[i + 1] + cnt[i];
  }
  vector<int> values(n + 2);
  for (int i = 0; i <= n + 1; i++) {
    values[i] = suf_cnt_sum[i] + i;
  }
  vector<int> suf_values_max(n + 3, -INF), suf_values_min(n + 3, INF);
  for (int i = n + 1; i >= 0; i--) {
    suf_values_max[i] = max(suf_values_max[i + 1], values[i]);
    suf_values_min[i] = min(suf_values_min[i + 1], values[i]);
  }
  vector<int> pref_cnt_sum(n + 1, 0);
  pref_cnt_sum[0] = cnt[0];
  for (int i = 1; i <= n; i++) {
    pref_cnt_sum[i] = pref_cnt_sum[i - 1] + cnt[i];
  }
  /*-----------------------find answer-------------------------------*/
  vector<int> ans;
  for (int x = first_value + 1, delta = 1; x <= a.back(); x++, delta++) {
    bool ok = true;
    // (suf[i], i) -> (suf[i], i - 1)
    // fact[cnt[i]] * rfact[cnt[i]]
    int pos = (int)(upper_bound(a.begin(), a.end(), x) - a.begin());
    ok &= (suf_cnt_max[pos] < p);
    ok &= (pos < p);
    //n - p >= suf_cnt_sum[i + 1] + i -> ok = false
    ok &= (pref_cnt_sum.back() - pref_cnt_sum[delta] > n - p);
    ok &= (suf_values_min[delta + 1] - delta - 1 > n - p);
    // n < i + suf_cnt_sum[i + 1] -> ok = false
    ok &= (pref_cnt_sum.back() - pref_cnt_sum[delta] <= n);
    ok &= (suf_values_max[delta + 1] - delta - 1 <= n);
    // n - p >= suf_cnt_sum[i] + i ok = false
    ok &= (pref_cnt_sum.back() > n - p);
    ok &= (suf_values_min[delta + 1] - delta > n - p);
    // n < i + suf_cnt_sum[i] -> ok = false
    ok &= (pref_cnt_sum.back() <= n);
    ok &= (suf_values_max[delta + 1] - delta <= n);
    // try to push
    if (ok) {
      ans.push_back(x);
    }
  }
  cout << ans.size() << '\n';
  for (auto el : ans) {
    cout << el << ' ';
  }
  cout << '\n';
}