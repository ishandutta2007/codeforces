#include<cstdio>
const int N=105;
int T,n,m;
char s[N];
signed main()
{
	int x;
	register int i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);x=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(j=1;j<=m;j++)
			{
				if(i==n&&s[j]=='D')
					x++;
				if(j==m&&s[j]=='R')
					x++;
			}
		}
		printf("%d\n",x);
	}
}