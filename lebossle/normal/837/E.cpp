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

set<lli> divs;

lli f(lli a, lli b) {
  LOG(a);
  LOG(b);
  lli g = __gcd(a, b);
  if (g == a)
    return b/g;
  lli next=0;
  for (lli d : divs)
    if (d%g == 0 && d != g)
      next = max(next, b-((b/g)%(d/g))*g);
  return (b-next)/g + f(a, next);
}

int main() {
  lli a, b;
  cin >> a >> b;
  for (lli i=1; i*i<=a; ++i)
    if (a%i == 0) {
      divs.insert(i);
      divs.insert(a/i);
    }
  cout << f(a, b) << endl;
}