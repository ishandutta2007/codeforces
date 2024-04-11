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
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int w,h;

namespace combinatorics
{
	int *fac;
	int *ifac;
	int mod;
	inline int add(int a,int b)
	{
		return (a+b)%mod;
	}
	inline int minus(int a,int b)
	{
		return (a-b+mod)%mod;
	}
	inline int mutiply(int a,int b)
	{
		return (1LL*a*b)%mod;
	}
	inline int fastpow(int basic,int x)
	{
		int res=1;
		while(x)
		{
			if(x&1)	res=mutiply(res,basic);
			basic=mutiply(basic,basic);
			x>>=1;
		}
		return res;
	}
	inline int inv(int x)
	{
		return fastpow(x,mod-2);
	}
	void init(int n,int tmod)
	{
		mod=tmod;
		fac=new int[n+5];
		ifac=new int[n+5];
		fac[0]=1;
		for(int i=1;i<=n;i++)
		{
			fac[i]=mutiply(fac[i-1],i);
		}
		ifac[n]=inv(fac[n]);
		for(int i=n-1;i>=0;i--)
		{
			ifac[i]=mutiply(ifac[i+1],i+1);
		}
	}
	inline int C(int n,int m)
	{
		return mutiply(mutiply(fac[n],ifac[m]),ifac[n-m]);
	}
	inline int Cat(int x)
	{
		return mutiply(C(x*2,x),inv(x+1));
	}
};
using namespace combinatorics;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>w>>h;
	init(100,998244353);
	cout<<fastpow(2,(w+h))<<endl;
	return 0;
}