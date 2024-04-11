#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<int> a, b, inds, ans;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  a.resize(n);
  for (auto &el : a) {
    cin >> el;
  }
  b.resize(n);
  for (auto &el : b) {
    cin >> el;
  }
  inds.resize(n);
  iota(inds.begin(), inds.end(), 0);
  sort(inds.begin(), inds.end(), [&](int &i, int &j) {
    return a[i] > a[j];
  });
  ans.push_back(inds[0]);
  for (int i = 1; i < n; i += 2) {
    if (i == n - 1 || (b[inds[i]] >= b[inds[i + 1]])) {
      ans.push_back(inds[i]);
    } else {
      ans.push_back(inds[i + 1]);
    }
  }
  cout << ans.size() << '\n';
  for (auto &el : ans) {
    cout << el + 1 << ' ';
  }
}