#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,p;
int dp[111][555555],cur[111],a[555555],ld[111],sum[555555],dpp[555555],bit[1111],sz;
void update(int x,int p)
{
	while(x<=sz)
	{
		bit[x]=max(bit[x],p);
		x+=x&(-x);
	}
}
int query(int x)
{
	int res=0;
	while(x>=1)
	{
		res=max(res,bit[x]);
		x-=x&(-x);
	}
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&k,&p);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		a[i]%=p;
	}
	if (k*p>=n)
	{
		for (int i=0;i<=k;i++) 
		{
			for (int j=0;j<=n;j++) 
			dp[i][j]=1e9;
		}
		dp[0][0]=0;
		for (int i=1;i<=k;i++)
		{
			for (int j=0;j<p;j++) cur[j]=1e9;
			for (int j=1;j<=n;j++)
			{
				for (int h=0;h<p;h++) ld[(h+a[j])%p]=cur[h];
				for (int h=0;h<p;h++) cur[h]=ld[h];
				cur[a[j]]=min(cur[a[j]],dp[i-1][j-1]);
				for (int h=0;h<p;h++) dp[i][j]=min(dp[i][j],cur[h]+h);
			}
		}
		cout<<dp[k][n]<<endl;
	}
	else
	{
		for (int i=1;i<=n;i++) sum[i]=(sum[i-1]+a[i])%p;
		sz=1;
		while(sz<p) sz*=2;
		for (int i=1;i<=n;i++)
		{
			dpp[i]=query(sum[i]+1)+1;
			update(sum[i]+1,dpp[i]);
		}
		if (dpp[n]>=k) cout<<sum[n]<<endl;
		else cout<<sum[n]+p<<endl;
	}
	return 0;
}