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

void solve() {
  lli d, m;
  cin >> d >> m;
  lli ans=0, cur=1, i;
  for (i=2; i<=d; i*=2) {
    ans = (ans + cur*i/2)%m;
    cur = (ans+1)%m;
    LOG(ans);
    LOG(cur);
    LOG(i);
  }
  ans = (ans + cur*(d+1-i/2))%m;
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta)
    solve();
}