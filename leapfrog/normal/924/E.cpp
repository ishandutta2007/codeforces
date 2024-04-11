//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,dp[10005],L,R;struct node{int h,v;}a[10005];
int main()
{
	read(n),read(L),read(R);int sm=0;
	for(int i=1;i<=n;i++) read(a[i].h),sm+=a[i].h;
	for(int i=1;i<=n;i++) read(a[i].v);
	sort(a+1,a+n+1,[](node a,node b){return a.v^b.v?a.v<b.v:a.h>b.h;});
	int gg=L;L=sm-R,R=sm-gg;memset(dp,~0x3f,sizeof(dp)),dp[0]=0;
	for(int i=1;i<=n;i++) for(int j=sm;j>=a[i].h;j--) dp[j]=max(dp[j],dp[j-a[i].h]+a[i].v*(L<=j&&j<=R));
	int mx=0;for(int i=0;i<=sm;i++) mx=max(mx,dp[i]);
	return printf("%d\n",mx),0;
}