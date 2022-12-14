#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5;
int n,m,x[555555],y[555555],w[555555],pa[555555],q,num,cur;
bool ans[555555];
vector<int> v[555555];
vector<pair<int,int> > g[555555];
vector<pair<int,int> > edit;
int root(int x)
{
	if (pa[x]!=x)
	{
		edit.push_back(make_pair(x,pa[x])); 
		pa[x]=root(pa[x]);
	}
	return pa[x];
}
bool Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return 0;
	edit.push_back(make_pair(rx,pa[rx])); 
	pa[rx]=ry;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&w[i]);
		v[w[i]].push_back(i); 
	}
	for (int i=1;i<=n;i++) pa[i]=i;
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&num);
		for (int j=1;j<=num;j++)
		{
			scanf("%d",&cur);
			g[w[cur]].push_back(make_pair(i,cur)); 
		}
	}
	for (int i=1;i<=maxn;i++)
	{
		for (int j=0;j<g[i].size();j++)
		{
			if (!j || g[i][j].first!=g[i][j-1].first)
			{
				for (int k=(int)edit.size()-1;k>=0;k--)
				{
					pa[edit[k].first]=edit[k].second;
				}
				edit.clear();
			}
			if (!Union(x[g[i][j].second],y[g[i][j].second])) ans[g[i][j].first]=1;
		}
		for (int j=0;j<v[i].size();j++)
		{
			Union(x[v[i][j]],y[v[i][j]]);
		}
		edit.clear();
	}
	for (int i=1;i<=q;i++)
	{
		if (ans[i]) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}