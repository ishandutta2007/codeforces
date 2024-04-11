#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    array<int, 3> cnt = {0, 0, 0};
    for (auto &el : s) {
      int cur_num = (el == 'R' ? 0 : (el == 'S' ? 1 : 2));
      cnt[cur_num]++;
    }
    int max_num = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    cout << string(s.size(), (max_num == 0 ? 'P' : (max_num == 1 ? 'R' : 'S'))) << '\n';
  }
}