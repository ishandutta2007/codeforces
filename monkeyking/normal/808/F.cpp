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
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
using namespace std;
bool isprime[200005];
vector <int> prime;
int n,k;
int power[1005],magic[1005],level[1005];
vector <pii> vOdd,vEven;

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
	const int DistInf=1069074182;
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
		int flow=0;
		while(bfs())
		{
			memset(cur,0,sizeof(int)*g.n);
			int tf=dfs(g.src,DistInf);
			flow+=tf;
		}
		return flow;
	}
};

bool check(int lvl)
{
	int max1=-1;
	vOdd.clear();
	vEven.clear();
	for(int i=0;i<n;i++)
	{
		if(level[i]>lvl) continue;
		if(magic[i]==1) chmax(max1,power[i]);
		else if(magic[i]&1)
		{
			vOdd.push_back(mp(magic[i],power[i]));
		}
		else
		{
			vEven.push_back(mp(magic[i],power[i]));
		}
	}
	if(max1!=-1) vOdd.push_back(mp(1,max1));
	Network g;
	g.init((int)vOdd.size()+(int)vEven.size()+2);
	g.feedsd((int)vOdd.size()+(int)vEven.size(),(int)vOdd.size()+(int)vEven.size()+1);
	for(int i=0;i<vOdd.size();i++)
	{
		for(int j=0;j<vEven.size();j++)
		{
			if(isprime[vOdd[i].first+vEven[j].first]) g.addEdge(i,j+(int)vOdd.size(),inf);
		}
	}
	int total=0;
	for(int i=0;i<vOdd.size();i++)
	{
		total+=vOdd[i].second;
		g.addEdge(g.src,i,vOdd[i].second);
	}
	for(int j=0;j<vEven.size();j++)
	{
		total+=vEven[j].second;
		g.addEdge((int)vOdd.size()+j,g.dst,vEven[j].second);
	}
	Dinic::init(g);
	int f=Dinic::dinic();
	return total-f>=k;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	for(int i=2;i<=100000*2;i++)
	{
		if(isprime[i]) prime.push_back(i);
		for(auto j:prime)
		{
			if(i*j>200000) break;
			isprime[i*j]=false;
			if(i%j==0) break;
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>power[i]>>magic[i]>>level[i];
	}
	int l=1,r=n,res=-1,mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))
		{
			res=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<res<<endl;
	return 0;
}