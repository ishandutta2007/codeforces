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
const int mod=1e9+7;
const int div2=(mod+1)/2;
using namespace std;
int phi[5000005];
bool prime[5000005];
ll dp1[10005];
//ll dp2[1005];
vector <int> p;
int dp[5000005];

int fastpow(int basic,int x)
{
	int res=1;
	while(x)
	{
		if(x&1) res=(1LL*res*basic)%mod;
		x>>=1;
		basic=(1LL*basic*basic)%mod;
	}
	return res;
}

int calc(int x)
{
	return ((1LL*x*(x-1))%mod*div2)%mod;
}

void solve1()
{
	for(int i=2;i<=10000;i++)
	{
		dp1[i]=calc(i);
		for(int j=2;j*j<=i;j++)
		{
			if(i%j!=0) continue;
			dp1[i]=min(dp1[i],(dp1[i/j]+1LL*j*calc(j))%mod);
			break;
//			dp1[i]=min(dp1[i],(dp1[j]+1LL*(i/j)*calc(i/j))%mod);
		}
	}
}
//
//void solve2()
//{
//	for(int i=2;i<=1000;i++)
//	{
//		dp2[i]=calc(i);
//		for(int j=2;j*j<=i;j++)
//		{
//			if(i%j!=0) continue;
//			dp2[i]=min(dp2[i],dp2[i/j]+(j)*calc(j));
//			break;
//		}
//	}
//}

int mut(int a,int b)
{
	return (1LL*a*b)%mod;
}

int add(int a,int b)
{
	return (a+b)%mod;
}

int main()
{
//	freopen("input.txt","r",stdin);
	dp1[1]=0;
	solve1();
	for(int i=2;i<=5000000;i++)
	{
		prime[i]=true;
	}
	for(int i=2;i<=5000000;i++)
	{
		if(!prime[i]) continue;
		for(int j=i+i;j<=5000000;j+=i)
		{
			if(!prime[j]) continue;
			prime[j]=false;
			phi[j]=i;
		}
	}
//	cout<<calc(5926/2)<<endl;
	dp[1]=0;
	for(int i=2;i<=5000000;i++)
	{
		if(prime[i]) dp[i]=calc(i);
		else
		{
			dp[i]=add(dp[i/phi[i]],mut(i/phi[i],calc(phi[i])));
		}
	}
	int t,l,r;
	cin>>t>>l>>r;
	int res=0;
	int pow=1;
	for(int i=0;i<=r-l;i++)
	{
		res=add(res,mut(pow,dp[l+i]));
		pow=(1LL*pow*t)%mod;
	}
	cout<<res<<endl;
	return 0;
}