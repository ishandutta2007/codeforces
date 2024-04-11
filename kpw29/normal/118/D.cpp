#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int mod = 1e8;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, a, b, c;
int t[4];
int dp[110][110][2];

int main()
{
    cin >> n >> m >> t[0] >> t[1];
    dp[0][0][0] = dp[0][0][1] = 1;
    for (int i=0; i<=n; ++i)
      for (int j=0; j<=m; ++j)
      {
          if (!(i || j)) continue;
          for (int k=0; k<2; ++k)
          {
              for (int ile = 1; ile <= t[k]; ++ile)
              if (!k) {
                  if (i - ile >= 0) dp[i][j][k] += dp[i-ile][j][k^1];
              }
              else if (j - ile >= 0) dp[i][j][k] += dp[i][j-ile][k^1];
              dp[i][j][k] %= mod;
          }
      }
      
    cout << (dp[n][m][0] + dp[n][m][1])%mod;
}