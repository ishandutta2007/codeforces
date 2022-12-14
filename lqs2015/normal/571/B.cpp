#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[5555][5555],n,k,p,q,pos,sz,a[333333];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	p=n%k;
	q=k-p;
	sz=n/k;
	for (int i=0;i<=p;i++)
	{
		for (int j=0;j<=q;j++)
		dp[i][j]=2e9;
	}
	dp[0][0]=0;
	for (int i=0;i<=p;i++)
	{
		for (int j=0;j<=q;j++)
		{
			pos=(i+j)*sz+i;
			if (i) dp[i][j]=min(dp[i][j],dp[i-1][j]+a[pos]-a[pos-sz]);
			if (j) dp[i][j]=min(dp[i][j],dp[i][j-1]+a[pos]-a[pos-sz+1]);
		}
	}
	printf("%d\n",dp[p][q]);
	return 0;
}