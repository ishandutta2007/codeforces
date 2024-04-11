//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/rand>
//using namespace std;
//int n,q;
//
//struct Edge
//{
//	int x;
//	int y;
//	inline void input()
//	{
//		scanf("%d%d",&x,&y);
//		x--;
//		y--;
//	}
//	bool operator < (const Edge &e)const
//	{
//		if(x!=e.x) return x<e.x;
//		return y<e.y;
//	}
//};
//ostream & operator << (ostream &cout,const Edge &e)
//{
//	cout<<mp(e.x,e.y);
//	return cout;
//}
//
//struct Operation
//{
//	int cflag=0;
//	int nothing=0;
//	pii cf=mp(-1,-1);
//	pii crk=mp(-1,-1);
//};
//
//struct DSU
//{
//	int f[100005];
//	int c[100005];
//	int rk[100005];
//	int pcol[100005];
//	int flag;
//	vector<Operation> operations;
//	int find(int x,int &col)
//	{
//		if(x==f[x])
//		{
//			col=0;
//			return x;
//		}
//		else
//		{
//			int px=find(f[x],col);
//			col^=pcol[x];
//			return px;
//		}
//	}
//	inline void merge(int x,int y,Operation &p)
//	{
////		debug(x,y);
//		if(flag==false)
//		{
//			p.nothing=true;
//			return;
//		}
//		int cx,cy;
//		x=find(x,cx);
//		y=find(y,cy);
//		if(x==y)
//		{
//			if(cx==cy)
//			{
//				flag=false;
//				p.cflag=true;
//				return;
//			}
//			else
//			{
//				p.nothing=true;
//				return;
//			}
//		}
//		else
//		{
//			if(rk[x]<rk[y])
////			if(rand(0,1))
//			{
//				f[x]=y;
//				p.cf=mp(x,y);
//				pcol[x]=(cx^cy^1);
//				p.crk=mp(x,rk[x]);
////				debug(x,pcol[x]);
//			}
//			else
//			{
//				f[y]=x;
//				pcol[y]=(cx^cy^1);
//				p.cf=mp(y,x);
//				p.crk=mp(x,rk[x]);
//				rk[x]+=(rk[x]==rk[y]);
////				debug(y,pcol[y]);
//			}
//		}
////		print();
//	}
//	inline void undo()
//	{
//		Operation p=operations.back();
//		operations.pop_back();
//		if(p.nothing) return;
//		if(p.cflag)
//		{
//			flag=true;
//			return;
//		}
//		f[p.cf.first]=p.cf.first;
//		pcol[p.cf.first]=0;
//		rk[p.crk.first]=p.crk.second;
//	}
//	inline string ok()
//	{
//		return (flag?"YES":"NO");
//	}
//	inline void init()
//	{
//		memset(c,-1,sizeof(c));
//		memset(pcol,0,sizeof(pcol));
//		for(int i=0;i<n;i++)
//		{
//			f[i]=i;
//		}
//		flag=true;
//	}
//	inline void add(Edge e)
//	{
////		debug(e);
//		operations.push_back(Operation());
//		merge(e.x,e.y,operations.back());
//	}
//	inline void print()
//	{
////		debug(1,pcol[1],f[1]);
////		for(int i=0;i<n;i++)
////		{
////			int col,fx;
////			fx=find(i,col);
////			cout<<col<<' ';
////			cout<<f[i]<<' ';
////		}
////		cout<<endl;
//	}
//	inline void test()
//	{
//		add({0,1});
//		cout<<pcol[0]<<' '<<pcol[1]<<endl;
//		exit(0);
//	}
//}dsu;
//
//struct Manager
//{
//	vector<Edge> data[400005];
//	
//	int nn;
//	inline void init()
//	{
//		nn=1;
//		while(nn<q) nn<<=1;
//	}
//	inline void add(int l,int r,Edge e)
//	{
////		debug(l,r,e.x,e.y);
//		add(1,0,nn,l,r,e);
//	}
//	void add(int x,int l,int r,int ql,int qr,Edge e)
//	{
//		if(r<=ql || l>=qr) return;
//		if(l>=ql && r<=qr)
//		{
////			debug(x,e);
//			data[x].push_back(e);
//			return;
//		}
//		add(x*2,l,l+r>>1,ql,qr,e);
//		add(x*2+1,l+r>>1,r,ql,qr,e);
//	}
//	void dfs(int x)
//	{
////		debug(x);
//		for(auto &q:data[x]) dsu.add(q);
//		if(x<nn)
//		{
//			dfs(x*2);
//			dfs(x*2+1);
//		}
//		else if(x<nn+q)
//		{
////			for(int i=0;i<n;i++)
////			{
////				cout<<dsu.rk[i]<<' ';
////			}
////			cout<<endl;
////			dsu.print();
////			printf("%s\n",dsu.ok().c_str());
//			puts(dsu.ok().c_str());
//		}
//		for(auto &q:data[x]) dsu.undo();
//	}
//	inline void solve()
//	{
//		dsu.init();
////		debug("FUCLK");
//		dfs(1);
//	}
//}manager;
//
//map<Edge,int> m;
//int main()
//{
////	freopen("input.txt","r",stdin);
////	freopen("output.txt","w",stdout);
//	cin>>n>>q;
//	dsu.init();
////	dsu.test();
////	for(int i=0;i<q;i++)
////	{
////		Edge e;
////		e.input();
////		dsu.add(e);
////		cout<<dsu.ok()<<endl;
////	}
////	exit(0);
//	manager.init();
//	for(int i=0;i<q;i++)
//	{
//		Edge e;
//		e.input();
//		if(m[e])
//		{
//			manager.add(m[e]-1,i,e);
//			m[e]=0;
//		}
//		else
//		{
//			m[e]=i+1;
//		}
//	}
//	for(auto &q:m)
//	{
////		debug(q);
//		if(q.second==0) continue;
//		manager.add(q.second-1,::q,q.first);
//	}
//	manager.solve();
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
#ifndef _SELF_RAND
#define _SELF_RAND 1
//#if __cplusplus < 201103L
#if __cplusplus < 202003L
long long _Rand_Gen_Num() {return 1LL*rand()*RAND_MAX+rand();}
int rand(int l,int r) {long long x=_Rand_Gen_Num();return x%(r-l+1)+l;}
#else
#include <time.h>
#include <chrono>
#include <random>
using namespace std; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
#endif
template <typename Iterator>
void _m_random_shuffle(Iterator begin,Iterator end)
{
    for(Iterator it=begin+1;it!=end;it++)
    {
        iter_swap(begin+rand(0,it-begin),it);
    }
}
#define random_shuffle(a,b) _m_random_shuffle(a,b)
#endif
using namespace std;
int n,q;

