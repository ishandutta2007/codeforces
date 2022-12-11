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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a)
    cin >> i;
  for (int i=0; i<n; i+=2)
    a[i] = abs(a[i]);
  for (int i=1; i<n; i+=2)
    a[i] = -abs(a[i]);
  for (int i=0; i<n; ++i)
    cout << a[i] << (i==n-1?'\n':' ');
}

int main() {
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta) {
    solve();
  }
}