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
#include <bitset>

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

using namespace std;
namespace factorization
{
	vector <int> getfactors(int x)
	{
		vector <int> vec;
		for(int i=1;i*i<=x;i++)
		{
			if(x%i==0)
			{
				vec.push_back(i);
				if(i!=x/i) vec.push_back(x/i);
			}
		}
		sort(vec.begin(),vec.end());
		return vec;
	}
	vector <pair<int,int> > factorize(int x)
	{
		vector <pair<int,int> > vec;
		int nx=x;
		for(int i=2;i*i<=x;i++)
		{
			if(nx%i==0)
			{
				int s=0;
				while(nx%i==0)
				{
					s++;
					nx/=i;
				}
				vec.push_back(make_pair(i,s));
			}
		}
		if(nx!=1) vec.push_back(make_pair(nx,1));
		return vec;
	}
};
using namespace factorization;

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
int n,q;
vector <pair<int,int> > a[105];
vector <int> id[105];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>q;
	int nn=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a[i]=factorize(x);
		for(auto u:a[i])
		{
			id[i].push_back(nn++);
		}
	}
	Network g;
	g.init(nn+2);
	int x,y;
	while(q--)
	{
		cin>>x>>y;
		x--;
		y--;
		if(x&1) swap(x,y);
		for(int i=0;i<a[x].size();i++)
		{
			for(int j=0;j<a[y].size();j++)
			{
				if(a[x][i].first==a[y][j].first)
				{
					g.addEdge(id[x][i],id[y][j],inf);
				}
			}
		}
	}
	int s=nn,t=nn+1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			if(i&1)
			{
				g.addEdge(id[i][j],t,a[i][j].second);
			}
			else
			{
				g.addEdge(s,id[i][j],a[i][j].second);
			}
		}
	}
	g.feedsd(s,t);
	Dinic::init(g);
	cout<<Dinic::dinic()<<endl;
	return 0;
}