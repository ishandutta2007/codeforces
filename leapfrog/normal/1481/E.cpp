//
#include<bits/stdc++.h>////
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,a[500005],ri[500005],le[500005],f[500005],dp[500005],g[500005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),f[a[i]]++;
	for(int i=1;i<=n;i++) ri[a[i]]=i;
	for(int i=n;i>=1;i--) le[a[i]]=i;
	for(int i=n;i>=1;i--)
	{
		dp[i]=dp[i+1],g[a[i]]++;
		if(i==le[a[i]]) dp[i]=max(dp[i],dp[ri[a[i]]+1]+f[a[i]]);
		else dp[i]=max(dp[i],g[a[i]]);
	}
	return printf("%d\n",n-dp[1]),0;
}