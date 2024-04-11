#include<iostream>
using namespace std;
int dp[111][16];
string s,t;
main()
{
	cin>>s>>t;
	for(int i=0;i<s.size();i++)for(int j=0;j<16;j++)dp[i][j]=-1;
	dp[0][(s[0]=='X')<<1|(t[0]=='X')]=0;
	for(int i=1;i<s.size();i++)
	{
		int next=(s[i]=='X')<<1|(t[i]=='X');
		for(int j=0;j<16;j++)
		{
			if(dp[i-1][j]<0)continue;
			int now=(j&3)<<2|next;
			dp[i][now]=max(dp[i][now],dp[i-1][j]);
			if(!(now&14))dp[i][now|14]=max(dp[i][now|14],dp[i-1][j]+1);
			if(!(now&13))dp[i][now|13]=max(dp[i][now|13],dp[i-1][j]+1);
			if(!(now&11))dp[i][now|11]=max(dp[i][now|11],dp[i-1][j]+1);
			if(!(now&7))dp[i][now|7]=max(dp[i][now|7],dp[i-1][j]+1);
		}
	}
	int ans=0;
	for(int i=0;i<16;i++)ans=max(ans,dp[s.size()-1][i]);
	cout<<ans<<endl;
}