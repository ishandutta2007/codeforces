#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Fenwik {
  int n;
  vector<int> bit;
  int max_value;

  void unite(int n_, int max_value_) {
    n = n_;
    max_value = max_value_;
    bit.assign(n + 1, 0);
  }

  int get(int L, int R) {
    return get(R) - get(L);
  }

  int get(int pos) {
    int ans = 0;
    for (; pos > 0; pos -= pos & -pos) {
      ans += bit[pos];
    }
    return ans;
  }

  void add(int pos, int delta) {
    int val = get(pos, pos + 1);
    delta = min(delta, max_value - val);
    for (pos++; pos <= n; pos += pos & -pos) {
      bit[pos] += delta;
    }
  }
};

int n, k, a, b, q;
Fenwik bit_a, bit_b;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> k >> a >> b >> q;
  bit_a.unite(n, a);
  bit_b.unite(n, b);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos, delta;
      cin >> pos >> delta;
      pos--;
      bit_a.add(pos, delta);
      bit_b.add(pos, delta);
    } else {
      int pos;
      cin >> pos;
      pos--;
      int ans = 0;
      ans += bit_b.get(0, pos);
      ans += bit_a.get(pos + k, n);
      cout << ans << '\n';
    }
  }
}