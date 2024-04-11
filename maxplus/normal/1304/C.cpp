#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < n; ++i) {
      int t, l, h;
      cin >> t >> l >> h;
      v.emplace_back(t, std::make_pair(l, h));
    }
    sort(v.begin(), v.end());
    int t = 0, l = m, h = m, f = 1;
    for (int i = 0; i < n; ++i) {
      int nt = v[i].first, nl = l - (nt - t), nh = h + (nt - t);
      t = nt;
      l = max(nl, v[i].second.first);
      h = min(nh, v[i].second.second);
      if (l > h) {
        f = 0;
      }
    }
    if (f) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}