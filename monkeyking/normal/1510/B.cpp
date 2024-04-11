//Original Code:
//#define CostType long long 
//#include <self/utility>
//#include <self/debug>
//#include <self/mcmf>
//using namespace std;
//NetworkWithCost g;
//MCMF d;
//int k,n;
//vector<int> v;
//vector<int> edges[2005];
//int nxt[2005];
//int head[2005];
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	quickcin;
//	cin>>k>>n;
//	g.init(n+n+2);
//	int src=n+n,dst=n+n+1;
//	g.feedsd(src,dst);
//	int cost=0;
//	for(int i=0;i<n;i++)
//	{
//		string str;cin>>str;
//		int s=0;
//		for(int i=0;i<k;i++)
//		{
//			if(str[i]=='1') s|=(1<<i);
//		}
//		v.push_back(s);
//		int c=__builtin_popcount(s);
//		g.addEdge(src,i,1,0);//cost+=c+1;
//		g.addEdge(i,dst,1,c+1);
//		// g.addEdge(i,dst,1,c+1);
//		// g.addEdge(i,dst,1,0);
//		g.addEdge(i+n,dst,1,0);
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			if((v[i]&v[j])==v[i] && i!=j) g.addEdge(i,j+n,1,0);
//		}
//	}
//	d.init(g);
//	pair<int,ll> f=d.run();
//	assert(f.first==n);
//	// cout<<f.second<<endl;
//	cout<<cost+f.second-1<<endl;
//	memset(nxt,-1,sizeof(nxt));
//	memset(head,1,sizeof(head));
//	for(int i=0;i<n;i++)
//	{
//		for(auto &e:d.g.edges[i])
//		{
//			if(!e.dir || e.vertex-n>=n || e.flow==1) continue;
//			// debug(i,e.vertex-n);
//			nxt[i]=e.vertex-n;
//			head[e.vertex-n]=false;
//		}
//	}
//	// for(int i=0;i<n;i++){
//	// 	cout<<head[i]<<' ';
//	// }
//	// cout<<endl;
//	// cout<<nxt[0]<<endl;
//	int fst=true;
//	for(int i=0;i<n;i++)
//	{
//		if(head[i])
//		{
//			if(!fst) cout<<"R ";
//			int now=0;
//			int id=i;
//			while(id!=-1)
//			{
//				while(now!=v[id])
//				{
//					int c=__builtin_ctz(v[id]^now);
//					cout<<c<<' ';
//					now|=(1<<c);
//				}
//				id=nxt[id];
//			}
//			fst=false;
//		}
//	}
//	cout<<endl;
//	return 0;
//}

//substituted with C++ Inliner
#define CostType long long 
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
const double eps=1e-9;
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
ostream &operator<<(ostream &cout, vector<T> vec)
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

#ifndef CostType
#define CostType int
#endif
struct NetworkWithCost
{
	struct Edge
	{
		int vertex;
		int flow;
		CostType cost;
		int inv;
		int dir;
	};
	vector <Edge> *edges;
	inline void addEdge(int x,int y,int limit,CostType cost)
	{
		Edge edge;
		edge.cost=cost;
		edge.flow=limit;
		edge.vertex=y;
		edge.inv=(int)edges[y].size();
		edge.dir=true;
		edges[x].push_back(edge);
		edge.vertex=x;
		edge.flow=0;
		edge.cost=-cost;
		edge.inv=(int)edges[x].size()-1;
		edge.dir=false;
		edges[y].push_back(edge);
	}
	int src,dst;
	int n;
	void init(int _n)
	{
		n=_n;
		edges=new vector <Edge> [n];
		src=dst=-1;
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
		}
		src=dst=-1;
	}
};

namespace MCMFSpace
{
	void operator += (pii &a,const pii &b)
	{
		a.first+=b.first;
		a.second+=b.second;
	}
}

struct MCMF
{
	const CostType DistInf=numeric_limits<CostType>::max()/2-1e7;
	NetworkWithCost g;
	CostType *dist;
	bool *visit;
	int *cur;
	queue <int> que;
	inline void init(NetworkWithCost &_g)
	{
		g=_g;
		dist=new CostType[g.n+5];
		visit=new bool[g.n+5];
		cur=new int[g.n+5];
	}
	
	bool bellmanford()
	{
	//	cout<<"Bf started";
		for(int i=0;i<g.n;i++)
		{
			dist[i]=DistInf;
		}
		dist[g.src]=0;
		int changeCommitted;
		for(int T=0;T<g.n;T++)
		{
			changeCommitted=0;
			for(int i=0;i<g.n;i++)
			{
				if(dist[i]==DistInf) continue;
				assert(dist[i]>=-DistInf);
				for(auto &e:g.edges[i])
				{
					if(e.flow==0) continue;
					if(dist[e.vertex]>dist[i]+e.cost)
					{
						dist[e.vertex]=dist[i]+e.cost;
						changeCommitted=true;
					}
				}
			}
			if(!changeCommitted) break;
		}
	//	system("pause");
		return (dist[g.dst]<DistInf);
	}
	
