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
int n,k,d,a[500005];char dp[500005];
int main()
{
	read(n),read(k),read(d);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1),dp[0]=1;int nw=1;
	for(int i=0;i<=n;i++) if(dp[i]) {nw=max(nw,i+k);while(nw<=n&&a[i+1]+d>=a[nw]) dp[nw++]=1;}
	return puts(dp[n]?"YES":"NO"),0;
}