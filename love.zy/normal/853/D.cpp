#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 300005;
int n;
ll a[MAXN], dp[MAXN][35];
inline void chkmin(ll & x, ll y) {
  if(y < x) x = y;
}
int main() {
  scanf("%d", &n);
  for(ll i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  memset(dp, 127 / 2, sizeof(dp));
  dp[0][0] = 0;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j <= 30; j++) {
      chkmin(dp[i + 1][j + a[i] / 1000], dp[i][j] + a[i]);
      chkmin(dp[i + 1][j - min(j, a[i] / 100)], dp[i][j] + a[i] - 100 * min(j, a[i] / 100));
    }
  }
  ll ans = LLONG_MAX;
  for(ll j = 0; j <= 30; j++) {
    ans = min(ans, dp[n][j]);
  }
  printf("%lld\n", ans);
  return 0;
}