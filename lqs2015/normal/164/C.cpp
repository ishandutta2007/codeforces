#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
map<int,int> mp;
int n,k,S[2222],T[2222],c[2222],cnt,p[2222],dist[2222],s,t,h[2222],pre[2222],prepos[2222];
struct edge
{
	int to,cap,val,rev;
};
vector<edge> g[2222];
void mcf()
{
	int f=k;
	while(f>0)
	{
		fill(dist+1,dist+cnt+1,1e9);
		priority_queue<pair<int,int> > pq;
		pq.push(make_pair(0,s));
		dist[s]=0;
		while(!pq.empty())
		{
			int x=pq.top().second;pq.pop();
			for (int i=0;i<g[x].size();i++)
			{
				edge e=g[x][i];
				if (e.cap>0 && dist[e.to]>dist[x]+e.val+h[x]-h[e.to])
				{
					dist[e.to]=dist[x]+e.val+h[x]-h[e.to];
					pre[e.to]=x;
					prepos[e.to]=i;
					pq.push(make_pair(-dist[e.to],e.to)); 
				}
			}
		}
		if (dist[t]==1e9) return;
		for (int i=1;i<=cnt;i++) h[i]+=dist[i];
		f--;
		for (int i=t;i!=s;i=pre[i])
		{
			g[pre[i]][prepos[i]].cap--;
			g[i][g[pre[i]][prepos[i]].rev].cap++;
		}
	}
}
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>S[i]>>T[i]>>c[i];
		T[i]+=S[i];
		mp[T[i]]=mp[S[i]]=1;
	}
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		mp[it->first]=++cnt;
	}
	for (int i=1;i<cnt;i++)
	{
		g[i].push_back((edge){i+1,1e9,0,g[i+1].size()});
		g[i+1].push_back((edge){i,0,0,g[i].size()-1}); 
	}
	for (int i=1;i<=n;i++)
	{
		p[i]=g[mp[S[i]]].size();
		g[mp[S[i]]].push_back((edge){mp[T[i]],1,-c[i],g[mp[T[i]]].size()});
		g[mp[T[i]]].push_back((edge){mp[S[i]],0,c[i],g[mp[S[i]]].size()-1});
	}
	s=1;t=cnt;
	mcf();
	for (int i=1;i<=n;i++)
	{
		if (g[mp[S[i]]][p[i]].cap) cout<<0<<" ";
		else cout<<1<<" ";
	}
	cout<<endl;
	return 0;
}