#include<iostream>
using namespace std;
int N,K;
string S;
bool dp[1010][2020];
main()
{
	cin>>N>>K>>S;
	dp[0][K]=true;
	for(int i=0;i<N;i++)
	{
		for(int j=-K+1;j<K;j++)if(dp[i][j+K])
		{
			if(S[i]=='L'||S[i]=='?')dp[i+1][j+K-1]=true;
			if(S[i]=='W'||S[i]=='?')dp[i+1][j+K+1]=true;
			if(S[i]=='D'||S[i]=='?')dp[i+1][j+K]=true;
		}
	}
	int st=K;
	if(dp[N][0])st=0;
	if(dp[N][2*K])st=2*K;
	if(st==K)cout<<"NO"<<endl;
	else
	{
		for(int i=N;i--;)
		{
			if((S[i]=='L'||S[i]=='?')&&st+1<2*K&&dp[i][st+1])S[i]='L',st++;
			else if((S[i]=='W'||S[i]=='?')&&st-1>0&&dp[i][st-1])S[i]='W',st--;
			else S[i]='D';
		}
		cout<<S<<endl;
	}
}