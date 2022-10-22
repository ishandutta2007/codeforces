//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/factorization>
//#include <self/tree>
//#include <self/ModInt>
//#include <self/SegmentTree>
//using namespace std;
//using Int=ModInt <mod>;
//Factorization d;
//map <pii,int> mID;
//int cntTrees;
//Tree::LCAFast lca;
//vector <int> order;
//int n,q;
//vector <int> edges[100005];
//int dfn[100005];
//int par[100005];
//int a[100005];
//int l[100005];
//int r[100005];
//
//void go(int x,int par)
//{
//	static int T=0;
//	order.push_back(x);
//	l[x]=dfn[x]=T++;
//	::par[x]=par;
//	for(auto u:edges[x])
//	{
//		if(u==par) continue;
//		go(u,x);
//	}
//	r[x]=T;
//}
//FenwickTree <int> bs,bl;
//
//struct Operation
//{
//	FenwickTree <int> &bit;
//	int l,r;
//	int value;
//};
//
//struct Query
//{
//	int pos;
//	int mut;
//	int id;
//};
//
//Int res[100005];
//vector <Query> queries[100000*20+5];
//vector <Operation> operations[100000*20+5];
//vector <pii> lsh;
//tuple <int,int,int> dat[100005];
//int main()
//{
//	freopen("input.txt","r",stdin);
//	// freopen("output.txt","w",stdout);
//	d.initPrimeList(10000000);
//	scanf("%d",&n);
//	for(int i=0;i<n-1;i++)
//	{
//		int x,y;
//		scanf("%d%d",&x,&y);
//		x--;
//		y--;
//		edges[x].push_back(y);
//		edges[y].push_back(x);
//	}
//	bs.init(n);
//	bl.init(n);
//	lca.init(edges,edges+n);
//	go(0,-1);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",a+i);
//		vector<pii> v=d.factorizeFast(a[i]);
//		for(auto x:v)
//		{
//			lsh.push_back(x);
//			lsh.push_back(mp(x.first,inf));
//			lsh.push_back(mp(x.first,-1));
//		}
//	}
//	scanf("%d",&q);
//	for(int i=0;i<q;i++)
//	{
//		int u,v,x;
//		scanf("%d%d%d",&u,&v,&x);
//		u--;
//		v--;
//		dat[i]=make_tuple(u,v,x);
//		int z=lca.lca(u,v);
//		res[i]=Int(1)/Int(__gcd(a[z],x));
//		vector<pii> vv=d.factorizeFast(x);
//		for(auto x:vv)
//		{
//			lsh.push_back(x);
//		}
//	}
//	sort(all(lsh));
//	lsh.erase(unique(all(lsh)),lsh.end());
//	for(int i=0;i<q;i++)
//	{
//		int u,v,x;
//		tie(u,v,x)=dat[i];
//		vector<pii> vv=d.factorizeFast(x);
//		int z=lca.lca(u,v);
//		z=par[z];
//		for(auto x:vv)
//		{
//			queries[lower_bound(all(lsh),x)-lsh.begin()].push_back({u,1,i});
//			queries[lower_bound(all(lsh),x)-lsh.begin()].push_back({v,1,i});
//			if(z==-1) continue;
//			queries[lower_bound(all(lsh),x)-lsh.begin()].push_back({z,-1,i});
//			queries[lower_bound(all(lsh),x)-lsh.begin()].push_back({z,-1,i});
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		vector<pii> v=d.factorizeFast(a[i]);
//		int l=::l[i];
//		int r=::r[i];
//		for(auto &x:v)
//		{
//			int st=lower_bound(all(lsh),mp(x.first,-1))-lsh.begin();
//			operations[st].push_back({bl,l,r,1});
//			int md=lower_bound(all(lsh),x)-lsh.begin();
//			operations[md].push_back({bl,l,r,-1});
//			operations[md].push_back({bs,l,r,x.second});
//			int ed=lower_bound(all(lsh),mp(x.first,inf))-lsh.begin();
//			operations[ed].push_back({bs,l,r,-x.second});
//		}
//	}
//	for(int T=0;T<(int)lsh.size();T++)
//	{
//		for(auto &x:operations[T])
//		{
//			// if(lsh[T].first==5 && (&x.bit==&bs))
//			// {
//			// 	cout<<x.l<<' '<<x.r<<' '<<x.value<<endl;
//			// }
//			x.bit.add(x.l,x.value);
//			x.bit.add(x.r,-x.value);
//		}
//		for(auto &x:queries[T])
//		{
//			Int b=lsh[T].first;
//			int e=lsh[T].second;
//			// if(x.id==3)
//			// {
//			// 	cout<<bs.query(x.pos)<<' '<<bl.query(x.pos)<<' '<<b<<' '<<(x.mut==1?"+":"-")<<e<<endl;
//			// }
//			// if(x.id==3) cout<<b<<' '<<e<<endl;
//			// cout<<dfn[x.pos]<<endl;
//			Int t=b^(bs.query(dfn[x.pos])+bl.query(dfn[x.pos])*e);
//			if(x.mut==1) res[x.id]*=t;else res[x.id]/=t;
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		assert(bs.query(i)==0);
//		assert(bl.query(i)==0);
//	}
//	for(int i=0;i<q;i++)
//	{
//		printf("%d\n",res[i].x);
//	}
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
#ifdef __TAKE_MOD
int mod;
#else
#ifdef __TAKE_CONST_MOD
const int mod=__TAKE_CONST_MOD;
#else
const int mod=1000000007;
#endif
#endif
const int gmod=5;
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
#endif
using namespace std;
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

template <typename T>
void operator*=(vector<T> &vec, int k)
{
	for (auto &x : vec)
		x *= k;
}

template <typename T>
void operator-=(vector<T> &a, const vector<T> &b)
{
	assert(a.size() == b.size());
	for (size_t it = 0; it < a.size(); it++)
	{
		a[it] -= b[it];
	}
}

