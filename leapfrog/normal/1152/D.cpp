//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,dp[2005][2005],ans;
int main()
{
	read(n),dp[1][1]=1,ans=0;
	for(int i=2;i<=n+1;i++) for(int j=1;j<=i;j++) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%P;
	for(int i=1;i<=n+1;i++) for(int j=1;j<=i;j++) if((i+j)&1) ans=(ans+dp[i][j])%P;
	return printf("%d\n",ans),0;
}