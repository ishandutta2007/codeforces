#include<iostream>
#include<algorithm>
using namespace std;
int N,p[100];
int dp[101][101][2];
main()
{
	cin>>N;
	int vc=0,ec=0,oc=0;
	for(int i=0;i<N;i++)
	{
		cin>>p[i];
		if(p[i]==0)vc++;
		else if(p[i]%2==0)ec++;
		else oc++;
	}
	int EC=N/2-ec,OC=(N+1)/2-oc;
	for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)dp[i][j][0]=dp[i][j][1]=1e9;
	dp[0][EC][0]=dp[0][EC][1]=0;
	for(int i=0;i<N;i++)
	{
		for(int j=max(0,vc-OC);j<=EC;j++)
		{
			for(int k=0;k<2;k++)
			{
				if(dp[i][j][k]>1e8)continue;
				if(p[i]!=0)
				{
					dp[i+1][j][p[i]%2]=min(dp[i+1][j][p[i]%2],dp[i][j][k]+(k!=p[i]%2));
				}
				else
				{
					if(j>0)
					{
						dp[i+1][j-1][0]=min(dp[i+1][j-1][0],dp[i][j][k]+(k!=0));
					}
					if(vc-j>0)
					{
						dp[i+1][j][1]=min(dp[i+1][j][1],dp[i][j][k]+(k!=1));
					}
				}
			}
		}
		if(p[i]==0)vc--;
	}
	cout<<min(dp[N][0][0],dp[N][0][1])<<endl;
}