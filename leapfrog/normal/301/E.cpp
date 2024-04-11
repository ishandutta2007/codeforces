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
const int P=1000000007;int n,m,K,C[105][105],dp[2][105][105][105],rs;
int main()
{
	read(n),read(m),read(K),C[0][0]=1,n++,dp[1][0][1][1]=1;
	for(int i=1;i<=K;i++) for(int j=0;j<=i;j++) C[i][j]=min((j?C[i-1][j-1]:0)+C[i-1][j],1919);
	for(int i=0;i<=m;i++)
	{
		int ls=(i&1)^1,nw=i&1;if(i)
		{
			int tp=0;for(int j=2;j<=n;j++)
				for(int k=1;k<=K;k++) tp=(tp+dp[ls][j][0][k])%P;
			rs=(rs+1ll*tp*(m-i+1))%P;
		}if(i==m) break;else memset(dp[nw],0,sizeof(dp[nw]));
		for(int j=0;j<=n;j++) for(int k=1;k<=n;k++) for(int l=1;l<=K;l++)
			if(dp[ls][j][k][l]) for(int z=k;z<=n-j;z++) if(l*C[z-1][k-1]<=K)
				dp[nw][j+z][z-k][l*C[z-1][k-1]]=(dp[nw][j+z][z-k][l*C[z-1][k-1]]+dp[ls][j][k][l])%P;
	}
	return printf("%d\n",rs),0;
}