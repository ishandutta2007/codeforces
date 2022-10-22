#include <bits/stdc++.h>
using namespace std;
#define N 5005
#define ll long long
#define set(a,vl) memset(a,vl,sizeof(a))
int n,m1,m2,a[5][N];ll dp[2][N];
void W(ll &x,ll y) {x=min(x,y);}
int main()
{
	scanf("%d %d %d",&n,&m1,&m2);set(dp[0],0x3f);dp[0][0]=0;
	for(int i=0;i<5;++i) for(int j=1;j<=n;++j) scanf("%d",&a[i][j]);
	for(int i=1,fl=1;i<=n;++i,fl^=1)
	{
		a[1][i]+=a[0][i];a[2][i]-=a[0][i];
		a[3][i]+=a[0][i];a[4][i]-=a[0][i];set(dp[fl],0x3f);
		if(i==m1) for(int j=i>m2;j<i;++j)
		{
			if(j) W(dp[fl][j],dp[fl^1][j]+a[3][i]); 
			W(dp[fl][j+1],dp[fl^1][j]+a[4][i]);
		}
		else if(i==m2) for(int j=i>m1;j<i;++j)
		{
			if(j) W(dp[fl][j],dp[fl^1][j]+a[1][i]); 
			W(dp[fl][j+1],dp[fl^1][j]+a[2][i]);
		}
		else for(int j=(i>m1)+(i>m2);j<i;++j)
		{
			if(j>1) W(dp[fl][j-1],dp[fl^1][j]+a[1][i]+a[3][i]);
			if(j>(i>m2)) W(dp[fl][j],dp[fl^1][j]+a[1][i]+a[4][i]);
			if(j>(i>m1)) W(dp[fl][j],dp[fl^1][j]+a[2][i]+a[3][i]);
			W(dp[fl][j+1],dp[fl^1][j]+a[2][i]+a[4][i]);
		}
	}printf("%lld\n",dp[n&1][1]);return 0;
}