#include<iostream>
using namespace std;
int N;
long long S[201][201];
long long dp[201][201];
int root[201][201];
int pr[201];
void dfs(int l,int r,int p)
{
	if(l==r)return;
	int v=root[l][r];
	pr[v]=p+1;
	dfs(l,v,v);
	dfs(v+1,r,v);
}
main()
{
	cin>>N;
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
	{
		int c;cin>>c;
		S[i][j]=c+S[i-1][j]+S[i][j-1]-S[i-1][j-1];
	}
	for(int k=1;k<=N;k++)for(int i=0;i+k<=N;i++)
	{
		dp[i][i+k]=1e18;
		for(int l=i;l<i+k;l++)
		{
			long long now=dp[i][l]+(S[l][N]-S[i][N])-(S[l][l]-S[i][l]-S[l][i]+S[i][i])+
				dp[l+1][i+k]+(S[i+k][N]-S[l+1][N])-(S[i+k][i+k]-S[l+1][i+k]-S[i+k][l+1]+S[l+1][l+1]);
			if(dp[i][i+k]>now)
			{
				dp[i][i+k]=now;
				root[i][i+k]=l;
			}
		}
	}
	dfs(0,N,-1);
	for(int i=0;i<N;i++)cout<<pr[i]<<(i+1==N?"\n":" ");
}