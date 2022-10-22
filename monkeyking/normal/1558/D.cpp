//Original Code:
//#define __TAKE_CONST_MOD 998244353
//#include <self/utility>
//#include <self/debug>
//#include <self/combinatorics>
//#include <self/rand>
//using namespace std;
//using combinatorics::C;
//
//struct node
//{
//	node *l=nullptr,*r=nullptr;
//	int data;
//	int count=1;
//	int rd=rand(1,1000000000);
//	int size=1;
//	int sm=0;
//	int key;
//	// node(){}
//	node(int _key,int _data):key(_key),data(_data){}
//};
//
//inline void pushup(node *rt)
//{
//	rt->size=(rt->l==nullptr?0:rt->l->size)+(rt->r==nullptr?0:rt->r->size)+rt->count;
//}
//
//inline void pushtag(node *rt,int sm)
//{
//	if(!rt) return;
//	rt->sm+=sm;
//	rt->key+=sm;
//}
//
//inline void pushdown(node *rt)
//{
//	pushtag(rt->l,rt->sm);
//	pushtag(rt->r,rt->sm);
//	rt->sm=0;
//}
//
//pair<node*,node*> split(node *rt,int key)
//{
//	if(rt==nullptr) return mp(nullptr,nullptr);
//	pushdown(rt);
//	if(rt->key<=key)
//	{
//		pair<node*,node*> p=split(rt->r,key);
//		rt->r=p.first;
//		pushup(rt);
//		return mp(rt,p.second);
//	}
//	else
//	{
//		pair<node*,node*> p=split(rt->l,key);
//		rt->l=p.second;
//		pushup(rt);
//		return mp(p.first,rt);
//	}
//}
//
//int sz(node *rt)
//{
//	return (rt==nullptr?0:rt->size);
//}
//
//node* merge(node *x,node *y)
//{
//	if(x==nullptr) return y;
//	if(y==nullptr) return x;
//	if(x->rd<y->rd)
//	{
//		pushdown(y);
//		y->l=merge(x,y->l);
//		pushup(y);
//		return y;
//	}
//	else
//	{
//		pushdown(x);
//		x->r=merge(x->r,y);
//		pushup(x);
//		return x;
//	}
//}
//
//int count(node *rt,int x)
//{
//	if(rt==nullptr) return 0;
//	if(rt->data==x) return rt->count;
//	if(rt->data<=x) return count(rt->r,x);else return count(rt->l,x);
//}
//
//int checksum(node *rt)
//{
//	if(!rt) return 0;
//	return rt->data+checksum(rt->l)+checksum(rt->r);
//}
//
//int n,m;
//void solve()
//{
//	scanf("%d%d",&n,&m);
//	node *rt=0;
//	for(int i=0;i<m;i++)
//	{
//		int x,y;
//		scanf("%d%d",&x,&y);
//		x--;
//		y--;
//		pair<node*,node*> o1=split(rt,y-1);
//		pushtag(o1.second,1);
//		pair<node*,node*> o2=split(o1.first,y-2);
//		if(o2.second) o2.second->data=0;
//		rt=merge(merge(merge(o2.first,o2.second),new node(y,1)),o1.second);
//	}
//	printf("%d\n",C(n+n-1-checksum(rt),n));
//}
//
//int main()
//{
//	combinatorics::init(400000,mod);
//	int T;
//	cin>>T;
//	while(T--)
//	{
//		solve();
//	}
//	return 0;
//}

