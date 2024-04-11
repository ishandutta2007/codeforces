#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> g[222222];
int n,x,y,col[222222],con[222222],mxi,ans;
void dfs(int i,int fa)
{
	if (!fa)
	{
		col[i]=1;
		int cnt=1;
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			col[to]=++cnt;
			dfs(to,i);
		}
	}
	else
	{
		int cnt=0;
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			if (to==fa) continue;
			cnt++;
			if (cnt==col[i] || cnt==col[fa]) cnt++;
			if (cnt==col[i] || cnt==col[fa]) cnt++;
			col[to]=cnt;
			dfs(to,i);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		con[x]++;
		con[y]++;
	}
	mxi=1;
	for (int i=2;i<=n;i++)
	{
		if (con[i]>con[mxi]) mxi=i;
	}
	ans=con[mxi]+1;
	dfs(mxi,0);
	printf("%d\n",ans);
	for (int i=1;i<=n;i++)
	{
		if (i-1) printf(" ");
		printf("%d",col[i]);
	}
	printf("\n");
	return 0;
}