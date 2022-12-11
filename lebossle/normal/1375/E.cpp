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

typedef pair<int, int> ii;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int& i : v)
    cin >> i;
  set<int,  greater<int>> vals(v.begin(), v.end());
  vector<ii> ans;
  vector<int> p = v;
  for (int val : vals)
    for (int i=n-1; i>=0; --i)
      if (v[i] == val)
        for (int j=0; j<i; ++j)
          if (v[j] > val) {
            ans.emplace_back(j, i);
            swap(p[i], p[j]);
          }
  cout << ans.size() << '\n';
  for (int i=0; i<ans.size(); ++i)
    cout << ans[i].first+1 << ' ' << ans[i].second+1 << '\n';
}