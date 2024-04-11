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
const int mod=998244353;
using namespace std;
int n;
int a[505];
int dp[505][505];

int dfs(int l,int r)
{
	if(l>=r) return 1;
	if(dp[l][r]!=-1) return dp[l][r];
	int k=-1,minx=inf;
	for(int i=l;i<=r;i++)
	{
		if(minx>a[i]) minx=a[i],k=i;
	}
	ll lhs=0,rhs=0;
//	if(l==0 && r==2) cout<<k<<endl;
//	if(l==0 && r==2) cout<<(k-1)-l+1<<endl;
	for(int len=0;len<=(k-1)-l+1;len++)
	{
//		if(l==0 && r==2) cout<<l<<'-'<<l+len-1<<' '<<l+len<<'-'<<k-1<<endl;
		lhs+=1LL*dfs(l,l+len-1)*dfs(l+len,k-1);
		lhs%=mod;
	}
	for(int len=0;len<=(r-(k+1)+1);len++)
	{
		rhs+=1LL*dfs(k+1,k+1+len-1)*dfs(k+1+len,r);
		rhs%=mod;
	}
	lhs%=mod;
	rhs%=mod;
	dp[l][r]=(1LL*lhs*rhs)%mod;
	return dp[l][r];
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>n;
//	cout<<n<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0,n-1)<<endl;
	return 0;
}