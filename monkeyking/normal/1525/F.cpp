//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/network>
//using namespace std;
//int n,m,k;
//Network g;
//Dinic d;
//vector<int> ops;
//int a[55],b[55];
//int c[55],key[55];
//int ct;
//vector<int> edges[55];
//
//pair<ll,vector<int> > solve()
//{
//	memset(key,0,sizeof(key));
//	memset(c,0,sizeof(c));
//	int preMin=inf;
//	for(int i=0;i<k;i++)
//	{
//		if(b[i]<preMin)
//		{
//			key[i]=1;
//			preMin=b[i];
//		}
//	}
//	// for(int i=0;i<k;i++)
//	// {
//	// 	debug(b[i],key[i]);
//	// 	cout<<b[i]<<' '<<key[i]<<endl;
//	// }
//	// cout<<endl;
//	for(int i=0;i<k;i++)
//	{
//		if((i+1)>=ct)
//		{
//			for(int j=i;j>=0;j--)
//			{
//				if(key[j])
//				{
//					c[j]++;
//					break;
//				}
//			}
//		}
//	}
//	ll res=0;
//	for(int i=0;i<n;i++)
//	{
//		res+=a[i];
//	}
//	for(int i=0;i<n;i++)
//	{
//		res-=1LL*c[i]*b[i];
//	}
//	vector<int> v;
//	int s=0;
//	for(int i=0;i<k;i++)
//	{
//		for(int j=0;j<c[i];j++,s++)
//		{
//			v.push_back(ops[s]);
//		}
//		v.push_back(0);
//	}
//	return mp(res,v);
//}
//
//
//void getMinCut()
//{
//	auto has=[](int x)->bool{for(auto y:ops) if(y==x) return 1;return 0;};
//	// debug(ops);
//	for(int tc=ct+1;tc<=n;tc++)
//	{
//		for(int del=-n;del<=n;del++)
//		{
//			if(del==0) continue;
//			if(has(del)) continue;
//			Network g;
//			Dinic d;
//			int src=n*2,dst=src+1;
//			g.init(dst+1);
//			g.feedsd(src,dst);
//			for(int i=0;i<n;i++)
//			{
//				for(auto j:edges[i])
//				{
//					// debug(i,j+n);
//					g.addEdge(i,j+n,1);
//				}
//			}
//			// debug(del);
//			for(int i=0;i<n;i++)
//			{
//				if(!(has(i+1) || i+1==del)) g.addEdge(src,i,1);
//				if(!(has(-i-1) || -i-1==del)) g.addEdge(i+n,dst,1);
//			}
//			d.init(g);
//			// int wtf=n-d.dinic();
//			// debug(wtf);
//			if(n-d.dinic()==tc)
//			{
//				ops.push_back(del);
//				break;
//			}
//		}
//	}
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>n>>m>>k;
//	int src=n*2,dst=src+1;
//	g.init(dst+1);
//	g.feedsd(src,dst);
//	for(int i=0;i<m;i++)
//	{
//		int x,y;
//		scanf("%d%d",&x,&y);
//		x--;
//		y--;
//		edges[x].push_back(y);
//		g.addEdge(x,y+n,1);
//	}
//	for(int i=0;i<k;i++)
//	{
//		cin>>a[i]>>b[i];
//	}
//	for(int i=0;i<n;i++)
//	{
//		g.addEdge(src,i,1);
//		g.addEdge(i+n,dst,1);
//	}
//	d.init(g);
//	ct=n-d.dinic();
//	// debug(ct);
//	getMinCut();
//	// for(int i=0;i<t;i++) ops.push_back(0);
//	// debug(ops,ct);
//	pair<ll,vector<int> > res=solve();
//	for(int i=0;i<n;i++)
//	{
//		int t=0;swap(b[i],t);
//		auto ans=solve();
//		ans.first-=a[i];
//		chmax(res,ans);
//		swap(b[i],t);
//	}
//	cout<<res.second.size()<<endl;
//	for(auto x:res.second)
//	{
//		cout<<x<<' ';
//	}
//	cout<<endl;
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
#define mt make_tuple
#define ll long long 
#define ull unsigned long long
#define pii pair<int,int>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define quickcin ios_base::sync_with_stdio(false);
#ifdef __TAKE_MOD
int mod;
#else
#ifdef __TAKE_CONST_MOD
const int mod=__TAKE_CONST_MOD;
#else
const int mod=1000000007;
#endif
#endif
const int gmod=3;
const int inf=1039074182;
#ifdef __TAKE_CONST_EPS
const double eps=__TAKE_CONST_EPS;
#else
const double eps=1e-9;
#endif
const double pi=3.141592653589793238462643383279;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;
#endif
#ifndef _SELF_DEBUG
#define _SELF_DEBUG 1
#ifndef _SELF_OPERATOR
#define _SELF_OPERATOR 1
using namespace std;
template <typename T>
ostream & operator<<(ostream &cout, const vector<T> &vec)
{
	cout << "{";
	for (int i = 0; i < (int)vec.size(); i++)
	{
		cout << vec[i];
		if (i != (int)vec.size() - 1)
			cout << ',';
	}
	cout << "}";
	return cout;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &cout, pair<T1, T2> p)
{
	cout << "(" << p.first << ',' << p.second << ")";
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, set<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T, typename T2>
ostream &operator<<(ostream &cout, multiset<T, T2> s)
{
	vector<T> t;
	for (auto x : s)
		t.push_back(x);
	cout << t;
	return cout;
}

template <typename T>
ostream &operator<<(ostream &cout, queue<T> q)
{
	vector<T> t;
	while (q.size())
	{
		t.push_back(q.front());
		q.pop();
	}
	cout << t;
	return cout;
}

template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &cout, map<T1, T2, T3> m)
{
	for (auto &x : m)
	{
		cout << "Key: " << x.first << ' ' << "Value: " << x.second << endl;
	}
	return cout;
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x,const pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
}
template <typename T1,typename T2>
pair<T1,T2> operator + (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return make_pair(x.first+y.first,x.second+y.second);
}

