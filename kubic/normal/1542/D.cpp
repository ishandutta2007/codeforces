#include <bits/stdc++.h>
using namespace std;
#define N 505
#define MOD 998244353
int n,ans,a[N],dp[N][N];
void W(int &x,int y) {x=(x+y)%MOD;}
int slv(int x)
{
	int res=0;dp[0][0]=1;
	for(int i=1;i<x;++i)
	{
		for(int j=0;j<=i;++j) dp[i][j]=dp[i-1][j];
		for(int j=0;j<i;++j)
		{
			if(!a[i]) W(dp[i][max(j-1,0)],dp[i-1][j]);
			else if(a[i]<=a[x]) W(dp[i][j+1],dp[i-1][j]);	
			else W(dp[i][j],dp[i-1][j]);
		}
	}for(int i=1;i<=x;++i) dp[x][i]=dp[x-1][i-1];
	for(int i=x+1;i<=n;++i)
	{
		dp[i-1][0]=0;
		for(int j=0;j<=i;++j) dp[i][j]=dp[i-1][j];
		for(int j=0;j<i;++j)
		{
			if(!a[i]) W(dp[i][max(j-1,0)],dp[i-1][j]);
			else if(a[i]<a[x]) W(dp[i][j+1],dp[i-1][j]);	
			else W(dp[i][j],dp[i-1][j]);
		}
	}for(int i=1;i<=n;++i) W(res,dp[n][i]);return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		char op[2];scanf("%s",op);
		if(op[0]=='+') scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i) if(a[i])
		W(ans,1ll*slv(i)*a[i]%MOD);
	printf("%d\n",ans);return 0;
}