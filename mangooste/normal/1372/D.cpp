#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> a;
vector<ll> pref_odd, pref_even;
ll ans = 0;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  pref_odd.assign(n + 1, 0);
  pref_even.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pref_odd[i] = pref_odd[i - 1];
    pref_even[i] = pref_even[i - 1];
    if (i % 2) {
      pref_odd[i] += a[i];
    } else {
      pref_even[i] += a[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    ll cur_ans = 0;
    if (i % 2) {
      cur_ans += pref_odd[i];
      cur_ans += pref_even.back() - pref_even[i];
    } else {
      cur_ans += pref_even[i];
      cur_ans += pref_odd.back() - pref_odd[i];
    }
    ans = max(ans, cur_ans);
  }
  cout << ans << '\n';
}