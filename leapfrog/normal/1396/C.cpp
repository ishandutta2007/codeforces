//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int n;ll r1,r2,r3,d,dp[1000005][2],a[1000005];
int main()
{
	read(n,r1,r2,r3,d);for(int i=1;i<=n;i++) read(a[i]);
	dp[1][0]=r1*a[1]+r3,dp[1][1]=min(r2,r1*(a[1]+1));
	for(int i=2;i<=n;i++)
	{
		dp[i][0]=dp[i-1][1]+d+min(r2,r1*(a[i]+1))+d+r1+d+r1;
		dp[i][0]=min(dp[i][0],dp[i-1][1]+d+r1*a[i]+r3+d+r1+d);
		dp[i][0]=min(dp[i][0],dp[i-1][0]+d+r1*a[i]+r3);
		dp[i][1]=dp[i-1][1]+d+min(r2,r1*(a[i]+1))+d+r1+d;
		dp[i][1]=min(dp[i][1],dp[i-1][0]+min(r2,r1*(a[i]+1))+d);
	}
	return printf("%lld\n",min(dp[n][0],dp[n-1][1]+d+r1*a[n]+r3+d+r1)),0;
}
/*

1.  boss
2.  boss  2/3
3.  2/3 

dp[i][0/1]  i 0 1  boss 
*/