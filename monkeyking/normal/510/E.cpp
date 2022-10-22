#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n;
int a[205];
vector <int> vec[205];
vector <vector<int> > res;
bool visit[205];

using namespace std;
struct Network
{
	void inline addEdge(int x,int y,int flow)
	{
		rev[x].push_back(edges[y].size());
		rev[y].push_back(edges[x].size());
		edges[x].push_back(make_pair(y,flow));
		edges[y].push_back(make_pair(x,0));
		dir[x].push_back(true);
		dir[y].push_back(false);
	}
	vector <pair<int,int> > *edges;
	vector <int> *rev;
	vector <bool> *dir;
	int src,dst;
	int n;
	void init(int _n)
	{
		n=_n;
		edges=new vector <pair<int,int> > [n+5];
		rev=new vector <int> [n+5];
		dir=new vector <bool> [n+5];
	}
	void feedEdges(vector <pair<int,int> > _edges[],vector <int> _rev[])
	{
		for(int i=0;i<n;i++)
		{
			edges[i]=_edges[i];
			rev[i]=_rev[i];
		}
	}
	void feedsd(int _src,int _dst)
	{
		src=_src;
		dst=_dst;
	}
};
namespace Dinic
{
	const int DistInf=1039074182;
	Network g;
	int *dist;
	bool *visit;
	queue <int> que;
	inline void init(Network &_g)
	{
		g=_g;
		dist=new int[g.n+5];
		visit=new bool[g.n+5];
	}
	inline bool bfs()
	{
		for(int i=0;i<g.n;i++)
		{
			dist[i]=DistInf;
		}
		dist[g.src]=0;
		que.push(g.src);
		while(que.size())
		{
			int x=que.front();
			que.pop();
			for(int i=0;i<g.edges[x].size();i++)
			{
				if(g.edges[x][i].second==0) continue;
				int u=g.edges[x][i].first;
				if(dist[u]>dist[x]+1)
				{
					dist[u]=dist[x]+1;
					que.push(u);
				}
			}
		}
		return (dist[g.dst]<DistInf);
	}
	int dfs(int x,int flow)
	{
		if(x==g.dst) return flow;
		int gain=0;
		for(int i=0;i<g.edges[x].size();i++)
		{
			int u=g.edges[x][i].first;
			if(dist[u]!=dist[x]+1) continue;
			if(g.edges[x][i].second==0) continue;
			int &rm=g.edges[x][i].second;
			int tf=dfs(u,min(rm,flow));
			rm-=tf;
			g.edges[u][g.rev[x][i]].second+=tf;
			flow-=tf;
			gain+=tf;
			if(flow==0) break;
		}
		return gain;
	}
	inline int dinic()
	{
		int flow=0;
		while(bfs())
		{
			int tf;
			while(tf=dfs(g.src,DistInf))
			{
				flow+=tf;
			}
		}
		return flow;
	}
};


Network g;

bool isprime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0) return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	g.init(n+2);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(isprime(a[i]+a[j]))
			{
				int x=i,y=j;
				if(a[i]&1) continue;
				g.addEdge(x,y,1);
			}
		}
	}
//	for(int i=0;i<g.n;i++)
//	{
//		for(int j=0;j<g.edges[i].size();j++)
//		{
//			int u=i,v=g.edges[i][j].first;
//			cout<<u<<'-'<<v<<' ';
//		}
//		cout<<endl;
//	}
//	for(int i=0;i<g.n;i++)
//	{
//		for(int j=0;j<g.rev[i].size();j++)
//		{
//			int u=i,id=g.rev[i][j];
//			cout<<u<<'-'<<id<<' ';
//		}
//		cout<<endl;
//	}
//	for(int i=0;i<g.n;i++)
//	{
//		for(int j=0;j<g.edges[i].size();j++)
//		{
//			int u=i,v=g.edges[i][j].first;
////			cout<<i<<' '<<g.rev[i][j]<<endl;
//			if(g.edges[v][g.rev[i][j]].first!=u)
//			{
//				cout<<u<<'-'<<v<<endl;
//			}
//		}
//	}
//	return 0;
	int s=n,t=n+1;
	int sumeven=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]&1) g.addEdge(i,t,2),sumeven++;else g.addEdge(s,i,2);
	}
	g.feedsd(s,t);
	Dinic::init(g);
	int f=Dinic::dinic();
	if(sumeven+sumeven!=n) over("Impossible");
	if(f!=n) over("Impossible");
//	for(int i=0;i<Dinic::g.n;i++)
//	{
//		for(int j=0;j<Dinic::g.edges[i].size();j++)
//		{
//			bool exp=(Dinic::g.edges[j][Dinic::g.rev[i][j]].first==i);
////			if(!exp) cout<<i<<'-'<<j<<endl;
//			if(i<n && Dinic::g.edges[i][j].first<n)
//			{
//				bool exp=(Dinic::g.edges[i][j].second+Dinic::g.edges[j][Dinic::g.rev[i][j]].second==1);
//				if(!exp) cout<<i<<' '<<Dinic::g.edges[i][j].first<<endl;
//			}//assert(Dinic::g.edges[i][j].second+Dinic::g.edges[j][Dinic::g.rev[i][j]].second==1);
//			if(Dinic::g.dir[i][j])
//			{
//				if(Dinic::g.edges[i][j].first==3)
//				{
//					cout<<""<<i<<' '<<3<<' '<<g.edges[i][j].second<<endl;
//				}
//				if(i==3)
//				{
//					cout<<""<<3<<' '<<g.edges[i][j].first<<' '<<g.edges[i][j].second<<endl;
//				}
//			}
//		}
//	}
//	for(int i=0;i<Dinic::g.edges[5].size();i++)
//	{
//		if(Dinic::g.edges[5][i].first==t) cout<<g.edges[5][i].second<<endl;
//	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<Dinic::g.edges[i].size();j++)
		{
			int u=i,v=g.edges[i][j].first,f=g.edges[i][j].second;
			if(u<n && v<n && Dinic::g.dir[i][j] && f==0)
			{
				vec[u].push_back(v);
				vec[v].push_back(u);
			}
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		for(auto x:vec[i])
//		{
//			cout<<i<<' '<<x<<endl;
//		}
//	}
	for(int i=0;i<n;i++)
	{
		if(visit[i]) continue;
		int now=i,par=-1;
		vector <int> v;
		do
		{
			v.push_back(now);
			visit[now]=true;
			int nxt;
			if(vec[now][0]==par) nxt=vec[now][1];else nxt=vec[now][0];
			par=now;
			now=nxt;
		}while(now!=i);
		res.push_back(v);
	}
	cout<<res.size()<<endl;
	for(auto x:res)
	{
		cout<<x	.size()<<' ';
		for(auto y:x)
		{
			cout<<y+1<<' ';
		}
		cout<<endl;
	}
	return 0;
}