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

int n, m, q;
vector<int> a, b;
ll sum_a = 0;
set<ll> sum_b;

void calc_sum_b() {
  vector<int> even, odd;
  for (int i = 0; i < m; i++) {
    if (i % 2 == 0) {
      even.push_back(b[i]);
    } else {
      odd.push_back(b[i]);
    }
  }
  vector<ll> pref_even(even.size() + 1, 0ll);
  for (int i = 0; i < (int)even.size(); i++) {
    pref_even[i + 1] = pref_even[i] + even[i];
  }
  vector<ll> pref_odd(odd.size() + 1, 0ll);
  for (int i = 0; i < (int)odd.size(); i++) {
    pref_odd[i + 1] = pref_odd[i] + odd[i];
  }
  int cnt_even = (n + 1) / 2;
  int cnt_odd = n - cnt_even;
  for (int i = 0; i + cnt_even - 1 < (int)even.size() && i + cnt_odd - 1 < (int)odd.size(); i++) {
    ll cur = 0;
    cur += pref_even[i + cnt_even] - pref_even[i];
    cur -= pref_odd[i + cnt_odd] - pref_odd[i];
    sum_b.insert(cur);
  }
  for (int i = 0; i + 1 + cnt_odd - 1 < (int)even.size() && i + cnt_even - 1 < (int)odd.size(); i++) {
    ll cur = 0;
    cur += pref_odd[i + cnt_even] - pref_odd[i];
    cur -= pref_even[i + 1 + cnt_odd] - pref_even[i + 1]; 
    sum_b.insert(cur);
  }
}

void update(int L, int R, ll x) {
  if (L % 2 == 0) {
    if (R % 2 == 1) {
      sum_a += x;
    }
  } else {
    if (R % 2 == 0) {
      sum_a -= x;
    }
  }
}

ll get() {
  auto it = sum_b.lower_bound(sum_a);
  ll ans = 1e18;
  if (it != sum_b.end()) {
    ans = min(ans, *it - sum_a);
  }
  if (it != sum_b.begin()) {
    it--;
    ans = min(ans, sum_a - *it);
  }
  return ans;
}

void Main() {
  cin >> n >> m >> q;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  b.resize(m);
  for (auto &el : b) {
    cin >> el;
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      sum_a += a[i];
    } else {
      sum_a -= a[i];
    }
  }
  calc_sum_b();
  // cout << "sum_b = ";
  // for (auto el : sum_b) {
  //   cout << el << ' ';
  // }
  // cout << endl;
  // cout << "sum_a = " << sum_a << endl;
  cout << get() << '\n';
  while (q--) {
    int L, R;
    ll x;
    cin >> L >> R >> x;
    L--;
    update(L, R, x);
    // cout << "sum_a = " << sum_a << endl;
    cout << get() << '\n';
  }
}