	bool dijkstra()
	{
		for(int i=0;i<g.n;i++)
		{
			dist[i]=-1;
		}
		dist[g.src]=0;
		priority_queue <pair<CostType,int>,vector<pair<CostType,int> >,greater<pair<CostType,int> > > pq;
		pq.push(mp(0,0));
		while(pq.size())
		{
			int x=pq.top().second;
			CostType cost=pq.top().first;
			pq.pop();
			if(dist[x]!=cost) continue;
			for(auto &e:g.edges[x])
			{
				if(e.flow==0) continue;
				if(dist[e.vertex]>cost+e.cost || dist[e.vertex]==-1)
				{
					dist[e.vertex]=cost+e.cost;
					pq.push(mp(dist[e.vertex],e.vertex));
				}
			}
		}
		return (dist[g.dst]!=-1);
	}
	
	pair<int,CostType> dfs(int x,int flow)
	{
		if(x==g.dst) return mp(flow,0);
		visit[x]=1;
		pair<int,CostType> res={0,0};
		for(int &i=cur[x];i<(int)g.edges[x].size();i++)
		{
			int u=g.edges[x][i].vertex;
			int c=g.edges[x][i].cost;
			if(visit[u]) continue;
			if(dist[u]!=dist[x]+c) continue;
			if(g.edges[x][i].flow==0) continue;
			pii f=dfs(u,min(flow,g.edges[x][i].flow));
			flow-=f.first;
			res.first+=f.first;res.second+=f.second;
			res.second+=g.edges[x][i].cost*f.first;
			g.edges[x][i].flow-=f.first;
			g.edges[u][g.edges[x][i].inv].flow+=f.first;
			if(flow==0) break;
		}
		visit[x]=0;
		return res;
	}
	
	pair<int,CostType> run()
	{
		pair<int,CostType> x=mp(0,0);
		for(int i=0;i<g.n;i++)
		{
			visit[i]=0;
		}
		while(bellmanford())
		{
			for(int i=0;i<g.n;i++)
			{
				assert(visit[i]==0);
			}
			for(int i=0;i<g.n;i++)
			{
				cur[i]=0;
			}
			pair<int,CostType> f=dfs(g.src,inf);
			x+=f;
		}
		return x;
	}
};
using namespace std;
NetworkWithCost g;
MCMF d;
int k,n;
vector<int> v;
vector<int> edges[2005];
int nxt[2005];
int head[2005];

int main()
{
//	// freopen("input.txt","r",stdin);
	quickcin;
	cin>>k>>n;
	g.init(n+n+2);
	int src=n+n,dst=n+n+1;
	g.feedsd(src,dst);
	int cost=0;
	for(int i=0;i<n;i++)
	{
		string str;cin>>str;
		int s=0;
		for(int i=0;i<k;i++)
		{
			if(str[i]=='1') s|=(1<<i);
		}
		v.push_back(s);
		int c=__builtin_popcount(s);
		g.addEdge(src,i,1,0);//cost+=c+1;
		g.addEdge(i,dst,1,c+1);
		// g.addEdge(i,dst,1,c+1);
		// g.addEdge(i,dst,1,0);
		g.addEdge(i+n,dst,1,0);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if((v[i]&v[j])==v[i] && i!=j) g.addEdge(i,j+n,1,0);
		}
	}
	d.init(g);
	pair<int,ll> f=d.run();
	assert(f.first==n);
	// cout<<f.second<<endl;
	cout<<cost+f.second-1<<endl;
	memset(nxt,-1,sizeof(nxt));
	memset(head,1,sizeof(head));
	for(int i=0;i<n;i++)
	{
		for(auto &e:d.g.edges[i])
		{
			if(!e.dir || e.vertex-n>=n || e.flow==1) continue;
			// debug(i,e.vertex-n);
			nxt[i]=e.vertex-n;
			head[e.vertex-n]=false;
		}
	}
	// for(int i=0;i<n;i++){
	// 	cout<<head[i]<<' ';
	// }
	// cout<<endl;
	// cout<<nxt[0]<<endl;
	int fst=true;
	for(int i=0;i<n;i++)
	{
		if(head[i])
		{
			if(!fst) cout<<"R ";
			int now=0;
			int id=i;
			while(id!=-1)
			{
				while(now!=v[id])
				{
					int c=__builtin_ctz(v[id]^now);
					cout<<c<<' ';
					now|=(1<<c);
				}
				id=nxt[id];
			}
			fst=false;
		}
	}
	cout<<endl;
	return 0;
}