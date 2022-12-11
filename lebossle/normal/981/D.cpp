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

typedef long long int lli;

vector<lli> a;

map<tuple<lli, int, int>, bool> memo;
bool dp(int i, int k, lli goal) {
  if (i == a.size())
    return k == 0;
  if (k == 0)
    return false;
  tuple<lli, int, int> key(goal, i, k);
  if (memo.count(key))
    return memo[key];
  lli acum=0;
  for (int j=i; j<a.size(); ++j) {
    acum += a[j];
    if ((goal & ~acum)==0 && dp(j+1, k-1, goal)) {
      memo[key] = true;
      return true;
    }
  }
  memo[key] = false;
  return false;
}

int main() {
  int n, k;
  cin >> n >> k;
  a.resize(n);
  for (lli& i : a)
    cin >> i;
  lli ans=0;
  for (lli bit = 1LL<<62; bit>0; bit>>=1)
    if (dp(0, k, ans|bit))
      ans |= bit;
  cout << ans << endl;
  LOG(memo);
}