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
int dp[255][255];
int n,k;
int kp[255],k1p[255];

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
		if(n==0 && m==0) return 1;
		return multiply(multiply(fac[n],ifac[m]),ifac[n-m]);
	}
	inline int Cat(int x)
	{
		return multiply(C(x*2,x),inv(x+1));
	}
};
using namespace combinatorics;

int main()
{
//	freopen("input.txt","r",stdin);
	init(255,1e9+7);
	dp[0][0]=1;
	cin>>n>>k;
	for(int i=0;i<=n;i++)
	{
		kp[i]=fastpow(k,i);
		k1p[i]=fastpow(k-1,i);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int nxt=j;nxt<=n;nxt++)
			{
//				bool debug=(i==0 && j==0 && nxt==0);
//				if(i==0 && j==0 && nxt==0) cout<<k1p[n-nxt]<<' '<<kp[j]<<endl;
				dp[i+1][nxt]+=multiply(multiply(dp[i][j],multiply(k1p[n-nxt],kp[j])),C(n-j,nxt-j));
//				if(debug) cout<<dp[i+1][nxt]<<endl;
//				if(i+1==2 && nxt==2) cout<<dp[2][2]<<endl;
				if(j==nxt) dp[i+1][nxt]-=multiply(multiply(dp[i][j],k1p[j]),k1p[n-nxt]);
//				if(i+1==2 && nxt==2) cout<<dp[2][2]<<endl;
				if(dp[i+1][nxt]<0) dp[i+1][nxt]+=combinatorics::mod;
				if(dp[i+1][nxt]>=combinatorics::mod) dp[i+1][nxt]-=combinatorics::mod;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=n;j++)
//		{
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	cout<<dp[n][n]<<endl;
	return 0;
}