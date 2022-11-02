//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,m,a[200005],dp[200005],pc;
inline void solve()
{
	read(n),m=0,dp[2]=0;for(int i=1,x;i<=n;i++) read(x),a[x]++,m=max(m,x);
	dp[1]=a[1];for(int i=2;i<=m;i++,dp[i]=a[i]) for(int j=1;j*j<=i;j++) if(i%j==0)
		{dp[i]=max(dp[i],dp[j]+a[i]);if(j*j!=i&&j!=1) dp[i]=max(dp[i],dp[i/j]+a[i]);}
	int mx=0;for(int i=1;i<=m;i++) mx=max(mx,dp[i]),a[i]=0;
	printf("%d\n",n-mx);
}
int main() {for(read(T);T--;) solve();return 0;}