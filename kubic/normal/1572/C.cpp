#include <bits/stdc++.h>
using namespace std;
#define N 3005
int T,n,a[N],nw[N],pr[N],dp[N][N];
void slv()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) nw[i]=0;
	for(int i=1,x;i<=n;++i) scanf("%d",&x),pr[i]=nw[x],nw[x]=i;
	for(int r=1;r<=n;++r) for(int l=r-1;l;--l)
	{
		dp[l][r]=dp[l][r-1]+1;
		for(int i=pr[r];i>=l;i=pr[i])
			dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]);
	}printf("%d\n",dp[1][n]);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}