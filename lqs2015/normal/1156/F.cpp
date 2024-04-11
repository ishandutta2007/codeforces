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
void add(int &x,int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int n,x,cnt[5555],dp[5555][5555],sum[5555][5555],inv[5555],ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	inv[0]=1;
	for (int i=1;i<=n;i++) inv[i]=binpow(i,mod-2);
	dp[0][0]=1;sum[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			dp[i][j]=1ll*sum[i-1][j-1]*cnt[i]%mod*inv[n-j+1]%mod;
		}
		for (int j=0;j<=n;j++)
		{
			sum[i][j]=(sum[i-1][j]+dp[i][j])%mod;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			add(ans,1ll*dp[i][j]*(cnt[i]-1)%mod*inv[n-j]%mod);
		}
	}
	printf("%d\n",ans);
	return 0;
}