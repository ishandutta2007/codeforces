//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int P=998244353;
int n,X[200005],Y[200005];ll dp[200005],sdp[200005];char v[200005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(X[i]),read(Y[i]),read(v[i]);
	sdp[0]=dp[0]=(X[1]<<1)-Y[1];for(int i=1;i<n;i++)
	{
		dp[i]=(X[i+1]-X[i])<<1;int wh=lower_bound(X+1,X+n+1,Y[i+1])-X-1;
		dp[i]=(dp[i]+sdp[i-1]-sdp[wh-1]+X[wh]-Y[i+1])%P,sdp[i]=(sdp[i-1]+dp[i])%P;
	}
	ll rs=0;for(int i=1;i<=n;i++) if(!v[i]) rs=(rs+X[i]-X[i-1])%P;else rs=(rs+dp[i-1])%P;
	return printf("%lld\n",(rs+P+1)%P),0;
}