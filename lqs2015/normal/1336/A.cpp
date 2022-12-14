#include<bits/stdc++.h>
using namespace std;
int n,k,x,y,dep[222222],sub[222222],arr[222222];
long long ans;
vector<int> g[222222];
void dfs(int i,int fa)
{
	dep[i]=dep[fa]+1;sub[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		sub[i]+=sub[to];
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) arr[i]=dep[i]-sub[i];
	sort(arr+1,arr+n+1);
	reverse(arr+1,arr+n+1);
	for (int i=1;i<=k;i++)
	{
		ans+=arr[i];
	}
	printf("%lld\n",ans);
	return 0;
}