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
ll n,q;

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
	inline int multiply(int a,int b)
	{
		return (1LL*a*b)%mod;
	}
	inline int fastpow(int basic,int x)
	{
		int res=1;
		while(x)
		{
			if(x&1)	res=multiply(res,basic);
			basic=multiply(basic,basic);
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
			fac[i]=multiply(fac[i-1],i);
		}
		ifac[n]=inv(fac[n]);
		for(int i=n-1;i>=0;i--)
		{
			ifac[i]=multiply(ifac[i+1],i+1);
		}
	}
	inline int C(int n,int m)
	{
		return multiply(multiply(fac[n],ifac[m]),ifac[n-m]);
	}
	inline int Cat(int x)
	{
		return multiply(C(x*2,x),inv(x+1));
	}
};
using namespace combinatorics;

int solve(int x)
{
	ll res=0;
	ll n=q;
	while(n)
	{
		res+=(n/x);
		n/=x;
		res%=(mod-1);
	}
	return fastpow(x,res);
}

int main()
{
//	freopen("input.txt","r",stdin);
	init(2,1e9+7);
	cin>>n>>q;
	vector <int> vec;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			vec.push_back(i);
			while(n%i==0)
			{
				n/=i;
			}
		}
	}
	if(n!=1) vec.push_back(n);
	int res=1;
	for(auto x:vec)
	{
		res=multiply(res,solve(x));
	}
	cout<<res<<endl;
	return 0;
}