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
int n,P,dp[4000005],sdp[4000005],cf[4000005];
int main()
{
	read(n),read(P),dp[1]=1,sdp[1]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=(dp[i]+cf[i])%P,dp[i]=(sdp[i-1]+dp[i])%P,sdp[i]=(sdp[i-1]+dp[i])%P,cf[i+1]=(cf[i+1]+cf[i])%P;
		for(int k=2;k*i<=n;k++) cf[k*i]=(cf[k*i]+dp[i])%P,cf[min(k*i+k,n+1)]=(cf[min(k*i+k,n+1)]+P-dp[i])%P;
	//	for(int i=1;i<=n;i++) printf("%d%c",cf[i],i==n?'\n':' ');
	}
	//for(int i=1;i<=n;i++) printf("%d%c",dp[i],i==n?'\n':' ');
	return printf("%d\n",dp[n]),0;
}