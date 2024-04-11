#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;
long long dp[2][40];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		int now=0;
		for(int j=0;j<40;j++)dp[now][j]=-1e18;
		dp[now][0]=0;
		for(int i=0;i<N;i++)
		{
			int nxt=1-now;
			for(int j=0;j<40;j++)dp[nxt][j]=-1e18;
			int A;cin>>A;
			for(int j=0;j<40;j++)
			{
				dp[nxt][j]=max(dp[nxt][j],dp[now][j]-K+((long long)A>>j));
				dp[nxt][min(39,j+1)]=max(dp[nxt][min(39,j+1)],dp[now][j]+((long long)A>>j+1));
			}
			now=nxt;
		}
		long long ans=0;
		for(int j=0;j<40;j++)ans=max(ans,dp[now][j]);
		cout<<ans<<"\n";
	}
}