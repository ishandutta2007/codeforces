#include<cstdio>
#define min(a,b) (a<b?a:b)
const int N(2005),inf(1e8);
int n,step(inf),cnt;
int a[N];
int g[N][N];
inline int gcd(int x,int y)
{
	return x?gcd(y%x,x):y;
}
signed main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		g[i][i]=a[i];
		if(a[i]==1)
			cnt++;
	}
	if(cnt)
	{
		printf("%d\n",n-cnt);
		return 0;
	}
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			g[i][j]=gcd(g[i][j-1],a[j]);
			if(g[i][j]==1)
				step=min(step,j-i);
		}
	if(step==inf)
		puts("-1");
	else
		printf("%d\n",step+n-1);
	return 0;
}