//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/ModInt>
//using namespace std;
//using Int=ModInt <998244353>;
//int n,m;
//vector <int> edges[200005];
//vector <int> invEdges[200005];
//
//struct Distance
//{
//	int base;
//	int exp;
//	Distance(){exp=2000000;base=2000000;}
//	Distance(int _b):base(_b),exp(0){}
//	Distance(int _b,int _e):base(_b),exp(_e){}
//	bool operator < (const Distance &d)const&
//	{
//		if(exp<=20 && d.exp<=20) return (base+(1<<exp))<(d.base+(1<<d.exp));
//		if(exp!=d.exp) return exp<d.exp;
//		return base<d.base;
//	}
//	bool operator == (const Distance &d)const&
//	{
//		return !((*this)<d) && !(d<(*this));
//	}
//	bool operator != (const Distance &d)const&
//	{
//		return !((*this)==d);
//	}
//}dist[200005][22];
//
//inline void dijkstra()
//{
//	set <pair<Distance,pii> > squ;
//	squ.insert(mp(0,mp(0,0)));
//	dist[0][0]=Distance(0);
//	while(squ.size())
//	{
//		Distance s=squ.begin()->first;
//		int x=squ.begin()->second.first;
//		int level=squ.begin()->second.second;
//		squ.erase(squ.begin());
//		if(s!=dist[x][level]) continue;
//		if(level&1)
//		{
//			for(auto u:invEdges[x])
//			{
//				Distance ns(s.base+1,s.exp);
//				if(ns<dist[u][level])
//				{
//					dist[u][level]=ns;
//					squ.insert(mp(dist[u][level],mp(u,level)));
//				}
//			}
//		}
//		else
//		{
//			for(auto u:edges[x])
//			{
//				Distance ns(s.base+1,s.exp);
//				if(ns<dist[u][level])
//				{
//					dist[u][level]=ns;
//					squ.insert(mp(dist[u][level],mp(u,level)));
//				}
//			}
//		}
//		Distance ns(s.base,s.exp+1);
//		int nlevel=level+1;
//		if(nlevel==21) nlevel=19;
//		int u=x;
//		if(ns<dist[u][nlevel])
//		{
//			dist[u][nlevel]=ns;
//			squ.insert(mp(dist[u][nlevel],mp(u,nlevel)));
//		}
//	}
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	scanf("%d%d",&n,&m);
//	int x,y;
//	for(int i=0;i<m;i++)
//	{
//		scanf("%d%d",&x,&y);
//		x--;
//		y--;
//		edges[x].push_back(y);
//		invEdges[y].push_back(x);
//	}
//	dijkstra();
//	Distance res;
//	for(int level=0;level<=20;level++)
//	{
//		chmin(res,dist[n-1][level]);
//	}
//	Int base=res.base;
//	cout<<base+(Int(2)^res.exp)-1<<endl;
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
using namespace std;
using Int=ModInt <998244353>;
int n,m;
vector <int> edges[200005];
vector <int> invEdges[200005];

struct Distance
{
	int base;
	int exp;
	Distance(){exp=2000000;base=2000000;}
	Distance(int _b):base(_b),exp(0){}
	Distance(int _b,int _e):base(_b),exp(_e){}
	bool operator < (const Distance &d)const&
	{
		if(exp<=20 && d.exp<=20) return (base+(1<<exp))<(d.base+(1<<d.exp));
		if(exp!=d.exp) return exp<d.exp;
		return base<d.base;
	}
	bool operator == (const Distance &d)const&
	{
		return !((*this)<d) && !(d<(*this));
	}
	bool operator != (const Distance &d)const&
	{
		return !((*this)==d);
	}
}dist[200005][22];

inline void dijkstra()
{
	set <pair<Distance,pii> > squ;
	squ.insert(mp(0,mp(0,0)));
	dist[0][0]=Distance(0);
	while(squ.size())
	{
		Distance s=squ.begin()->first;
		int x=squ.begin()->second.first;
		int level=squ.begin()->second.second;
		squ.erase(squ.begin());
		if(s!=dist[x][level]) continue;
		if(level&1)
		{
			for(auto u:invEdges[x])
			{
				Distance ns(s.base+1,s.exp);
				if(ns<dist[u][level])
				{
					dist[u][level]=ns;
					squ.insert(mp(dist[u][level],mp(u,level)));
				}
			}
		}
		else
		{
			for(auto u:edges[x])
			{
				Distance ns(s.base+1,s.exp);
				if(ns<dist[u][level])
				{
					dist[u][level]=ns;
					squ.insert(mp(dist[u][level],mp(u,level)));
				}
			}
		}
		Distance ns(s.base,s.exp+1);
		int nlevel=level+1;
		if(nlevel==21) nlevel=19;
		int u=x;
		if(ns<dist[u][nlevel])
		{
			dist[u][nlevel]=ns;
			squ.insert(mp(dist[u][nlevel],mp(u,nlevel)));
		}
	}
}

int main()
{
//	// freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		edges[x].push_back(y);
		invEdges[y].push_back(x);
	}
	dijkstra();
	Distance res;
	for(int level=0;level<=20;level++)
	{
		chmin(res,dist[n-1][level]);
	}
	Int base=res.base;
	cout<<base+(Int(2)^res.exp)-1<<endl;
	return 0;
}