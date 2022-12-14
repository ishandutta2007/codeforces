#include<iostream>
using namespace std;
int dp[111][11111],n,a[111],b[111],k,t,suma,sumb;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=1;i<=n;i++) 
	{
		suma+=a[i];
		sumb+=b[i];
	}
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=10000;j++)
		dp[i][j]=-1e9;
	}
	dp[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j>=0;j--)
		{
			for (int k=10000;k>=0;k--)
			{
				dp[j+1][k+b[i]]=max(dp[j+1][k+b[i]],dp[j][k]+a[i]);
			}
		}
	}
	t=1e9;k=1e9;
	for (int i=0;i<=n;i++)
	{
		for (int j=suma;j<=10000;j++)
		{
			if (dp[i][j]<0) continue;
			if (k>i || (k==i && t>suma-dp[i][j]))
			{
				k=i;
				t=suma-dp[i][j];
			}
		}
	}
	cout<<k<<" "<<t<<endl;
	return 0;
}