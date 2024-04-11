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
int n,a[55],dp[55],sm=0;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=n;i;i--) dp[i]=max(dp[i+1],sm+a[i]-dp[i+1]),sm+=a[i];
	return printf("%d %d\n",sm-dp[1],dp[1]),0;
}