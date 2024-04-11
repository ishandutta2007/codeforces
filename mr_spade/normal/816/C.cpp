#include<cstdio>
#include<cstring>
#define min(a,b) (a<b?a:b)
const int N=105,inf=0x7f7f7f;
int n,m,g[N][N],ans;
int hang[N],lie[N];
signed main()
{
	int i,j;
	int mx,cmx;
	bool bmx;
	scanf("%d%d",&n,&m);
	memset(hang,inf,sizeof hang);
	memset(lie,inf,sizeof lie);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			scanf("%d",&g[i][j]);
			hang[i]=min(hang[i],g[i][j]);
			lie[j]=min(lie[j],g[i][j]);
		}
	if(n<m)
	{
		for(i=1;i<=n;i++)
		{
			if(!hang[i])
				continue;
			/*for(int C=1;C<=hang[i];C++)
				printf("row %d\n",i);*/
			for(j=1;j<=m;j++)
			{
				g[i][j]-=hang[i];
				lie[j]=min(lie[j],g[i][j]);
			}
		}
		for(j=1;j<=m;j++)
		{
			if(!lie[j])
				continue;
			for(i=1;i<=n;i++)
				g[i][j]-=lie[j];
			/*for(int C=1;C<=lie[j];C++)
				printf("col %d\n",j);*/
		}
	}
	else
	{
		for(j=1;j<=m;j++)
		{
			if(!lie[j])
				continue;
			/*for(int C=1;C<=lie[j];C++)
				printf("col %d\n",j);*/
			for(i=1;i<=n;i++)
			{
				g[i][j]-=lie[j];
				hang[i]=min(hang[i],g[i][j]);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(!hang[i])
				continue;
			for(j=1;j<=m;j++)
				g[i][j]-=hang[i];
			/*for(int C=1;C<=hang[i];C++)
				printf("row %d\n",i);*/
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(g[i][j])
			{
				puts("-1");
				return 0;
			}
	for(i=1;i<=n;i++)
		ans+=hang[i];
	for(j=1;j<=m;j++)
		ans+=lie[j];
	printf("%d\n",ans);
	for(i=1;i<=n;i++)
		for(int C=1;C<=hang[i];C++)
			printf("row %d\n",i);
	for(j=1;j<=m;j++)
		for(int C=1;C<=lie[j];C++)
			printf("col %d\n",j);
	return 0;
}