//substituted with C++ Inliner
#define __TAKE_CONST_MOD 998244353
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
namespace combinatorics
{
	int *fac;
	int *ifac;
	int __Tmod;
	inline int add(int a,int b)
	{
		return (a+b)%__Tmod;
	}
	inline int sub(int a,int b)
	{
		return (a-b+__Tmod)%__Tmod;
	}
	inline int mult(int a,int b)
	{
		return (1LL*a*b)%__Tmod;
	}
	inline int fastpow(int basic,int x)
	{
		chmod(x,__Tmod-1);
		if(x==0) return 1;
		int res=1;
		while(x)
		{
			if(x&1)	res=mult(res,basic);
			basic=mult(basic,basic);
			x>>=1;
		}
		return res;
	}
	inline int inv(int x)
	{
		return fastpow(x,__Tmod-2);
	}
	inline int div(int a,int b)
	{
		return mult(a,inv(b));
	}
	void init(int n,int tmod)
	{
		__Tmod=tmod;
		fac=new int[n+5];
		ifac=new int[n+5];
		fac[0]=1;
		for(int i=1;i<=n;i++)
		{
			fac[i]=mult(fac[i-1],i);
		}
		ifac[n]=inv(fac[n]);
		for(int i=n-1;i>=0;i--)
		{
			ifac[i]=mult(ifac[i+1],i+1);
		}
	}
	inline int C(int n,int m)
	{
		if(n<m || n<0 || m<0) return 0;
		return mult(mult(fac[n],ifac[m]),ifac[n-m]);
	}
	inline int Cat(int x)
	{
		return mult(C(x*2,x),inv(x+1));
	}
}

#ifndef _SELF_RAND
#define _SELF_RAND 1
#if __cplusplus < 201103L
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
using combinatorics::C;

struct node
{
	node *l=nullptr,*r=nullptr;
	int data;
	int count=1;
	int rd=rand(1,1000000000);
	int size=1;
	int sm=0;
	int key;
	// node(){}
	node(int _key,int _data):key(_key),data(_data){}
};

inline void pushup(node *rt)
{
	rt->size=(rt->l==nullptr?0:rt->l->size)+(rt->r==nullptr?0:rt->r->size)+rt->count;
}

inline void pushtag(node *rt,int sm)
{
	if(!rt) return;
	rt->sm+=sm;
	rt->key+=sm;
}

inline void pushdown(node *rt)
{
	pushtag(rt->l,rt->sm);
	pushtag(rt->r,rt->sm);
	rt->sm=0;
}

pair<node*,node*> split(node *rt,int key)
{
	if(rt==nullptr) return mp(nullptr,nullptr);
	pushdown(rt);
	if(rt->key<=key)
	{
		pair<node*,node*> p=split(rt->r,key);
		rt->r=p.first;
		pushup(rt);
		return mp(rt,p.second);
	}
	else
	{
		pair<node*,node*> p=split(rt->l,key);
		rt->l=p.second;
		pushup(rt);
		return mp(p.first,rt);
	}
}

int sz(node *rt)
{
	return (rt==nullptr?0:rt->size);
}

node* merge(node *x,node *y)
{
	if(x==nullptr) return y;
	if(y==nullptr) return x;
	if(x->rd<y->rd)
	{
		pushdown(y);
		y->l=merge(x,y->l);
		pushup(y);
		return y;
	}
	else
	{
		pushdown(x);
		x->r=merge(x->r,y);
		pushup(x);
		return x;
	}
}

int count(node *rt,int x)
{
	if(rt==nullptr) return 0;
	if(rt->data==x) return rt->count;
	if(rt->data<=x) return count(rt->r,x);else return count(rt->l,x);
}

int checksum(node *rt)
{
	if(!rt) return 0;
	return rt->data+checksum(rt->l)+checksum(rt->r);
}

int n,m;
void solve()
{
	scanf("%d%d",&n,&m);
	node *rt=0;
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		pair<node*,node*> o1=split(rt,y-1);
		pushtag(o1.second,1);
		pair<node*,node*> o2=split(o1.first,y-2);
		if(o2.second) o2.second->data=0;
		rt=merge(merge(merge(o2.first,o2.second),new node(y,1)),o1.second);
	}
	printf("%d\n",C(n+n-1-checksum(rt),n));
}

int main()
{
	combinatorics::init(400000,mod);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}