template <typename T>
vector<T> operator*(const vector<T> &vec, int k)
{
	vector<T> res(vec);
	res *= k;
	return res;
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

template <typename T>
T operator*(vector<T> v1, vector<T> v2)
{
	assert(v1.size() == v2.size());
	int n = v1.size();
	T res = 0;
	for (int i = 0; i < n; i++)
	{
		res += v1[i] * v2[i];
	}
	return res;
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
#endif
using namespace std;
class Factorization
{
	public:
	vector <int> primes;
	bool *isprime;
	int n;
	void initPrimeList(int _n)
	{
		n=_n;
		isprime=new bool[n+5];
		for(int i=0;i<=n;i++)
		{
			isprime[i]=true;
		}
		isprime[0]=isprime[1]=false;
		for(int i=2;i<=n;i++)
		{
			if(isprime[i]) primes.push_back(i);
			for(auto &j:primes)
			{
				if(i*j>n) break;
				isprime[i*j]=false;
				if(i%j==0) break;
			}
		}
	}
	int getPrimeID(int p)
	{
		return lower_bound(primes.begin(),primes.end(),p)-primes.begin();
	}
	template <typename T>
	inline vector <T> getfactors(T x)
	{
		vector <T> vec;
		for(T i=1;i*i<=x;i++)
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
	inline vector <pair<int,int> > factorizeFast(int x)
	{
		vector <pair<int,int> > vec;
		int nx=x;
		for(auto i:primes)
		{
			if(i*i>x) break;
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
	inline vector <pair<int,int> > factorize(int x)
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
	inline vector <int> factorizeflat(int x)
	{
		vector <int> vec;
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
					vec.push_back(i);
				}
			}
		}
		if(nx!=1) vec.push_back(nx);
		return vec;
	}
	template <typename T>
	inline bool checkPrime(T x)
	{
		for(T i=2;i*i<=x;i++)
		{
			if(x%i==0) return false;
		}
		return true;
	}
};
#ifndef _SELF_GRAPH
#define _SELF_GRAPH 1
#include <vector>
using namespace std;
struct Graph
{
	public:
	bool unDirected;
	vector <vector <int> > edges;
	int n;
	int m;
	int isTree;
	template <typename Iterator>
	void init(Iterator begin,Iterator end,bool _unDirected=true)
	{
		unDirected=_unDirected;
		n=end-begin;
		edges.resize(n);
		for(Iterator it=begin;it!=end;it++)
		{
			edges[it-begin]=(*it);
			m+=it->size();
		}
		assert(m%2==0);
		m/=2;
		isTree=-1;
	}
	void init(int _n,bool _unDirected=true)
	{
		n=_n;
		m=0;
		edges.resize(n+5);
		unDirected=_unDirected;
		isTree=-1;
	}
	bool testTree()
	{
		if(isTree!=-1) return isTree;
		assert(unDirected==true);
		if(n!=m+1)
		{
			isTree=false;
			return isTree;
		}
		queue <int> que;
		vector <int> visit(n,0);
		que.push(0);
		while(que.size())
		{
			int x=que.front();
			visit[x]=true;
			que.pop();
			for(auto u:edges[x])
			{
				if(visit[u]) continue;
				que.push(u);
			}
		}
		for(int i=0;i<n;i++)
		{
			if(!visit[i])
			{
				isTree=false;
				return isTree;
			}
		}
		isTree=true;
		return isTree;
	}
	void feedEdges(vector <int> _edges[])
	{
		for(int i=0;i<n;i++)
		{
			edges[i]=_edges[i];
		}
	}
	void addEdges(int x,int y)
	{
		edges[x].push_back(y);
		if(unDirected) edges[y].push_back(x);
		m++;
	}
	void clear(int n)
	{
		for(int i=0;i<n;i++)
		{
			edges[i].clear();
		}
		m=0;
	}
	inline void reset(int _n)
	{
		int n=_n;
		clear(n);
	}
	inline void clear()
	{
		clear(n);
	}
	inline void print()
	{
		cout<<"A total of "<<m<<" edges"<<endl;
		for(int i=0;i<n;i++)
		{
			for(auto &j:edges[i])
			{
				if(!unDirected || (i<j)) cout<<"("<<i<<'-'<<j<<")"<<endl;
			}
		}
	}
};

template <typename T>
struct GraphWithCost
{
	public:
	bool unDirected;
	vector <vector <pair<int,T> > > edges;
	int n;
	int m;
	int isTree;
	void init(int _n,bool _unDirected)
	{
		n=_n;
		m=0;
		edges.resize(n+5);
//		dfn.resize(n+5);
//		low.resize(n+5);
		unDirected=_unDirected;
		isTree=-1;
	}
	void feedEdges(vector <pair<int,T> > _edges[])
	{
		for(int i=0;i<n;i++)
		{
			edges[i]=_edges[i];
		}
	}
	void addEdges(int x,int y,int cost)
	{
		edges[x].push_back(mp(y,cost));
		if(unDirected) edges[y].push_back(mp(x,cost));
		m++;
	}
	void clear()
	{
		for(int i=0;i<n;i++)
		{
			edges[i].clear();
		}
		m=0;
	}
	void print()
	{
		cout<<"A total of "<<m<<" edges"<<endl;
		for(int i=0;i<n;i++)
		{
			for(auto &j:edges[i])
			{
				if(!unDirected || (i<j.first)) cout<<"("<<i<<'-'<<j.first<<")"<<endl;
			}
		}
	}
};
#endif
#ifndef __SELF_ST_TABLE
#define __SELF_ST_TABLE 1

template <typename T,typename _Compare=std::less <T> >
struct StTableFast //
{
    std::vector <std::vector<T> > table;
    std::vector <int> logTable;
    _Compare comp;
    template <typename Iterator>
    void init(Iterator begin,Iterator end)
    {
        int n=end-begin;
        int lg=0;
        int nn=1;
        while(nn<=n)
        {
            nn<<=1;
            lg++;
        }
        lg--;
        table.resize(lg+1);
        for(int i=0;i<=lg;i++)
        {
            table[i].resize(n-(1<<i)+1);
        }
        logTable.resize(n+1);
        for(Iterator it=begin;it!=end;it++)
        {
            table[0][it-begin]=*it;
        }
        T ta,tb;
        for(int i=1;i<=lg;i++)
        {
            for(int j=0;j<n-(1<<i)+1;j++)
            {
                ta=table[i-1][j];
                tb=table[i-1][j+(1<<(i-1))];
                if(comp(ta,tb)) table[i][j]=ta;else table[i][j]=tb;
            }
        }
        logTable[1]=0;
        for(int i=2;i<=n;i++)
        {
            logTable[i]=logTable[i/2]+1;
        }
    }
    T query(int l,int r)
    {
        int n=r-l;
        int lg=logTable[n];
        T a=table[lg][l];
        T b=table[lg][r-(1<<lg)];
        if(comp(a,b)) return a;else return b;
    }
};

#endif
namespace Tree
{
	struct GetParent
	{
		template <typename T>
		void dfs(int x, int p, T &arr, Graph &g)
		{
			arr[x] = p;
			for (auto &u : g.edges[x])
			{
				if (u == p) continue;
				dfs(u, x, arr, g);
			}
		}
		template <typename T>
		void getParArray(Graph &g, int rt, T &arr)
		{
			dfs(rt, -1, arr, g);
		}
	};

	struct GetDepth
	{
		template <typename T>
		static void dfs(int x, int p, int depth, T &arr, Graph &g)
		{
			arr[x]=depth;
			for (auto &u : g.edges[x])
			{
				if (u == p) continue;
				dfs(u, x, depth + 1, arr, g);
			}
		}
		template <typename T>
		static void getDepArray(Graph &g,T &arr,int rt = 0)
		{
			dfs(rt,-1,0,arr,g);
		}
	};

	struct LCA
	{
		int N;
		int LOGN;
		vector <int> depth;
		vector <vector <int> > par;
		void error(string s)
		{
			cout << s << endl;
			exit(0);
		}
		void init(Graph &g)
		{
			if(g.unDirected == false)
			{
				error("Error occured! Now LCA-algorithm only supports undirected graph!");
			}
			N = g.n;
			int tn = N;
			LOGN = 0;
			while (tn)
			{
				tn /= 2;
				LOGN++;
			}
			depth.resize(N);
			par.resize(LOGN);
			for (int i = 0; i < LOGN; i++)
			{
				par[i].resize(N);
			}
			GetDepth ta;
			GetParent tb;
			ta.getDepArray(g,depth, 0);
			tb.getParArray(g, 0, par[0]);
			for (int k = 0; k < LOGN - 1; k++)
			{
				for (int i=0;i<g.n;i++)
				{
					if(par[k][i] == -1)
					{
						par[k+1][i]=-1;
					}
					else
					{
						par[k + 1][i] = par[k][par[k][i]];
					}
				}
			}
		}
		int lca(int a, int b)
		{
			if (depth[a] < depth[b]) swap(a, b);
			int t = depth[a] - depth[b];
			for (int i = 0; i < LOGN; i++)
			{
				if ((t & (1 << i)))	a=par[i][a];
			}
			if (a == b)	return a;
			for (int i = LOGN - 1; i >= 0; i--)
			{
				if (par[i][a] != par[i][b])
				{
					a = par[i][a];
					b = par[i][b];
				}
			}
			return par[0][a];
		}
		inline int getDist(int a, int b)
		{
			return depth[a]+depth[b]-depth[lca(a,b)]*2;
		}
	};
	struct LCAFast
	{
		vector <pii> eulerOrder;
		StTableFast <pii> stTable;
		vector <int> position;
		vector <int> depth;
		void dfs(int x,int par,const Graph &g)
		{
			position[x]=eulerOrder.size();
			eulerOrder.push_back(mp(depth[x],x));
			for(auto u:g.edges[x])
			{
				if(u==par) continue;
				dfs(u,x,g);
				eulerOrder.push_back(mp(depth[x],x));
			}
		}
		template <typename Iterator>
		inline void init(Iterator begin,Iterator end)
		{
			Graph g;
			g.init(begin,end);
			init(g);
		}
		void init(Graph &g)
		{
			int n=g.n;
			position.resize(n);
			GetDepth gd;
			depth.resize(n);
			gd.getDepArray(g,depth,0);
			dfs(0,-1,g);
			stTable.init(all(eulerOrder));
		}
		int lca(int x,int y)
		{
			int l=min(position[x],position[y]);
			int r=max(position[x],position[y])+1;
			return stTable.query(l,r).second;
		}
		inline int getDist(int x,int y)
		{
			int z=lca(x,y);
			return depth[x]+depth[y]-depth[z]*2;
		}
	};

	struct GetDiameter
	{
		static pair<int, int> dfs(Graph &g, int x, int par)
		{
			pair<int, int> res=make_pair(1, x);
			for (auto u : g.edges[x])
			{
				if (u==par)	continue;
				chmax(res, dfs(g, u, x) + make_pair(1, 0));
			}
			return res;
		}
		int getDiameter(Graph &g)
		{
			int a=dfs(g,0,-1).second;
			return dfs(g,a,-1).first;
		}
		int getDiameter(Graph &g,int &a,int &b)
		{
			a=dfs(g,0,-1).second;
			pii o=dfs(g,a,-1);
			b=o.second;
			return o.first;
		}
	};

	struct GetPSum
	{
		static void dfs(Graph &g, int dst[], int src[], int x = 0, int par = -1)
		{
			dst[x] = src[x];
			for (auto u : g.edges[x])
			{
				if (u == par) continue;
				dfs(g, dst, src, u, x);
				dst[x] += dst[u];
			}
		}
	};

	struct MarkLeaf
	{
		void mark(Graph &g,int arr[],int x=0)
		{
			for (int i = 0;i<g.n;i++)
			{
				if ((i!=x && (int)g.edges[i].size()<=1) || (i==x && g.edges[i].size()==0))
				{
					arr[i]=true;
				}
				else
				{
					arr[i]=false;
				}
			}
		}
	};

	struct JustVisit
	{
		int dfs(Graph &g, int arr[], int x = 0, int par = -1)
		{
			arr[x] = true;
			int cnt = 1;
			for (auto u : g.edges[x])
			{
				if (u == par)
					continue;
				cnt += dfs(g, arr, u, x);
			}
			return cnt;
		}
	};

	struct BulidSPTree
	{
		vector<int> dist;
		template <typename T>
		inline vector<pair<int, T>> build(GraphWithCost<T> &g, int rt)
		{
			vector<pair<int, T>> v(g.n);
			dist.resize(g.n);
			priority_queue<pii, vector<pii>, greater<pii>> que;
			for (int i = 0; i < g.n; i++)
			{
				dist[i] = inf;
			}
			dist[rt] = 0;
			que.push(mp(0, rt));
			while (que.size())
			{
				int x = que.top().second;
				int s = que.top().first;
				que.pop();
				if (s != dist[x])
					continue;
				for (int i = 0; i < g.edges[x].size(); i++)
				{
					int u = g.edges[x][i].first, ct = g.edges[x][i].second;
					if (dist[u] <= dist[x] + ct)
						continue;
					dist[u] = dist[x] + ct;
					v[u] = mp(x, ct);
					que.push(mp(dist[u], u));
				}
			}
			v[0] = mp(-1, 0);
			return v;
		}
	};
} // namespace Tree
#ifndef SELF_MODINT
#define SELF_MODINT 1
template <int mod>
struct ModInt
{
	int x;
	ModInt(){x=0;}
	ModInt(int _x){x=_x%mod;if(x<0) x+=mod;}
	ModInt(ll _x){x=_x%mod;if(x<0) x+=mod;}
	ModInt <mod>& operator ++()// prefix
	{
		++x;
		if(x==mod) x=0;
		return *this;
	}
	ModInt <mod> operator ++(int)
	{
		int t=x;
		x++;
		if(x==mod) x=0;
		return t;
	}
	ModInt <mod>& operator --()// prefix
	{
		--x;
		if(x==-1) x+=mod;
		return *this;
	}
	ModInt <mod> operator --(int)
	{
		int t=x;
		x--;
		if(x==-1) x+=mod;
		return t;
	}
};

template <int mod>
inline int mabs(const ModInt <mod> &a)
{
	return a.x;
}

template <int mod>
bool operator == (const ModInt <mod> &a,const ModInt <mod> &b)
{
	return a.x==b.x;
}

template <int mod>
bool operator == (ModInt <mod> a,int x)
{
	return (a.x==x);
}

template <int mod>
bool operator != (const ModInt <mod> &a,const ModInt <mod> &b)
{
	return (a.x!=b.x);
}

template <int mod>
bool operator != (ModInt <mod> a,int x)
{
	return (a.x!=x);
}

template <int mod>
ModInt <mod> operator + (ModInt <mod> a,int b)
{
	a.x+=b;
	if(a.x>=mod) a.x-=mod;
	return a;
}

template <int mod>
ModInt <mod> operator + (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x+b.x;
	if(tmp>=mod) tmp-=mod;
	return tmp;
}

template <int mod>
ModInt <mod> operator - (ModInt <mod> a,ModInt <mod> b)
{
	int tmp=a.x-b.x;
	if(tmp<0) tmp+=mod;
	return tmp;
}

template <int mod>
ModInt <mod> operator - (ModInt <mod> a,int b)
{
	return a-(ModInt <mod> )b;
}

template <int mod>
void operator -= (ModInt <mod> &a,ModInt <mod> b)
{
	a.x-=b.x;
	a.x+=(a.x>>31&mod);
}

template <int mod,typename T>
void operator -= (ModInt <mod> &a,const T &b)
{
	a.x-=b;
	a.x+=(a.x>>31&mod);
}

template <int mod>
ModInt <mod> operator * (ModInt <mod> a,ModInt <mod> b)
{
	return 1LL*a.x*b.x%mod;
}

template <int mod>
ModInt <mod> operator * (ModInt <mod> a,int b)
{
	return 1LL*a.x*b%mod;
}

template <int mod>
void operator *= (ModInt <mod> &a,ModInt <mod> b)
{
	a=a*b;
}

template <int mod,typename T>
void operator *= (ModInt <mod> &a,const T &b)
{
	a=a*b;
}

template <int mod>
void operator += (ModInt <mod> &a,ModInt <mod> b)
{
	a.x+=b.x;
	if(a.x>=mod) a.x-=mod;
}

template <int mod,typename T>
void operator +=(ModInt <mod> &a,const T &b)
{
	a.x+=b;
	if(a.x>=mod) a.x-=mod;
}

template <int mod>
inline ModInt <mod> inv(ModInt <mod> x)
{
	int m=mod-2;
	ModInt <mod> basic=x;
	x=1;
	while(m)
	{
		if(m&1) x*=basic;
		m>>=1;
		basic*=basic;
	}
	return x;
}

template <int mod>
ModInt <mod> operator / (ModInt <mod> a,ModInt <mod> b)
{
	return a*inv(b);
}

template <int mod>
ModInt <mod> operator / (ModInt <mod> a,int b)
{
	return a*inv((ModInt <mod>)b);
}

template <int mod>
void operator /= (ModInt <mod> &a,int b)
{
	a*=inv(ModInt <mod> (b));
}

template <int mod>
void operator /= (ModInt <mod> &a,ModInt <mod> b)
{
	a=a/b;
}

template <int mod>
ModInt <mod> operator ^ (ModInt <mod> basic,int x)
{
	ModInt <mod> res=1;
	while(x)
	{
		if(x&1)	res*=basic;
		basic*=basic;
		x>>=1;
	}
	return res;
}

template <int mod>
istream & operator >> (istream &cin,ModInt <mod> &x)
{
	cin>>x.x;
	x.x%=mod;
	if(x.x<0) x.x+=mod;
	return cin;
}

template <int mod>
ostream & operator << (ostream &cout,ModInt <mod> x)
{
	cout<<x.x;
	return cout;
}
#endif
//quality guarantee
template <typename T>
struct SegmentTreeMinUpdate //[)
{
	T maxValue = 1e9;
	T *data;
	T *tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn=1;
		while (nn<size)
		{
			nn<<=1;
		}
		data=new T[nn*2+5];
		tag=new T[nn*2+5];
		for (int i=0;i<=nn*2;i++)
		{
			data[i]=maxValue;
			tag[i]=maxValue;
		}
	}
	void pushdown(int x)
	{
		if (x >= nn) return;
		data[x * 2] = min(data[x * 2], tag[x]);
		data[x * 2 + 1] = min(data[x * 2 + 1], tag[x]);
		tag[x * 2] = min(tag[x * 2], tag[x]);
		tag[x * 2 + 1] = min(tag[x * 2 + 1], tag[x]);
		tag[x] = maxValue;
	}
	void update(int pos,T value)
	{
		update(pos,pos+1,value);
	}
	void update(int ql, int qr, T value)
	{
		update(1, 0, nn, ql, qr, value);
	}
	void update(int x, int l, int r, int ql, int qr, T value)
	{
		if (l>=qr || r<=ql)	return;
		pushdown(x);
		if (l>=ql && r<=qr)
		{
			data[x]=min(data[x],value);
			tag[x]=min(tag[x],value);
			return;
		}
		update(x*2,l,(l+r)>>1,ql,qr,value);
		update(x*2+1,(l+r)>>1,r,ql,qr,value);
		data[x]=min(data[x*2],data[x*2+1]);
	}
	T query(int pos)
	{
		return query(pos,pos+1);
	}
	T query(int ql, int qr)
	{
		return query(1,0,nn,ql,qr);
	}
	T query(int x, int l, int r, int ql, int qr)
	{
		if (l>=qr || r<=ql)	return maxValue;
		pushdown(x);
		if (l>=ql && r<=qr)
		{
			return data[x];
		}
		return min(query(x*2,l,(l+r)>>1,ql,qr),query(x*2+1,(l+r)>>1,r,ql,qr));
	}
};

//quality guarantee
template <typename T>
struct SegmentTreeMinAdd //[)
{
	//	#define ll int
	T *data;
	T *tagSum;
	int nn;
	T inf;
	int size()
	{
		return nn;
	}
	void init(int size, T _inf)
	{
		nn = 1;
		inf = _inf;
		while (nn < size)
		{
			nn <<= 1;
		}
		data = new T[nn * 2 + 5];
		tagSum = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			data[i] = inf;
			tagSum[i] = 0;
		}
	}
	void pushdown(int x)
	{
		if (x >= nn)
			return;
		data[x * 2] += tagSum[x];
		data[x * 2 + 1] += tagSum[x];
		tagSum[x * 2] += tagSum[x];
		tagSum[x * 2 + 1] += tagSum[x];
		tagSum[x] = 0;
	}
	void add(int l, int r, T value)
	{
		add(1, 0, nn, l, r, value);
	}
	void add(int x, int l, int r, int ql, int qr, T value)
	{
		if (l >= qr || r <= ql)
			return;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			data[x] = data[x] + value;
			tagSum[x] += value;
			return;
		}
		add(x * 2, l, l + r >> 1, ql, qr, value);
		add(x * 2 + 1, l + r >> 1, r, ql, qr, value);
		data[x] = min(data[x * 2], data[x * 2 + 1]);
	}
	T query()
	{
		return data[1];
	}
	T query(int ql, int qr)
	{
		return query(1, 0, nn, ql, qr);
	}
	T query(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)
			return inf;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return min(query(x * 2, l, l + r >> 1, ql, qr), query(x * 2 + 1, l + r >> 1, r, ql, qr));
	}
	void build(int a[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			data[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			data[i] = min(data[i * 2], data[i * 2 + 1]);
		}
	}
};

