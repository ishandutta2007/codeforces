#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
const int N=1e6+5;
int n,m;
int a[N];
int f[2][9][9];
signed main()
{
	int x,ans=0;
	register int i,j,k,l;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&x),a[x]++;
	memset(f[0],-1,sizeof(f[0]));
	f[0][0][0]=0;
	for(i=1;i<=m;i++)
	{
		memset(f[i&1],-1,sizeof(f[i&1]));
		for(j=0;j<9;j++)
			for(k=0;k<9;k++)
				if(f[(i-1)&1][j][k]>=0)
				{
					for(l=0;l<=j&&l<=k&&l<=a[i];l++)
					{
						x=(a[i]-l)%3;
						f[i&1][k-l][x]=max(f[i&1][k-l][x],f[(i-1)&1][j][k]+l+(a[i]-l-x)/3);
						if(x+3<=a[i]-l)
							f[i&1][k-l][x+3]=max(f[i&1][k-l][x+3],f[(i-1)&1][j][k]+l+(a[i]-l-x)/3-1);
						if(x+6<=a[i]-l)
							f[i&1][k-l][x+6]=max(f[i&1][k-l][x+6],f[(i-1)&1][j][k]+l+(a[i]-l-x)/3-2);
					}
				}
	}
	for(j=0;j<9;j++)
		for(k=0;k<9;k++)
			ans=max(ans,f[m&1][j][k]);
	printf("%d\n",ans);
	return 0;
}