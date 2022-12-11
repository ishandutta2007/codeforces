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
  lli n, m;
  cin >> n >> m;
  vector<lli> l(m);
  for (lli& i : l)
    cin >> i;
  vector<lli> acum(m+1, 0);
  for (lli i=0; i<m; ++i)
    acum[i+1] = acum[i] + l[i];
  if (acum[m] < n) {
    cout << -1 << endl;
    return 0;
  }
  vector<lli> ans(m);
  for (lli i=0; i<m; ++i) {
    if (l[i]+i > n) {
      cout << -1 << endl;
      return 0;
    }
    ans[i] = max(i, n - (acum[m]-acum[i]))+1;
  }
  for (lli i : ans)
    cout << i << ' ';
  cout << endl;
}