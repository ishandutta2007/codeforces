#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long n,x,y,sub[222222],all,dep[222222],cnt;
vector<long long> g[222222];
void dfs(long long i,long long fa)
{
	dep[i]=dep[fa]+1;sub[i]=1;
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
		all+=sub[to]*(n-sub[to]);
		sub[i]+=sub[to];
	}
}
int main()
{
	scanf("%I64d",&n);
	for (long long i=1;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	dfs(1,0);
	for (long long i=1;i<=n;i++)
	{
		if (dep[i]&1) cnt++;
	}
	all+=cnt*(n-cnt);
	printf("%I64d\n",all/2);
	return 0;
}