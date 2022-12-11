#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
const lli MOD = 1e9+7;

lli invMod(lli a, lli b) {
  if (a<=1)
    return a;
  return (1-invMod(b%a, a)*b)/a;
}

lli C(lli n, lli k) {
  lli ans=1;
  n%=MOD;
  for (lli i=0; i<k; ++i)
    ans = (ans * (((n-i) * invMod(i+1, MOD))%MOD))%MOD;
  return ans;
}

int main() {
  int n;
  lli s;
  cin >> n >> s;
  if (s == 0) {
    cout << 1 << endl;
    return 0;
  }
  vector<lli> f(n);
  for (lli& i : f)
    cin >> i;
  vector<lli> sums(1<<n, 0), coef(1<<n, (n&1?-1:1));
  for (int i=0; i<n; ++i)
    for (int j=0; j<(1<<i); ++j) {
      sums[j+(1<<i)] = sums[j]+f[i]+1;
      coef[j+(1<<i)] = coef[j]*-1;
    }
  cout << endl;
  lli ans=0;
  for (int i=0; i<(1<<n); ++i)
    if (sums[i] > s)
      ans = (ans + coef[i]*C(sums[i]-1-s, n-1))%MOD;
  cout << (ans+MOD)%MOD << endl;
}