//quality guarantee
template <typename T>
struct SegmentTreeMaxAdd //[)
{
	T *data;
	T *tagSum;
	int nn;
	T inf;
	int size()
	{
		return nn;
	}
	void init(int size, T _inf)
	{
		nn = 1;
		inf = _inf;
		while (nn < size)
		{
			nn <<= 1;
		}
		data = new T[nn * 2 + 5];
		tagSum = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			data[i] = -inf;
			tagSum[i] = 0;
		}
	}
	inline void pushdown(int x)
	{
		if (x >= nn) return;
		data[x * 2] += tagSum[x];
		data[x * 2 + 1] += tagSum[x];
		tagSum[x * 2] += tagSum[x];
		tagSum[x * 2 + 1] += tagSum[x];
		tagSum[x] = 0;
	}
	void add(int l, int r, T value)
	{
		add(1, 0, nn, l, r, value);
	}
	void add(int x, int l, int r, int ql, int qr, T value)
	{
		if (l >= qr || r <= ql) return;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			data[x] = data[x] + value;
			tagSum[x] += value;
			return;
		}
		add(x * 2, l, l + r >> 1, ql, qr, value);
		add(x * 2 + 1, l + r >> 1, r, ql, qr, value);
		data[x] = max(data[x * 2], data[x * 2 + 1]);
	}
	T query()
	{
		return data[1];
	}
	T query(int ql, int qr)
	{
		return query(1, 0, nn, ql, qr);
	}
	T query(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)	return -inf;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return max(query(x * 2, l, l + r >> 1, ql, qr), query(x * 2 + 1, l + r >> 1, r, ql, qr));
	}
	void build(int a[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			data[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			data[i] = max(data[i * 2], data[i * 2 + 1]);
		}
	}
};

