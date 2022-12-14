#include<bits/stdc++.h>
using namespace std;
int n,p,k,s[111111][7],cnt[222];
pair<int,int> a[111111];
long long dp[111111][133],ans,sum,mx[11];
void upd(long long &x,long long y)
{
	if (x<y) x=y;
}
int main()
{
	scanf("%d%d%d",&n,&p,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<p;j++)
		{
			scanf("%d",&s[i][j]);
		}
	}
	for (int i=0;i<(1<<p);i++) cnt[i]=__builtin_popcount(i);
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<(1<<p);j++)
		{
			dp[i][j]=-1e18;
		}
	}
	dp[0][0]=0;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<(1<<p);j++)
		{
			if (dp[i][j]<0) continue;
			upd(dp[i+1][j],dp[i][j]+a[i+1].first);
			for (int k=0;k<p;k++)
			{
				if (j&(1<<k)) continue;
				upd(dp[i+1][j^(1<<k)],dp[i][j]+s[a[i+1].second][k]);
			}
		}
	}
	for (int i=0;i<p;i++) mx[i]=-1e17;
	ans=-1e18;
	for (int i=n;i>=0;i--)
	{
		for (int j=0;j<(1<<p);j++)
		{
			if (i==cnt[j]+k)
			{
				sum=0;
				for (int k=0;k<p;k++)
				{
					if (!(j&(1<<k))) sum+=mx[k];
				}
				upd(ans,dp[i][j]+sum);
			}
		}
		for (int j=0;j<p;j++)
		{
			upd(mx[j],s[a[i].second][j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}