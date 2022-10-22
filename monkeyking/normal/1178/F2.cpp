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
int a[1000005];
int n,m;
int low[505];
int high[505];
ll dp[1005][1005];

int dfs(int l,int r)
{
	if(l>r) return 1;
	if(dp[l][r]!=-1) return dp[l][r];
	for(int i=l;i<=r;i++)
	{
		if(!(l<=low[a[i]] && low[a[i]]<=r && l<=high[a[i]] && high[a[i]]<=r))
		{
			return 0;
		}
	}
	int minx=inf;
	for(int i=l;i<=r;i++)
	{
		if(minx>a[i]) minx=a[i];
	}
	int lm=low[minx];
	int rm=high[minx];
	ll lhs=0,rhs=0;
	for(int len=0;len<=(lm-1)-l+1;len++)
	{
//		if(l==0 && r==2) cout<<l<<'-'<<l+len-1<<' '<<l+len<<'-'<<k-1<<endl;
		lhs+=1LL*dfs(l,l+len-1)*dfs(l+len,lm-1);
		lhs%=mod;
	}
	for(int len=0;len<=(r-(rm+1)+1);len++)
	{
		rhs+=1LL*dfs(rm+1,rm+1+len-1)*dfs(rm+1+len,r);
		rhs%=mod;
	}
	ll &res=dp[l][r];
	res=(1LL*lhs*rhs)%mod;
//	cout<<l<<' '<<r<<' '<<res<<' '<<lhs<<' '<<rhs<<' '<<lm<<' '<<rm<<endl;
	int last=lm;
	for(int i=lm+1;i<=rm;i++)
	{
		if(a[i]==minx)
		{
			res*=dfs(last+1,i-1);
			last=i;
			res%=mod;
		}
	}
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	cin>>m>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	int nn=0;
	for(int i=0;i<n;i++)
	{
		if(i==0 || a[i]!=a[i-1]) a[nn++]=a[i];
	}
	if(nn>2*m) over(0);
	n=nn;
	memset(low,0x3f,sizeof(low));
	memset(high,-1,sizeof(high));
	for(int i=0;i<n;i++)
	{
		low[a[i]]=min(low[a[i]],i);
		high[a[i]]=max(high[a[i]],i);
	}
	cout<<dfs(0,n-1)<<endl;
	return 0;
}