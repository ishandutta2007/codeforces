#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int t,N;
string S,T;
main()
{
	cin>>t;
	for(;t--;)
	{
		cin>>N>>S>>T;
		vector<vector<int> >cnts(N+1,vector<int>(26));
		vector<vector<int> >cntt(N+1,vector<int>(26));
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<26;j++)cnts[i+1][j]=cnts[i][j];
			for(int j=0;j<26;j++)cntt[i+1][j]=cntt[i][j];
			cnts[i+1][S[i]-'a']++;
			cntt[i+1][T[i]-'a']++;
		}
		if(cnts[N]!=cntt[N])
		{
			cout<<-1<<"\n";
			continue;
		}
		vector<vector<int> >dp(N+1,vector<int>(N+1,-(int)1e9));
		dp[0][0]=0;
		for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)
		{
			if(i<N&&j<N&&S[i]==T[j])dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
			if(i<N&&cnts[i][S[i]-'a']<cntt[j][S[i]-'a'])dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(j<N)dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
		}
		cout<<N-dp[N][N]<<"\n";
	}
}