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
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
const int mod=1e9+7;
const ll llinf=1LL*inf*inf;
using namespace std;
int n;
int a[100005];
int sum[100005];
int phi[100005];

template <typename T>
inline vector <T> getfactors(T x)
{
	vector <T> vec;
	for(T i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			vec.push_back(i);
			if(i!=x/i) vec.push_back(x/i);
		}
	}
	sort(vec.begin(),vec.end());
	return vec;
}

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
		return mult(mult(fac[n],ifac[m]),ifac[n-m]);
	}
	inline int Cat(int x)
	{
		return mult(C(x*2,x),inv(x+1));
	}
};
using namespace combinatorics;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	vector <int> factors;
	for(int i=0;i<n;i++)
	{
		factors=getfactors(a[i]);
		for(auto x:factors)
		{
			sum[x]++;
		}
	}
	phi[1]=1;
	for(int i=1;i<=100000;i++)
	{
		for(int j=i+i;j<=100000;j+=i)
		{
			phi[j]-=phi[i];
		}
		if(phi[i]==-1) phi[i]=mod-1;
	}
	init(0,1e9+7);
	int res=0;
	for(int i=1;i<=100000;i++)
	{
		res=add(res,mult(phi[i],sub(fastpow(2,sum[i]),1)));
	}
	cout<<res<<endl;
	return 0;
}