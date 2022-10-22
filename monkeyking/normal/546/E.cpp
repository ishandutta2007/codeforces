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
int n,m;
vector <int> vec[105];
int a[105];
int b[105];
vector <pair<int,int> > edges[215];
vector <int> rev[215];
int res[105][105];

void inline addEdge(int x,int y,int flow)
{
	rev[x].push_back(rev[y].size());
	rev[y].push_back(rev[x].size());
	edges[x].push_back(mp(y,flow));
	edges[y].push_back(mp(x,0));
}

using namespace std;
struct Network
{
	vector <pair<int,int> > *edges;
	vector <int> *rev;
	int src,dst;
	int n;
	void init(int _n)
	{
		n=_n;
		edges=new vector <pair<int,int> > [n+5];
		rev=new vector <int> [n+5];
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
Network g;
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
			if(x<n && u<2*n)
			{
				res[x][u-n]+=tf;
			}
			else if(x<2*n && u<n)
			{
				res[x-n][u]-=tf;
			}
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

int main()
{
// 	freopen("input.txt","r",stdin);
	cin>>n>>m;
	int sa=0,sb=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sa+=a[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		sb+=b[i];
	}
	if(sa!=sb) over("NO");
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		addEdge(i,i+n,inf);
		for(int j=0;j<vec[i].size();j++)
		{
			addEdge(i,vec[i][j]+n,inf);
		}
	}
	int src=2*n,dst=2*n+1;
	for(int i=0;i<n;i++)
	{
		addEdge(src,i,a[i]);
	}
	for(int i=n;i<2*n;i++)
	{
		addEdge(i,dst,b[i-n]);
	}
	g.init(2*n+2);
	g.feedEdges(edges,rev);
	g.feedsd(2*n,2*n+1);
	Dinic::init(g);
	if(Dinic::dinic()==sa)
	{
		memset(res,0,sizeof(res));
		for(int i=n;i<2*n;i++)
		{
			for(auto x:Dinic::g.edges[i])
			{
				if(x.first>=n) continue;
				res[x.first][i-n]=x.second;
//				cout<<x.first<<' '<<i-n<<' '<<x.second<<endl;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			int s=0;
			for(int j=0;j<n;j++)
			{
				s+=res[i][j];
			}
			if(s!=a[i])
			{
				cout<<s<<' '<<a[i]<<endl;
				cout<<i<<endl;
				exit(0);
			}
		}
		cout<<"YES\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<res[i][j]<<' ';
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"NO\n";
	}
//	cout<<Dinic::dinic()<<endl;
	return 0;
}