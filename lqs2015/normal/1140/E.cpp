#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,k,a[222222],dp[222222][2],cnt,ans,cur,DP[222222],pre;
bool f;
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
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dp[0][1]=k-1;
	for (int i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][1];
		dp[i][1]=(1ll*dp[i-1][0]*(k-1)+1ll*dp[i-1][1]*(k-2))%mod;
	}
	cur=1;
	for (int i=1;i<=n;i+=2)
	{
		if (a[i]==-1) cnt++;
		else
		{
			if (!f)
			{
				if (cnt) cur=1ll*cur*(1ll*dp[cnt-1][0]+1ll*dp[cnt-1][1])%mod;
			}
			else
			{
					if (pre!=a[i]) cur=1ll*cur*dp[cnt][1]%mod*binpow(k-1,mod-2)%mod;
					else cur=1ll*cur*dp[cnt][0]%mod;
			}
			f=1;cnt=0;pre=a[i];
		}
	}
	if (cnt) 
	{
		if (!f) 
		{
			cur=1ll*cur*k%mod;
			for (int i=3;i<=n;i+=2) cur=1ll*cur*(k-1)%mod;
		}
		else cur=1ll*cur*(1ll*dp[cnt-1][0]+1ll*dp[cnt-1][1])%mod;
	}
	ans=cur;cur=1;cnt=0;f=0;pre=0;
	for (int i=2;i<=n;i+=2)
	{
		if (a[i]==-1) cnt++;
		else
		{
			if (!f)
			{
				if (cnt) cur=1ll*cur*(1ll*dp[cnt-1][0]+1ll*dp[cnt-1][1])%mod;
			}
			else
			{
					if (pre!=a[i]) cur=1ll*cur*dp[cnt][1]%mod*binpow(k-1,mod-2)%mod;
					else cur=1ll*cur*dp[cnt][0]%mod;
			}
			f=1;cnt=0;pre=a[i];
		}
	}
	if (cnt) 
	{
		if (!f) 
		{
			cur=1ll*cur*k%mod;
			for (int i=4;i<=n;i+=2) cur=1ll*cur*(k-1)%mod;
		}
		else cur=1ll*cur*(1ll*dp[cnt-1][0]+1ll*dp[cnt-1][1])%mod;
	}
	ans=1ll*ans*cur%mod;
	printf("%d\n",ans);
	return 0;
}