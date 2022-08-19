/**
 *    author:  tourist
 *    created: 24.04.2022 15:36:58       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template<typename T>
int lis(const vector<T>& a) {
  vector<T> u;
  for (const T& x : a) {
    auto it = upper_bound(u.begin(), u.end(), x);
    if (it == u.end()) {
      u.push_back(x);
    } else {
      *it = x;
    }
  }
  return (int) u.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long v;
  cin >> n >> v;
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  // (t[j] - t[i]) * v >= x[i] - x[j]
  // (t[j] - t[i]) * v >= x[j] - x[i]
  // t[j] * v + x[j] >= t[i] * v + x[i]
  // t[j] * v - x[j] >= t[i] * v - x[i]
  vector<pair<long long, long long>> a;
  for (int i = 0; i < n; i++) {
    if (t[i] * v >= abs(x[i])) {
      a.emplace_back(t[i] * v + x[i], t[i] * v - x[i]);
    }
  }
  sort(a.begin(), a.end());
  vector<long long> b;
  for (int i = 0; i < (int) a.size(); i++) {
    b.push_back(a[i].second);
  }
  cout << lis(b) << '\n';
  return 0;
}