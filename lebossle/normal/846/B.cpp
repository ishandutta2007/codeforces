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
  lli n, k, m;
  cin >> n >> k >> m;
  vector<lli> t(k);
  for (lli& i : t)
    cin >> i;
  sort(t.begin(), t.end());
  lli sum=0;
  for (lli i : t)
    sum += i;
  lli best=0;
  for (lli full=0; full<=n; ++full) {
    lli time=sum*full;
    if (time > m)
      break;
    lli cur=full*(k+1);
    for (lli i : t) {
      lli amt = min((m-time)/i, n-full);
      cur += amt;
      time += i*amt;
    }
    best = max(best, cur);
  }
  cout << best << endl;
}