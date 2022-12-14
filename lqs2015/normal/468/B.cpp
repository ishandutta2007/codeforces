#include<bits/stdc++.h>
using namespace std;
int n,a,b,c[222222],cp,col[222222],cc;
map<int,int> mp;
vector<int> g[444444],rg[444444];
vector<int> v;
bool used[222222],ans[222222];
void addedge(int x,int y)
{
	if (x==y) return;
	g[x].push_back(y);
	rg[y].push_back(x);
}
void dfs(int i)
{
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (!used[to]) dfs(to);
	}
	v.push_back(i);
}
void rdfs(int i)
{
	col[i]=cc;
	for (int j=0;j<rg[i].size();j++)
	{
		int to=rg[i][j];
		if (!col[to]) rdfs(to);
	}
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		mp[c[i]]=i;
	}
	for (int i=1;i<=n;i++)
	{
		if (mp.find(a-c[i])==mp.end())
		{
			addedge(i,i+n);
		}
		else
		{
			cp=mp[a-c[i]];
			addedge(i,cp);
			addedge(i+n,cp+n);
		}
		if (mp.find(b-c[i])==mp.end())
		{
			addedge(i+n,i);
		}
		else
		{
			cp=mp[b-c[i]];
			addedge(i,cp);
			addedge(i+n,cp+n);
		}
	}
	for (int i=1;i<=2*n;i++)
	{
		if (!used[i]) dfs(i);
	}
	for (int i=(int)v.size()-1;i>=0;i--)
	{
		if (!col[v[i]])
		{
			++cc;
			rdfs(v[i]);
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (col[i]==col[i+n])
		{
			printf("NO\n");
			return 0;
		}
		if (col[i]<col[i+n]) ans[i]=1;
	}
	printf("YES\n");
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}