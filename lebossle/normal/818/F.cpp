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

int main() {
  int q;
  cin >> q;
  for (int qa=0; qa<q; ++qa) {
    lli n;
    cin >> n;
    lli l=1, r=n+1;
    while (r-l > 1) {
      lli m = (l+r)/2;
      lli bridges = n-m;
      lli maxNonBridge = m*(m-1)/2;
      if (maxNonBridge < bridges)
        l = m;
      else
        r = m;
    }
    lli best = (n-l) + l*(l-1)/2;
    best = max(best, 2*(n-r));
    cout << best << '\n';
  }
}