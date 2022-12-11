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
  vector<int> v(n);
  for (int& i : v)
    cin >> i;
  set<int> unset, missing;
  for (int i=0; i<n; ++i) {
    unset.insert(i);
    missing.insert(i);
  }
  missing.insert(n);
  vector<int> cnt(n+1, 0);
  for (int i : v) {
    missing.erase(i);
    cnt[i]++;
  }
  vector<int> ans;
  while (!unset.empty()) {
    int mex = *missing.begin();
    int tgt;
    if (mex == n) {
      tgt = *unset.begin();
    } else {
      tgt = mex;
      unset.erase(mex);
    }
    ans.push_back(tgt);
    cnt[v[tgt]]--;
    if (cnt[v[tgt]] == 0)
      missing.insert(v[tgt]);
    v[tgt] = mex;
    cnt[mex]++;
    missing.erase(mex);
  }
  cout << ans.size() << '\n';
  for (int i=0; i<ans.size(); ++i)
    cout << ans[i]+1 << (i==ans.size()-1?"":" ");
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  for (int ta=0; ta<t; ++ta) {
    solve();
  }
}