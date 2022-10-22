//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/network>
//using namespace std;
//int n,m;
//vector <pair<int,pii> > edges;
//
//bool check(int len)
//{
//    Network g;
//    g.init(n+n+2);
//    int src=n+n,dst=n+n+1;
//    g.feedsd(src,dst);
//    for(int i=0;i<n;i++)
//    {
//        g.addEdge(src,i,1);
//    }
//    for(int i=0;i<n;i++)
//    {
//        g.addEdge(i+n,dst,1);
//    }
//    for(int i=0;i<len;i++)
//    {
//        auto &e=edges[i];
//        int x,y;
//        x=e.second.first;
//        y=e.second.second;
//        g.addEdge(x,y+n,1);
//    }
//    Dinic d;
//    d.init(g);
//    int f=d.dinic();
//    return (f==n);
//}
//
//int main()
//{
//	freopen("input.txt","r",stdin);
//    cin>>n>>m;
//    for(int i=0;i<m;i++)
//    {
//        int x,y,z;
//        scanf("%d%d%d",&x,&y,&z);
//        x--;
//        y--;
//        edges.push_back(mp(z,mp(x,y)));
//    }
//    sort(all(edges));
//    int l=1,r=m,res=-1,mid;
//    while(l<=r)
//    {
//        mid=(l+r)>>1;
//        if(check(mid))
//        {
//            res=mid;
//            r=mid-1;
//        }
//        else
//        {
//            l=mid+1;
//        }
//    }
//    cout<<(res==-1?-1:edges[res-1].first)<<endl;
//	return 0;
//}

//substituted with C++ Inliner
#ifndef _SELF_UTILITY
#define _SELF_UTILITY 1
#include <numeric>
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
#include <time.h>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
const int mod=1e9+7;
const int gmod=2;
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
#endif
using namespace std;
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator << (ostream& cout,vector<T> vec)
{
	cout<<"{";
	for(int i=0;i<(int)vec.size();i++)
	{
		cout<<vec[i];
		if(i!=(int)vec.size()-1) cout<<',';
	}
	cout<<"}";
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream & cout,pair<T1,T2> p)
{
	cout<<"("<<p.first<<','<<p.second<<")";
	return cout;
}

template <typename T,typename T2>
ostream & operator << (ostream & cout,set <T,T2> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream & cout,multiset <T> s)
{
	vector <T> t;
	for(auto x:s) t.push_back(x);
	cout<<t;
	return cout;
}

template <typename T>
ostream & operator << (ostream &cout,queue <T> q)
{
	vector <T> t;
	while(q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout<<t;
	return cout;
}

template <typename T1,typename T2>
ostream & operator << (ostream &cout,map <T1,T2> m)
{
	for(auto &x:m)
	{
		cout<<"Key: "<<x.first<<' '<<"Value: "<<x.second<<endl;
	}
	return cout;
}

template <typename T>
T operator * (vector <T> v1,vector <T> v2)
{
	assert(v1.size()==v2.size());
	int n=v1.size();
	T res=0;
	for(int i=0;i<n;i++)
	{
		res+=v1[i]*v2[i];
	}
	return res;
}

template <typename T1,typename T2>
pair<T1,T2> operator + (pair<T1,T2> x,pair<T1,T2> y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
void operator += (pair<T1,T2> &x,pair<T1,T2> y)
{
	x.first+=y.first;
	x.second+=y.second;
}

template <typename T1,typename T2>
pair<T1,T2> operator - (pair<T1,T2> x)
{
	return make_pair(-x.first,-x.second);
}

template <typename T>
vector<vector<T> > operator ~ (vector<vector <T> > vec)
{
	vector <vector<T> > v;
	int n=vec.size(),m=vec[0].size();
	v.resize(m);
	for(int i=0;i<m;i++)
	{
		v[i].resize(n);
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[i][j]=vec[j][i];
		}
	}
	return v;
}
#endif

void print0x(int x)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	std::reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}

template <typename T>
void print0x(T x,int len)
{
	std::vector <int> vec;
	while(x)
	{
		vec.push_back(x&1);
		x>>=1;
	}
	reverse(vec.begin(),vec.end());
	for(int i=vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(int i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
#endif
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
	void inline addEdge(int x,int y,int flow,int id)
	{
		edgeID[x].push_back(id);
		edgeID[y].push_back(id);
		addEdge(x,y,flow);
	}
	vector <int> *edgeID=nullptr;
	vector <pair<int,int> > *edges=nullptr;
	vector <int> *rev=nullptr;
	vector <int> *dir=nullptr;
	int src,dst;
	int n;
	void init(int _n)
	{
		n=_n;
		edges=new vector <pair<int,int> > [n];
		rev=new vector <int> [n];
		edgeID=new vector <int> [n];
		dir=new vector <int> [n];
		src=dst=-1;
	}
	void operator = (const Network &g)
	{
		if(edges) delete [] edges;
		if(rev) delete [] rev;
		if(edgeID) delete [] edgeID;
		if(dir) delete [] dir;
		n=g.n;
		src=g.src;
		dst=g.dst;
		edges=new vector <pair<int,int> > [n];
		rev=new vector <int> [n];
		edgeID=new vector <int> [n];
		dir=new vector <int> [n];
		for(int i=0;i<n;i++)
		{
			edgeID[i]=g.edgeID[i];
			rev[i]=g.rev[i];
			edges[i]=g.edges[i];
			dir[i]=g.dir[i];
		}
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
			edgeID[i].clear();
		}
		src=dst=-1;
	}
	~Network()
	{
		if(edges) delete [] edges;
		if(rev) delete [] rev;
		if(dir) delete [] dir;
		if(edgeID) delete [] edgeID;
	}
};

struct Dinic
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
	~Dinic()
	{
		delete [] dist;
		delete [] visit;
		delete [] cur;
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
			for(int i=0;i<(int)g.edges[x].size();i++)
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
		for(int &i=cur[x];i<(int)g.edges[x].size();i++)
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

using namespace std;
int n,m;
vector <pair<int,pii> > edges;

bool check(int len)
{
    Network g;
    g.init(n+n+2);
    int src=n+n,dst=n+n+1;
    g.feedsd(src,dst);
    for(int i=0;i<n;i++)
    {
        g.addEdge(src,i,1);
    }
    for(int i=0;i<n;i++)
    {
        g.addEdge(i+n,dst,1);
    }
    for(int i=0;i<len;i++)
    {
        auto &e=edges[i];
        int x,y;
        x=e.second.first;
        y=e.second.second;
        g.addEdge(x,y+n,1);
    }
    Dinic d;
    d.init(g);
    int f=d.dinic();
    return (f==n);
}

int main()
{
//	freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        x--;
        y--;
        edges.push_back(mp(z,mp(x,y)));
    }
    sort(all(edges));
    int l=1,r=m,res=-1,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
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
    cout<<(res==-1?-1:edges[res-1].first)<<endl;
	return 0;
}