template <typename T1,typename T2>
pair<T1,T2> operator - (const pair<T1,T2> &x,const pair<T1,T2> &y)
{
	return mp(x.first-y.first,x.second-y.second);
}

template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> x)
{
	return make_pair(-x.first, -x.second);
}

template <typename T>
vector<vector<T>> operator~(vector<vector<T>> vec)
{
	vector<vector<T>> v;
	int n = vec.size(), m = vec[0].size();
	v.resize(m);
	for (int i = 0; i < m; i++)
	{
		v[i].resize(n);
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v[i][j] = vec[j][i];
		}
	}
	return v;
}
#endif
#include <sstream>
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
	for(int i=(int)vec.size();i<len;i++)
	{
		putchar('0');
	}
	for(size_t i=0;i<vec.size();i++)
	{
		std::cout<<vec[i];
	}
	std::cout<<' ';
}
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#endif
using namespace std;
struct Network
{
	void inline addEdge(int x,int y,int flow)
	{
		assert(x>=0 && y>=0 && x<n && y<n);
		assert(flow>=0);
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
int n,m,k;
Network g;
Dinic d;
vector<int> ops;
int a[55],b[55];
int c[55],key[55];
int ct;
vector<int> edges[55];

pair<ll,vector<int> > solve()
{
	memset(key,0,sizeof(key));
	memset(c,0,sizeof(c));
	int preMin=inf;
	for(int i=0;i<k;i++)
	{
		if(b[i]<preMin)
		{
			key[i]=1;
			preMin=b[i];
		}
	}
	// for(int i=0;i<k;i++)
	// {
	// 	debug(b[i],key[i]);
	// 	cout<<b[i]<<' '<<key[i]<<endl;
	// }
	// cout<<endl;
	for(int i=0;i<k;i++)
	{
		if((i+1)>=ct)
		{
			for(int j=i;j>=0;j--)
			{
				if(key[j])
				{
					c[j]++;
					break;
				}
			}
		}
	}
	ll res=0;
	for(int i=0;i<n;i++)
	{
		res+=a[i];
	}
	for(int i=0;i<n;i++)
	{
		res-=1LL*c[i]*b[i];
	}
	vector<int> v;
	int s=0;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<c[i];j++,s++)
		{
			v.push_back(ops[s]);
		}
		v.push_back(0);
	}
	return mp(res,v);
}


void getMinCut()
{
	auto has=[](int x)->bool{for(auto y:ops) if(y==x) return 1;return 0;};
	// debug(ops);
	for(int tc=ct+1;tc<=n;tc++)
	{
		for(int del=-n;del<=n;del++)
		{
			if(del==0) continue;
			if(has(del)) continue;
			Network g;
			Dinic d;
			int src=n*2,dst=src+1;
			g.init(dst+1);
			g.feedsd(src,dst);
			for(int i=0;i<n;i++)
			{
				for(auto j:edges[i])
				{
					// debug(i,j+n);
					g.addEdge(i,j+n,1);
				}
			}
			// debug(del);
			for(int i=0;i<n;i++)
			{
				if(!(has(i+1) || i+1==del)) g.addEdge(src,i,1);
				if(!(has(-i-1) || -i-1==del)) g.addEdge(i+n,dst,1);
			}
			d.init(g);
			// int wtf=n-d.dinic();
			// debug(wtf);
			if(n-d.dinic()==tc)
			{
				ops.push_back(del);
				break;
			}
		}
	}
}

int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>n>>m>>k;
	int src=n*2,dst=src+1;
	g.init(dst+1);
	g.feedsd(src,dst);
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		edges[x].push_back(y);
		g.addEdge(x,y+n,1);
	}
	for(int i=0;i<k;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		g.addEdge(src,i,1);
		g.addEdge(i+n,dst,1);
	}
	d.init(g);
	ct=n-d.dinic();
	// debug(ct);
	getMinCut();
	// for(int i=0;i<t;i++) ops.push_back(0);
	// debug(ops,ct);
	pair<ll,vector<int> > res=solve();
	for(int i=0;i<n;i++)
	{
		int t=0;swap(b[i],t);
		auto ans=solve();
		ans.first-=a[i];
		chmax(res,ans);
		swap(b[i],t);
	}
	cout<<res.second.size()<<endl;
	for(auto x:res.second)
	{
		cout<<x<<' ';
	}
	cout<<endl;
	return 0;
}