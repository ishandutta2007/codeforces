#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define int ll

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a) {
      cin >> el;
      el--;
    }
    if (is_sorted(a.begin(), a.end())) {
      cout << "0\n";
      continue;
    }
    set<int> bad;
    for (int i = 0; i < n; i++) {
      if (a[i] != i) {
        bad.insert(i);
      }
    }
    vector<int> inds(bad.begin(), bad.end());
    bool ok = true;
    for (int i = 0; i < inds.size(); i++) {
      ok &= (inds[i] - inds[0] == i);
    }
    cout << (2 - ok) << '\n';
  }
}