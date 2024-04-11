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

lli pow(lli b, lli p, lli lim) {
  if (p == 0)
    return 1;
  if (p%2 == 1)
    return min(lim, pow(b, p-1, lim)*b);
  lli aux = pow(b, p/2, lim);
  return min(lim, aux*aux);
}

int main() {
  lli n, l, r;
  cin >> n >> l >> r;
  r++;
  if (n == 1) {
    cout << r-l << endl;
    return 0;
  }
  if (n == 2) {
    lli d = r-l;
    cout << d*(d-1) << endl;
    return 0;
  }
  vector<lli> basePows;
  for (lli i=1; pow(i, n-1, r) < r; ++i)
    basePows.push_back(pow(i, n-1, r));
  vector<lli> fl(basePows.size()), fr(basePows.size());
  for (int i=0; i<basePows.size(); ++i) {
    fl[i] = (l+basePows[i]-1)/basePows[i];
    fr[i] = (r+basePows[i]-1)/basePows[i];
  }
  LOG(basePows);
  LOG(fl);
  LOG(fr);
  lli ans=0;
  for (int i=0; i<basePows.size(); ++i)
    for (int j=0; j<basePows.size(); ++j)
      if (__gcd(basePows[i], basePows[j]) == 1 && i!=j) {
        int tl = max(fl[i], fl[j]);
        int tr = min(fr[i], fr[j]);
        if (tr > tl)
          ans += tr-tl;
        LOG(make_tuple(i, j, tl, tr));
      }
  cout << ans << endl;
}