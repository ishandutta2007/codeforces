//Original Code:
//#include <self/utility>
//#include <self/debug>
//#include <self/combinatorics>
//using namespace std;
//using combinatorics::C;
//int n,m,k,s;
//int ids[2005];
//int x[2005],y[2005];
//const int L=21;
//int dp[2005][L+1];
//int a[L+1];
//
//inline int fastpow(ll basic,int x)
//{
//	ll res=1;
//	while(x)
//	{
//		if(x&1) (res*=basic)%=mod;
//		(basic*=basic)%=mod;
//		x>>=1;
//	}
//	return res;
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	combinatorics::init(200000,mod);
//	cin>>n>>m>>k>>s;
//	x[0]=1;y[0]=1;
//	x[k+1]=n;y[k+1]=m;
//	for(int i=1;i<=k;i++)
//	{
//		cin>>x[i]>>y[i];
//		ids[i]=i;
//	}
//	sort(ids+1,ids+k+1,[](int a,int b){
//		return x[a]+y[a]<x[b]+y[b];
//	});
//	ids[0]=0;
//	ids[k+1]=k+1;
//	dp[0][0]=1;
//	for(int i=0;i<=k;i++)
//	{
//		for(int j=i+1;j<=k+1;j++)
//		{
//			if(x[ids[i]]>x[ids[j]] || y[ids[i]]>y[ids[j]]) continue;
//			int w=C(x[ids[j]]-x[ids[i]]+y[ids[j]]-y[ids[i]],x[ids[j]]-x[ids[i]]);
//			for(int len=0;len<=L;len++)
//			{
//				if(!dp[ids[i]][len]) continue;
//				int t=1LL*dp[ids[i]][len]*w%mod;
//				chadd((j==k+1?a[min(len+1,L)]:dp[ids[j]][min(len+1,L)]),t);
//				chadd(dp[ids[j]][len],mod-t);
//			}
//		}
//	}
//	int res=0;
//	int now=s;
//	for(int len=1;len<=L;len++)
//	{
//		res=(1LL*a[len]*now+res)%mod;
//		now=(now+1)/2;
//	}
//	cout<<1LL*res*fastpow(C(n+m-2,n-1),mod-2)%mod<<endl;
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

using namespace std;
using combinatorics::C;
int n,m,k,s;
int ids[2005];
int x[2005],y[2005];
const int L=21;
int dp[2005][L+1];
int a[L+1];

inline int fastpow(ll basic,int x)
{
	ll res=1;
	while(x)
	{
		if(x&1) (res*=basic)%=mod;
		(basic*=basic)%=mod;
		x>>=1;
	}
	return res;
}

int main()
{
//	// freopen("input.txt","r",stdin);
	combinatorics::init(200000,mod);
	cin>>n>>m>>k>>s;
	x[0]=1;y[0]=1;
	x[k+1]=n;y[k+1]=m;
	for(int i=1;i<=k;i++)
	{
		cin>>x[i]>>y[i];
		ids[i]=i;
	}
	sort(ids+1,ids+k+1,[](int a,int b){
		return x[a]+y[a]<x[b]+y[b];
	});
	ids[0]=0;
	ids[k+1]=k+1;
	dp[0][0]=1;
	for(int i=0;i<=k;i++)
	{
		for(int j=i+1;j<=k+1;j++)
		{
			if(x[ids[i]]>x[ids[j]] || y[ids[i]]>y[ids[j]]) continue;
			int w=C(x[ids[j]]-x[ids[i]]+y[ids[j]]-y[ids[i]],x[ids[j]]-x[ids[i]]);
			for(int len=0;len<=L;len++)
			{
				if(!dp[ids[i]][len]) continue;
				int t=1LL*dp[ids[i]][len]*w%mod;
				chadd((j==k+1?a[min(len+1,L)]:dp[ids[j]][min(len+1,L)]),t);
				chadd(dp[ids[j]][len],mod-t);
			}
		}
	}
	int res=0;
	int now=s;
	for(int len=1;len<=L;len++)
	{
		res=(1LL*a[len]*now+res)%mod;
		now=(now+1)/2;
	}
	cout<<1LL*res*fastpow(C(n+m-2,n-1),mod-2)%mod<<endl;
	return 0;
}