#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<pair<int,long long> > v[200005];
long long dist[200005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while (m--)
	{
		int a,b;
		long long c;
		scanf("%d%d%I64d",&a,&b,&c);
		v[a].push_back(make_pair(b,2LL*c));
		v[b].push_back(make_pair(a,2LL*c));
	}
	for (int i=1;i<=n;i++)
	scanf("%I64d",&dist[i]);
	for (int i=1;i<=n;i++)
	v[0].push_back(make_pair(i,dist[i]));
	set<pair<long long,int> > s;
	s.insert(make_pair(0,0));
	for (int i=1;i<=n;i++)
	dist[i]=(1LL<<60);
	while (!s.empty())
	{
		long long d=(*s.begin()).first;
		int node=(*s.begin()).second;
		s.erase(s.begin());
		if (d>dist[node])
		continue;
		for (int i=0;i<v[node].size();i++)
		{
			if (dist[node]+v[node][i].second<dist[v[node][i].first])
			{
				dist[v[node][i].first]=dist[node]+v[node][i].second;
				s.insert(make_pair(dist[v[node][i].first],v[node][i].first));
			}
		}
	}
	for (int i=1;i<=n;i++)
	printf("%I64d ",dist[i]);
}