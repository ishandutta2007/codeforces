//n*m1~K	1<=n,m<=10001<=k<=10
//:n+m-1Kn,m10123535353
#include <bits/stdc++.h>
using namespace	std;
#define	mp(x,y)	make_pair(x,y)
#define	bit(x,d) ((((x)&(1<<(d)))==0)?0:1)
#define ll long long
using namespace std;
const int N = 10 + 2;
const ll MOD = 1000000000+7;
int	F[N][N],vis[N],a[N][N],n,m,k,x;
ll	ans;
void dfs(int x, int y)
{
	if (x == (n + 1))	
	{
		ans ++;
		if (ans == MOD)	ans = 0;
		return;
	}
	
	F[x][y] = F[x - 1][y] | F[x][y - 1];	//
	int	p = 1, q = k, c = 0;
	for(int	i = 1; i <= k; i ++) 
		if (bit(F[x][y],i - 1))	c ++;
	if (((n - x) + (m - y) + 1) > (k - c))	return;	//
	ll sum = -1,pre;
	if (a[x][y] > 0) p = q = a[x][y];
	for(int	i =	p; i <=	q; i ++)	
		if(!(bit(F[x][y],i-1)))
		{
			if(!vis[i])	
			{
				if(sum >= 0)	//
				{
					ans += sum;
					if (ans > MOD) ans -= MOD;
					continue;
				}
				pre = ans;
			}
			F[x][y] ^= (1 << (i - 1)), vis[i] ++;
			if	(y == m)	dfs(x + 1, 1);	
			else dfs(x, y + 1);
			F[x][y] ^= (1 << (i - 1)) ,vis[i] --;
			if	(!vis[i])
				sum = (ans - pre) % MOD;
		}
		
}

int	main()
{
	scanf("%d%d%d",&n,&m,&k);
	if	((n+m-1)>k)	{printf("%d\n",0); return 0;}
	memset(F,0,sizeof(F));
	memset(vis,0,sizeof(vis));
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
		{
			scanf("%d",&a[i][j]);
			if (a[i][j] > 0) vis[a[i][j]] ++;	//
		}
	ans = 0;
	dfs(1,1);
	printf("%I64d\n",ans);

	return	0;
}