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

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a)
    cin >> i;
  vector<int> val(n);
  for (int i=0; i<n; ++i)
    val[i] = a[i] + i;
  sort(val.begin(), val.end());
  vector<int> ans(n);
  for (int i=0; i<n; ++i)
    ans[i] = val[i] - i;
  for (int i=1; i<n; ++i)
    if (ans[i-1] > ans[i]) {
      cout << ":(" << endl;
      return 0;
    }
  for (int i : ans)
    cout << i << ' ';
}