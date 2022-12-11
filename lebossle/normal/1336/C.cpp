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

const lli MOD = 998244353;

string t, s;

lli memoBasic[3001][3001]={};
lli memoSpill[3001][3001]={};
lli& getMemo(int tl, int tr, int si) {
  if (tr == t.size())
    return memoSpill[tl][si];
  else
    return memoBasic[tl][tr];
}

lli dp(int tl, int tr, int si) {
  if (si == s.size()) {
    if (tl == 0 && tr == t.size())
      return 1;
    else
      return 0;
  }
  lli& memo = getMemo(tl, tr, si);
  if (memo != 0)
    return memo-1;
  lli ans=0;
  //stop
  if (tl == 0 && tr == t.size())
    ans++;
  //add to front
  if (tl > 0 && t[tl-1] == s[si])
    ans = (ans + dp(tl-1, tr, si+1))%MOD;
  if (tl == t.size())
    ans = (ans + dp(tl, tr, si+1))%MOD;
  //add to back
  if (tr < t.size() && t[tr] == s[si])
    ans = (ans + dp(tl, tr+1, si+1))%MOD;
  if (tr == t.size())
    ans = (ans + dp(tl, tr, si+1))%MOD;
  memo = ans+1;
  return ans;
}

int main() {
  cin >> s >> t;
  lli ans=0;
  for (int i=0; i<=t.size(); ++i) {
    ans = (ans + dp(i, i, 0))%MOD;
  }
  cout << ans << endl;
}