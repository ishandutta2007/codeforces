/**
 *    author:  tourist
 *    created: 30.05.2021 17:49:57       
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    string foo;
    cin >> foo;
    for (int j = 0; j < m; j++) {
      if (foo[j] == '1') {
        a[i] |= (1LL << j);
      }
    }
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  shuffle(order.begin(), order.end(), rng);
  int best = 0;
  string ans(m, '0');
  for (int it = 0; it < min(n, 200); it++) {
    int me = order[it];
    vector<int> bits;
    for (int j = 0; j < m; j++) {
      if ((a[me] >> j) & 1) {
        bits.push_back(j);
      }
    }
    int sz = (int) bits.size();
    vector<int> cnt(1 << sz);
    for (int i = 0; i < n; i++) {
      int u = 0;
      for (int j = 0; j < sz; j++) {
        if ((a[i] >> bits[j]) & 1) {
          u |= (1 << j);
        }
      }
      cnt[u] += 1;
    }
    for (int bit = 0; bit < sz; bit++) {
      for (int t = 0; t < (1 << sz); t++) {
        if (t & (1 << bit)) {
          cnt[t ^ (1 << bit)] += cnt[t];
        }
      }
    }
    for (int t = 0; t < (1 << sz); t++) {
      if (2 * cnt[t] >= n && __builtin_popcount(t) > best) {
        best = __builtin_popcount(t);
        ans = string(m, '0');
        for (int j = 0; j < sz; j++) {
          if (t & (1 << j)) {
            ans[bits[j]] = '1';
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}