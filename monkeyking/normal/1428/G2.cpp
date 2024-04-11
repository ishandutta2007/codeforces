//Original Code:
//#include <self/utility>
//#include <self/debug>
//using namespace std;
//int k;
//ll f[6];
//int cnt;
//ll cost[10005];
//ll value[10005];
//ll dp[1000005];
//ll pw[6];
//ll g[1000005][7];
//ll vt[6][20];
//
//inline void add(ll c,ll v)
//{
//	cost[cnt]=c;
//	value[cnt]=v;
//	cnt++;
//	assert(cnt<=1000);
//}
//
//inline void make(int n,int k=k)
//{
//	k-=2;
//	if(k<=0) return;
//	int nn=1;
//	while(nn<=k)
//	{
//		add(1LL*nn*pw[n]*9,1LL*f[n]*3*nn);
//		k-=nn;
//		nn<<=1;
//	}
//	add(1LL*k*pw[n]*9,1LL*f[n]*3*k);
//}
//
//inline void solve()
//{
//	int n;
//	cin>>n;
//	printf("%lld\n",g[n][0]);
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	pw[0]=1;
//	for(int i=1;i<6;i++)
//	{
//		pw[i]=pw[i-1]*10;
//	}
//	cin>>k;
//	for(int i=0;i<6;i++) cin>>f[i];
//	for(int i=0;i<6;i++)
//	{
//		make(i);
//	}
//	memset(dp,-0x3f,sizeof(dp));
//	memset(g,-0x3f,sizeof(g));
//	dp[0]=0;
//	// for(int i=0;i<cnt;i++) cout<<cost[i]<<' '<<value[i]<<endl;
//	for(int i=0;i<cnt;i++)
//	{
//		if(cost[i]>1000000) continue;
//		for(int j=1000000-cost[i];j>=0;j--)
//		{
//			chmax(dp[j+cost[i]],dp[j]+value[i]);
//		}
//	}
//	memset(vt,-0x3f,sizeof(vt));
//	for(int i=0;i<6;i++)
//	{
//		for(int a=0;a<10;a++)
//		{
//			for(int b=0;b<(k>=2?10:1);b++)
//			{
//				chmax(vt[i][a+b],(a%3==0?f[i]*a/3:0)+(b%3==0?f[i]*b/3:0));
//			}
//		}
//	}
//	for(int i=0;i<=1000000;i++)
//	{
//		chmax(g[i][6],dp[i]);
//		for(int j=6;j>=1;j--)
//		{
//			if(g[i][j]<=-llinf) continue;
//			int w=j-1;
//			for(int ch=0;ch<=18;ch++)
//			{
//				if(i+ch*pw[w]>1000000) break;
//				chmax(g[i+ch*pw[w]][j-1],g[i][j]+vt[w][ch]);
//			}
//		}
//	}
//	int q;
//	cin>>q;
//	while(q--)
//	{
//		solve();
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
int k;
ll f[6];
int cnt;
ll cost[10005];
ll value[10005];
ll dp[1000005];
ll pw[6];
ll g[1000005][7];
ll vt[6][20];

inline void add(ll c,ll v)
{
	cost[cnt]=c;
	value[cnt]=v;
	cnt++;
	assert(cnt<=1000);
}

inline void make(int n,int k=k)
{
	k-=2;
	if(k<=0) return;
	int nn=1;
	while(nn<=k)
	{
		add(1LL*nn*pw[n]*9,1LL*f[n]*3*nn);
		k-=nn;
		nn<<=1;
	}
	add(1LL*k*pw[n]*9,1LL*f[n]*3*k);
}

inline void solve()
{
	int n;
	cin>>n;
	printf("%lld\n",g[n][0]);
}

int main()
{
//	// freopen("input.txt","r",stdin);
	pw[0]=1;
	for(int i=1;i<6;i++)
	{
		pw[i]=pw[i-1]*10;
	}
	cin>>k;
	for(int i=0;i<6;i++) cin>>f[i];
	for(int i=0;i<6;i++)
	{
		make(i);
	}
	memset(dp,-0x3f,sizeof(dp));
	memset(g,-0x3f,sizeof(g));
	dp[0]=0;
	// for(int i=0;i<cnt;i++) cout<<cost[i]<<' '<<value[i]<<endl;
	for(int i=0;i<cnt;i++)
	{
		if(cost[i]>1000000) continue;
		for(int j=1000000-cost[i];j>=0;j--)
		{
			chmax(dp[j+cost[i]],dp[j]+value[i]);
		}
	}
	memset(vt,-0x3f,sizeof(vt));
	for(int i=0;i<6;i++)
	{
		for(int a=0;a<10;a++)
		{
			for(int b=0;b<(k>=2?10:1);b++)
			{
				chmax(vt[i][a+b],(a%3==0?f[i]*a/3:0)+(b%3==0?f[i]*b/3:0));
			}
		}
	}
	for(int i=0;i<=1000000;i++)
	{
		chmax(g[i][6],dp[i]);
		for(int j=6;j>=1;j--)
		{
			if(g[i][j]<=-llinf) continue;
			int w=j-1;
			for(int ch=0;ch<=18;ch++)
			{
				if(i+ch*pw[w]>1000000) break;
				chmax(g[i+ch*pw[w]][j-1],g[i][j]+vt[w][ch]);
			}
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		solve();
	}
	return 0;
}