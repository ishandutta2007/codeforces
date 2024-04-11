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
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
int n;
int a[505];
int dp[505][505];

int dfs(int l,int r)
{
	if(dp[l][r]!=-1) return dp[l][r];
	if(l>r) return dp[l][r]=0;
	if(l==r) return dp[l][r]=1;
	if(l==r-1)
	{
		return dp[l][r]=(a[l]!=a[r])+1;
	}
	dp[l][r]=3487921;
	if(a[l]==a[r])
	{
		dp[l][r]=dfs(l+1,r-1);
	}
	for(int k=l;k<=r;k++)
	{
		dp[l][r]=min(dp[l][r],dfs(l,k)+dfs(k+1,r));
	}
	return dp[l][r];
}

int main()
{
	memset(dp,-1,sizeof(dp)); 
//	freopen("input.txt","r",stdin);
	cin>>n;
	rep(n)
	{
		cin>>a[i];
	}
	cout<<dfs(0,n-1)<<endl;
	return 0;
}