#include<iostream>
using namespace std;
int n,k,dp[111];
bool f[111];
char c;
int main()
{
	cin>>n>>k;
	getchar();
	for (int i=1;i<=n;i++) 
	{
		cin>>c;
		f[i]=c-'0';
	}
	for (int i=1;i<=n;i++) dp[i]=1e9;
	dp[1]=0;
	for (int i=2;i<=n;i++)
	{
		if (!f[i]) continue;
		for (int j=i-1;j>=max(1,i-k);j--)
		{
			dp[i]=min(dp[i],dp[j]+1);
		}
	}
	if (dp[n]==1e9) cout<<-1<<endl;
	else cout<<dp[n]<<endl;
	return 0;
}