#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
const int inf=100000000;
int n;
int p[maxn+5];
int but[2];
int dp[maxn+5][maxn+5][2];
int sum[maxn+5];
void chm(int &x,int y)
{
	if(x>y) x=y;
	return;
}
void updata(int i,int j,int l)
{
	if(p[i+1]!=0) chm(dp[i+1][j][p[i+1]%2],dp[i][j][l]+((p[i+1]%2)^l));
	else
	{
		chm(dp[i+1][j][0],dp[i][j][l]+(l));
		chm(dp[i+1][j+1][1],dp[i][j][l]+(l^1));
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		if(p[i]==0) sum[i]++;
		sum[i]+=sum[i-1];
		but[i%2]++;
		if(p[i]==0) continue;
		but[p[i]%2]--;
	}
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j][0]=dp[i][j][1]=inf;
	if(p[1]==0) dp[1][0][0]=0,dp[1][1][1]=0;
	if(p[1]!=0) dp[1][0][p[1]%2]=0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j>sum[i]) continue;
			if(j>but[1]) continue;
			int k=sum[i]-j;
			if(k>but[0]) continue;
			if(p[i]==0) updata(i,j,0),updata(i,j,1);
			else updata(i,j,p[i]%2);
		}
	}
	printf("%d\n",min(dp[n][but[1]][0],dp[n][but[1]][1]));
	return 0;
}