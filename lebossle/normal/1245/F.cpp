#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    solve();
  }
}

typedef long long int lli;

map<tuple<lli, bool, bool, bool>, lli> memo;
lli f(lli l, lli r, lli p=1<<30, bool gl=false, bool lr=false, bool dif=false) {
  if (p == 0)
    return (dif?2:1);
  auto key = make_tuple(p, gl, lr, dif);
  if (memo.count(key))
    return memo[key];
  bool canGL = ((l&p) == 0);
  bool canLR = ((r&p) > 0);
  lli ans=0;
  // 0 0
  if (gl || canGL)
    ans += f(l, r, p>>1, gl, lr || canLR, dif);
  // 0 1
  if ((gl || canGL) && (lr || canLR))
    ans += f(l, r, p>>1, gl, lr, true);
  // 1 0
  if (dif)
    ans += f(l, r, p>>1, gl || canGL, lr || canLR, true);
  memo[key] = ans;
  return ans;
}

void solve() {
  lli l, r;
  cin >> l >> r;
  memo.clear();
  cout << f(l, r) << '\n';
}