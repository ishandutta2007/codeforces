#include <bits/stdc++.h>
using namespace std;

// This code uses the bossle/cp library
// Available at https://github.com/bossle/cp

typedef long long int lli;

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

lli lcm(lli a, lli b) {
  return a*b/__gcd(a, b);
}

int main() {
  lli a, b;
  cin >> a >> b;
  if (a<b)
    swap(a, b);
  lli g = a-b;
  lli best = lcm(a, b), argBest=0;
  for (lli d0 = 1; d0*d0 <= g; ++d0)
    if (g%d0 == 0)
      for (lli d : vector<lli>{d0, g/d0}) {
        lli k = d - b%d;
        lli cand = lcm(a+k, b+k);
        if (cand < best) {
          best = cand;
          argBest = k;
        }
      }
  cout << argBest << endl;
}