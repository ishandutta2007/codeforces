#include <bits/stdc++.h>
using namespace std;

// This code uses the bossle/cp library
// Available at https://github.com/bossle/cp

// #pragma STDC FENV_ACCESS OFF
// #pragma STDC FP_CONTRACT ON
// #pragma STDC CX_LIMITED_RANGE ON
// #pragma GCC optimize "O3"

namespace cp_base {

auto init = (
  ios::sync_with_stdio(false),
  cin.tie(nullptr)
);

}  // namespace cp_base

       

#define LOG(x) 

typedef long long int lli;

lli INF = 3e18;

lli value(lli x, lli y, lli z) {
  return (x-y)*(x-y) + (x-z)*(x-z) + (y-z)*(y-z);
}

lli calculate(vector<lli> l, vector<lli> r, vector<lli> m) {
  lli ans = INF;
  int ri=0;
  for (int li=0; li<l.size(); ++li) {
    while (ri < r.size() && r[ri] < l[li])
      ri++;
    if (ri == r.size())
      return ans;
    auto it = lower_bound(m.begin(), m.end(), (l[li]+r[ri])/2);
    if (it != m.end())
      ans = min(ans, value(l[li], *it, r[ri]));
    if (it != m.begin()) {
      it--;
      ans = min(ans, value(l[li], *it, r[ri]));
    }
  }
  return ans;
}

void solve() {
  int nr, ng, nb;
  cin >> nr >> ng >> nb;
  vector<lli> r(nr), g(ng), b(nb);
  for (lli& ri : r)
    cin >> ri;
  for (lli& gi : g)
    cin >> gi;
  for (lli& bi : b)
    cin >> bi;
  sort(r.begin(), r.end());
  sort(g.begin(), g.end());
  sort(b.begin(), b.end());
  lli ans = INF;
  ans = min(ans, calculate(r, g, b));
  ans = min(ans, calculate(r, b, g));
  ans = min(ans, calculate(g, r, b));
  ans = min(ans, calculate(g, b, r));
  ans = min(ans, calculate(b, r, g));
  ans = min(ans, calculate(b, g, r));
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int ta=0; ta < t; ++ta) {
    solve();
  }
}