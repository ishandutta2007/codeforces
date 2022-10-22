//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int n,m;
//int a[200005];
//
//struct SegmentTree
//{
//	pii data[524288];
//	static const int nn=262144;
//	inline pii merge(const pii &a,const pii &b)
//	{
//		if(a.first<b.first) return mp(a.first,min(a.second,b.first));
//		else return mp(b.first,min(b.second,a.first));
//	}
//	inline void update(int pos,int value)
//	{
//		pos+=nn;
//		data[pos]=mp(value,inf);
//		pos>>=1;
//		while(pos)
//		{
//			data[pos]=merge(data[pos*2],data[pos*2+1]);
//			pos>>=1;
//		}
//	}
//	inline int query(int l,int r)
//	{
//		pii t=query(1,0,nn,l,r);
//		if(t.second==inf) return inf+inf;
//		return t.first+t.second;
//	}
//	inline pii query(int x,int l,int r,int ql,int qr)
//	{
//		if(l>=qr || r<=ql) return mp(inf,inf);
//		if(l>=ql && r<=qr)
//		{
//			return data[x];
//		}
//		return merge(query(x*2,l,(l+r)>>1,ql,qr),query(x*2+1,(l+r)>>1,r,ql,qr));
//	}
//	inline void init()
//	{
//		for(int i=0;i<524288;i++)
//		{
//			data[i]=mp(inf,inf);
//		}
//	}
//}sgt[10];
//
//
//inline void update(int pos,int x)
//{
//	int t=x;
//	int len=0;
//	for(int i=0;i<10;i++)
//	{
//		if(x%10!=0) sgt[len].update(pos,t);else sgt[len].update(pos,inf);
//		x/=10;
//		len++;
//	}
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	// freopen("output.txt","w",stdout);
//	for(int i=0;i<10;i++) sgt[i].init();
//	scanf("%d%d",&n,&m);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",a+i);
//		update(i,a[i]);
//	}
//	while(m--)
//	{
//		int type;
//		scanf("%d",&type);
//		if(type==1)
//		{
//			int i,x;
//			scanf("%d%d",&i,&x);
//			i--;
//			a[i]=x;
//			update(i,a[i]);
//		}
//		else
//		{
//			int l,r;
//			scanf("%d%d",&l,&r);
//			l--;
//			int res=2LL*inf;
//			for(int i=0;i<10;i++)
//			{
//				chmin(res,sgt[i].query(l,r));
//			}
//			printf("%d\n",(res==2LL*inf?-1:res));
//		}
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
int n,m;
int a[200005];

struct SegmentTree
{
	pii data[524288];
	static const int nn=262144;
	inline pii merge(const pii &a,const pii &b)
	{
		if(a.first<b.first) return mp(a.first,min(a.second,b.first));
		else return mp(b.first,min(b.second,a.first));
	}
	inline void update(int pos,int value)
	{
		pos+=nn;
		data[pos]=mp(value,inf);
		pos>>=1;
		while(pos)
		{
			data[pos]=merge(data[pos*2],data[pos*2+1]);
			pos>>=1;
		}
	}
	inline int query(int l,int r)
	{
		pii t=query(1,0,nn,l,r);
		if(t.second==inf) return inf+inf;
		return t.first+t.second;
	}
	inline pii query(int x,int l,int r,int ql,int qr)
	{
		if(l>=qr || r<=ql) return mp(inf,inf);
		if(l>=ql && r<=qr)
		{
			return data[x];
		}
		return merge(query(x*2,l,(l+r)>>1,ql,qr),query(x*2+1,(l+r)>>1,r,ql,qr));
	}
	inline void init()
	{
		for(int i=0;i<524288;i++)
		{
			data[i]=mp(inf,inf);
		}
	}
}sgt[10];


inline void update(int pos,int x)
{
	int t=x;
	int len=0;
	for(int i=0;i<10;i++)
	{
		if(x%10!=0) sgt[len].update(pos,t);else sgt[len].update(pos,inf);
		x/=10;
		len++;
	}
}

int main()
{
//	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	for(int i=0;i<10;i++) sgt[i].init();
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		update(i,a[i]);
	}
	while(m--)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			int i,x;
			scanf("%d%d",&i,&x);
			i--;
			a[i]=x;
			update(i,a[i]);
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			l--;
			int res=2LL*inf;
			for(int i=0;i<10;i++)
			{
				chmin(res,sgt[i].query(l,r));
			}
			printf("%d\n",(res==2LL*inf?-1:res));
		}
	}
	return 0;
}