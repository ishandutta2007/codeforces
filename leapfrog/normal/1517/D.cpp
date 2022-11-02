//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,m,K,dp[505][505][11],x[505][505],y[505][505];
inline char chk(int &a,int b) {a=min(a,b);}
int main()
{
	read(n),read(m),read(K),memset(dp,0x3f,sizeof(dp));
	if(K&1) {for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("-1%c",j==m?'\n':' ');return 0;}
	K>>=1;for(int i=1;i<=n;i++) for(int j=1;j<m;j++) read(x[i][j]);
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++) read(y[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dp[i][j][0]=0;
	for(int k=1;k<=K;k++) for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		if(i^1) chk(dp[i][j][k],dp[i-1][j][k-1]+y[i-1][j]);
		if(i^n) chk(dp[i][j][k],dp[i+1][j][k-1]+y[i][j]);
		if(j^1) chk(dp[i][j][k],dp[i][j-1][k-1]+x[i][j-1]);
		if(j^m) chk(dp[i][j][k],dp[i][j+1][k-1]+x[i][j]);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",dp[i][j][K]*2,j==m?'\n':' ');
	return 0;
}