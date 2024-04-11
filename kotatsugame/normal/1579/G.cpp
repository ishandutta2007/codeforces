#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
int dp[2][2001];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int now=0;
		for(int i=0;i<=2000;i++)dp[now][i]=1e9;
		dp[now][0]=0;
		for(int i=0;i<N;i++)
		{
			int A;cin>>A;
			int nxt=1-now;
			for(int j=0;j<=2000;j++)dp[nxt][j]=1e9;
			for(int j=0;j<=2000;j++)if(dp[now][j]!=(int)1e9)
			{
				dp[nxt][max(j-A,0)]=min(dp[nxt][max(j-A,0)],dp[now][j]+A);
				if(j+A<=2000)dp[nxt][j+A]=min(dp[nxt][j+A],max(dp[now][j]-A,0));
			}
			now=nxt;
		}
		int ans=1e9;
		for(int j=0;j<=2000;j++)ans=min(ans,j+dp[now][j]);
		cout<<ans<<"\n";
	}
}