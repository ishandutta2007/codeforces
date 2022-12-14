#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
vector<long long> g[1111],rg[1111];
long long a[1111][1111];
bool vis[1111];
long long n,m,p,x,y,cnty,cnth,so[1111],ve[1111],dp[1111],f,pos,ans;
long long binpow(long long a,long long t)
{
	long long res=1,pp=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*pp%p;
		pp=pp*pp%p;
	}
	return res;
}
void gauss()
{
	for (long long i=1;i<=cnty;i++)
	{
		for (long long j=i;j<=cnty;j++)
		{
			if (a[j][i]) 
			{
				pos=j;
				break;
			}
		}
		if (pos!=i) 
		{
			f*=-1;
			for (long long j=1;j<=cnty;j++)
			{
				swap(a[i][j],a[pos][j]);
			}
		}
		for (long long j=i+1;j<=cnty;j++)
		{
			if (a[j][i])
			{
				long long aa=a[j][i]*binpow(a[i][i],p-2)%p;
				for (long long k=i;k<=cnty;k++)
				{
					a[j][k]=(a[j][k]-aa*a[i][k])%p;
				}
			}
		}
	}
	ans=f;
	for (long long i=1;i<=cnty;i++)
	{
		ans=ans*a[i][i]%p;
	}
}
void dfs(int i)
{
	if (dp[i]!=-1) return;
	dp[i]=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		dfs(to);
		dp[i]=(dp[i]+dp[to])%p;
	}
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&p);
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		g[x].push_back(y); 
		rg[y].push_back(x); 
	}
	for (long long i=1;i<=n;i++)
	{
		if (rg[i].empty()) so[i]=++cnty;
		if (g[i].empty()) ve[i]=++cnth;
	}
	for (int i=1;i<=n;i++)
	{
		if (ve[i])
		{
			memset(dp,-1,sizeof(dp));
			dp[i]=1;
			for (int j=1;j<=n;j++)
			{
				if (so[j])
				{
					dfs(j);
					a[so[j]][ve[i]]=dp[j];
				}
			}
		}
	}
	f=1;
	gauss();
	if (ans<0) ans+=p;
	printf("%I64d\n",ans);
	return 0;
}