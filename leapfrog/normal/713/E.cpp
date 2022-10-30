//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,a[200005],v[200005],L,R,dp[200005];
inline char check(int x)
{
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(dp[i-1]>=v[i]-1) dp[i]=max(dp[i],v[i]+x);
		if(dp[i-1]>=v[i]-x-1) dp[i]=max(dp[i],v[i]);
		if(i>2&&dp[i-2]>=v[i]-x-1) dp[i]=max(dp[i],v[i-1]+x);
	}
	if(dp[n]>=m-x-1) return 1;else dp[2]=max(v[2],x);
	for(int i=3;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(dp[i-1]>=v[i]-1) dp[i]=max(dp[i],v[i]+x);
		if(dp[i-1]>=v[i]-x-1) dp[i]=max(dp[i],v[i]);
		if(dp[i-2]>=v[i]-x-1) dp[i]=max(dp[i],v[i-1]+x);
	}
	if(dp[n]>=m-1||dp[n]>=m+v[2]-x-1) return 1;else return 0;
}
int main()
{
	read(m),read(n);int mxw=1;if(n==1) return printf("%d\n",m-1),0;
	for(int i=1;i<=n;i++) read(a[i]),a[i+n]=a[i]+m;
	for(int i=1;i<=n;i++) if(a[i+1]-a[i]>a[mxw+1]-a[mxw]) mxw=i;
	L=0,R=a[mxw+1]-a[mxw];int md,res=-1;
	for(int i=1;i<=n;i++) v[i]=a[i+mxw];
	for(int i=n;i>=1;i--) v[i]-=v[1];
	while(L<=R) {md=(L+R)>>1;if(check(md)) res=md,R=md-1;else L=md+1;}
	return printf("%d\n",res),0;
}