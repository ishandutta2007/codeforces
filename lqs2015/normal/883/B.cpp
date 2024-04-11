#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,k,l[222222],r[222222],a[222222],x,y,ans[222222],pos,deg[222222],degr[222222];
pair<int,pair<int,int> > que[222222];
vector<int> g[222222],rg[222222];
int used[222222],f,fl;
set<pair<int,int> > s;
void out()
{
	printf("-1\n");
	exit(0);
}
void dfsl(int i)
{
	if (a[i]) l[i]=a[i];
	else l[i]=1;
	used[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (used[to]==1)
		{
			f=1;
			return;
		}
		dfsl(to);
		l[i]=max(l[i],l[to]+1);
	}
	used[i]=2;
}
void dfsr(int i)
{
	if (a[i]) r[i]=a[i];
	else r[i]=k;
	used[i]=1;
	for (int j=0;j<rg[i].size();j++)
	{
		int to=rg[i][j];
		if (used[to]==1)
		{
			f=1;
			return;
		}
		dfsr(to);
		r[i]=min(r[i],r[to]-1);
	}
	used[i]=2;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		deg[y]++;degr[x]++;
		g[x].push_back(y);
		rg[y].push_back(x);  
	}
	for (int i=1;i<=n;i++)
	{
		if (!deg[i]) 
		{
			fl=1;
			dfsl(i);
		}
	}
	if (!fl || f) out();
	memset(used,0,sizeof(used));fl=0;
	for (int i=1;i<=n;i++)
	{
		if (!degr[i])
		{
			fl=1;
			dfsr(i);
		}
	}
	if (!fl || f) out();
	for (int i=1;i<=n;i++) 
	{
		if (l[i]>r[i]) out();
	}
	for (int i=1;i<=n;i++)
	{
		que[i]=make_pair(l[i],make_pair(r[i],i));
	}
	sort(que+1,que+n+1);
	pos=1;
	for (int i=1;i<=k;i++)
	{
		while(pos<=n && que[pos].first<=i)
		{
			s.insert(que[pos].second);
			pos++;
		}
		if (s.empty()) out();
		if (s.begin()->first!=i)
		{
			ans[s.begin()->second]=i;
			s.erase(s.begin());
		}
		else
		{
			while(s.begin()->first==i)
			{
				ans[s.begin()->second]=i;
				s.erase(s.begin());
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}