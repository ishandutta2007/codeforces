#include<bits/stdc++.h>
#define re register
#define ui unsigned int
#define ull unsigned long long
ui f[2][2][2],g[2][2][2],col[200100],ex[200100];
const ui mod=1e9+7;
void add(re ui&a,re ui b){(a+=b)>mod?a-=mod:0;}
int main()
{
//	freopen("life.in","r",stdin);

//	freopen("life.out","w",stdout);
	re int n,p;
	scanf("%d%d",&n,&p);
	ex[0]=1;
	for(re int i=1;i<=n;i++)scanf("%d",&col[i]),ex[i]=2*ex[i-1]%mod;
	f[0][0][0]=1;
	for(re int i=1;i<=n;i++)
	{
		memset(g,0,sizeof(g));
		if(col[i]==0||col[i]==-1)
		{
			for(re int j=0;j<=1;j++)
			{
				for(re int j1=0;j1<=1;j1++)
				{
					g[1][0][!j1]=(g[1][0][!j1]+(ull)f[j][0][j1]*ex[i-1])%mod;
					if(i>1)
					{
						g[1][1][!j1]=(g[1][1][!j1]+(ull)f[j][1][j1]*ex[i-2])%mod;
						g[j][1][j1]=(g[j][1][j1]+(ull)f[j][1][j1]*ex[i-2])%mod;
					}
				}
			}
		}
		if(col[i]==1||col[i]==-1)
		{
			for(re int j=0;j<=1;j++)
			{
				for(re int j1=0;j1<=1;j1++)
				{
					g[0][1][!j1]=(g[0][1][!j1]+(ull)f[0][j][j1]*ex[i-1])%mod;
					if(i>1)
					{
						g[1][1][!j1]=(g[1][1][!j1]+(ull)f[1][j][j1]*ex[i-2])%mod;
						g[1][j][j1]=(g[1][j][j1]+(ull)f[1][j][j1]*ex[i-2])%mod;
					}
				}
			}
		}
		memcpy(f,g,sizeof(f));
	}
	re ui ans=0;
	for(re int j=0;j<=1;j++)
	{
		for(re int j1=0;j1<=1;j1++)
		{
			add(ans,f[j][j1][p]);
		}
	}
	printf("%u\n",ans);
}