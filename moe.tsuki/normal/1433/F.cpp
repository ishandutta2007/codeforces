#include<bits/stdc++.h>
using namespace std;
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define int long long
const int maxn = 78, oo = 123456789345678ll;
int a[maxn][maxn];
int dp[maxn + maxn][maxn][maxn];
int mx[maxn][maxn], ans[maxn][maxn];
//vector<int> v[maxn];
//map<int, vector<int> > app;
main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m, k; cin >> n >> m >> k;
  F1 (i, n) F1 (j, m) cin >> a[i][j];
  F1 (i, n)
  {
    F (p, maxn)
      F (j, k) dp[i][p][j] = -oo;
    dp[i][0][0] = 0;
    F1 (j, m)
    {
      F (p, maxn)
        F (q, k)
          dp[i + n][p][q] = dp[i][p][q];
      F (p, maxn - 1)
        F (q, k)
          dp[i + n][p + 1][(q + a[i][j]) % k]
            = max(dp[i + n][p + 1][(q + a[i][j]) % k]
            , dp[i][p][q] + a[i][j]);
      F (p, maxn)
        F (q, k)
          dp[i][p][q] = dp[i + n][p][q];
    }
    F (j, k)
      mx[i][j] = -oo;
    F (j, k) F (p, m / 2 + 1) mx[i][j] = max(mx[i][j], dp[i][p][j]);
    /*F (p, m / 2 + 1)
    {
      cout << "Take " << p << ":\n"; 
      F (j, k) cout << dp[i][p][j] << ' ';
      cout << '\n';
    }
    F (j, k) cout << mx[i][j] << ' ';
    cout << '\n';*/
  }
  F (i, n + 1)
    F (j, k) ans[i][j] = -oo;
  ans[0][0] = 0;
  F1 (i, n)
  {
    F (j, k)
      F (p, k)
        ans[i][j] = max(ans[i][j], ans[i - 1][(j - p + k) % k] + mx[i][p]);
  }
  cout << ans[n][0] << '\n';
}