#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
struct mat
{
	int a[111][111];
	mat()
	{
		for (int i=1;i<=maxn;i++)
		{
			for (int j=1;j<=maxn;j++)
			{
				if (i!=j) a[i][j]=-1e9;
			}
		}
	}
	mat operator * (const mat &u) const
	{
		mat res;
		for (int i=1;i<=maxn;i++)
		{
			for (int j=1;j<=maxn;j++)
			{
				res.a[i][j]=-1e9;
				for (int k=1;k<=maxn;k++)
				{
					res.a[i][j]=max(res.a[i][j],a[i][k]+u.a[k][j]);
				}
			}
		}
		return res;
	}
}ma;
mat binpow(mat a,int t)
{
	mat res,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=res*p;
		p=p*p;
	}
	return res;
}
int n,t,a[111],dp[111],ans,s[111],cnt;
map<int,int> mp;
int main()
{
	scanf("%d%d",&n,&t);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=a[i];
	}
	sort(s+1,s+n+1);
	cnt=unique(s+1,s+n+1)-s-1;
	for (int i=1;i<=cnt;i++) mp[s[i]]=i;
	for (int i=1;i<=n;i++) a[i]=mp[a[i]];
	for (int i=1;i<=maxn;i++)
	{
		for (int j=1;j<=n;j++) dp[j]=-1e9;
		for (int j=1;j<=n;j++)
		{
			if (a[j]>=i) dp[j]=1;
		}
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<j;k++)
			{
				if (a[j]>=a[k]) dp[j]=max(dp[j],dp[k]+1);
			}
		}
		for (int j=1;j<=n;j++)
		{
			ma.a[i][a[j]]=dp[j];
		}
		ma.a[i][i]=max(ma.a[i][i],0);
	}
	ma=binpow(ma,t);
	for (int i=1;i<=maxn;i++) ans=max(ans,ma.a[1][i]);
	printf("%d\n",ans);
	return 0;
}