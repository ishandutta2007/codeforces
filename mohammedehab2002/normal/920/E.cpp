#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
using namespace std;
int par[200005],sz[200005];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
void Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x==y)
	return;
	par[y]=x;
	sz[x]+=sz[y];
	sz[y]=0;
}
vector<int> v[200005];
bool b[200005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int c=1;
	for (int i=1;i<=n;i++)
	{
		par[i]=i;
		sz[i]=1;
		if (v[i].size()<v[c].size())
		c=i;
	}
	for (int i=1;i<=n;i++)
	{
		if (find(v[c].begin(),v[c].end(),i)==v[c].end())
		Union(c,i);
		else
		{
			memset(b,0,sizeof(b));
			for (int x=0;x<v[i].size();x++)
			b[v[i][x]]=1;
			for (int x=1;x<=n;x++)
			{
				if (!b[x])
				Union(i,x);
			}
		}
	}
	set<int> s;
	vector<int> ans;
	for (int i=1;i<=n;i++)
	s.insert(find(i));
	printf("%d\n",s.size());
	for (set<int>::iterator it=s.begin();it!=s.end();it++)
	ans.push_back(sz[*it]);
	sort(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++)
	printf("%d ",ans[i]);
}