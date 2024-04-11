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
const int mod=998244353;
const int inf=1039074182;
const int g=3;
const double eps=1e-9;
const ll llinf=2LL*inf*inf;
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31 & mod);}
template <typename T1,typename T2> inline void chadd(T1 &x,T2 b) {x+=b;if(x>=mod) x-=mod;}
template <typename T1,typename T2> inline void chmul(T1 &x,T2 b) {x=1LL*x*b%mod;}
template <typename T1,typename T2> inline void chmod(T1 &x,T2 b) {x%=b,x+=b;if(x>=b) x-=b;}
template <typename T> inline T mabs(T x) {return (x<0?-x:x);}
using namespace std;
const int LogN=20;
const int MaxN=(1<<LogN);
int w[MaxN+5];
int fac[MaxN+5];
int ifac[MaxN+5];

inline int fastpow(int basic,int x)
{
	int res=1;
	while(x)
	{
		if(x&1) res=1LL*res*basic%mod;
		basic=1LL*basic*basic%mod;
		x>>=1;
	}
	return res;
}

inline int C(int n,int m)
{
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

inline int Cat(int n)
{
	return 1LL*C(2*n,n)*fastpow(n+1,mod-2)%mod;
}

namespace NTT
{
	int inv[MaxN+5];
	vector<int> buf;
	inline int zeta(int n,int m,int rev)
	{
		return ((rev?w[MaxN-MaxN/n*m]:w[MaxN/n*m]));
	}
	inline void ntt(vector<int> &v,int rev,int lg)
	{
		int n=(1<<lg);
		buf.resize(n,0);
		v.resize(n,0);
		for(int i=0;i<n;i++)
		{
			inv[i]=(inv[i>>1]>>1) | ((i&1)<<(lg-1));
		}
		for(int i=0;i<n;i++)
		{
			buf[i]=v[inv[i]];
		}
		for(int b=1;b<n;b*=2)
		{
			for(int i=0;i<n;i+=b*2)
			{
				for(int j=0;j<b;j++)
				{
					v[i+j]=((ll)buf[i+j]+1LL*zeta(b*2,j,rev)*buf[i+j+b])%mod;
					v[i+j+b]=((ll)buf[i+j]+1LL*zeta(b*2,j+b,rev)*buf[i+j+b])%mod;
				}
			}
			buf=v;
		}
		int t=fastpow(n,mod-2);
		if(rev)
		{
			for(int i=0;i<v.size();i++)
			{
				v[i]=1LL*v[i]*t%mod;
			}
		}
	}
	inline void multiply(vector<int> a,vector<int> b,vector<int> &c)
	{
		int n=(int)a.size()+b.size()-1;
		int nn=1,lg=0;
		while(nn<n)
		{
			nn<<=1;
			lg++;
		}
		c.resize(nn);
		a.resize(nn,0);
		b.resize(nn,0);
		ntt(a,0,lg);
		ntt(b,0,lg);
		for(int i=0;i<nn;i++)
		{
			c[i]=1LL*a[i]*b[i]%mod;
		}
		ntt(c,1,lg);
		while(c.size() && c.back()==0) c.pop_back();
		for(auto &x:c)
		{
			chmin(x,1);
		}
	}
	inline vector<int> operator * (vector<int> a,vector<int> b)
	{
		vector<int> c;
		multiply(a,b,c);
		return c;
	}
	inline vector<int> multiply(vector<int> a,vector<int> b)
	{
		// cout<<a<<' '<<b<<' '<<a*b<<endl;
		return a*b;
	}
}

inline void putnum(int x)
{
	if(x==0)
	{
		putchar('0');
		putchar(' ');
		return;
	}
	static char buf[10];
	static int len;
	len=0;
	while(x)
	{
		buf[len++]=x%10;
		x/=10;
	}
	reverse(buf,buf+len);
	for(int i=0;i<len;i++)
	{
		putchar(buf[i]+'0');
	}
	putchar(' ');
}

inline void print(vector<int> a)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=0) putnum(a[i]);
	}
	puts("");
}

int n,k;
int a[1005];
vector<int> basic;
vector<int> res;
inline void solve()
{
	cin>>n>>k;
	basic.resize(1001,0);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		basic[a[i]]=1;
	}
	res.push_back(1);
	// for(int i=0;i<basic.size();i++)
	// {
	// 	if(basic[i]!=0) putnum(i);
	// }
	// puts("");
	// print(res);
	// print(basic);
	// basic=NTT::multiply(basic,basic);
	// res=NTT::multiply(res,basic);
	// print(res);
	// exit(0);
	while(k)
	{
		// cout<<res<<' '<<basic<<endl;
		if(k&1) res=NTT::multiply(res,basic);
		// cout<<res<<endl;
		k>>=1;
		if(k!=0) basic=NTT::multiply(basic,basic);
	}
	for(int i=0;i<res.size();i++)
	{
		if(res[i]!=0) putnum(i);
	}
}

int main()
{
	w[0]=1;
	int ur=fastpow(g,(mod-1)>>LogN);
	for(int i=1;i<=MaxN;i++)
	{
		w[i]=1LL*w[i-1]*ur%mod;
	}
	// NTT::test();
	solve();
	return 0;
}