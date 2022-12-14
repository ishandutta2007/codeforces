#include<bits/stdc++.h>
using namespace std;
int n,x,y,dep[111111],ans1,ans2,f0,f1,cnt;
vector<int> g[111111];
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
		if (g[i].size()==1)
		{
			if (dep[i]&1) f1=1;
			else f0=1;
		}
	}
	if (f0&f1) ans1=3;
	else ans1=1;
	ans1=min(ans1,n-1);
	ans2=n-1;
	for (int i=1;i<=n;i++)
	{
		cnt=0;
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			if (g[to].size()==1) cnt++;
		}
		if (cnt) ans2-=(cnt-1);
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}