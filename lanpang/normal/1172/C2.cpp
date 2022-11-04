#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 998244353;

int n , m , a[maxn] , w[maxn];
LL ni[6010] , g[2] , dp[2][maxn] , p[2];

LL qp(LL x , LL y)
{
	if (!y) return 1;
	LL z = qp(x,y/2);
	if (y%2) return x*z%mod*z%mod;
	else return z*z%mod;
}

void add(LL &x , LL y)
{
	x = (x+y)%mod;
}

int main()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&w[i]);
		g[a[i]] = (g[a[i]]+w[i])%mod;
	}
	for (i = 0 ; i <= 6000 ; i++)
		ni[i] = qp(g[0]+g[1]+i-3000,mod-2);
	dp[0][0] = 1;
	for (i = 0 ; i < m ; i++)
	{
		for (j = 0 ; j <= i ; j++)
		{
			if (!dp[i%2][j]) continue;
			add(dp[1-i%2][j+1],dp[i%2][j]*(g[0]-j)%mod*ni[3000-j+i-j]%mod);
			add(dp[1-i%2][j],dp[i%2][j]*(g[1]+i-j)%mod*ni[3000-j+i-j]%mod);
			dp[i%2][j] = 0;
		}
	}
	for (i = 0 ; i <= m ; i++)
	{
		add(p[0],(g[0]-i)%mod*qp(g[0],mod-2)%mod*dp[m%2][i]%mod);
		add(p[1],(g[1]+m-i)%mod*qp(g[1],mod-2)%mod*dp[m%2][i]%mod);
	}
	for (i = 1 ; i <= n ; i++)
		printf("%I64d\n",p[a[i]]*w[i]%mod);
	return 0;
}