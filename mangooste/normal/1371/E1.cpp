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

int n, p;
vector<int> a, fact, rfact;

int mult(int a, int b) {
  return 1ll * a * b % p;
}

int bin_pow(int a, int b) {
  if (b == 0) {
    return 1;
  } else if (b % 2 == 1) {
    return mult(bin_pow(a, b - 1), a);
  } else {
    return bin_pow(mult(a, a), b / 2);
  }
}

int C(int n, int k) {
  if (k > n) {
    return 0;
  }
  return mult(fact[n], mult(rfact[k], rfact[n - k]));
}

void Main() {
  cin >> n >> p;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = mult(fact[i - 1], i);
  }
  rfact.resize(n + 1);
  for (int i = n; i >= 0; i--) {
    rfact[i] = bin_pow(fact[i], p - 2);
  }
  vector<int> ans;
  int mx = *max_element(a.begin(), a.end());
  int mn = *min_element(a.begin(), a.end());
  for (int x = max(mn, mx - n + 1); x <= mx; x++) {
    vector<int> when(n);
    for (int i = 0; i < n; i++) {
      if (x >= a[i]) {
        when[i] = 0;
      } else {
        when[i] = a[i] - x;
      }
    }
    vector<int> cnt(n, 0);
    for (auto el : when) {
      cnt[el]++;
    }
    int cur = 1;
    int free = 0;
    for (int i = n - 1; i >= 0 && cur != 0; i--) {
      free++;
      cur = mult(cur, mult(C(free, cnt[i]), fact[cnt[i]]));
      free -= cnt[i];
    }
    if (cur % p != 0) {
      ans.push_back(x);
    }
  }
  cout << ans.size() << '\n';
  for (auto el : ans) {
    cout << el << ' ';
  }
  cout << '\n';
}