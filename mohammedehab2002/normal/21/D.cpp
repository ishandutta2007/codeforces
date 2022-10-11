#include <iostream>
#include <vector>
#include <set>
using namespace std;
int deg[15],par[15],dist[(1<<15)];
vector<pair<pair<int,int>,int> > v;
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
	if (x!=y)
	par[x]=y;
}
int main()
{
	int n,m,sum=0;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	par[i]=i;
	while (m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v.push_back({{a-1,b-1},c});
		deg[a-1]++;
		deg[b-1]++;
		Union(a-1,b-1);
		sum+=c;
	}
	int l=0;
	for (int i=1;i<n;i++)
	{
		if (!deg[i])
		continue;
		if (find(i)!=find(l))
		{
			printf("-1");
			return 0;
		}
		l=i;
	}
	int st=0;
	for (int i=0;i<n;i++)
	{
		if (deg[i]%2)
		st|=(1<<i);
	}
	for (int mask=0;mask<(1<<n);mask++)
	dist[mask]=(1<<30);
	set<pair<int,int> > s;
	s.insert({0,st});
	dist[st]=0;
	while (!s.empty())
	{
		int d=(*s.begin()).first,mask=(*s.begin()).second;
		s.erase(s.begin());
		if (d>dist[mask])
		continue;
		if (!mask)
		{
			printf("%d",sum+d);
			return 0;
		}
		for (auto i:v)
		{
			int tmp=mask;
			tmp^=(1<<i.first.first);
			tmp^=(1<<i.first.second);
			if (d+i.second<dist[tmp])
			{
				dist[tmp]=d+i.second;
				s.insert({dist[tmp],tmp});
			}
		}
	}
}