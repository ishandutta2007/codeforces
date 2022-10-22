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
int n,b,q;
pair<int,int> hints[10005];
int p[5];
vector <pair<pii,int> > vec;

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
		edges=new vector <pair<int,int> > [n];
		rev=new vector <int> [n];
		dir=new vector <bool> [n];
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
	void clear()
	{
		for(int i=0;i<n;i++)
		{
			edges[i].clear();
			rev[i].clear();
			dir[i].clear();
		}
	}
};
namespace Dinic
{
	const int DistInf=1039074182;
	Network g;
	int *dist;
	bool *visit;
	int *cur;
	queue <int> que;
	inline void init(Network &_g)
	{
		g=_g;
		dist=new int[g.n+5];
		visit=new bool[g.n+5];
		cur=new int[g.n+5];
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
//		if(cur[x]!=0)
//		{
//			cout<<x<<' '<<cur[x]<<endl;
//		}
		for(int &i=cur[x];i<g.edges[x].size();i++)
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
		memset(cur,0,sizeof(int)*g.n);
		int flow=0;
		while(bfs())
		{
			memset(cur,0,sizeof(int)*g.n);
			int tf;
			tf=dfs(g.src,DistInf);
//			while(tf=dfs(g.src,DistInf))
//			{
				flow+=tf;
//			}
		}
		return flow;
	}
};
Network g;

int calc(int l,int r,int rem)
{
	int res=0;
	for(int i=l;i<=r;i++)
	{
		if(i%5==rem) res++;
	}
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>b>>q;
	p[0]=p[1]=p[2]=p[3]=p[4]=n/5;
	int x,y;
	for(int i=0;i<q;i++)
	{
		cin>>x>>y;
		hints[i].first=x;
		hints[i].second=y;
	}
	sort(hints,hints+q);
	vec.push_back(mp(mp(1,hints[0].first),hints[0].second));
	for(int i=0;i<q-1;i++)
	{
		vec.push_back(mp(mp(hints[i].first+1,hints[i+1].first),hints[i+1].second-hints[i].second));
	}
	vec.push_back(mp(mp(hints[q-1].first+1,b),n-hints[q-1].second));
	int len=0;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i].second<0) over("unfair");
//		cout<<vec[i].first.second-vec[i].first.first+1<<' '<<vec[i].second<<endl;
		if(vec[i].first.second-vec[i].first.first+1<vec[i].second) over("unfair");
		if(vec[i].first.second-vec[i].first.first+1==1 && vec[i].second==1) p[vec[i].first.first%5]--;
		if(vec[i].first.second-vec[i].first.first+1!=0 && vec[i].first.second-vec[i].first.first+1!=1) vec[len++]=vec[i];
	}
	vec.erase(vec.begin()+len,vec.end());
//	for(int i=0;i<len;i++)
//	{
//		cout<<vec[i].first.first<<' '<<vec[i].first.second<<' '<<vec[i].second<<endl;
//	}
	g.init(1+5+len*6+1);
	int src=5+len*6,dst=src+1;
	g.feedsd(src,dst);
	for(int i=0;i<5;i++)
	{
		g.addEdge(src,i,p[i]);
	}
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<5;j++)
		{
			g.addEdge(j,i*6+5+5,calc(vec[i].first.first,vec[i].first.second,j));
//			g.addEdge(j,i*6+j+5,calc(vec[i].first.first,vec[i].first.second,j));
//			g.addEdge(i*6+j+5,i*6+5+5,inf);
		}
		g.addEdge(i*6+5+5,dst,vec[i].second);
	}
	int full=0;
	for(int i=0;i<5;i++)
	{
		if(p[i]<0) over("unfair");
		full+=p[i];
	}
	Dinic::init(g);
	int flow=Dinic::dinic();
	if(flow==full)
	{
		cout<<"fair"<<endl;
	}
	else
	{
		cout<<"unfair"<<endl;
	}
	return 0;
}