#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,x,y,dep[222222],a,b;
vector<int> g[222222];
void dfs(int i,int fa)
{
	dep[i]=dep[fa]+1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
	{
		if (dep[i]&1) a++;
		else b++;
	}
	printf("%d\n",min(a,b)-1);
	return Accepted;
}