#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 998244353;

LL n , k , l , dp[2010][2010] , ans , jc[2010];

LL qp(LL x , LL y)
{
	if (!y) return 1ll;
	LL z = qp(x,y/2);
	if (y%2) return z*z%mod*x%mod;
	else return z*z%mod;
}

int main()
{
	LL i , j;
	cin >> n >> k >> l;
	jc[0] = 1;
	for (i = 1 ; i <= n ; i++)
		jc[i] = jc[i-1]*i%mod;
	dp[0][0] = 1;
	for (i = 0 ; i <= n ; i++)
	{
		for (j = 0 ; j <= i ; j++)
		{
			if (!dp[i][j]) continue;
			if (j < i) dp[i][j+1] = (dp[i][j+1]+dp[i][j]*(i-j)%mod)%mod;
			if (i < n) dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
		}
	}
	for (i = 0 ; i <= n ; i++)
		for (j = 0 ; j <= i ; j++)
			if (i-j >= k) ans = (ans+dp[i][j]*dp[n-j][n-i]%mod*jc[i-j]%mod)%mod;
	ans = ans*qp(dp[n][n],mod-2)%mod*l%mod*qp(n*2+1,mod-2)%mod;
	cout << ans << "\n";
	return 0;
}