//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n,m;
//vector<int> edges[100005];
//int regions;
//vector<int> v[100005];
//pii edge[100005];
//map<pii,int> ids;
//int from[400005],to[400005],pos[400005],cnt,bel[400005];
//int vis[400005];
//int rk[100005];
//vector<vector<int> > vSort;
//int res[100005];
//
//void dfs1(int x,int j,int reg,vector<int> &v)
//{
//	// debug(x,j,reg,v);
//	int y=edges[x][j],id=ids[mp(y,x)],id2=ids[mp(x,y)];
//	if(vis[id2]) return;
//	vis[id2]=1;
//	v.emplace_back(x);
//	bel[id2]=reg;
//	// id=(id+1)%edges[y].size();
//	// debug(y,id,id2);
//	if(x!=y) dfs1(y,(pos[id]+1)%edges[y].size(),reg,v);
//}
//
//int dfs2(int x,int par=-1)
//{
//	int ban=0;
//	for(auto u:edges[x])
//	{
//		if(u==par) continue;
//		int ban2=dfs2(u,x);
//		if(ban2 & ban)
//		{
//			int x=__builtin_ctz(ban2 & ban);
//			for(int j=x;j<20;j++) ban|=(1<<j);
//		}
//		ban|=ban2;
//	}
//	for(int i=19;i>=0;i--)
//	{
//		if(ban & (1<<i)) continue;
//		ban|=(1<<i);
//		for(int j=19;j>i;j--) ban&=~(1<<j);
//		res[x]=i;
//		return ban;
//	}
//	assert(0);return 0;
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
//		edge[i]=mp(x,y);
//		edges[x].emplace_back(y);
//		edges[y].emplace_back(x);
//	}
//	for(int i=0;i<n;i++)
//	{
//		int x=i,y=(i+1)%n;
//		edges[x].emplace_back(y);
//		edges[y].emplace_back(x);
//	}
//	for(int i=0;i<n;i++)
//	{
//		sort(all(edges[i]),[&](int x,int y){
//			if((x<i)!=(y<i)) return (x<i)>(y<i);
//			return x>y;
//		});
//		for(int j=0;j<(int)edges[i].size();j++)
//		{
//			int x=i,y=edges[i][j];
//			ids[mp(x,y)]=cnt;
//			from[cnt]=x;to[cnt]=y;pos[cnt]=j;cnt++;
//		}
//	}
//	// for(int i=0;i<n;i++) debug(i,edges[i]);
//	// for(int i=0;i<n;i++) debug(edges[i]);
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<(int)edges[i].size();j++)
//		{
//			// j=1;
//			int x=i,y=edges[i][j];
//			int id=ids[mp(x,y)];
//			if(vis[id]) continue;
//			dfs1(i,j,regions,v[regions]);
//			regions++;
//		}
//		// return 0;
//	}
//	for(int i=0;i<regions;i++)
//	{
//		sort(all(v[i]));reverse(all(v[i]));
//		vSort.emplace_back(v[i]);
//	}
//	sort(all(vSort));
//	for(int i=0;i<regions;i++)
//	{
//		rk[i]=lower_bound(all(vSort),v[i])-vSort.begin();
//	}
//	regions--;
//	for(int i=0;i<regions;i++) edges[i].clear();
//	for(int i=0;i<m;i++)
//	{
//		auto [x,y]=edge[i];
//		int a=rk[bel[ids[mp(x,y)]]];
//		int b=rk[bel[ids[mp(y,x)]]];
//		// debug(a,b);
//		edges[a].emplace_back(b);
//		edges[b].emplace_back(a);
//	}
//	dfs2(0);
//	// debug(regions);
//	// debug(edges[0],edges[1]);
//	for(int i=0;i<regions;i++)
//	{
//		cout<<res[i]<<' ';
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
vector<int> edges[100005];
int regions;
vector<int> v[100005];
pii edge[100005];
map<pii,int> ids;
int from[400005],to[400005],pos[400005],cnt,bel[400005];
int vis[400005];
int rk[100005];
vector<vector<int> > vSort;
int res[100005];

void dfs1(int x,int j,int reg,vector<int> &v)
{
	// debug(x,j,reg,v);
	int y=edges[x][j],id=ids[mp(y,x)],id2=ids[mp(x,y)];
	if(vis[id2]) return;
	vis[id2]=1;
	v.emplace_back(x);
	bel[id2]=reg;
	// id=(id+1)%edges[y].size();
	// debug(y,id,id2);
	if(x!=y) dfs1(y,(pos[id]+1)%edges[y].size(),reg,v);
}

int dfs2(int x,int par=-1)
{
	int ban=0;
	for(auto u:edges[x])
	{
		if(u==par) continue;
		int ban2=dfs2(u,x);
		if(ban2 & ban)
		{
			int x=__builtin_ctz(ban2 & ban);
			for(int j=x;j<20;j++) ban|=(1<<j);
		}
		ban|=ban2;
	}
	for(int i=19;i>=0;i--)
	{
		if(ban & (1<<i)) continue;
		ban|=(1<<i);
		for(int j=19;j>i;j--) ban&=~(1<<j);
		res[x]=i;
		return ban;
	}
	assert(0);return 0;
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
		edge[i]=mp(x,y);
		edges[x].emplace_back(y);
		edges[y].emplace_back(x);
	}
	for(int i=0;i<n;i++)
	{
		int x=i,y=(i+1)%n;
		edges[x].emplace_back(y);
		edges[y].emplace_back(x);
	}
	for(int i=0;i<n;i++)
	{
		sort(all(edges[i]),[&](int x,int y){
			if((x<i)!=(y<i)) return (x<i)>(y<i);
			return x>y;
		});
		for(int j=0;j<(int)edges[i].size();j++)
		{
			int x=i,y=edges[i][j];
			ids[mp(x,y)]=cnt;
			from[cnt]=x;to[cnt]=y;pos[cnt]=j;cnt++;
		}
	}
	// for(int i=0;i<n;i++) debug(i,edges[i]);
	// for(int i=0;i<n;i++) debug(edges[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(int)edges[i].size();j++)
		{
			// j=1;
			int x=i,y=edges[i][j];
			int id=ids[mp(x,y)];
			if(vis[id]) continue;
			dfs1(i,j,regions,v[regions]);
			regions++;
		}
		// return 0;
	}
	for(int i=0;i<regions;i++)
	{
		sort(all(v[i]));reverse(all(v[i]));
		vSort.emplace_back(v[i]);
	}
	sort(all(vSort));
	for(int i=0;i<regions;i++)
	{
		rk[i]=lower_bound(all(vSort),v[i])-vSort.begin();
	}
	regions--;
	for(int i=0;i<regions;i++) edges[i].clear();
	for(int i=0;i<m;i++)
	{
		auto [x,y]=edge[i];
		int a=rk[bel[ids[mp(x,y)]]];
		int b=rk[bel[ids[mp(y,x)]]];
		// debug(a,b);
		edges[a].emplace_back(b);
		edges[b].emplace_back(a);
	}
	dfs2(0);
	// debug(regions);
	// debug(edges[0],edges[1]);
	for(int i=0;i<regions;i++)
	{
		cout<<res[i]<<' ';
	}
	return 0;
}