//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int Ca,n,tg[5005],w[5005];ll dp[5005];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(tg[i]);
	for(int i=1;i<=n;i++) read(w[i]),dp[i]=0;
	for(int i=1;i<=n;i++) for(int j=i-1;j;j--) if(tg[i]^tg[j])
	{
		ll wi=dp[i],wj=dp[j];
		dp[j]=max(wj,wi+abs(w[i]-w[j]));
		dp[i]=max(wi,wj+abs(w[i]-w[j]));
	}
	ll res=0;for(int i=1;i<=n;i++) res=max(res,dp[i]);
	printf("%lld\n",res);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}