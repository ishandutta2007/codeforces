#include <stdio.h>
#define MAXLEN 105
int n,m,g[MAXLEN][MAXLEN],ans;
int main()
{
	int i,j,k,t1,t2,t3;
	scanf("%d%d",&n,&m);
	for(i = 1;i <= m;i ++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		g[t1][t2]=t3;
	}
	for(i = 1;i <= n;i ++)
		for(j = 1;j <= n;j ++)
			if(g[i][j])
				for(k = 1;k <= n;k ++)
					if(g[k][i])
						if(g[i][j] >= g[k][i])
						{
							g[i][j] -= g[k][i];
							g[k][j] += g[k][i];
							g[k][i] = 0;
						}
						else
						{
							g[k][i] -= g[i][j];
							g[k][j] += g[i][j];
							g[i][j] = 0;
						}
	for(i = 1;i <= n;i ++)
		for(j = 1;j <= n;j ++)
			ans += g[i][j];
	printf("%d",ans);
	return 0;
}