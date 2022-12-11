#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
const lli MOD = 1e9+7;

lli powMod(lli b, lli p) {
  if (p == 0)
    return 1;
  if (p == 1)
    return b;
  if (p%2==1)
    return (powMod(b, p-1)*b)%MOD;
  lli ans = powMod(b, p/2);
  return (ans*ans)%MOD;
}

int main() {
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> acum(n+1, 0);
  for (int i=0; i<n; ++i) {
    acum[i+1] = acum[i] + s[i]-'0';
  }
  for (int ta=0; ta<q; ++ta) {
    int l, r;
    cin >> l >> r;
    l--;
    int tot = r-l, ones = acum[r]-acum[l];
    lli ans = powMod(2, tot) - powMod(2, tot-ones);
    cout << (ans + MOD)%MOD << '\n';
  }
}