//quality guarantee
template <typename T>
struct SegmentTreeMinChange //[)
{
	const T unchanged = -1;
	const T maxValue = 1e9;
	T *data;
	T *tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn = 1;
		while (nn < size)
		{
			nn <<= 1;
		}
		data = new T[nn * 2 + 5];
		tag = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			data[i] = maxValue;
			tag[i] = unchanged;
		}
	}
	void build(int a[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			data[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			data[i] = min(data[i * 2], data[i * 2 + 1]);
		}
	}
	void pushdown(int x)
	{
		if (x >= nn)
			return;
		if (tag[x] == unchanged)
			return;
		data[x * 2] = tag[x];
		data[x * 2 + 1] = tag[x];
		tag[x * 2] = tag[x];
		tag[x * 2 + 1] = tag[x];
		tag[x] = unchanged;
	}
	void change(int ql, int qr, T value)
	{
		change(1, 0, nn, ql, qr, value);
	}
	void change(int x, int l, int r, int ql, int qr, T value)
	{
		if (l >= qr || r <= ql)
			return;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			data[x] = value;
			tag[x] = value;
			return;
		}
		change(x * 2, l, l + r >> 1, ql, qr, value);
		change(x * 2 + 1, l + r >> 1, r, ql, qr, value);
		data[x] = min(data[x * 2], data[x * 2 + 1]);
	}
	T query()
	{
		return data[1];
	}
	T query(int ql, int qr)
	{
		return query(1, 0, nn, ql, qr);
	}
	inline T operator[](int pos)
	{
		return query(pos, pos + 1);
	}
	T query(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)
			return maxValue;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return min(query(x * 2, l, l + r >> 1, ql, qr), query(x * 2 + 1, l + r >> 1, r, ql, qr));
	}
};

