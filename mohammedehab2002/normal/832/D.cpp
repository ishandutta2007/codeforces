#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int dp[20][100005],dep[100005],tmp[3];
vector<int> v[100005];
void dfs(int node,int pnode,int d)
{
	dp[0][node]=pnode;
	dep[node]=d;
	for (int i=0;i<v[node].size();i++)
	{
		if (v[node][i]!=pnode)
		dfs(v[node][i],node,d+1);
	}
}
int lca(int u,int v)
{
	if (dep[u]>dep[v])
	swap(u,v);
	int diff=dep[v]-dep[u];
	for (int i=0;i<20;i++)
	{
		if ((diff&(1<<i)))
		v=dp[i][v];
	}
	if (u==v)
	return u;
	for (int i=19;i>=0;i--)
	{
		if (dp[i][u]!=dp[i][v])
		{
			u=dp[i][u];
			v=dp[i][v];
		}
	}
	return dp[0][u];
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		v[i].push_back(a);
		v[a].push_back(i);
	}
	for (int i=0;i<20;i++)
	{
		for (int x=0;x<100005;x++)
		dp[i][x]=-1;
	}
	dfs(1,-1,0);
	for (int i=1;i<20;i++)
	{
		for (int x=2;x<=n;x++)
		{
			if (dp[i-1][x]!=-1)
			dp[i][x]=dp[i-1][dp[i-1][x]];
		}
	}
	while (q--)
	{
		for (int i=0;i<3;i++)
		scanf("%d",&tmp[i]);
		sort(tmp,tmp+3);
		int ans=1;
		do {
			int a=lca(tmp[0],tmp[1]),b=lca(tmp[0],tmp[2]),c=lca(tmp[1],tmp[2]);
			if (a==tmp[0] && b==tmp[0])
			ans=max(ans,dep[c]-dep[tmp[0]]+1);
			else if (a!=b)
			ans=max(ans,dep[tmp[0]]-max(dep[a],dep[b])+1);
			else
			ans=max(ans,dep[c]+dep[tmp[0]]-2*dep[a]+1);
		} while (next_permutation(tmp,tmp+3));
		printf("%d\n",ans);
	}
}