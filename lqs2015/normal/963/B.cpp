#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
using namespace std;
set<pair<int,int> > s;
int x,n,ans[222222],deg[222222],r,dep[222222];
vector<int> g[222222];
bool f[222222];
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
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (!x) 
		{
			r=i;
			continue;
		}
		g[i].push_back(x);
		g[x].push_back(i);
		deg[i]++;deg[x]++;
	}
	dfs(r,0);
	for (int i=1;i<=n;i++)
	{
		if (deg[i]%2==0) s.insert(make_pair(-dep[i],i)); 
	}
	for (int i=1;i<=n;i++)
	{
		if (s.empty()) 
		{
			printf("NO\n");
			return 0;
		}
		int ind=s.begin()->second;
		s.erase(s.begin()); 
		f[ind]=1;
		ans[i]=ind;
		for (int j=0;j<g[ind].size();j++)
		{
			int to=g[ind][j];
			if (f[to]) continue;
			if (deg[to]%2==0) s.erase(s.find(make_pair(-dep[to],to)));
			else s.insert(make_pair(-dep[to],to));
			deg[to]--;  
		}
	}
	printf("YES\n");
	for (int i=1;i<=n;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}