#include<iostream>
#include<vector>
using namespace std;
int A[5000];
int dp[5001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<=N;i++)dp[i]=1e9;
		dp[0]=0;
		for(int i=0;i<N;i++)
		{
			int x=0;
			for(int j=i;j>=0;j--)
			{
				x^=A[j];
				if(x>0)dp[i+1]=min(dp[i+1],dp[j]+(i-j)+1);
				else dp[i+1]=min(dp[i+1],dp[j]+(i-j));
			}
		}
		cout<<dp[N]<<"\n";
	}
}