#include<bits/stdc++.h>
using namespace std;
int n,x[222222],y[222222],m,col[222222];
bool f,ans[222222];
vector<pair<int,int> > g[222222];
void dfs(int i,int c)
{
	col[i]=c;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;
		if (col[to])
		{
			if (col[to]+c!=3) f=1;
		}
		else 
		{
			dfs(to,3-c);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		g[x[i]].push_back(make_pair(y[i],i));
		g[y[i]].push_back(make_pair(x[i],i));  
	}
	dfs(1,1);
	if (f) printf("NO\n");
	else
	{
		for (int i=1;i<=n;i++)
		{
			if (col[i]==1)
			{
				for (int j=0;j<g[i].size();j++)
				{
					int to=g[i][j].first,id=g[i][j].second;
					if (i==x[id]) ans[id]=1;
				}
			}
		}
		printf("YES\n");
		for (int i=1;i<=m;i++) printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}