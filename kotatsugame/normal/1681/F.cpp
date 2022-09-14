#include<iostream>
#include<vector>
#include<map>
using namespace std;
int N;
vector<pair<int,pair<int,int> > >G[5<<17];
int DOWN[5<<17];
int c[5<<17];
map<int,int>ret;
void dfs1(int u,int p)
{
	map<int,int>now;
	c[u]=1;
	for(pair<int,pair<int,int> >e:G[u])
	{
		int v=e.first;
		if(v==p)continue;
		dfs1(v,u);
		int col=e.second.first,eid=e.second.second;
		DOWN[eid]=ret[col];
		ret[col]=c[v];
		if(now.size()<ret.size())swap(now,ret);
		for(pair<int,int>p:ret)now[p.first]+=p.second;
		c[u]+=c[v];
	}
	ret.swap(now);
}
long long ans=0;
int cnt[5<<17];
void dfs2(int u,int p)
{
	for(pair<int,pair<int,int> >e:G[u])
	{
		int v=e.first;
		if(v==p)continue;
		int col=e.second.first,eid=e.second.second;
		ans+=(long long)(c[v]-DOWN[eid])*(N-c[v]-(cnt[col]-c[v]));
		int prv=cnt[col];
		cnt[col]=DOWN[eid]+(N-c[v]);
		dfs2(v,u);
		cnt[col]=prv;
	}
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N-1;i++)
	{
		int u,v,x;cin>>u>>v>>x;
		u--,v--;
		G[u].push_back(make_pair(v,make_pair(x,i)));
		G[v].push_back(make_pair(u,make_pair(x,i)));
	}
	dfs1(0,-1);
	for(pair<int,int>p:ret)cnt[p.first]+=p.second;
	dfs2(0,-1);
	cout<<ans<<endl;
}