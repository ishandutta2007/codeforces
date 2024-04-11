#include<bits/stdc++.h>
#define int long long
#define mo 1000000007
#define N 2000006
using namespace std;
int dp[N][3],p3[N],T,n;
signed main()
{
	dp[1][0]=0;
	dp[1][1]=1;
	dp[2][0]=1;
	dp[2][1]=1;
	p3[0]=1;
	for (int i=1;i<=2000005;i++) (p3[i]=p3[i-1]*3)%=mo;
	for (int i=3;i<=2000005;i++)
	{
		(dp[i][1]+=dp[i-1][0])%=mo;
		(dp[i][1]+=2*dp[i-2][0])%=mo;
		(dp[i][1]+=1)%=mo;
		(dp[i][0]+=max(dp[i-1][0],dp[i-1][1]))%=mo;
		(dp[i][0]+=max(dp[i-2][0],dp[i-2][1])*2)%=mo;
	}
	cin>>T;
	while (T--)
	{
		cin>>n;
		if (n<=2) cout<<0<<endl; else
		if (n==3) cout<<4<<endl; else
		cout<<(max(dp[n-2][0],dp[n-2][1]))*4%mo<<endl;
	}
}