template <typename T>
struct FenwickTree
{
	const T E = 0;
	T *bit;
	int nn;
	inline void init(int n)
	{
		n++;
		nn = 1;
		while (nn < n)
			nn <<= 1;
		bit = new T[nn + 5];
		for (int i = 0; i <= nn; i++)
		{
			bit[i] = 0;
		}
	}
	inline void clear(int n)
	{
		nn = 1;
		while (nn < n)
			nn <<= 1;
		for (int i = 0; i <= nn; i++)
		{
			bit[i] = 0;
		}
	}
	inline void add(int x, T delta)
	{
		x++;
		while (x <= nn)
		{
			bit[x] += delta;
			x += x & -x;
		}
	}
	inline T query(int x)
	{
		x++;
		T res = E;
		while (x)
		{
			res += bit[x];
			x &= x - 1;
		}
		return res;
	}
	inline T query(int l, int r) //[]
	{
		return query(r) - (l > 0 ? query(l - 1) : 0);
	}
};

template <typename T>
struct SegmentTreeSumAdd
{
	const T E = 0;
	int nn;
	T *data;
	T *tag;
	void init(int _n)
	{
		nn = 1;
		while (nn < _n)
			nn <<= 1;
		data = new T[nn * 2 + 5];
		tag = new T[nn * 2 + 5];
		for (int i = 0; i < 2 * nn; i++)
		{
			tag[i] = E;
			data[i] = E;
		}
	}
	void pushdown(int x, int l, int r)
	{
		if (x >= nn) return;
		data[x * 2] += tag[x] * (r - l >> 1);
		data[x * 2 + 1] += tag[x] * (r - l >> 1);
		tag[x * 2] += tag[x];
		tag[x * 2 + 1] += tag[x];
		tag[x] = 0;
	}
	void build(T a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			data[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			data[i] = data[i * 2] + data[i * 2 + 1];
		}
	}
	void add(int x, int ql, int qr, int l, int r, T delta)
	{
		if (l >= qr || r <= ql)
			return;
		pushdown(x, l, r);
		if (l >= ql && r <= qr)
		{
			tag[x] += delta;
			data[x] += delta * (r - l);
			return;
		}
		add(x * 2, ql, qr, l, l + r >> 1, delta);
		add(x * 2 + 1, ql, qr, l + r >> 1, r, delta);
		data[x] = data[x * 2] + data[x * 2 + 1];
	}
	T query(int x, int ql, int qr, int l, int r)
	{
		if (l >= qr || r <= ql)
			return E;
		pushdown(x, l, r);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return query(x * 2, ql, qr, l, l + r >> 1) + query(x * 2 + 1, ql, qr, l + r >> 1, r);
	}
	inline void add(int l, int r, T delta)
	{
		add(1, l, r, 0, nn, delta);
	}
	inline void add(int pos,T delta)
	{
		add(pos,pos+1,delta);
	}
	inline T query(int l, int r)
	{
		return query(1, l, r, 0, nn);
	}
	inline T query(int pos)
	{
		return query(pos,pos+1);
	}
};

