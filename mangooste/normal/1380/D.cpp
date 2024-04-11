#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = (ll)1e18;

int n, m, x, k, y;
ll ans = 0;
vector<int> a, b, where, poses;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> x >> k >> y;
  a.assign(n, 0);
  for (auto &el : a) {
    cin >> el;
    el--;
  }
  b.assign(m, 0);
  for (auto &el : b) {
    cin >> el;
    el--;
  }
  where.assign(n, -1);
  for (int i = 0; i < n; i++) {
    where[a[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    poses.push_back(where[b[i]]);
  }
  poses.push_back(n);
  if (!is_sorted(poses.begin(), poses.end())) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < poses.size(); i++) {
    int L = (i ? poses[i - 1] + 1 : 0);
    int R = poses[i];
    if (L >= R) {
      continue;
    }
    ll res = INF;
    int mx = *max_element(a.begin() + L, a.begin() + R);
    bool can = false;
    if (L) {
      can |= (a[L - 1] > mx);
    }
    if (R != n) {
      can |= (a[R] > mx);
    }
    for (int i = R - L - 1 + can; i >= 0; i--) {
      int ost = R - L - i;
      if (ost % k == 0) {
        res = min(res, 1ll * (ost / k) * x + 1ll * i * y);
      }
    }
    ans += res;
    if (res == INF) {
      ans = -1;
      break;
    }
  }
  cout << ans << '\n';
}