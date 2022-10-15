#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define int unsigned long long
#define ff first
#define ss second
int aaa(int a, int b) {
  return (a > b ? a - b : b - a);
}
void solve() {
  std::pair<int, int> aa, bb, cc, dd;
  int z, ans = 0;
  std::cin >> aa.ff >> aa.ss >> bb.ff >> bb.ss >> cc.ff >> cc.ss >> dd.ff >> dd.ss >> z;
  std::vector<std::pair<int,int> > v;
  v.push_back(aa);
  while (aa.ff * bb.ff + cc.ff <= 2e16 && aa.ss * bb.ss + cc.ss <= 2e16) {
    (aa.ff *= bb.ff) += cc.ff;
    (aa.ss *= bb.ss) += cc.ss;
    v.push_back(aa);
  }
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v.size(); j++) {
      int cur = aaa(dd.ff, v[i].ff) + aaa(dd.ss, v[i].ss) + aaa(v[i].ff, v[j].ff) + aaa(v[i].ss, v[j].ss);
      if (cur <= z) ans = std::max(ans, abs(i - j) + 1ull);
    }
  }
  std::cout << ans << "\n";
}
int32_t main(){
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
}