#include<bits/stdc++.h>
#define Accepted 0 
using namespace std;
int test,n,k,x,y,z,cnt;
vector<pair<int,int> > g[555555];
long long dp[555555][2],a[555555],cur;
void dfs(int i,int fa)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;
		if (to==fa) continue;
		dfs(to,i);
	}
	cnt=0;cur=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		a[++cnt]=dp[to][1]+val-dp[to][0];
		cur+=dp[to][0];
	}
	sort(a+1,a+cnt+1);
	reverse(a+1,a+cnt+1);
	dp[i][0]=dp[i][1]=cur;
	for (int j=1;j<=cnt && j<=k;j++) 
	{
		if (a[j]<0) break;
		dp[i][0]+=a[j];
	}
	for (int j=1;j<=cnt && j<k;j++) 
	{
		if (a[j]<0) break;
		dp[i][1]+=a[j];
	}
}
int main()
{
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			g[x].push_back(make_pair(y,z));
			g[y].push_back(make_pair(x,z));
		}
		dfs(1,0);
		printf("%lld\n",dp[1][0]);
	}
	return Accepted;
}