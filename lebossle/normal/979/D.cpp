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

int solve(const set<int>& cands, int lim, int x) {
  LOG(cands);
  LOG(lim);
  LOG(x);
  if (cands.empty() || *cands.begin() > lim)
    return -1;
  int ans=0;
  for (int bit = 1<<20; bit>0; bit>>=1) {
    int cand = ans|bit;
    auto it = cands.lower_bound(cand);
    if (it == cands.end() || (cand/bit) != (*it/bit) || *it > lim)
      continue;
    auto old = cands.lower_bound(ans);
    if ((*old^x)/bit > (cand^x)/bit)
      continue;
    ans = cand;
  }
  return ans;
}

int main() {
  int q;
  cin >> q;
  vector<vector<int>> divs(1e5+1);
  for (int i=1; i<divs.size(); ++i)
    for (int j=i; j<divs.size(); j+=i)
      divs[j].push_back(i);
  vector<set<int>> multsInA(1e5+1);
  for (int qa=0; qa<q; ++qa) {
    int t;
    cin >> t;
    if (t==1) {
      int u;
      cin >> u;
      LOG(t);
      LOG(u);
      for (int i : divs[u])
        multsInA[i].insert(u);
    } else {
      int x, k, s;
      cin >> x >> k >> s;
      LOG(make_tuple(t, x, k, s));
      if (x%k != 0) {
        cout << -1 << '\n';
        continue;
      }
      cout << solve(multsInA[k], s-x, x) << '\n';
    }
  }
}