#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
int n,x,y,sub[444444],rt;
vector<int> g[444444];
bool ans[444444];
multiset<int> s;
void Init(int i,int fa)
{
	sub[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		Init(to,i);
		sub[i]+=sub[to];
	}
}
pair<int,int> findgrav(int i,int fa,int all)
{
	pair<int,int> res=make_pair(1e9,1e9);
	int mx=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		res=min(res,findgrav(to,i,all));
		mx=max(mx,sub[to]);
	}
	mx=max(mx,all-sub[i]);
	res=min(res,make_pair(mx,i));
	return res;
}
void dfs(int i,int fa,int su)
{
	if (su*2==n)
	{
		ans[i]=1;
	}
	else 
	{
		if (s.empty())
		{
			if (n-sub[i]<=n/2) ans[i]=1;
			else ans[i]=0;
		} 
		else
		{
		 	if (n-sub[i]-*s.rbegin()<=n/2) ans[i]=1;
			else ans[i]=0;
		}
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i,su);
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
	Init(1,0);
	rt=findgrav(1,0,n).second;
	Init(rt,0);
	ans[rt]=1;
	for (int j=0;j<g[rt].size();j++) s.insert(sub[g[rt][j]]);
	for (int j=0;j<g[rt].size();j++)
	{
		s.erase(s.find(sub[g[rt][j]]));
		dfs(g[rt][j],rt,sub[g[rt][j]]);
		s.insert(sub[g[rt][j]]);
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}