#include<iostream>
using namespace std;
int a[1111][1111],n,k,dp[1111][1111][2],zx,zy;
bool Left[1111][1111][2];
int p[2]={2,5},way[2222];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		cin>>a[i][j];
	}
	for (int i=2;i<=n;i++)
	{
		dp[i][0][0]=dp[i][0][1]=dp[0][i][0]=dp[0][i][1]=1<<29;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (!a[i][j])
			{
				zx=i;
				zy=j;
			}
			for (int k=0;k<2;k++)
			{
				dp[i][j][k]=min(dp[i][j-1][k],dp[i-1][j][k])+!a[i][j];
				Left[i][j][k]=dp[i][j-1][k]<dp[i-1][j][k];
				for(int x=a[i][j];x && x%p[k]==0;x/=p[k]) dp[i][j][k]++;
			}
		}
	}
	int k=dp[n][n][0]>dp[n][n][1] ? 1 : 0;
	if (zx>0 && dp[n][n][k]>0)
	{
		cout<<"1"<<endl;
		for (int i=2;i<=zy;i++) cout<<"R";
		for (int i=2;i<=zx;i++) cout<<"D";
		for (int i=zy+1;i<=n;i++) cout<<"R";
		for (int i=zx+1;i<=n;i++) cout<<"D";
		cout<<endl;
		return 0;
	}
	cout<<dp[n][n][k]<<endl;
	for (int i=2*n-3,x=n,y=n;i>=0;i--,Left[x][y][k] ? y-- : x--)
	{
		way[i]=Left[x][y][k];
	}
	for (int i=0;i<2*n-2;i++)
	{
		if (way[i]) cout<<"R";
		else cout<<"D";
	}
	cout<<endl;
	return 0;
}