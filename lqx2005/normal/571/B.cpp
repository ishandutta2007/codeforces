#include<bits/stdc++.h>
using namespace std;
const int maxn=310000;
const int maxm=5100;
int n,k;
int a[maxn],dp[maxm][maxm];
void chm(int &x,int y)
{
	if(x==-1||x>y) x=y;
	return;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ca=k-n%k,cb=n%k;
	int sa=n/k,sb=n/k+1;
	for(int i=0;i<=k;i++) for(int j=0;j<=k;j++) dp[i][j]=-1;
	dp[0][0]=0;
	for(int i=0;i<=ca;i++)
	{
		for(int j=0;j<=cb;j++)
		{
			if(dp[i][j]==-1) continue;
			int pa=(i+1)*sa+j*sb;
			int pb=i*sa+(j+1)*sb;
			if(pa<=n) chm(dp[i+1][j],dp[i][j]+a[pa]-a[pa-sa+1]);
			if(pb<=n) chm(dp[i][j+1],dp[i][j]+a[pb]-a[pb-sb+1]);
		}
	}
	printf("%d\n",dp[ca][cb]);
	return 0;
}