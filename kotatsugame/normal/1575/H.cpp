#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
string A,B;
int to[500],ed;
int dp[2][505][501];
main()
{
	cin>>N>>M>>A>>B;
	for(int i=0;i<M;i++)
	{
		string now=B.substr(0,i);
		now+=B[i]=='0'?'1':'0';
		for(int k=0;k<=now.size();k++)
		{
			if(now.substr(k)==B.substr(0,now.size()-k))
			{
				to[i]=now.size()-k;
				break;
			}
		}
	}
	for(int k=1;k<=M;k++)if(B.substr(k)==B.substr(0,M-k))
	{
		ed=M-k;
		break;
	}
	int now=0;
	int mx=N-M+1;
	for(int i=0;i<=mx;i++)for(int j=0;j<M;j++)dp[now][i][j]=1e9;
	dp[now][0][0]=0;
	for(int i=0;i<N;i++)
	{
		int nxt=1-now;
		for(int j=0;j<=mx;j++)for(int k=0;k<M;k++)dp[nxt][j][k]=1e9;
		for(int j=0;j<=mx;j++)for(int k=0;k<M;k++)
		{
			if(A[i]==B[k])
			{
				if(k+1==M)dp[nxt][j+1][ed]=min(dp[nxt][j+1][ed],dp[now][j][k]);
				else dp[nxt][j][k+1]=min(dp[nxt][j][k+1],dp[now][j][k]);
				dp[nxt][j][to[k]]=min(dp[nxt][j][to[k]],dp[now][j][k]+1);
			}
			else
			{
				if(k+1==M)dp[nxt][j+1][ed]=min(dp[nxt][j+1][ed],dp[now][j][k]+1);
				else dp[nxt][j][k+1]=min(dp[nxt][j][k+1],dp[now][j][k]+1);
				dp[nxt][j][to[k]]=min(dp[nxt][j][to[k]],dp[now][j][k]);
			}
		}
		now=nxt;
	}
	for(int k=0;k<=mx;k++)
	{
		int ans=1e9;
		for(int j=0;j<M;j++)ans=min(ans,dp[now][k][j]);
		if(ans==(int)1e9)ans=-1;
		cout<<ans<<(k==mx?"\n":" ");
	}
}