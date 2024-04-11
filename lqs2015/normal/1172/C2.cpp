#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod; 
	}
	return res;
}
int n,m,w[222222],suma,sumb,f[3333][3333],g[3333][3333];
bool a[222222];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
		if (!a[i]) suma+=w[i];
		else sumb+=w[i];
	}
	for (int i=m;i>=0;i--)
	{
		for (int j=m;j>=0;j--)
		{
			if (i+j>m) continue;
			if (i+j==m) f[i][j]=g[i][j]=1;
			else
			{
				int iv=binpow(suma+sumb+i-j,mod-2);
				f[i][j]=(1ll*f[i][j+1]*(suma-j)%mod*iv%mod+1ll*f[i+1][j]*(sumb+i+1)%mod*iv%mod)%mod;
				g[i][j]=(1ll*g[i][j+1]*(suma-j-1)%mod*iv%mod+1ll*g[i+1][j]*(sumb+i)%mod*iv%mod)%mod;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (!a[i]) printf("%d\n",(1ll*w[i]*g[0][0]%mod+mod)%mod);
		else printf("%d\n",(1ll*w[i]*f[0][0]%mod+mod)%mod);
	}
	return 0;
}