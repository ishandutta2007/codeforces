//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n;
//int w[500005];
//vector<int> edges[500005];
//vector<int> lsh;
//vector<pii> incr[500005],decr[500005];
//int depth[500005];
//int heavy[500005];
//pair<int,pii> best;
//
//int curID;
//inline pii queryInc(const vector<pii> &v,int val)
//{
//	int l=0,r=v.size()-1,mid,res=-1;
//	while(l<=r)
//	{
//		mid=(l+r)>>1;
//		if(v[mid].first<val)
//		{
//			res=mid;
//			l=mid+1;
//		}
//		else
//		{
//			r=mid-1;
//		}
//	}
//	if(res==-1) return mp(0,curID);
//	else return mp(res+1,v[res].second);
//}
//
//inline pii queryDec(const vector<pii> &v,int val)
//{
//	int l=0,r=v.size()-1,mid,res=-1;
//	while(l<=r)
//	{
//		mid=(l+r)>>1;
//		if(v[mid].first>val)
//		{
//			res=mid;
//			l=mid+1;
//		}
//		else
//		{
//			r=mid-1;
//		}
//	}
//	if(res==-1) return mp(0,curID);
//	else return mp(res+1,v[res].second);
//}
//
//void dfs(int x,int par)
//{
//	depth[x]=0;
//	heavy[x]=-1;
//	for(auto u:edges[x])
//	{
//		if(u==par) continue;
//		dfs(u,x);
//		chmax(depth[x],depth[u]);
//		if(heavy[x]==-1 || depth[u]>depth[heavy[x]]) heavy[x]=u;
//	}
//	curID=x;
//	if(heavy[x]!=-1) swap(incr[x],incr[heavy[x]]),swap(decr[x],decr[heavy[x]]);
//	depth[x]++;
//	for(auto u:edges[x])
//	{
//		if(u==par) continue;
//		if(u==heavy[x]) continue;
//		for(int i=0;i<(int)incr[u].size();i++)
//		{
//			auto o=incr[u][i];
//			pii t=queryDec(decr[x],o.first);
//			chmax(best,mp(t.first+i+1,mp(t.second,o.second)));
//		}
//		for(int i=0;i<(int)decr[u].size();i++)
//		{
//			auto o=decr[u][i];
//			pii t=queryInc(incr[x],o.first);
//			chmax(best,mp(t.first+i+1,mp(t.second,o.second)));
//		}
//		pii o1,o2;
//		o1=queryInc(incr[x],w[x]);o2=queryDec(decr[u],w[x]);
//		chmax(best,mp(1+o1.first+o2.first,mp(o1.second,o2.second)));
//		o1=queryDec(decr[x],w[x]);o2=queryInc(incr[u],w[x]);
//		chmax(best,mp(1+o1.first+o2.first,mp(o1.second,o2.second)));
//		if(incr[x].size()<incr[u].size()) incr[x].resize(incr[u].size(),mp(inf,-1));
//		if(decr[x].size()<decr[u].size()) decr[x].resize(decr[u].size(),mp(-inf,-1));
//		for(int i=0;i<(int)incr[u].size();i++)
//		{
//			chmin(incr[x][i],incr[u][i]);
//		}
//		for(int i=0;i<(int)decr[u].size();i++)
//		{
//			chmax(decr[x][i],decr[u][i]);
//		}
//	}
//	pii o;
//	o=queryInc(incr[x],w[x]);
//	if(o.first>=(int)incr[x].size()) incr[x].emplace_back(mp(w[x],o.second));
//	else chmin(incr[x][o.first],mp(w[x],o.second));
//	o=queryDec(decr[x],w[x]);
//	if(o.first>=(int)decr[x].size()) decr[x].emplace_back(mp(w[x],o.second));
//	else chmax(decr[x][o.first],mp(w[x],o.second));
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>n;
//	for(int i=0;i<n;i++) scanf("%d",w+i),lsh.push_back(w[i]);
//	for(int i=0;i<n-1;i++)
//	{
//		int x,y;
//		scanf("%d%d",&x,&y);
//		x--;
//		y--;
//		edges[x].emplace_back(y);
//		edges[y].emplace_back(x);
//	}
//	sort(all(lsh));
//	lsh.erase(unique(all(lsh)),lsh.end());
//	for(int i=0;i<n;i++) w[i]=lower_bound(all(lsh),w[i])-lsh.begin();
//	dfs(0,-1);
//	chmax(best,mp((int)incr[0].size(),mp(0,incr[0].back().second)));
//	chmax(best,mp((int)decr[0].size(),mp(0,decr[0].back().second)));
//	cout<<best.first<<endl;
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
int n;
int w[500005];
vector<int> edges[500005];
vector<int> lsh;
vector<pii> incr[500005],decr[500005];
int depth[500005];
int heavy[500005];
pair<int,pii> best;

