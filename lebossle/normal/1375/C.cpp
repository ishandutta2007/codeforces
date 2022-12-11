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
  /*
  vector<int> mini=a, maxi=a;
  for (int i=1; i<n; ++i)
    mini[i] = min(mini[i], mini[i-1]);
  for (int i=n-2; i>=0; --i)
    maxi[i] = max(maxi[i], maxi[i+1]);
  for (int i=0; i<n-1; ++i)
    if (mini[i] > maxi[i+1]) {
      cout << "NO" << '\n';
      return;
    }
  */
  if (a[0] < a[n-1])
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}

int main() {
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta) {
    solve();
  }
}