#include<bits/stdc++.h>
using namespace std;
#define re register
const int mod=998244353;
int f[3010][3010],g[3010][3010],w[200100],im[6200],a[200100];
int ex(re int a,re int b)
{
	re int ans=1;
	for(;b;b>>=1,a=(long long)a*a%mod)if(b&1)ans=(long long)ans*a%mod;
	return ans;
}
int main()
{
	re int n,m,qaq=0,qa=0,qb=0;f[0][0]=g[0][0]=1;scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]),qaq+=w[i];if(a[i])qa+=w[i];else qb+=w[i];
	}
	for(re int i=-m;i<=m;i++)im[i+3010]=ex(qaq+i,mod-2);
	for(re int i=m;i>=0;i--)
	{
		f[i][m-i]=g[i][m-i]=1;
		for(re int j=m-i-1;j>=0;j--)
		{
			f[i][j]=((long long)f[i+1][j]*(qa+i+1)%mod*im[3010+i-j]+(long long)f[i][j+1]*(qb-j)%mod*im[3010+i-j])%mod;
			g[i][j]=((long long)g[i+1][j]*(qa+i)%mod*im[3010+i-j]+(long long)g[i][j+1]*(qb-j-1)%mod*im[3010+i-j])%mod;
		}
	}
	for(re int i=1;i<=n;i++)printf("%lld\n",(long long)w[i]*(a[i]?f[0][0]:g[0][0])%mod);
}