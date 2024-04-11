#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,d[333333],a[333333],cnt,pos,x,y;
vector<pair<int,int> > g[333333];
vector<int> ans;
bool used[333333];
void dfs(int i)
{
	used[i]=1;
	if (d[i]==1) a[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (used[to]) continue;
		dfs(to);
		if (a[to]&1) 
		{
			ans.push_back(val); 
			a[i]++;
			a[to]++;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(make_pair(y,i));
		g[y].push_back(make_pair(x,i)); 
	}
	for (int i=1;i<=n;i++)
	{
		if (d[i]==1) cnt++;
		if (d[i]==-1) pos=i;
	}
	if (cnt&1)
	{
		if (!pos) 
		{
			printf("-1\n");
			return 0;
		}
		d[pos]=1;
	}
	dfs(1);
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
	printf("%d ",ans[i]);
	printf("\n");
	return 0;
}