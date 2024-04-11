//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;typedef long double ld;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int P=1e9+7;int n,cn,dp[1000005];
int main()
{
	read(n);for(int i=1,x;i<=n;i++) read(x),cn+=x==1;
	dp[0]=dp[1]=1;for(int i=2;i<=cn;i++) dp[i]=(dp[i-1]+1ll*dp[i-2]*(i-1))%P;
	int rs=dp[cn];for(int i=n;i>cn;i--) rs=1ll*rs*i%P;
	return printf("%d\n",rs),0;
}