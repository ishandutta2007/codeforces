//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n, m;
//vector<int> edges[300005];
//int depth[300005];
//vector<pii> ed[300005];
//int sz[300005];
//
//struct Value
//{
//	multiset<pair<int, ll>, greater<pair<int, ll>>> squ;
//	multiset<ll> values;
//	ll delta;
//	Value()
//	{
//		squ.clear();
//		values.clear();
//		delta = 0;
//	}
//};
//ostream &operator<<(ostream &cout, const Value *v)
//{
//	cout << '{' << "delta=" << v->delta << ","
//		 << "squ=" << v->squ << ',' << "values=" << v->values << "}";
//	return cout;
//}
//
//inline void error()
//{
//	puts("-1");
//	exit(0);
//}
//
//void go(int x, int par = -1, int d = 0)
//{
//	depth[x] = d;
//	for (auto u : edges[x])
//	{
//		if (u == par)
//			continue;
//		go(u, x, d + 1);
//	}
//}
//
//void go2(int x, int par = -1)
//{
//	sz[x] = ed[x].size();
//	for (auto u : edges[x])
//	{
//		if (u == par)
//			continue;
//		go2(u, x);
//		sz[x] += sz[u];
//	}
//}
//
//inline void merge(Value *dp, Value *t)
//{
//	assert(dp && t);
//	// cout << "Merging:" << dp << ' ' << t << '=' << endl;
//	assert(!t->squ.empty());
//	ll mint = *t->values.begin(), mindp = *dp->values.begin();
//	// ll mint = llinf, mindp = llinf;
//	ll nv = dp->delta + t->delta;
//	// for (auto &o : (t->squ))
//	// {
//	// 	chmin(mint, o.second);
//	// }
//	// for (auto &o : (dp->squ))
//	// {
//	// 	chmin(mindp, o.second);
//	// }
//	dp->delta = nv + mint;
//	for (auto &o : (t->squ))
//	{
//		dp->squ.insert(mp(o.first, o.second - mint + mindp));
//		dp->values.insert(o.second - mint + mindp);
//	}
//	// cout << dp << endl;
//	delete t;
//}
//
//inline Value *make(const vector<pii> ed)
//{
//	Value *dp = new Value;
//	for (auto &o : ed)
//	{
//		dp->squ.insert(o);
//		dp->values.insert(o.second);
//	}
//	return dp;
//}
//
//Value *dfs(int x, int par)
//{
//	Value *dp = nullptr;
//	if ((x != 0 && edges[x].size() == 1))
//	{
//		dp = make(ed[x]);
//		if (dp->squ.empty())
//			error();
//		return dp;
//	}
//	pii maxSize = mp(-1, -1);
//	for (auto u : edges[x])
//	{
//		if (u == par)
//			continue;
//		chmax(maxSize, mp(sz[u], u));
//	}
//	// cout << x << ' ' << maxSize << endl;
//	for (auto u : edges[x])
//	{
//		if (u == par)
//			continue;
//		if (maxSize == mp(sz[u], u))
//		{
//			dp = dfs(u, x);
//			break;
//		}
//	}
//	for (auto u : edges[x])
//	{
//		if (u == par || maxSize == mp(sz[u], u))
//			continue;
//		merge(dp, dfs(u, x));
//	}
//	if (!ed[x].empty())
//	{
//		ed[x].push_back(mp(depth[x], 0));
//		Value *tmp = make(ed[x]);
//		merge(dp, tmp);
//	}
//	if (x == 0)
//		return dp;
//	while (!dp->squ.empty() && dp->squ.begin()->first == depth[x])
//	{
//		dp->values.erase(dp->values.find(dp->squ.begin()->second));
//		dp->squ.erase(dp->squ.begin());
//	}
//	// dp->squ.erase(dp->squ.begin());
//	if (dp->squ.empty())
//		error();
//	return dp;
//}
//
//namespace Test
//{
//	inline void test()
//	{
//		Value *a = new Value;
//		Value *b = new Value;
//		a->delta = 1;
//		b->delta = 5;
//		a->squ = {{2, 1}, {1, 3}};
//		b->squ = {{3, -1}, {1, -2}};
//		merge(a, b);
//		cout << a->delta << ' ' << a->squ << endl;
//	}
//} // namespace Test
//using Test::test;
//
//int main()
//{
//	// freopen("input.txt", "r", stdin);
//	// test();
//	cin >> n >> m;
//	if (n == 1)
//		over(0);
//	int x, y;
//	for (int i = 0; i < n - 1; i++)
//	{
//		scanf("%d%d", &x, &y);
//		x--;
//		y--;
//		edges[x].push_back(y);
//		edges[y].push_back(x);
//	}
//	int cntLeaf = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (edges[i].size() == 1 && (i != 0))
//			cntLeaf++;
//	}
//	// cout << cntLeaf << endl;
//	go(0, -1);
//	for (int i = 0; i < m; i++)
//	{
//		int x, y, c;
//		scanf("%d%d%d", &x, &y, &c);
//		x--;
//		y--;
//		if (x == y)
//			continue;
//		y = depth[y];
//		ed[x].push_back(mp(y, c));
//	}
//	go2(0, -1);
//	Value *dp = dfs(0, -1);
//	if (dp->squ.empty())
//		over(0);
//	ll minValue = llinf;
//	for (auto &o : dp->squ)
//	{
//		chmin(minValue, o.second);
//	}
//	printf("%lld\n", minValue + dp->delta);
//	delete dp;
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
#ifdef __TAKE_CONTROL_OF_MOD
int mod;
#else
const int mod=998244353;
#endif
const int gmod=2;
const int inf=1039074182;
const double eps=1e-9;
const ll llinf=1LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
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
pair<T1, T2> operator+(pair<T1, T2> x, pair<T1, T2> y)
{
	return make_pair(x.first + y.first, x.second + y.second);
}

