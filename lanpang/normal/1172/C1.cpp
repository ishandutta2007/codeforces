#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 998244353;

int n , m , a[55] , w[55];
LL ni[3010] , dp[55][55][55] , s[2] , ct , ans[55];

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

void jisuan(int x , LL g)
{
	memset(dp,0,sizeof(dp));
	dp[0][0][0] = 1;
	int i , j , k;
	for (i = 0 ; i < m ; i++)
	{
		for (j = 0 ; j <= i ; j++)
		{
			for (k = 0 ; k <= i-j ; k++)
			{
				if (!dp[i][j][k]) continue;
				LL si = s[0]+s[1]-k+i-j-k+w[x]+g*j;
				add(dp[i+1][j+1][k],dp[i][j][k]*(w[x]+g*j)%mod*ni[si]%mod);
				add(dp[i+1][j][k+1],dp[i][j][k]*(s[0]-k)%mod*ni[si]%mod);
				add(dp[i+1][j][k],dp[i][j][k]*(s[1]+i-j-k)%mod*ni[si]%mod);
			}
		}
	}
	for (i = 0 ; i <= m ; i++)
	{
		ct = 0;
		for (j = 0 ; j <= m ; j++)
		{
			if (!dp[m][i][j]) continue;
			ct += dp[m][i][j];
		}
		add(ans[x],ct*(w[x]+g*i));
	}
}

int main()
{
	int i , j , x , y;
	for (i = 1 ; i <= 3000 ; i++)
		ni[i] = qp(i,mod-2);
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
		cin >> a[i];
	for (i = 1 ; i <= n ; i++)
	{
		cin >> w[i];
		s[a[i]] += w[i];
	}
	for (i = 1 ; i <= n ; i++)
	{
		s[a[i]] -= w[i];
		if (a[i]) jisuan(i,1);
		else jisuan(i,-1);
		s[a[i]] += w[i];
	}
	for (i = 1 ; i <= n ; i++)
		cout << ans[i] << "\n";
	return 0;
}