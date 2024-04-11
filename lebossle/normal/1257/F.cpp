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

int popcount(int x) {
  int ans=0;
  while (x) {
    ans++;
    x&=x-1;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a)
    cin >> i;
  map<vector<int>, int> lower;
  for (int l=0; l<(1<<15); ++l) {
    vector<int> ans(n);
    for (int i=0; i<n; ++i)
      ans[i] = popcount((a[i]&((1<<15)-1))^l);
    for (int i=n-1; i>=0; --i)
      ans[i] -= ans[0];
    lower[ans] = l;
  }
  for (int u=0; u<(1<<15); ++u) {
    vector<int> goal(n);
    for (int i=0; i<n; ++i)
      goal[i] = popcount((a[i]>>15)^u);
    for (int i=n-1; i>=0; --i)
      goal[i] = goal[0]-goal[i];
    if (lower.count(goal)) {
      cout << ((u<<15)|lower[goal]) << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}