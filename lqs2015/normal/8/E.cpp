#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long n,k,a[55],x,dp[55][55][2][2],vis[55][55][2][2];
long long solve(long long l,long long r,long long rev,long long irev)
{
	if (l>r) return 1;
	if (vis[l][r][rev][irev]) return dp[l][r][rev][irev];
	vis[l][r][rev][irev]=1;
	dp[l][r][rev][irev]=0;
	for (long long i=0;i<2;i++)
	{
		if (!~a[l] || a[l]==i)
		{
			for (long long j=0;j<2;j++)
			{
				if (!~a[r] || a[r]==j)
				{
					if ((l<r || i==j) && (rev || i<=j) && (irev || i<=1-j))
					{
						dp[l][r][rev][irev]+=solve(l+1,r-1,rev|(i<j),irev|(i<1-j));
					}
				}
			}
		}
	}
	return dp[l][r][rev][irev];
}
int main()
{
	cin>>n>>k;
	k++;
	memset(a,-1,sizeof(a));
	if (solve(1,n,0,0)<k) 
	{
		cout<<-1<<endl;
		return 0;
	}
	for (long long i=1;i<=n;i++)
	{
		a[i]=0;
		memset(vis,0,sizeof(vis));
		x=solve(1,n,0,0);
		if (x<k)
		{
			k-=x;
			a[i]=1;
		}
	}
	for (long long i=1;i<=n;i++) cout<<a[i];
	cout<<endl;
	return 0;
}