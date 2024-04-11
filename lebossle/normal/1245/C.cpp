#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}

typedef long long int lli;

const lli MOD = 1e9+7;

void solve() {
  string s;
  cin >> s;
  lli ans=1;
  lli u=0, n=0;
  for (char c : s) {
    lli old = ans;
    if (c == 'w' || c == 'm') {
      cout << 0 << endl;
      return;
    } else if (c == 'u') {
      ans = (ans+u)%MOD;
      u = old;
      n = 0;
    } else if (c == 'n') {
      ans = (ans+n)%MOD;
      u = 0;
      n = old;
    } else {
      u = 0;
      n = 0;
    }
  }
  cout << ans << endl;
}