//Original Code:
//#define __TAKE_CONST_MOD 998244353
//#include <self/utility>
//using namespace std;
//int coe[5005][5005];
//int n,m,k;
//int fac[5005];
//int pm[5005];
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
//inline int inv(int x)
//{
//	return fastpow(x,mod-2);
//}
//
//int main()
//{
//	// freopen("input.txt","r",stdin);
//	coe[0][0]=1;
//	fac[0]=1;
//	pm[0]=1;
//	cin>>n>>m>>k;
//	for(int i=1;i<=min(n,k);i++) fac[i]=1LL*fac[i-1]*(n-i+1)%mod;
//	for(int i=1;i<=k;i++) pm[i]=1LL*pm[i-1]*m%mod;
//	for(int t=0;t<k;t++)
//	{
//		for(int i=0;i<=t;i++)
//		{
//			chadd(coe[t+1][i],1LL*i*coe[t][i]%mod);
//			chadd(coe[t+1][i+1],coe[t][i]);
//		}
//	}
//	int res=0;
//	for(int i=0;i<=min(k,n);i++)
//	{
//		chadd(res,1LL*coe[k][i]*fastpow(m,n-i)%mod*fac[i]%mod);
//	}
//	res=1LL*res*(fastpow(inv(m),n))%mod;
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
#endif
using namespace std;
int coe[5005][5005];
int n,m,k;
int fac[5005];
int pm[5005];

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

inline int inv(int x)
{
	return fastpow(x,mod-2);
}

int main()
{
//	// freopen("input.txt","r",stdin);
	coe[0][0]=1;
	fac[0]=1;
	pm[0]=1;
	cin>>n>>m>>k;
	for(int i=1;i<=min(n,k);i++) fac[i]=1LL*fac[i-1]*(n-i+1)%mod;
	for(int i=1;i<=k;i++) pm[i]=1LL*pm[i-1]*m%mod;
	for(int t=0;t<k;t++)
	{
		for(int i=0;i<=t;i++)
		{
			chadd(coe[t+1][i],1LL*i*coe[t][i]%mod);
			chadd(coe[t+1][i+1],coe[t][i]);
		}
	}
	int res=0;
	for(int i=0;i<=min(k,n);i++)
	{
		chadd(res,1LL*coe[k][i]*fastpow(m,n-i)%mod*fac[i]%mod);
	}
	res=1LL*res*(fastpow(inv(m),n))%mod;
	cout<<res<<endl;
	return 0;
}