int curID;
inline pii queryInc(const vector<pii> &v,int val)
{
	int l=0,r=v.size()-1,mid,res=-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(v[mid].first<val)
		{
			res=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	if(res==-1) return mp(0,curID);
	else return mp(res+1,v[res].second);
}

inline pii queryDec(const vector<pii> &v,int val)
{
	int l=0,r=v.size()-1,mid,res=-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(v[mid].first>val)
		{
			res=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	if(res==-1) return mp(0,curID);
	else return mp(res+1,v[res].second);
}

void dfs(int x,int par)
{
	depth[x]=0;
	heavy[x]=-1;
	for(auto u:edges[x])
	{
		if(u==par) continue;
		dfs(u,x);
		chmax(depth[x],depth[u]);
		if(heavy[x]==-1 || depth[u]>depth[heavy[x]]) heavy[x]=u;
	}
	curID=x;
	if(heavy[x]!=-1) swap(incr[x],incr[heavy[x]]),swap(decr[x],decr[heavy[x]]);
	depth[x]++;
	for(auto u:edges[x])
	{
		if(u==par) continue;
		if(u==heavy[x]) continue;
		for(int i=0;i<(int)incr[u].size();i++)
		{
			auto o=incr[u][i];
			pii t=queryDec(decr[x],o.first);
			chmax(best,mp(t.first+i+1,mp(t.second,o.second)));
		}
		for(int i=0;i<(int)decr[u].size();i++)
		{
			auto o=decr[u][i];
			pii t=queryInc(incr[x],o.first);
			chmax(best,mp(t.first+i+1,mp(t.second,o.second)));
		}
		pii o1,o2;
		o1=queryInc(incr[x],w[x]);o2=queryDec(decr[u],w[x]);
		chmax(best,mp(1+o1.first+o2.first,mp(o1.second,o2.second)));
		o1=queryDec(decr[x],w[x]);o2=queryInc(incr[u],w[x]);
		chmax(best,mp(1+o1.first+o2.first,mp(o1.second,o2.second)));
		if(incr[x].size()<incr[u].size()) incr[x].resize(incr[u].size(),mp(inf,-1));
		if(decr[x].size()<decr[u].size()) decr[x].resize(decr[u].size(),mp(-inf,-1));
		for(int i=0;i<(int)incr[u].size();i++)
		{
			chmin(incr[x][i],incr[u][i]);
		}
		for(int i=0;i<(int)decr[u].size();i++)
		{
			chmax(decr[x][i],decr[u][i]);
		}
	}
	pii o;
	o=queryInc(incr[x],w[x]);
	if(o.first>=(int)incr[x].size()) incr[x].emplace_back(mp(w[x],o.second));
	else chmin(incr[x][o.first],mp(w[x],o.second));
	o=queryDec(decr[x],w[x]);
	if(o.first>=(int)decr[x].size()) decr[x].emplace_back(mp(w[x],o.second));
	else chmax(decr[x][o.first],mp(w[x],o.second));
}

int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++) scanf("%d",w+i),lsh.push_back(w[i]);
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		edges[x].emplace_back(y);
		edges[y].emplace_back(x);
	}
	sort(all(lsh));
	lsh.erase(unique(all(lsh)),lsh.end());
	for(int i=0;i<n;i++) w[i]=lower_bound(all(lsh),w[i])-lsh.begin();
	dfs(0,-1);
	chmax(best,mp((int)incr[0].size(),mp(0,incr[0].back().second)));
	chmax(best,mp((int)decr[0].size(),mp(0,decr[0].back().second)));
	cout<<best.first<<endl;
	return 0;
}