struct Edge
{
	int x;
	int y;
	inline void input()
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
	}
	bool operator < (const Edge &e)const
	{
		if(x!=e.x) return x<e.x;
		return y<e.y;
	}
};
ostream & operator << (ostream &cout,const Edge &e)
{
	cout<<mp(e.x,e.y);
	return cout;
}

struct Operation
{
	int cflag=0;
	int nothing=0;
	pii cf=mp(-1,-1);
	pii crk=mp(-1,-1);
};

struct DSU
{
	int f[100005];
	int c[100005];
	int rk[100005];
	int pcol[100005];
	int flag;
	vector<Operation> operations;
	int find(int x,int &col)
	{
		if(x==f[x])
		{
			col=0;
			return x;
		}
		else
		{
			int px=find(f[x],col);
			col^=pcol[x];
			return px;
		}
	}
	inline void merge(int x,int y,Operation &p)
	{
//		debug(x,y);
		if(flag==false)
		{
			p.nothing=true;
			return;
		}
		int cx,cy;
		x=find(x,cx);
		y=find(y,cy);
		if(x==y)
		{
			if(cx==cy)
			{
				flag=false;
				p.cflag=true;
				return;
			}
			else
			{
				p.nothing=true;
				return;
			}
		}
		else
		{
			if(rk[x]<rk[y])
//			if(rand(0,1))
			{
				f[x]=y;
				p.cf=mp(x,y);
				pcol[x]=(cx^cy^1);
				p.crk=mp(x,rk[x]);
//				debug(x,pcol[x]);
			}
			else
			{
				f[y]=x;
				pcol[y]=(cx^cy^1);
				p.cf=mp(y,x);
				p.crk=mp(x,rk[x]);
				rk[x]+=(rk[x]==rk[y]);
//				debug(y,pcol[y]);
			}
		}
//		print();
	}
	inline void undo()
	{
		Operation p=operations.back();
		operations.pop_back();
		if(p.nothing) return;
		if(p.cflag)
		{
			flag=true;
			return;
		}
		f[p.cf.first]=p.cf.first;
		pcol[p.cf.first]=0;
		rk[p.crk.first]=p.crk.second;
	}
	inline string ok()
	{
		return (flag?"YES":"NO");
	}
	inline void init()
	{
		memset(c,-1,sizeof(c));
		memset(pcol,0,sizeof(pcol));
		for(int i=0;i<n;i++)
		{
			f[i]=i;
		}
		flag=true;
	}
	inline void add(Edge e)
	{
//		debug(e);
		operations.push_back(Operation());
		merge(e.x,e.y,operations.back());
	}
	inline void print()
	{
//		debug(1,pcol[1],f[1]);
//		for(int i=0;i<n;i++)
//		{
//			int col,fx;
//			fx=find(i,col);
//			cout<<col<<' ';
//			cout<<f[i]<<' ';
//		}
//		cout<<endl;
	}
	inline void test()
	{
		add({0,1});
		cout<<pcol[0]<<' '<<pcol[1]<<endl;
		exit(0);
	}
}dsu;

