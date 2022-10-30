//Coded by Kamiyama_Shiki on 2021.10.31 {{{
//
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
const int N=3005;int n,a[N],dp[N][N];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	memset(dp,0x3f,sizeof(dp));for(int i=2;i<=n;i++) dp[i][1]=0;
	for(int i=2,cnt=0;i<=n;i++,cnt=0)
	{
		for(int j=i-1;j>=1;j--) if(j+a[j]>=i)
			dp[j+a[j]+1][i]=min(dp[i][j]+cnt++,dp[j+a[j]+1][i]);
		for(int j=i+1;j<=n;j++) dp[j][i]=min(dp[j-1][i],dp[j][i]);
	}
	//for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("%d%c",dp[i][j],j==n?'\n':' ');
	printf("%d\n",dp[n+1][n]);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}