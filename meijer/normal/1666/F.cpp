#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MX = 5005;
const ll MOD = 998244353;

int t;
int n;
int a[MX];
int f[MX];
int g[MX];
ll dp[MX][MX];
ll fact[MX];

ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}

int main() {
  fact[0] = 1;
  for (int i=1; i<MX; i++) fact[i] = fact[i-1]*ll(i)%MOD;

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0; i<n; i++)
      cin >> a[i];

    if (n == 2) {
      cout << (a[0] == a[1] ? 0 : 1) << endl;
      continue;
    }
    
    f[n-1] = n;
    for (int i=n-2; i>=0; i--) {
      if (a[i+1] != a[i]) f[i] = i+1;
      else f[i] = f[i+1];
    }
    g[0] = 0;
    for (int i=1; i<n; i++) {
      if (a[i-1] != a[i]) g[i] = i;
      else g[i] = g[i-1];
    }
    
    for (int i=0; i<=n; i++)
      dp[i][n] = 0;
    dp[n][n] = 1;
    for (int j=n-2; j>=0; j-=2) {
      for (int i=0; i<=n; i++)
        dp[i][j] = 0;
      ll sm = 0;
      for (int i=n-1; i>=j; i--) {
        if (j == n-2)
          sm += dp[f[i]][j+2];
        else if (j == 0 && g[i] - j - 1 >= 0)
          sm += dp[f[i]][j+2] * ll (g[i] - j) % MOD * ll(g[i] - j - 1) % MOD;
        else if (g[i] - j - 1 >= 0)
          sm += dp[f[i]][j+2] * ll (g[i] - j - 1) % MOD;
        sm %= MOD;
        dp[i][j] = sm;
      }
    }

    for (int i=0; i<n; i++) if(i == 0 || a[i-1] != a[i]) {
      dp[0][0] = dp[0][0] * inv(fact[f[i]-i]) % MOD;
    }

    cout << dp[0][0] << endl;
  }
}