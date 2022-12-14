#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str[111111];
long long dp[111111][2];
long long n,c[111111],ans;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>c[i];
	for (int i=1;i<=n;i++) cin>>str[i];
	for (int i=1;i<=n;i++) 
	{
		for (int j=0;j<=1;j++)
		dp[i][j]=1e18;
	}
	dp[1][0]=0;dp[1][1]=c[1];
	for (int i=2;i<=n;i++)
	{
		string st=str[i-1];
		string stt=str[i];
		if (st<=stt) dp[i][0]=min(dp[i][0],dp[i-1][0]);
		reverse(stt.begin(),stt.end());
		if (st<=stt) dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
		reverse(stt.begin(),stt.end());
		reverse(st.begin(),st.end());
		if (st<=stt) dp[i][0]=min(dp[i][0],dp[i-1][1]);
		reverse(stt.begin(),stt.end());
		if (st<=stt) dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
		reverse(stt.begin(),stt.end());
	}
	ans=min(dp[n][0],dp[n][1]);
	if (ans==1e18) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}