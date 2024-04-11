#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[222222],w[222222];
int suma,sumb,dp[3333][3333],fdp[55][55][55],ans[222222];
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
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
	if (x<0) x+=mod;
}
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
		ans[i]=w[i];
	}
	dp[0][0]=1;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<=i;j++)
		{
			if (!dp[i][j]) continue;
			add(dp[i+1][j],1ll*dp[i][j]*(sumb+(i-j))%mod*binpow(suma+(i-j)+sumb-j,mod-2)%mod);
			add(dp[i+1][j+1],1ll*dp[i][j]*(suma-j)%mod*binpow(suma+(i-j)+sumb-j,mod-2)%mod);
		}
	}
	for (int i=1;i<=n;i++)
	{
		fdp[i][0][0]=1;
		for (int j=0;j<m;j++)
		{
			for (int k=0;k<=j;k++)
			{
				if (!fdp[i][j][k]) continue;
				if (!a[i])
				{
					add(fdp[i][j+1][k],1ll*fdp[i][j][k]*(suma-j-(w[i]-k))%mod*binpow(suma-j,mod-2)%mod);
					add(fdp[i][j+1][k+1],1ll*fdp[i][j][k]*(w[i]-k)%mod*binpow(suma-j,mod-2)%mod);
					add(ans[i],1ll*fdp[i][j][k]*dp[m][j]%mod*(mod-k)%mod);
				}
				else
				{
					add(fdp[i][j+1][k],1ll*fdp[i][j][k]*(sumb+j-(w[i]+k))%mod*binpow(sumb+j,mod-2)%mod);
					add(fdp[i][j+1][k+1],1ll*fdp[i][j][k]*(w[i]+k)%mod*binpow(sumb+j,mod-2)%mod);
					add(ans[i],1ll*fdp[i][j][k]*dp[m][m-j]%mod*k%mod);
				}
			}
		}
		for (int k=0;k<=m;k++)
		{
			if (!a[i]) 
			{
				add(ans[i],1ll*fdp[i][m][k]*dp[m][m]%mod*(mod-k)%mod);
			}
			else
			{
				add(ans[i],1ll*fdp[i][m][k]*dp[m][0]%mod*k%mod);
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}