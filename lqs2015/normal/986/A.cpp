#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
long long dp[111111][111],n,m,k,s,a[111111],x,y,ans,b[111];
vector<long long> g[111111];
queue<pair<long long,long long> > q;
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&k,&s);
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (long long i=1;i<=m;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	memset(dp,-1,sizeof(dp));
	for (long long i=1;i<=n;i++)
	{
		dp[i][a[i]]=0;
		q.push(make_pair(i,a[i]));
	}
	while(!q.empty())
	{
		x=q.front().first;y=q.front().second;
		q.pop();
		for (long long i=0;i<g[x].size();i++)
		{
			long long to=g[x][i];
			if (dp[to][y]==-1)
			{
				dp[to][y]=dp[x][y]+1;
				q.push(make_pair(to,y)); 
			}
		}
	}
	for (long long i=1;i<=n;i++)
	{
		ans=0;
		for (long long j=1;j<=k;j++) b[j]=dp[i][j];
		sort(b+1,b+k+1);
		for (long long j=1;j<=s;j++) ans+=b[j];
		printf("%I64d ",ans);
	}
	printf("\n");
	return 0;
}