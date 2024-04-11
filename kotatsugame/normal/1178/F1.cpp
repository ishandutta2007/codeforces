#include<iostream>
#include<algorithm>
using namespace std;
long long mod=998244353;
int dp[501][501];
int N,M;
int C[500];
int dfs(int L,int R)
{
	if(L+1>=R)return 1;
	else if(dp[L][R]>=0)return dp[L][R];
	int id=L;
	for(int i=L+1;i<R;i++)
	{
		if(C[id]>C[i])id=i;
	}
	long long retL=0,retR=0;
	for(int l=id;l>=L;l--)
	{
		retL=(retL+(long long)dfs(L,l)*dfs(l,id)%mod)%mod;
	}
	for(int r=id+1;r<=R;r++)
	{
		retR=(retR+(long long)dfs(id+1,r)*dfs(r,R)%mod)%mod;
	}
	return dp[L][R]=retL*retR%mod;
}
main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		cin>>C[i];
	}
	for(int i=0;i<=N;i++)for(int j=0;j<=N;j++)dp[i][j]=-1;
	cout<<dfs(0,N)<<endl;
}