template <typename T>
struct SegmentTreeMinIntervalAdd //[)
{
	T *data;
	T *tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn = 1;
		while (nn < size)
		{
			nn <<= 1;
		}
		data = new T[nn * 2 + 5];
		tag = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			data[i] = inf;
			tag[i] = 0;
		}
	}
	void build(T a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			data[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			data[i] = min(data[i * 2], data[i * 2 + 1]);
		}
	}
	void pushdown(int x)
	{
		if (x >= nn)
			return;
		data[x * 2] += tag[x];
		data[x * 2 + 1] += tag[x];
		tag[x * 2] += tag[x];
		tag[x * 2 + 1] += tag[x];
		tag[x] = 0;
	}
	void add(int ql, int qr, T value)
	{
		add(1, 0, nn, ql, qr, value);
	}
	void add(int x, int l, int r, int ql, int qr, T value)
	{
		if (l >= qr || r <= ql)
			return;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			data[x] += value;
			tag[x] += value;
			return;
		}
		add(x * 2, l, l + r >> 1, ql, qr, value);
		add(x * 2 + 1, l + r >> 1, r, ql, qr, value);
		data[x] = min(data[x * 2], data[x * 2 + 1]);
	}
	T query(int ql, int qr)
	{
		return query(1, 0, nn, ql, qr);
	}
	T query(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)
			return inf;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return min(query(x * 2, l, l + r >> 1, ql, qr), query(x * 2 + 1, l + r >> 1, r, ql, qr));
	}
	//used in debug
	void print()
	{
		for (int i = 0; i < nn; i++)
		{
			cout << query(i, i + 1) << ' ';
		}
		cout << endl;
	}
};

template <typename T>
struct SegmentTreeMutChange // 
{
	T E;
	int nn;
	T *data;
	T *tag;
	bool *unChanged;
	void init(int _n,T _E)
	{
		E=_E;
		nn = 1;
		while (nn < _n)
			nn <<= 1;
		data = new T[nn * 2 + 5];
		tag = new T[nn * 2 + 5];
		unChanged = new bool[nn * 2 + 5];
		for (int i = 0; i < 2 * nn; i++)
		{
			tag[i] = E;
			data[i] = E;
			unChanged[i] = true;
		}
	}
	void pushdown(int x, int l, int r)
	{
		if (x >= nn)
			return;
		if (unChanged[x])
			return;
		data[x * 2] = fastpow(tag[x], (r - l) >> 1);
		data[x * 2 + 1] = fastpow(tag[x], (r - l) >> 1);
		tag[x * 2] *= tag[x];
		tag[x * 2 + 1] *= tag[x];
		unChanged[x] = true;
	}
	void build(T a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			data[i + nn] = a[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			data[i] = data[i * 2] * data[i * 2 + 1];
		}
	}
	void change(int x, int ql, int qr, int l, int r, T value)
	{
		if (l >= qr || r <= ql)
			return;
		if (l >= ql && r <= qr)
		{
			tag[x] = value;
			data[x] = fastpow(value, qr - ql);
			unChanged[x] = false;
			return;
		}
		pushdown(x, l, r);
		change(x * 2, ql, qr, l, l + r >> 1, value);
		change(x * 2 + 1, ql, qr, l + r >> 1, r, value);
		data[x] = data[x * 2] * data[x * 2 + 1];
	}
	T query(int x, int ql, int qr, int l, int r)
	{
		if (l >= qr || r <= ql) return E;
		pushdown(x, l, r);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return query(x * 2, ql, qr, l, l + r >> 1) * query(x * 2 + 1, ql, qr, l + r >> 1, r);
	}
	void multiplicate(int x,int l,int r,int ql,int qr,T &res)
	{
		if (l >= qr || r <= ql) return;
		pushdown(x, l, r);
		if (l >= ql && r <= qr)
		{
			res=data[x]*res;
			return;
		}
		multiplicate(x*2+1,(l+r)>>1,r,ql,qr,res);
		multiplicate(x*2,l,(l+r)>>1,ql,qr,res);
	}
	void multiplicate(int l,int r,T &res)
	{
		multiplicate(1,0,nn,l,r,res);
	}
	bool IntChanged = false;
	bool SinChanged = false;
	inline void error()
	{
		cout << "Error occured in Segment Tree" << endl;
		exit(0);
	}
	inline void change(int l, int r, T value)
	{
		IntChanged = true;
		if (SinChanged)
			error();
		change(1, l, r, 0, nn, value);
	}
	inline void change(int pos, T value)
	{
		SinChanged = true;
		if (IntChanged)
			error();
		pos += nn;
		data[pos] = value;
		pos /= 2;
		while (pos)
		{
			data[pos] = data[pos * 2] * data[pos * 2 + 1];
			pos /= 2;
		}
	}
	inline T query(int l, int r)
	{
		return query(1, l, r, 0, nn);
	}
	inline T query()
	{
		return data[1];
	}
};

