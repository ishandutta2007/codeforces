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

int n, m, half;
vector<ll> s;
vector<int> a;
map<vector<int>, int> cnt;
ll ans = 0;

void Main() {
  cin >> n >> m;
  half = (n + 1) / 2;
  s.resize(m);
  a.resize(m);
  for (int i = 0; i < m; i++) {
    string cur;
    cin >> cur >> a[i];
    s[i] = 0;
    for (int j = 0; j < n; j++) {
      s[i] *= 2;
      s[i] += cur[j] - '0';
    }
  }
  for (ll mask = 0; mask < (1 << half); mask++) {
    vector<int> cur;
    bool ok = true;
    for (int i = 0; i < m; i++) {
      ll cur_mask = (s[i] >> (n - half));
      cur.push_back(half - __builtin_popcount(cur_mask ^ mask));
      if (cur.back() > a[i]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cnt[cur]++;
    }
  }
  for (ll mask = 0; mask < (1 << (n - half)); mask++) {
    vector<int> cur;
    bool ok = true;
    for (int i = 0; i < m; i++) {
      ll cur_mask = s[i] % (1ll << (n - half));
      cur.push_back(n - half - __builtin_popcount(cur_mask ^ mask));
      if (cur.back() > a[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    vector<int> need;
    for (int i = 0; i < m; i++) {
      need.push_back(a[i] - cur[i]);
    }
    ans += cnt[need];
  }
  cout << ans << '\n';
}