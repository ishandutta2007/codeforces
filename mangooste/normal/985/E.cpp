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

struct Fenwik {
  int n;
  vector<int> bit;

  void unite(int n_) {
    n = n_;
    bit.resize(n + 1);
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

  void increase(int pos, int delta) {
    for (pos++; pos <= n; pos += pos & -pos) {
      bit[pos] += delta;
    }
  }
};

int n, k, d;
vector<int> a, dp;
Fenwik bit;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> k >> d;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  sort(a.begin(), a.end());
  dp.assign(n + 1, 0);
  bit.unite(n + 1);
  bit.increase(0, 1);
  for (int i = 0; i < n; i++) {
    int L = lower_bound(a.begin(), a.end(), a[i] - d) - a.begin();
    int R = i - k + 1;
    if (L <= R && bit.get(L, R + 1) > 0) {
      dp[i + 1] = 1;
    }
    bit.increase(i + 1, dp[i + 1]);
  }
  cout << (dp.back() ? "YES\n" : "NO\n");
}