struct Manager
{
	vector<Edge> data[400005];
	
	int nn;
	inline void init()
	{
		nn=1;
		while(nn<q) nn<<=1;
	}
	inline void add(int l,int r,Edge e)
	{
//		debug(l,r,e.x,e.y);
		add(1,0,nn,l,r,e);
	}
	void add(int x,int l,int r,int ql,int qr,Edge e)
	{
		if(r<=ql || l>=qr) return;
		if(l>=ql && r<=qr)
		{
//			debug(x,e);
			data[x].push_back(e);
			return;
		}
		add(x*2,l,l+r>>1,ql,qr,e);
		add(x*2+1,l+r>>1,r,ql,qr,e);
	}
	void dfs(int x)
	{
//		debug(x);
		for(auto &q:data[x]) dsu.add(q);
		if(x<nn)
		{
			dfs(x*2);
			dfs(x*2+1);
		}
		else if(x<nn+q)
		{
//			for(int i=0;i<n;i++)
//			{
//				cout<<dsu.rk[i]<<' ';
//			}
//			cout<<endl;
//			dsu.print();
//			printf("%s\n",dsu.ok().c_str());
			puts(dsu.ok().c_str());
		}
		for(auto &q:data[x]) dsu.undo();
	}
	inline void solve()
	{
		dsu.init();
//		debug("FUCLK");
		dfs(1);
	}
}manager;

map<Edge,int> m;
int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	cin>>n>>q;
	dsu.init();
//	dsu.test();
//	for(int i=0;i<q;i++)
//	{
//		Edge e;
//		e.input();
//		dsu.add(e);
//		cout<<dsu.ok()<<endl;
//	}
//	exit(0);
	manager.init();
	for(int i=0;i<q;i++)
	{
		Edge e;
		e.input();
		if(m[e])
		{
			manager.add(m[e]-1,i,e);
			m[e]=0;
		}
		else
		{
			m[e]=i+1;
		}
	}
	for(auto &q:m)
	{
//		debug(q);
		if(q.second==0) continue;
		manager.add(q.second-1,::q,q.first);
	}
	manager.solve();
	return 0;
}