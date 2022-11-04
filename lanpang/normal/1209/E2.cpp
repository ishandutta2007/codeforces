#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int T , n , m , f[20][2010] , dp[20][4200] , s[20][4200] , nm , ff[20][20];

struct mmp{
	int x , k;
	bool operator < (const mmp &op) const{
		return x > op.x;
	}
}h[2010];

void check(int x , int y)
{
	int i , j , ss;
	s[x][y] = 0;
	for (i = 0 ; i < n ; i++)
	{
		ss = 0;
		for (j = 1 ; j <= n ; j++)
			ss += f[(i+j > n ? i+j-n : i+j)][x]*((y>>(j-1))&1);
		s[x][y] = max(s[x][y],ss);
	}
}

int main()
{
	int i , j , k;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (i = 1 ; i <= n ; i++)
			for (j = 1 ; j <= m ; j++)
				scanf("%d",&f[i][j]);
		for (k = 1 ; k <= m ; k++)
		{
			j = 0;
			for (i = 1 ; i <= n ; i++)
				j = max(j,f[i][k]);
			h[k].k = k;
			h[k].x = j;
		}
		sort(h+1,h+m+1);
		nm = min(n,m);
		for (k = 1 ; k <= nm ; k++)
		{
			for (i = 1 ; i <= n ; i++)
				ff[i][k] = f[i][h[k].k];
		}
		m = nm;
		for (k = 1 ; k <= m ; k++)
			for (i = 1 ; i <= n ; i++)
				f[i][k] = ff[i][k];
		for (i = 0 ; i < (1<<n) ; i++)
			dp[0][i] = 0;
		for (k = 1 ; k <= m ; k++)
		{
			for (i = 0 ; i < (1<<n) ; i++)
				check(k,i);
			dp[k][0] = 0;
			for (i = 1 ; i < (1<<n) ; i++)
			{
				dp[k][i] = max(s[k][i],dp[k-1][i]);
				for (j = (i&(i-1)) ; j ; j = (i&(j-1)))
					dp[k][i] = max(dp[k][i],dp[k-1][j]+s[k][i-j]);
			}
		}
		cout << dp[m][(1<<n)-1] << "\n";
	}
	return 0;
}