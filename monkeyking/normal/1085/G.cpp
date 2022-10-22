//Original Code:
//#define __TAKE_CONST_MOD 998244353
//#include <self/utility>
//#include <self/debug>
//#include <self/FastIO>
//using namespace std;
//int n;
//int a[2005][2005];
//int d[2005];
//int f[2005][2005];
//int fac[2005];
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
//struct BIT
//{
//	int bit[2005];
//
//	void add(int x,int delta)
//	{
//		x++;
//		while(x<=n)
//		{
//			bit[x]+=delta;
//			x+=x & (-x);
//		}
//	}
//
//	int query(int x)
//	{
//		x++;
//		int res=0;
//		while(x)
//		{
//			res+=bit[x];
//			x&=x-1;
//		}
//		return res;
//	}
//
//	void init(int n)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			bit[i]++;
//			int pos=i+(i & (-i));
//			if(pos<=n) bit[pos]+=bit[i];
//		}
//	}
//}b1,b2;
//
//int h0[2005],h1[2005];
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			a[i][j]=getnum();
//			a[i][j]--;
//		}
//	}
//	fac[0]=1;
//	for(int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%mod;
//	d[0]=1;
//	for(int i=2;i<=n;i++) d[i]=1LL*(i-1)*(d[i-1]+d[i-2])%mod;
//	f[0][0]=1;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=i;j++)
//		{
//			if(i==j) f[i][j]=d[i];
//			else f[i][j]=(1LL*(i-j)*f[i-1][j]+(j?1LL*j*f[i-1][j-1]:0LL))%mod;
//		}
//	}
//	// cout<<f[3][2]<<endl;
//	// cout<<f[2][1]<<endl;
//	// cout<<f[4][3]<<' '<<f[2][1]<<endl;
//	int res=0;
//	for(int i=0;i<n;i++)
//	{
//		int ans=0;
//		if(i==0)
//		{
//			b2.init(n);
//			for(int j=0;j<n;j++)
//			{
//				int rk=b2.query(a[i][j]);
//				ans=(1LL*fac[n-j-1]*(rk-1)+ans)%mod;
//				b2.add(a[i][j],-1);
//			}
//		}
//		else
//		{
//			b1.init(n);
//			b2.init(n);
//			int l=n;
//			for(int i=0;i<n;i++) h0[i]=1,h1[i]=1;
//			for(int j=0;j<n;j++)
//			{
//				int rk=b2.query(a[i][j]);
//				h0[a[i-1][j]]--;
//				if(h1[a[i-1][j]])
//				{
//					b1.add(a[i-1][j],-1);
//					l--;
//				}
//				int w=(a[i][j]==0?0:b1.query(a[i][j]-1));
//				if(a[i-1][j]>=a[i][j] || !h1[a[i-1][j]])
//				{
//					ans=(1LL*w*(w?f[n-j-1][l-1]:0)+1LL*(rk-w-1)*f[n-j-1][l]+ans)%mod;
//				}
//				else
//				{
//					ans=(1LL*w*f[n-j-1][l-1]+1LL*(rk-w-2)*f[n-j-1][l]+ans)%mod;
//				}
//				// if(i==3 && j==1) debug(ans,w,l,f[n-j-1][l-1]);
//				b2.add(a[i][j],-1);
//				h1[a[i][j]]--;
//				if(h0[a[i][j]])
//				{
//					b1.add(a[i][j],-1);
//					l--;
//				}
//			}
//		}
//		// cout<<ans<<endl;
//		res=(1LL*ans*fastpow(d[n],n-1-i)+res)%mod;
//	}
//	cout<<res<<endl;
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
namespace FastIO
{
    const int MaxBufSize=1024*1024;
    char buf[MaxBufSize+5];
    int cursor=MaxBufSize;
    inline char getchar()
    {
        if(cursor==MaxBufSize)
        {
            fread(buf,1,MaxBufSize,stdin);
            cursor=0;
        }
        return buf[cursor++];
    }
    inline ll getnum()
    {
        static ll res;
        static char c;
        static int mut;
        res=0;
        c=0;
        mut=1;
        while(!isdigit(c) && c!='-') c=getchar();
        if(c=='-')
        {
            mut=-1;
            c=getchar();
        }
        while(isdigit(c))
        {
            res=(res<<3)+(res<<1)+c-'0';
            c=getchar();
        }
        return res*mut;
    }
} // namespace FastIO
using FastIO::getnum;
using namespace std;
int n;
int a[2005][2005];
int d[2005];
int f[2005][2005];
int fac[2005];

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

struct BIT
{
	int bit[2005];

	void add(int x,int delta)
	{
		x++;
		while(x<=n)
		{
			bit[x]+=delta;
			x+=x & (-x);
		}
	}

	int query(int x)
	{
		x++;
		int res=0;
		while(x)
		{
			res+=bit[x];
			x&=x-1;
		}
		return res;
	}

	void init(int n)
	{
		for(int i=1;i<=n;i++)
		{
			bit[i]++;
			int pos=i+(i & (-i));
			if(pos<=n) bit[pos]+=bit[i];
		}
	}
}b1,b2;

int h0[2005],h1[2005];
int main()
{
//	// freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=getnum();
			a[i][j]--;
		}
	}
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%mod;
	d[0]=1;
	for(int i=2;i<=n;i++) d[i]=1LL*(i-1)*(d[i-1]+d[i-2])%mod;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==j) f[i][j]=d[i];
			else f[i][j]=(1LL*(i-j)*f[i-1][j]+(j?1LL*j*f[i-1][j-1]:0LL))%mod;
		}
	}
	// cout<<f[3][2]<<endl;
	// cout<<f[2][1]<<endl;
	// cout<<f[4][3]<<' '<<f[2][1]<<endl;
	int res=0;
	for(int i=0;i<n;i++)
	{
		int ans=0;
		if(i==0)
		{
			b2.init(n);
			for(int j=0;j<n;j++)
			{
				int rk=b2.query(a[i][j]);
				ans=(1LL*fac[n-j-1]*(rk-1)+ans)%mod;
				b2.add(a[i][j],-1);
			}
		}
		else
		{
			b1.init(n);
			b2.init(n);
			int l=n;
			for(int i=0;i<n;i++) h0[i]=1,h1[i]=1;
			for(int j=0;j<n;j++)
			{
				int rk=b2.query(a[i][j]);
				h0[a[i-1][j]]--;
				if(h1[a[i-1][j]])
				{
					b1.add(a[i-1][j],-1);
					l--;
				}
				int w=(a[i][j]==0?0:b1.query(a[i][j]-1));
				if(a[i-1][j]>=a[i][j] || !h1[a[i-1][j]])
				{
					ans=(1LL*w*(w?f[n-j-1][l-1]:0)+1LL*(rk-w-1)*f[n-j-1][l]+ans)%mod;
				}
				else
				{
					ans=(1LL*w*f[n-j-1][l-1]+1LL*(rk-w-2)*f[n-j-1][l]+ans)%mod;
				}
				// if(i==3 && j==1) debug(ans,w,l,f[n-j-1][l-1]);
				b2.add(a[i][j],-1);
				h1[a[i][j]]--;
				if(h0[a[i][j]])
				{
					b1.add(a[i][j],-1);
					l--;
				}
			}
		}
		// cout<<ans<<endl;
		res=(1LL*ans*fastpow(d[n],n-1-i)+res)%mod;
	}
	cout<<res<<endl;
	return 0;
}