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
const int mod=1e9+7;
using namespace std;
int a[1005][1005];
int b[1005][1005];
int c[1005][1005];
int n,m;
int r[1005];
int C[1005];

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
//using namespace combinatorics;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
	}
	for(int j=0;j<m;j++)
	{
		cin>>C[j];
	}
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	memset(c,-1,sizeof(c));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r[i];j++)
		{
			a[i][j]=1;
		}
		a[i][r[i]]=0;
	}
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<C[j];i++)
		{
			b[i][j]=1;
		}
		b[C[j]][j]=0;
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==-1 && b[i][j]==-1) res++;
			if(a[i][j]==-1 || b[i][j]==-1) continue;
			if(a[i][j]!=b[i][j]) over(0);
		}
	}
	combinatorics::init(2,1e9+7);
	cout<<combinatorics::fastpow(2,res)<<endl;
	return 0;
}