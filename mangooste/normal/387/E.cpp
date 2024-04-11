#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Fenwik {
  int n;
  vector<int> bit;

  void assign(int n_) {
    n = n_;
    bit.assign(n + 1, 0);
  }

  void update(int pos, int delta) {
    for (pos++; pos <= n; pos += pos & -pos) {
      bit[pos] += delta;
    }
  }

  int get(int L, int R) {
    return get(R) - get(L);
  }

  int get(int pos) {
    int res = 0;
    for (; pos > 0; pos -= pos & -pos) {
      res += bit[pos];
    }
    return res;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  Fenwik bit;
  bit.assign(n);
  vector<int> where;
  where.assign(n, -1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    where[x - 1] = i;
    bit.update(i, 1);
  }
  set<int> vals;
  for (int i = 0; i < n; i++) {
    vals.insert(i);
  }
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    vals.erase(x - 1);
  }
  set<int> less;
  less.insert(-1);
  less.insert(n);
  ll ans = 0;
  int pos = 0;
  for (auto &el : vals) {
    for (; pos < el; pos++) {
      if (vals.find(pos) == vals.end()) {
        less.insert(where[pos]);
      }
    }
    int R = *less.upper_bound(where[el]);
    int L = *(--less.upper_bound(where[el])) + 1;
    ans += bit.get(L, R);
    bit.update(where[el], -1);
  }
  cout << ans << '\n';
}