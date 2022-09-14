#include<iostream>
using namespace std;
const int mod=998244353;
int N,K;
int dp[2<<17];
int ans[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>K;
	dp[0]=1;
	int low=0;
	while(low<=N)
	{
		for(int i=low;i<=N;i++)
		{
			ans[i]+=dp[i];
			ans[i]-=mod*(ans[i]>=mod);
		}
		for(int i=N-K;i>=low;i--)
		{
			dp[i+K]=dp[i];
		}
		low+=K;
		for(int i=low;i+K<=N;i++)
		{
			dp[i+K]+=dp[i];
			dp[i+K]-=mod*(dp[i+K]>=mod);
		}
		K++;
	}
	for(int i=1;i<=N;i++)cout<<ans[i]<<(i==N?"\n":" ");
}