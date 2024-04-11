//Coded by Kamiyama_Shiki on 2021.11.08 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=3005;int n,K,at[N],st[N],tp;
ll vl[N],a[N][N],tmp[1000005],dp[25][N],rs=0;
inline void solve(int l,int r,int id)
{
	if(l==r)
	{
		for(int j=1;j<=at[l];j++) rs=max(rs,a[l][j]+dp[id][K-j]);
		return;
	}
	int nx=st[tp--],md=(l+r)>>1;
	for(int j=0;j<=K;j++) dp[nx][j]=dp[id][j];
	for(int i=l;i<=md;i++) for(int j=K;j>=at[i];j--) dp[nx][j]=max(dp[nx][j],dp[nx][j-at[i]]+vl[i]);
	solve(md+1,r,nx);for(int j=0;j<=K;j++) dp[nx][j]=dp[id][j];
	for(int i=md+1;i<=r;i++) for(int j=K;j>=at[i];j--) dp[nx][j]=max(dp[nx][j],dp[nx][j-at[i]]+vl[i]);
	solve(l,md,nx),st[++tp]=nx;
}
int main()
{
	read(n,K);for(int i=1;i<=n;i++)
	{
		read(at[i]);for(int j=1;j<=at[i];j++) read(tmp[j]),tmp[j]+=tmp[j-1];
		vl[i]=tmp[at[i]=min(K,at[i])];for(int j=1;j<=K;j++) a[i][j]=tmp[j];
	}
	for(int i=1;i<=24;i++) st[++tp]=i;
	return solve(1,n,0),printf("%lld\n",rs),0;
}