#include<bits/stdc++.h>
using namespace std;
int fp[2010][2010],lp[2010][2010],f[2010][2010],g[2010][2010],fl[2010][2010],gl[2010][2010];
char ss[2010];
const int mod=1e9+7;
#define re register
int main()
{
	re int n,m;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++)
	{
		scanf("%s",ss+1);
		for(re int j=1;j<=m;j++){if(ss[j]=='R')fp[i][j]=lp[i][j]=1;
		fp[i][j]+=fp[i][j-1];
		lp[i][j]+=lp[i-1][j];}
	}
	f[1][1]=g[1][1]=1;
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=m;j++)if(i!=1||j!=1)
		{
			re int x=(f[i][j-1]+g[i][j-1])%mod,y=fl[i][j-1];
			if(i==1&&j==2)x=1;
			for(;fp[i][m]-fp[i][y]>m-j&&y<j;y++)x=(x+mod-g[i][y])%mod;
			fl[i][j]=y;f[i][j]=x;
			x=(f[i-1][j]+g[i-1][j])%mod,y=gl[i-1][j];
			if(i==2&&j==1)x=1;
			for(;lp[n][j]-lp[y][j]>n-i&&y<i;y++)x=(x+mod-f[y][j])%mod;
			gl[i][j]=y;g[i][j]=x;
			//printf("**%d %d %d %d %d\n",i,j,y,x,fp[i][j]);
		}
	}
	
	if(n==1&&m==1)puts("1");
	else printf("%d\n",(f[n][m]+g[n][m])%mod);
}