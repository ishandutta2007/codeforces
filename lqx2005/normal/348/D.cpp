#include<bits/stdc++.h>
#define broken cerr << __LINE__ <<" "<< __FUNCTION__ << endl
#define debug(x) cerr << #x <<" = " << x << endl
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int, int> pii;
const int N = 3000 + 10;
const int mod = 1e9 + 7;
int dp[N][N], mp[N][N];
int n, m;
int sub(int x){return x < 0 ? x + mod : x;}
int ok(char w){return w == '.' || w == '#';}
int qpow(int a, int b)
{
  int res = 1;
  for(; b; b >>= 1, a = 1ll * a * a % mod) if(b & 1) res = 1ll * res * a % mod;
  return res;
}

int DP(int u, int l, int d, int r)
{
  for(int i = u - 1; i <= d + 1; i++) for(int j = l - 1; j <= r + 1; j++) dp[i][j] = 0;
  dp[u][l - 1] = 1;
  for(int i = u; i <= d; i++)
  {
    for(int j = l; j <= r; j++)
    {
      if(mp[i][j]) continue;
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
    }
  }
  return dp[d][r];
}



int main()
{
  // freopen("1.txt", "r", stdin);
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++)
  {
    char w;
    for(int j = 1; j <= m; j++)
    {
      while(!ok(w = getchar()));
      mp[i][j] = (w == '#');
    }
  }
  int ans = 1ll * DP(1, 2, n - 1, m) * DP(2, 1, n, m - 1) % mod;  
  ans = sub(ans - 1ll * DP(1, 2, n, m - 1) * DP(2, 1, n - 1, m) % mod);
  printf("%d\n", ans);
  return 0;
}