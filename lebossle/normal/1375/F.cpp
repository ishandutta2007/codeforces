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

typedef long long int lli;
typedef long double llf;

       

#define LOG(x) 

int main() {
  vector<lli> v(3);
  for (lli& i : v)
    cin >> i;
  cout << "First" << endl;
  lli sum = v[0]+v[1]+v[2];
  lli amt;
  int last;
  amt = sum;
  cout << amt << endl; cin >> last; last--; if(last < 0) return 0; v[last] += amt; sum = v[0]+v[1]+v[2];
  amt = 3*v[last] - sum;
  cout << amt << endl; cin >> last; last--; if(last < 0) return 0; v[last] += amt; sum = v[0]+v[1]+v[2];
  amt = v[last] - sum/3;
  cout << amt << endl; cin >> last; last--;
  assert(last == -1);
}