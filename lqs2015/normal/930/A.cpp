#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,x,num[111111],ans;
vector<int> g[111111];
void dfs(int i,int fa,int dep)
{
	num[dep]++;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i,dep+1);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		g[x].push_back(i);
		g[i].push_back(x);  
	}
	dfs(1,0,1);
	for (int i=1;i<=n;i++)
	{
		ans+=(num[i]%2);
	}
	printf("%d\n",ans);
	return 0;
}