//quality guarantee
template <typename T>
struct SegmentTreeMaxUpdate //[)
{
	T minValue = -1e9;
	T *data = 0;
	T *tag = 0;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		if (data)
			delete data;
		if (tag)
			delete tag;
		nn = 1;
		while (nn < size)
		{
			nn <<= 1;
		}
		data = new T[nn * 2 + 5];
		tag = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			data[i] = minValue;
			tag[i] = minValue;
		}
	}
	void pushdown(int x)
	{
		if (x >= nn)
			return;
		data[x * 2] = max(data[x * 2], tag[x]);
		data[x * 2 + 1] = max(data[x * 2 + 1], tag[x]);
		tag[x * 2] = max(tag[x * 2], tag[x]);
		tag[x * 2 + 1] = max(tag[x * 2 + 1], tag[x]);
		tag[x] = minValue;
	}
	void update(int pos, T value)
	{
		update(pos, pos + 1, value);
	}
	void update(int ql, int qr, T value)
	{
		update(1, 0, nn, ql, qr, value);
	}
	void update(int x, int l, int r, int ql, int qr, T value)
	{
		if (l >= qr || r <= ql)
			return;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			data[x] = max(data[x], value);
			tag[x] = max(tag[x], value);
			return;
		}
		update(x * 2, l, l + r >> 1, ql, qr, value);
		update(x * 2 + 1, l + r >> 1, r, ql, qr, value);
		data[x] = max(data[x * 2], data[x * 2 + 1]);
	}
	T query(int ql, int qr)
	{
		return query(1, 0, nn, ql, qr);
	}
	T query(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)
			return minValue;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return max(query(x * 2, l, l + r >> 1, ql, qr), query(x * 2 + 1, l + r >> 1, r, ql, qr));
	}
	~SegmentTreeMaxUpdate()
	{
		delete data;
		delete tag;
	}
};

template <typename T>
struct SegmentTreeMinMaxChange //[)
{
	const T maxValue = mp(inf, -1);
	const T minValue = mp(-inf, -1);
	T *dataMax;
	T *dataMin;
	T *tag;
	int nn;
	int size()
	{
		return nn;
	}
	void init(int size)
	{
		nn = 1;
		while (nn < size)
		{
			nn <<= 1;
		}
		dataMax = new T[nn * 2 + 5];
		dataMin = new T[nn * 2 + 5];
		for (int i = 0; i <= nn * 2; i++)
		{
			dataMin[i] = maxValue;
			dataMax[i] = minValue;
		}
	}
	void build(int a[], int len)
	{
		for (int i = 0; i < len; i++)
		{
			dataMax[i + nn] = mp(a[i], i);
			dataMin[i + nn] = mp(a[i], i);
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			dataMin[i] = min(dataMin[i * 2], dataMin[i * 2 + 1]);
			dataMax[i] = max(dataMax[i * 2], dataMax[i * 2 + 1]);
		}
	}
	void erase(int pos)
	{
		erase(1, 0, nn, pos, pos + 1);
	}
	void erase(int x, int l, int r, int ql, int qr)
	{
		if (l >= qr || r <= ql)
			return;
		if (l >= ql && r <= qr)
		{
			dataMax[x] = minValue;
			dataMin[x] = maxValue;
			return;
		}
		erase(x * 2, l, l + r >> 1, ql, qr);
		erase(x * 2 + 1, l + r >> 1, r, ql, qr);
		dataMin[x] = min(dataMin[x * 2], dataMin[x * 2 + 1]);
		dataMax[x] = max(dataMax[x * 2], dataMax[x * 2 + 1]);
	}
	pair<T, T> query(int x, int l, int r, int ql, int qr)
	{
		if (r <= ql || l >= qr)
			return mp(maxValue, minValue);
		if (l >= ql && r <= qr)
		{
			return mp(dataMin[x], dataMax[x]);
		}
		pair<T, T> o1 = query(x * 2, l, l + r >> 1, ql, qr);
		pair<T, T> o2 = query(x * 2 + 1, l + r >> 1, r, ql, qr);
		return mp(min(o1.first, o2.first), max(o1.second, o2.second));
	}
	inline pair<T, T> query(int l, int r)
	{
		return query(1, 0, nn, l, r);
	}
};

