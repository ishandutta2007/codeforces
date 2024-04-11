#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<random>
using namespace std;
int N;
double P[18][18];
double dp[1<<18][18];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>P[i][j];
	dp[(1<<N)-1][0]=1;
	for(int i=(1<<N)-1;i--;)for(int j=0;j<N;j++)if(i>>j&1)
	{
		for(int k=0;k<N;k++)if(!(i>>k&1))
		{
			dp[i][j]=max(dp[i][j],dp[i|1<<k][k]*P[k][j]+dp[i|1<<k][j]*P[j][k]);
		}
	}
	double ans=0;
	for(int i=0;i<N;i++)ans=max(ans,dp[1<<i][i]);
	cout<<fixed<<setprecision(16)<<ans<<endl;
}