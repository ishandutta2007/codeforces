#include<iostream>
using namespace std;
int T;
string N;
long long dp[11][2][2];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<=N.size();i++)for(int j=0;j<4;j++)dp[i][j/2][j%2]=0;
		dp[N.size()][0][0]=1;
		for(int i=N.size();i--;)
		{
			int nd=N[i]-'0';
			for(int j=0;j<2;j++)for(int k=0;k<2;k++)
			{
				int now=(nd-k+10)%10;
				for(int a=0;a<10;a++)
				{
					int b=(now-a+10)%10;
					dp[i][a+b+k>=10][j]+=dp[i+1][j][k];
				}
			}
		}
		cout<<dp[0][0][0]-2<<'\n';
	}
}