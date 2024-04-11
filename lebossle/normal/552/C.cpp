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

bool poss(lli w, lli m) {
  if (w == 0)
    return true;
  if (w%m == 0 && poss(w/m, m))
    return true;
  if (w%m == 1 && poss((w-1)/m, m))
    return true;
  if (w%m == m-1 && poss((w+1)/m, m))
    return true;
  return false;
}

int main() {
  lli w, m;
  cin >> w >> m;
  cout << (poss(m, w) ? "YES" : "NO") << endl;
}