#include<bits/stdc++.h>
using namespace std;
#define re register
struct pl
{
	int x,y;
}pp[2010];
inline bool cmp(const pl&A,const pl&B){return A.y>B.y;}
int bc[20][2010],f[5001],g[5001],k[5001];
int main()
{
	re int n,m,t;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d%d",&n,&m);
		for(re int i=1;i<=n;i++)
			for(re int j=1;j<=m;j++)scanf("%d",&bc[i][j]);
		for(re int j=1;j<=m;j++)
		{
			re int x=0;
			for(re int i=1;i<=n;i++)if(bc[i][j]>x)x=bc[i][j];
			pp[j]=(pl){j,x};
		}
		sort(pp+1,pp+m+1,cmp);
		memset(f,0,sizeof(f));
		for(re int i=1;i<=n&&i<=m;i++)
		{
			memset(k,0,(1<<n)*sizeof(int));
			for(re int j=1;j<=n;j++)
			{
				memcpy(g,f,(1<<n)*sizeof(int));
				for(re int kk=1;kk<=n;kk++)
				{
					re int x=bc[(j+kk-1)%n+1][pp[i].x],xx=kk-1;
					for(re int ii=(1<<n)-1;ii>=0;ii--)
					{
						if(ii&(1<<xx))ii^=1<<xx;
						if(g[ii|(1<<xx)]<g[ii]+x)g[ii|(1<<xx)]=g[ii]+x;
					}
				}
				for(re int ii=(1<<n)-1;ii>=0;ii--)if(k[ii]<g[ii])k[ii]=g[ii];
			}
			memcpy(f,k,(1<<n)*sizeof(int));
		}
		printf("%d\n",f[(1<<n)-1]);
	}
}