template <typename T1, typename T2>
void operator+=(pair<T1, T2> &x, pair<T1, T2> y)
{
	x.first += y.first;
	x.second += y.second;
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
int n, m;
vector<int> edges[300005];
int depth[300005];
vector<pii> ed[300005];
int sz[300005];

struct Value
{
	multiset<pair<int, ll>, greater<pair<int, ll>>> squ;
	multiset<ll> values;
	ll delta;
	Value()
	{
		squ.clear();
		values.clear();
		delta = 0;
	}
};
ostream &operator<<(ostream &cout, const Value *v)
{
	cout << '{' << "delta=" << v->delta << ","
		 << "squ=" << v->squ << ',' << "values=" << v->values << "}";
	return cout;
}

inline void error()
{
	puts("-1");
	exit(0);
}

void go(int x, int par = -1, int d = 0)
{
	depth[x] = d;
	for (auto u : edges[x])
	{
		if (u == par)
			continue;
		go(u, x, d + 1);
	}
}

void go2(int x, int par = -1)
{
	sz[x] = ed[x].size();
	for (auto u : edges[x])
	{
		if (u == par)
			continue;
		go2(u, x);
		sz[x] += sz[u];
	}
}

inline void merge(Value *dp, Value *t)
{
	assert(dp && t);
	// cout << "Merging:" << dp << ' ' << t << '=' << endl;
	assert(!t->squ.empty());
	ll mint = *t->values.begin(), mindp = *dp->values.begin();
	// ll mint = llinf, mindp = llinf;
	ll nv = dp->delta + t->delta;
	// for (auto &o : (t->squ))
	// {
	// 	chmin(mint, o.second);
	// }
	// for (auto &o : (dp->squ))
	// {
	// 	chmin(mindp, o.second);
	// }
	dp->delta = nv + mint;
	for (auto &o : (t->squ))
	{
		dp->squ.insert(mp(o.first, o.second - mint + mindp));
		dp->values.insert(o.second - mint + mindp);
	}
	// cout << dp << endl;
	delete t;
}

inline Value *make(const vector<pii> ed)
{
	Value *dp = new Value;
	for (auto &o : ed)
	{
		dp->squ.insert(o);
		dp->values.insert(o.second);
	}
	return dp;
}

Value *dfs(int x, int par)
{
	Value *dp = nullptr;
	if ((x != 0 && edges[x].size() == 1))
	{
		dp = make(ed[x]);
		if (dp->squ.empty())
			error();
		return dp;
	}
	pii maxSize = mp(-1, -1);
	for (auto u : edges[x])
	{
		if (u == par)
			continue;
		chmax(maxSize, mp(sz[u], u));
	}
	// cout << x << ' ' << maxSize << endl;
	for (auto u : edges[x])
	{
		if (u == par)
			continue;
		if (maxSize == mp(sz[u], u))
		{
			dp = dfs(u, x);
			break;
		}
	}
	for (auto u : edges[x])
	{
		if (u == par || maxSize == mp(sz[u], u))
			continue;
		merge(dp, dfs(u, x));
	}
	if (!ed[x].empty())
	{
		ed[x].push_back(mp(depth[x], 0));
		Value *tmp = make(ed[x]);
		merge(dp, tmp);
	}
	if (x == 0)
		return dp;
	while (!dp->squ.empty() && dp->squ.begin()->first == depth[x])
	{
		dp->values.erase(dp->values.find(dp->squ.begin()->second));
		dp->squ.erase(dp->squ.begin());
	}
	// dp->squ.erase(dp->squ.begin());
	if (dp->squ.empty())
		error();
	return dp;
}

namespace Test
{
	inline void test()
	{
		Value *a = new Value;
		Value *b = new Value;
		a->delta = 1;
		b->delta = 5;
		a->squ = {{2, 1}, {1, 3}};
		b->squ = {{3, -1}, {1, -2}};
		merge(a, b);
		cout << a->delta << ' ' << a->squ << endl;
	}
} // namespace Test
using Test::test;

int main()
{
	// freopen("input.txt", "r", stdin);
	// test();
	cin >> n >> m;
	if (n == 1)
		over(0);
	int x, y;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d%d", &x, &y);
		x--;
		y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	int cntLeaf = 0;
	for (int i = 0; i < n; i++)
	{
		if (edges[i].size() == 1 && (i != 0))
			cntLeaf++;
	}
	// cout << cntLeaf << endl;
	go(0, -1);
	for (int i = 0; i < m; i++)
	{
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		x--;
		y--;
		if (x == y)
			continue;
		y = depth[y];
		ed[x].push_back(mp(y, c));
	}
	go2(0, -1);
	Value *dp = dfs(0, -1);
	if (dp->squ.empty())
		over(0);
	ll minValue = llinf;
	for (auto &o : dp->squ)
	{
		chmin(minValue, o.second);
	}
	printf("%lld\n", minValue + dp->delta);
	delete dp;
	return 0;
}