template <typename T>
struct SegmentTreeWeightedSumChange
{
	T E = 0;
	int nn;
	T *data;
	T *tag;
	T *weight;
	T *weightSum;
	bool *unChanged;
	void init(int _n)
	{
		nn = 1;
		while (nn < _n)
			nn <<= 1;
		data = new T[nn * 2 + 5];
		tag = new T[nn * 2 + 5];
		weight = new T[nn * 2 + 5];
		weightSum = new T[nn * 2 + 5];
		unChanged = new bool[nn * 2 + 5];
		for (int i = 0; i < 2 * nn; i++)
		{
			tag[i] = E;
			data[i] = E;
			unChanged[i] = true;
			weightSum[i] = E;
		}
	}
	void pushdown(int x)
	{
		if (x >= nn)
			return;
		if (unChanged[x])
			return;
		data[x * 2] = tag[x] * weightSum[x * 2];
		data[x * 2 + 1] = tag[x] * weightSum[x * 2 + 1];
		tag[x * 2] = tag[x];
		tag[x * 2 + 1] = tag[x];
		unChanged[x] = true;
		unChanged[x * 2] = false;
		unChanged[x * 2 + 1] = false;
	}
	void build(T a[], T weight[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			data[i + nn] = a[i] * weight[i];
			weightSum[i + nn] = weight[i];
		}
		for (int i = nn - 1; i >= 1; i--)
		{
			weightSum[i] = weightSum[i * 2] + weightSum[i * 2 + 1];
			data[i] = data[i * 2] + data[i * 2 + 1];
		}
	}
	void change(int x, int ql, int qr, int l, int r, T value)
	{
		if (l >= qr || r <= ql)
			return;
		if (l >= ql && r <= qr)
		{
			tag[x] = value;
			data[x] = value * weightSum[x];
			unChanged[x] = false;
			return;
		}
		pushdown(x);
		change(x * 2, ql, qr, l, l + r >> 1, value);
		change(x * 2 + 1, ql, qr, l + r >> 1, r, value);
		data[x] = data[x * 2] + data[x * 2 + 1];
	}
	T query(int x, int ql, int qr, int l, int r)
	{
		if (l >= qr || r <= ql)
			return E;
		pushdown(x);
		if (l >= ql && r <= qr)
		{
			return data[x];
		}
		return query(x * 2, ql, qr, l, l + r >> 1) + query(x * 2 + 1, ql, qr, l + r >> 1, r);
	}
	inline void error()
	{
		cout << "Error occured in Segment Tree" << endl;
		exit(0);
	}
	inline void change(int l, int r, T value)
	{
		change(1, l, r, 0, nn, value);
	}
	inline void change(int pos, T value)
	{
		change(pos, pos + 1, value);
	}
	inline T query(int l, int r)
	{
		return query(1, l, r, 0, nn);
	}
	inline T query()
	{
		return data[1];
	}
};
using namespace std;
using Int=ModInt <mod>;
Factorization d;
map <pii,int> mID;
int cntTrees;
Tree::LCAFast lca;
vector <int> order;
int n,q;
vector <int> edges[100005];
int dfn[100005];
int par[100005];
int a[100005];
int l[100005];
int r[100005];

void go(int x,int par)
{
	static int T=0;
	order.push_back(x);
	l[x]=dfn[x]=T++;
	::par[x]=par;
	for(auto u:edges[x])
	{
		if(u==par) continue;
		go(u,x);
	}
	r[x]=T;
}
FenwickTree <int> bs,bl;

struct Operation
{
	FenwickTree <int> &bit;
	int l,r;
	int value;
};

struct Query
{
	int pos;
	int mut;
	int id;
};

Int res[100005];
vector <Query> queries[100000*20+5];
vector <Operation> operations[100000*20+5];
vector <pii> lsh;
tuple <int,int,int> dat[100005];
int main()
{
//	freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	d.initPrimeList(10000000);
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	bs.init(n);
	bl.init(n);
	lca.init(edges,edges+n);
	go(0,-1);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		vector<pii> v=d.factorizeFast(a[i]);
		for(auto x:v)
		{
			lsh.push_back(x);
			lsh.push_back(mp(x.first,inf));
			lsh.push_back(mp(x.first,-1));
		}
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int u,v,x;
		scanf("%d%d%d",&u,&v,&x);
		u--;
		v--;
		dat[i]=make_tuple(u,v,x);
		int z=lca.lca(u,v);
		res[i]=Int(1)/Int(__gcd(a[z],x));
		vector<pii> vv=d.factorizeFast(x);
		for(auto x:vv)
		{
			lsh.push_back(x);
		}
	}
	sort(all(lsh));
	lsh.erase(unique(all(lsh)),lsh.end());
	for(int i=0;i<q;i++)
	{
		int u,v,x;
		tie(u,v,x)=dat[i];
		vector<pii> vv=d.factorizeFast(x);
		int z=lca.lca(u,v);
		z=par[z];
		for(auto x:vv)
		{
			queries[lower_bound(all(lsh),x)-lsh.begin()].push_back({u,1,i});
			queries[lower_bound(all(lsh),x)-lsh.begin()].push_back({v,1,i});
			if(z==-1) continue;
			queries[lower_bound(all(lsh),x)-lsh.begin()].push_back({z,-1,i});
			queries[lower_bound(all(lsh),x)-lsh.begin()].push_back({z,-1,i});
		}
	}
	for(int i=0;i<n;i++)
	{
		vector<pii> v=d.factorizeFast(a[i]);
		int l=::l[i];
		int r=::r[i];
		for(auto &x:v)
		{
			int st=lower_bound(all(lsh),mp(x.first,-1))-lsh.begin();
			operations[st].push_back({bl,l,r,1});
			int md=lower_bound(all(lsh),x)-lsh.begin();
			operations[md].push_back({bl,l,r,-1});
			operations[md].push_back({bs,l,r,x.second});
			int ed=lower_bound(all(lsh),mp(x.first,inf))-lsh.begin();
			operations[ed].push_back({bs,l,r,-x.second});
		}
	}
	for(int T=0;T<(int)lsh.size();T++)
	{
		for(auto &x:operations[T])
		{
			// if(lsh[T].first==5 && (&x.bit==&bs))
			// {
			// 	cout<<x.l<<' '<<x.r<<' '<<x.value<<endl;
			// }
			x.bit.add(x.l,x.value);
			x.bit.add(x.r,-x.value);
		}
		for(auto &x:queries[T])
		{
			Int b=lsh[T].first;
			int e=lsh[T].second;
			// if(x.id==3)
			// {
			// 	cout<<bs.query(x.pos)<<' '<<bl.query(x.pos)<<' '<<b<<' '<<(x.mut==1?"+":"-")<<e<<endl;
			// }
			// if(x.id==3) cout<<b<<' '<<e<<endl;
			// cout<<dfn[x.pos]<<endl;
			Int t=b^(bs.query(dfn[x.pos])+bl.query(dfn[x.pos])*e);
			if(x.mut==1) res[x.id]*=t;else res[x.id]/=t;
		}
	}
	for(int i=0;i<n;i++)
	{
		assert(bs.query(i)==0);
		assert(bl.query(i)==0);
	}
	for(int i=0;i<q;i++)
	{
		printf("%d\n",res[i].x);
	}
	return 0;
}