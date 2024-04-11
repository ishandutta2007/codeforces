#include <iostream>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#define ll long long 
#define mp(a,b) make_pair(a,b)
using namespace std;
ll dist[100005];
int n,m;
vector <pair<int,int> > vec[100005];
bool visit[100005];
int trace[100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	int x,y,z;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>z;
		x--;
		y--;
		vec[x].push_back(mp(y,z));
		vec[y].push_back(mp(x,z));
	}
	memset(dist,0x3f,sizeof(dist));
	dist[0]=0;
	set <pair<ll,int> > squ;
	squ.insert(mp(0,0));
	while(squ.size())
	{
		ll cost=squ.begin()->first;
		int x=squ.begin()->second;
		squ.erase(squ.begin());
		if(x==n-1)
		{
			vector <int> vec;
			int now=x;
			vec.push_back(now);
			while(now!=0)
			{
				now=trace[now];
				vec.push_back(now);
			}
			reverse(vec.begin(),vec.end());
			for(auto x:vec)
			{
				cout<<x+1<<' ';
			}
			return 0;
		}
		if(visit[x]) continue;
		visit[x]=true;
		for(int i=0;i<vec[x].size();i++)
		{
			int u=vec[x][i].first;
			int c=vec[x][i].second;
			if(dist[u]>cost+c)
			{
				dist[u]=cost+c;
				trace[u]=x;
				squ.insert(mp(dist[u],u));
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}