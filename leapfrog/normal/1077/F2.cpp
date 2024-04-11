//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,K,m,a[5005],lg[5005];ll dp[5005][5005],st[5005][13];
inline ll qry(int l,int r) {ll g=lg[r-l+1];return max(st[l][g],st[r-(1<<g)+1][g]);}
int main()
{
	read(n),read(K),read(m),memset(dp,~0x3f,sizeof(dp)),dp[0][0]=0;
	lg[0]=-1;for(int i=1;i<=n;i++) read(a[i]),lg[i]=lg[i>>1]+1;
	for(int k=1;k<=m;k++)
	{
		for(int i=0;i<=n;i++) st[i][0]=dp[i][k-1];
		for(int j=0;j<12;j++) for(int i=0;i+(1<<j)<=n;i++) st[i][j+1]=max(st[i][j],st[i+(1<<j)][j]);
		for(int i=1;i<=n;i++) dp[i][k]=qry(max(0,i-K),i-1)+a[i];
		//for(int i=1;i<=n;i++) printf("%lld%c",dp[i][k],i==n?'\n':' ');
	}
	//for(int i=1;i<=K;i++) for(int j=1;j<=n;j++) printf("%d%c",dp[j][i],j==n?'\n':' ');
	ll mx=-1;for(int i=n-K+1;i<=n;i++) mx=max(mx,dp[i][m]);
	return printf("%lld\n",mx<0?-1:mx),0;
}