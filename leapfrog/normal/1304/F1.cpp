//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,K,a[55][20005],s[55][20005],dp[55][20005],mx1[55][25005],mx2[55][25005],t[100005];
inline int cf(int i,int l,int r) {if(l>r) swap(l,r);return s[i][l+K-1]-s[i][r-1];}
inline void build(int x,int l,int r,int *c)
{
}
int main()
{
	read(n),read(m),read(K);int mx=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]),s[i][j]=s[i][j-1]+a[i][j];
	for(int j=1;j<=m-K+1;j++) dp[1][j]=s[1][j+K-1]-s[1][j-1]+s[2][j+K-1]-s[2][j-1];
	for(int j=1;j<=m-K+1;j++) mx1[1][j]=max(mx1[1][j-1],dp[1][j]);
	for(int j=m-K+1;j>=1;j--) mx2[1][j]=max(mx2[1][j+1],dp[1][j]);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m-K+1;j++)
		{
			int now=s[i+1][j+K-1]-s[i+1][j-1]+s[i][j+K-1]-s[i][j-1];
			dp[i][j]=max(dp[i][j],now+max(j>K?mx1[i-1][j-K]:0,mx2[i-1][j+K]));
			for(int k=max(j-K+1,1);k<j;k++) dp[i][j]=max(dp[i][j],dp[i-1][k]+now-s[i][k+K-1]+s[i][j-1]);
			for(int k=j;k<=min(j+K-1,m-K+1);k++) dp[i][j]=max(dp[i][j],dp[i-1][k]+now-s[i][j+K-1]+s[i][k-1]);
		}
		for(int j=1;j<=m-K+1;j++) mx1[i][j]=max(mx1[i][j-1],dp[i][j]);
		for(int j=m-K+1;j>=1;j--) mx2[i][j]=max(mx2[i][j+1],dp[i][j]);
	}
	for(int j=1;j<=m-K+1;j++) mx=max(mx,dp[n][j]);
	return printf("%d\n",mx),0;
}