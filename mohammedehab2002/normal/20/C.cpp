#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
vector<pair<int,int> > v[100005];
int par[100005];
long long dist[100005];
void solve(int node)
{
	if (node!=1)
	solve(par[node]);
	printf("%d ",node);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	set<pair<int,int> > q;
	for (int i=2;i<=n;i++)
	dist[i]=(1LL<<62);
	q.insert(make_pair(0,1));
	while (!q.empty())
	{
		int u=(*q.begin()).second;
		q.erase(q.begin());
		for (int i=0;i<v[u].size();i++)
		{
			if (dist[u]+v[u][i].second<dist[v[u][i].first])
			{
				dist[v[u][i].first]=dist[u]+v[u][i].second;
				par[v[u][i].first]=u;
				q.insert(make_pair(dist[u]+v[u][i].second,v[u][i].first));
			}
		}
	}
	if (par[n])
	solve(n);
	else
	puts("-1");
}