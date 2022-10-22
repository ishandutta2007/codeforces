#include <bits/stdc++.h>
using namespace std;
#define N 805
const int lim=800;
int n,MOD,ans,f[N],C[N][N],dp[N][N];
int W(int &x,int y) {x=(x+y)%MOD;}
int main()
{
	scanf("%d %d",&n,&MOD);f[1]=dp[0][0]=1;
	for(int i=0;i<=lim;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}for(int i=2;i<=n;++i) f[i]=f[i-1]*2%MOD;
	for(int i=1,t;i<=n;++i)
	{
		W(dp[i][i],f[i]); 
		for(int j=2;j<i;++j) for(int k=i-j;k<=i;++k)
			W(dp[i][k],1ll*dp[j-1][k-i+j]*f[i-j]%MOD*C[k][i-j]%MOD);
	}for(int i=1;i<=n;++i) W(ans,dp[n][i]);
	printf("%d\n",ans);return 0;
}