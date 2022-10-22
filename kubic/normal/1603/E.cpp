#include <bits/stdc++.h>
using namespace std;
#define N 205
int n,MOD,ans,C[N][N],dp[N][N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int slv(int x)
{
	int res=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=x;++j) dp[i][j]=0;
		dp[i][0]=i<=x?C[n][i]:0;
	}
	for(int i=1;i<=n-x+1;++i) for(int j=x+i-1;j;--j)
		for(int k=x;k>=i;--k) for(int l=1;l<=j && i*l<=k;++l)
			W(dp[j][k],1ll*dp[j-l][k-i*l]*C[n-j+l][l]%MOD);
	for(int i=0;i<=x;++i) W(res,dp[n][i]);return res;
}
int main()
{
	scanf("%d %d",&n,&MOD);ans=1;
	for(int i=0;i<=n;++i) for(int j=0;j<=i;++j)
		C[i][j]=j?add(C[i-1][j],C[i-1][j-1]):1;
	for(int i=max(n-20,1);i<=n;++i) W(ans,slv(i));
	printf("%d\n",ans);return 0;
}