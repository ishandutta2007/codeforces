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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=1000005,P=1e9+7;
int n,a[N],dp[N][2];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),a[i]--;
	dp[1][0]=a[1],dp[1][1]=min(a[1],a[2]);
	for(int i=1;i<=n;i++) dp[i][0]=(1ll*dp[i-1][1]*min(a[i-1],a[i])+a[i])%P,
		dp[i][1]=(1ll*dp[i-1][1]*min(a[i-1],min(a[i],a[i+1]))+min(a[i],a[i+1]))%P;
	int r=0;for(int i=1;i<=n;i++) r=(r+dp[i][0])%P;
	return printf("%d\n",r),0;
}