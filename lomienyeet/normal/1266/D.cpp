#include <iostream>
#include <vector>
#define int long long
// wtf i have three consecutive tasks die to this
void solve() {
  int n, m;
  std::cin >> n >> m;
  int aaa[n + 1] = {};
  while (m--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    aaa[a] += c;
    aaa[b] -= c;
  }
  std::vector<int> aa, bb, cc;
  for (int i = 1; i <= n; i++) {
    (aaa[i] > 0 ? aa : (aaa[i] < 0 ? bb : cc)).push_back(i);
  }
  std::vector<std::pair<std::pair<int,int>,int> > ans;
  for (int i = 0, j = 0; i < aa.size(); i++) {
    while (j < bb.size() && aaa[aa[i]] >= -aaa[bb[j]]) {
      aaa[aa[i]] += aaa[bb[j]];
      ans.push_back({{aa[i], bb[j]}, -aaa[bb[j]]});
      j++;
    }
    if (j < bb.size() && aaa[aa[i]] != 0) {
      ans.push_back({{aa[i], bb[j]}, aaa[aa[i]]});
      aaa[bb[j]] += aaa[aa[i]];
      aaa[aa[i]] = 0;
    }
  }
  std::cout << ans.size() << "\n";
  for (auto i : ans) std::cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
}
int32_t main() {
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
}