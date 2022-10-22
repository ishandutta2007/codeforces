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
#include <string.h>
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
		src=dst=-1;
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
		src=dst=-1;
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
	inline int countflow()
	{
		int flow=0;
		for(auto x:g.edges[g.dst])
		{
			flow+=x.second;
		}
		return flow;
	}
	int delflow(int x,int y,int flow)
	{
		int _src=g.src;
		int _dst=g.dst;
		g.feedsd(y,x);
		bfs();
		memset(cur,0,sizeof(int)*g.n);
		int f=dfs(y,flow);
		g.feedsd(_src,_dst);
		return f;
	}
	int* getrmflow(int x,int y)
	{
		for(auto &e:g.edges[x])
		{
			if(e.first==y) return &e.second;
		}
	}
};

#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
int n;
string s;
Network g;
int num[256];
int a[64];
int type[100005];

struct Name
{
	int num[256];
	int a[64];
	Network g;
	string res;
	int len;
	int src,dst;
	inline void build()
	{
		src=6+64,dst=src+1;
		g.clear();
		g.feedsd(src,dst);
		for(int i=0;i<6;i++)
		{
			g.addEdge(src,i,num['a'+i]);
		}
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<64;j++)
			{
				if((1<<i) & j) g.addEdge(i,6+j,inf);
			}
		}
		for(int i=0;i<64;i++)
		{
			g.addEdge(6+i,dst,a[i]);
		}
	}
	inline void push_back(char c,int type)
	{
		res+=c;
		num[c]--;
		a[type]--;
	}
	inline void pop_back(char c,int type)
	{
		res.pop_back();
		num[c]++;
		a[type]++;
	}
	inline bool check(char c,int type,int rk=-1)
	{
//		cout<<c<<' '<<type<<' '<<rk<<endl;
		int i=c-'a',j=type+6;
		int flow=Dinic::delflow(i,j,1);
		if(flow)
		{
			assert(Dinic::delflow(src,i,1));
			assert(Dinic::delflow(j,dst,1));
			int *p=Dinic::getrmflow(src,i),*q=Dinic::getrmflow(j,dst);
			assert((*p));
			assert((*q));
			(*p)--;
			(*q)--;
			res.push_back(c);
			num[c]--;
			a[type]--;
			return true;
		}
		return false;
	}
};

int gettype(string x)
{
	if(x=="") return 63;
	int mask=0;
	for(int j=0;j<x.size();j++)
	{
		mask|=(1<<(x[j]-'a'));
	}
	return mask;
}

int main()
{
//	freopen("input.txt","r",stdin);
	quickcin;
	cin>>s;
	n=s.size();
	int src=6+64,dst=src+1;
	g.init(2+6+64);
	g.feedsd(src,dst);
	for(int i=0;i<n;i++)
	{
		num[s[i]]++;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int pi;
		cin>>pi;
		string x;
		cin>>x;
		pi--;
		int mask=0;
		for(int j=0;j<x.size();j++)
		{
			mask|=(1<<(x[j]-'a'));
		}
		a[mask]++;
		type[pi]=mask;
	}
	for(int i=0;i<n;i++)
	{
		if(type[i]==0) type[i]=63;
	}
	a[63]=n;
	for(int i=0;i<63;i++)
	{
		a[63]-=a[i];
	}
	Name name;
	for(int i=0;i<256;i++)
	{
		name.num[i]=num[i];
	}
	for(int i=0;i<64;i++)
	{
		name.a[i]=a[i];
	}
	for(int i=0;i<64;i++)
	{
		name.g=g;
	}
	name.len=n;
	name.res="";
	name.build();
	Dinic::init(name.g);
	if(Dinic::dinic()!=n) over("Impossible");
	for(int i=0;i<n;i++)
	{
//		cout<<i<<' '<<Dinic::countflow()<<endl;
		for(char c='a';c<='z';c++)
		{
			if(name.num[c]==0) continue;
			if(!(type[i] & (1<<(c-'a')))) continue;
			if(name.check(c,type[i],i)) break;
		}
	}
	cout<<name.res<<endl;
	return 0;
}