#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
string s;
vector<int> pref;
vector<ll> pref_sum, suf_sum;
double ans = 0.0;

bool vowel(char ch) {
  if (ch == 'I' || ch == 'E' || ch == 'A' || ch == 'O' || ch == 'U' || ch == 'Y') {
    return true;
  } else {
    return false;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> s;
  n = s.size();
  pref.assign(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + (vowel(s[i]) ? 1 : 0);
  }
  pref_sum.assign(n + 1, 0);
  for (int i = 0; i <= n; i++) {
    pref_sum[i] = (i == 0 ? 0ll : pref_sum[i - 1]) + pref[i];
  }
  suf_sum.assign(n + 1, 0);
  for (int i = n; i >= 0; i--) {
    suf_sum[i] = (i == n ? 0ll : suf_sum[i + 1]) + pref[i];
  }
  for (int len = 1; len <= n; len++) {
    ll cur = 0;
    cur -= pref_sum[min(len - 1, n - len)];
    cur += suf_sum[max(len, n - len + 1)];
    assert(cur >= 0);
    ans += (double)cur / len;
  }
  cout << fixed << setprecision(10) << ans << '\n';
}