//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n,m;
//vector<int> edges[45];
//int col[45];
//
//namespace BipariteGraph
//{
//	int dfs(int x)
//	{
//		for(auto u:edges[x])
//		{
//			if(col[u]==-1)
//			{
//				col[u]=col[x]^1;
//				if(!dfs(u)) return false;
//			}
//			else if(col[u]==col[x]) return false;
//		}
//		return true;
//	}
//	int count()
//	{
//		memset(col,-1,sizeof(col));
//		int res=0;
//		for(int i=0;i<n;i++)
//		{
//			if(col[i]==-1)
//			{
//				col[i]=0;
//				res++;
//				if(!dfs(i)) return -1;
//			}
//		}
//		return res;
//	}
//}
//
//namespace ConnectedComponent
//{
//	int vis[45];
//	void dfs(int x)
//	{
//		vis[x]=1;
//		for(auto u:edges[x])
//		{
//			if(vis[u]) continue;
//			dfs(u);
//		}
//	}
//	int count()
//	{
//		int res=0;
//		for(int i=0;i<n;i++)
//		{
//			if(!vis[i])
//			{
//				dfs(i);
//				res++;
//			}
//		}
//		return res;
//	}
//}
//
//namespace Hard
//{
//	ll adj[45];
//	const int B=20;
//	ll f[(1<<20)];
//	ll count()
//	{
//		ll res=0;
//		for(int i=0;i<n;i++)
//		{
//			for(auto j:edges[i]) adj[i]|=(1LL<<j);
//		}
//		for(int mask=0;mask<(1<<B);mask++)
//		{
//			int flag=1;
//			for(int i=0;i<B;i++) if(((adj[i] & mask) || (i>=n)) && ((1<<i) & mask)) flag=0;
//			if(!flag) continue;
//			f[mask]++;
//		}
//		for(int j=1;j<(1<<B);j<<=1)
//		{
//			for(int i=0;i<(1<<B);i++) if(i & j) f[i]+=f[i^j];
//		}
//		// cout<<f[(1<<B)-1]<<endl;
//		for(int mask=0;mask<(1<<B);mask++)
//		{
//			int flag=1;
//			int pt=0;
//			for(int i=0;i<B;i++)
//			{
//				if(((1<<i) & mask) && (i+B>=n || ((adj[i+B]>>B) & mask))) flag=0;
//				if((1<<i) & mask) pt|=adj[i+B] & ((1<<B)-1);
//			}
//			if(!flag) continue;
//			res+=f[((1<<B)-1)^pt];
//		}
//		return res;
//	}
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>n>>m;
//	for(int i=0;i<m;i++)
//	{
//		int x,y;
//		scanf("%d%d",&x,&y);
//		x--;y--;
//		edges[x].emplace_back(y);
//		edges[y].emplace_back(x);
//	}
//	int s0=0;
//	for(int i=0;i<n;i++) s0+=(edges[i].size()==0);
//	ll res=(1LL<<n);
//	res-=(m==0)*(1LL<<n);
//	memset(col,-1,sizeof(col));
//	int cnt=BipariteGraph::count();
//	if(cnt!=-1) res+=(1LL<<cnt);
//	res+=2*(1LL<<s0);
//	res-=(1LL<<ConnectedComponent::count());
//	res-=2*Hard::count();
//	cout<<res<<endl;
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
#define mp(a,b) make_pair(a,b)
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
		std::cout<<(x&1);
		x>>=1;
		len--;
		// vec.push_back(x&1);
		// x>>=1;
	}
	while(len--) cout<<0;
	// reverse(vec.begin(),vec.end());
	// for(int i=(int)vec.size();i<len;i++)
	// {
	// 	putchar('0');
	// }
	// for(size_t i=0;i<vec.size();i++)
	// {
	// 	std::cout<<vec[i];
	// }
	// std::cout<<' ';
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
int n,m;
vector<int> edges[45];
int col[45];

namespace BipariteGraph
{
	int dfs(int x)
	{
		for(auto u:edges[x])
		{
			if(col[u]==-1)
			{
				col[u]=col[x]^1;
				if(!dfs(u)) return false;
			}
			else if(col[u]==col[x]) return false;
		}
		return true;
	}
	int count()
	{
		memset(col,-1,sizeof(col));
		int res=0;
		for(int i=0;i<n;i++)
		{
			if(col[i]==-1)
			{
				col[i]=0;
				res++;
				if(!dfs(i)) return -1;
			}
		}
		return res;
	}
}

namespace ConnectedComponent
{
	int vis[45];
	void dfs(int x)
	{
		vis[x]=1;
		for(auto u:edges[x])
		{
			if(vis[u]) continue;
			dfs(u);
		}
	}
	int count()
	{
		int res=0;
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
			{
				dfs(i);
				res++;
			}
		}
		return res;
	}
}

namespace Hard
{
	ll adj[45];
	const int B=20;
	ll f[(1<<20)];
	ll count()
	{
		ll res=0;
		for(int i=0;i<n;i++)
		{
			for(auto j:edges[i]) adj[i]|=(1LL<<j);
		}
		for(int mask=0;mask<(1<<B);mask++)
		{
			int flag=1;
			for(int i=0;i<B;i++) if(((adj[i] & mask) || (i>=n)) && ((1<<i) & mask)) flag=0;
			if(!flag) continue;
			f[mask]++;
		}
		for(int j=1;j<(1<<B);j<<=1)
		{
			for(int i=0;i<(1<<B);i++) if(i & j) f[i]+=f[i^j];
		}
		// cout<<f[(1<<B)-1]<<endl;
		for(int mask=0;mask<(1<<B);mask++)
		{
			int flag=1;
			int pt=0;
			for(int i=0;i<B;i++)
			{
				if(((1<<i) & mask) && (i+B>=n || ((adj[i+B]>>B) & mask))) flag=0;
				if((1<<i) & mask) pt|=adj[i+B] & ((1<<B)-1);
			}
			if(!flag) continue;
			res+=f[((1<<B)-1)^pt];
		}
		return res;
	}
}

int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;y--;
		edges[x].emplace_back(y);
		edges[y].emplace_back(x);
	}
	int s0=0;
	for(int i=0;i<n;i++) s0+=(edges[i].size()==0);
	ll res=(1LL<<n);
	res-=(m==0)*(1LL<<n);
	memset(col,-1,sizeof(col));
	int cnt=BipariteGraph::count();
	if(cnt!=-1) res+=(1LL<<cnt);
	res+=2*(1LL<<s0);
	res-=(1LL<<ConnectedComponent::count());
	res-=2*Hard::count();
	cout<<res<<endl;
	return 0;
}