#include <bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,a[100005],v[100005],qaq[100005],b[100005],dp[405][205];
signed main()
{
	for(read(T);T--;)
	{
		memset(v,0,sizeof(v)),read(n);
		for(int i=1;i<=n;i++) read(a[i]);
		sort(a+1,a+n+1),memset(dp,0x7f,sizeof(dp)),dp[0][0]=0;
		for(int i=1;i<=2*n;i++)
		{
			int tmp=min(i,n);
			for(int j=0;j<=tmp;j++) dp[i][j]=dp[i-1][j],dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(a[j]-i));
		}
		int ans=1e9+5;
		for(int i=n;i<=2*n;i++) ans=min(ans,dp[i][n]);
		printf("%d\n",ans);
	}
	return 0;
}