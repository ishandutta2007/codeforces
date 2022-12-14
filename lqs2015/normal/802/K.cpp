#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,k,dp[111111][2],x,y,z,sum[111111];
vector<pair<int,int> > g[111111];
pair<int,int> c[111111];
void dfs(int i,int fa)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		dfs(to,i);
	}
	int sz=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		c[sz++]=make_pair(dp[to][0]+val,dp[to][1]+val);
	}
	sort(c,c+sz);
	reverse(c,c+sz);
	for (int j=0;j<sz;j++) sum[j+1]=sum[j]+c[j].first;
	dp[i][0]=sum[min(sz,k-1)];
	int mx=0;
	for (int j=0;j<sz;j++)
	{
		if (j<k-1) mx=max(mx,sum[min(sz,k)]+c[j].second-c[j].first);
		else mx=max(mx,sum[min(sz,k-1)]+c[j].second);
	} 
	dp[i][1]=mx;
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z)); 
	} 
	dfs(0,-1);
	printf("%d\n",dp[0][1]);
	return 0;
}