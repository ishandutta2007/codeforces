#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
int n,m,K,P,vl[105],C[105][105],dp[105][105][105];
inline int solve(int n,int d,int w)
{
	if(2*w-1>n) return 0;
	if(n==0) return w==0;
	if(n==1) return (d==1&&w==1)||(d!=1&&w==0);
	if(d==1) return w==1?vl[n]:0;
	int &rs=dp[n][d][w];if(~rs) return rs;else rs=0;
	for(int i=0;i<n;i++) for(int x=0;x<=w;x++)
		rs=(rs+1ll*solve(i,d-1,x)*solve(n-i-1,d-1,w-x)%P*C[n-1][i])%P;
	return rs;
}
int main()
{
	read(n,m,K,P),memset(dp,-1,sizeof(dp));
	for(int i=0;i<=n;i++) {C[i][0]=1;for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;}
	vl[0]=1,vl[1]=1;for(int i=2;i<=n;i++) for(int l=0;l<i;l++) vl[i]=(vl[i]+1ll*vl[l]*vl[i-l-1]%P*C[i-1][l])%P;
	return printf("%d\n",solve(n,m,K)),0;
}