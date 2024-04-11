#include<bits/stdc++.h>
using namespace std;
int n,m,c,q,pa[111111],x,y,z;
set<pair<int,int> > s[111111];
set<pair<int,int> >::iterator it;
set<int> t[111111];
set<int>::iterator itt;
char opt[11];
vector<pair<int,int> > g[111111];
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	if (t[rx].size()>t[ry].size())
	{
		pa[ry]=rx;
		for (itt=t[ry].begin();itt!=t[ry].end();itt++)
		{
			t[rx].insert(*itt); 
		}
	}
	else
	{
		pa[rx]=ry;
		for (itt=t[rx].begin();itt!=t[rx].end();itt++)
		{
			t[ry].insert(*itt); 
		}
	}
}
void addedge(int x,int y,int z)
{
	it=s[x].lower_bound(make_pair(z,0));
	if (it==s[x].end() || (it->first)!=z)
	{
		s[x].insert(make_pair(z,y));
	}
	else
	{
		Union(y,it->second);
	}
	t[root(x)].insert(y); 
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&c,&q);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(make_pair(z,y));
		g[y].push_back(make_pair(z,x));
		t[x].insert(y);
		t[y].insert(x);    
	}
	for (int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	for (int i=1;i<=n;i++) pa[i]=i;
	for (int i=1;i<=n;i++)
	{
		if (g[i].empty()) continue;
		s[i].insert(g[i][0]);
		for (int j=0;j<(int)g[i].size()-1;j++)
		{
			if (g[i][j].first==g[i][j+1].first) Union(g[i][j].second,g[i][j+1].second);
			else s[i].insert(g[i][j+1]);
		}
	}
	while(q--)
	{
		scanf("%s",opt);
		if (opt[0]=='+')
		{
			scanf("%d%d%d",&x,&y,&z);
			addedge(x,y,z);
			addedge(y,x,z);
		}
		else
		{
			scanf("%d%d",&x,&y);
			if (root(x)==root(y)) printf("Yes\n");
			else
			{
				if (t[root(x)].find(y)==t[root(x)].end()) printf("No\n");
				else printf("Yes\n");
			}
		}
	}
	return 0;
}