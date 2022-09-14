#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T;
int dp[10][2][1<<10];
vector<int>ok;
int pc[1<<10];
int calc(string N)
{
	for(int i=0;i<=N.size();i++)for(int j=0;j<2;j++)for(int k:ok)dp[i][j][k]=2e9;
	dp[0][0][0]=0;
	for(int i=0;i<N.size();i++)for(int j=0;j<2;j++)
	{
		int lim=j?0:N[i]-'0';
		for(int k:ok)if(dp[i][j][k]<(int)2e9)
		{
			for(int l=lim;l<=9;l++)
			{
				dp[i+1][j||lim<l][k|1<<l]=min(dp[i+1][j||l<<lim][k|1<<l],dp[i][j][k]*10+l);
			}
		}
	}
	int ans=2e9;
	for(int j=0;j<2;j++)for(int k:ok)
	{
		ans=min(ans,dp[N.size()][j][k]);
	}
	return ans;
}
int count(int N)
{
	int ap=0;
	while(N)
	{
		ap|=1<<N%10;
		N/=10;
	}
	return pc[ap];
}
main()
{
	for(int i=0;i<1<<10;i++)pc[i]=__builtin_popcount(i);
	cin>>T;
	for(;T--;)
	{
		string N;
		int K;
		cin>>N>>K;
		int n=0;
		for(char c:N)n=n*10+c-'0';
		if(count(n)<=K)
		{
			cout<<n<<"\n";
			continue;
		}
		if(K>=7)
		{
			while(count(n)>K)n++;
			cout<<n<<"\n";
			continue;
		}
		ok.clear();
		for(int i=0;i<1<<10;i++)if(pc[i]<=K)ok.push_back(i);
		int ans;
		if(N.size()<10)ans=calc(N);
		else ans=K==1?1111111111:1000000000;
		cout<<ans<<"\n";
	}
}