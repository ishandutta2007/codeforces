#include<bits/stdc++.h>
using namespace std;
int n,q,x,dep[333333],pa[333333],dd[333333],cen[333333],sub[333333],dp[333333];
vector<int> g[333333];
void dfs(int i,int fa)
{
	pa[i]=fa;dep[i]=dep[fa]+1;sub[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		sub[i]+=sub[to];
	}
}
void dft(int i,int fa)
{
	dd[i]=dep[i];dp[i]=i;
	int mx=0,all=sub[i];
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dft(to,i);
		if (dd[to]<dd[i])
		{
			dd[i]=dd[to];
			dp[i]=dp[to];
		}
		mx=max(mx,sub[to]);
	}
	int mg=dp[i];
	while(mg && mx*2>sub[mg]) mg=pa[mg];
	while(mg && (sub[mg]-all)*2<=sub[mg]) 
	{
		cen[mg]=i;
		mg=pa[mg];
	}
	dd[i]=dep[mg];dp[i]=mg;
}
int main()
{
	scanf("%d%d",&n,&q);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		g[x].push_back(i); 
	}	
	dfs(1,0);
	dft(1,0);
	while(q--)
	{
		scanf("%d",&x);
		printf("%d\n",cen[x]);
	}
	return 0;
}