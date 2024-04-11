#include<iostream>
using namespace std;
int N,M,K,P;
bool vis[101][101];
int memo[101][101][101];
int MX[101][101];
int comb[101][101];
void calc(int n,int l)
{
	if(vis[n][l])return;
	vis[n][l]=true;
	if(n==0)
	{
		memo[n][l][0]=1;
		MX[n][l]=0;
		return;
	}
	for(int i=0;i<n;i++)
	{
		calc(i,l+1);
		calc(n-i-1,l+1);
		if(l+1>=M)
		{
			int x=l+1==M;
			memo[n][l][x]+=(long long)memo[i][l+1][0]*memo[n-i-1][l+1][0]%P*comb[n-1][i]%P;
			memo[n][l][x]%=P;
			MX[n][l]=max(MX[n][l],1);
		}
		else
		{
			for(int a=0;a<=MX[i][l+1];a++)for(int b=0;b<=MX[n-i-1][l+1]&&a+b<=K;b++)
			{
				memo[n][l][a+b]+=(long long)memo[i][l+1][a]*memo[n-i-1][l+1][b]%P*comb[n-1][i]%P;
				memo[n][l][a+b]%=P;
			}
			MX[n][l]=max(MX[n][l],MX[i][l+1]+MX[n-i-1][l+1]);
		}
	}
	if(MX[n][l]>K)MX[n][l]=K;
}
main()
{
	cin>>N>>M>>K>>P;
	comb[0][0]=1;
	for(int i=1;i<=N;i++)
	{
		comb[i][0]=comb[i][i]=1;
		for(int j=1;j<i;j++)comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%P;
	}
	calc(N,0);
	cout<<memo[N][0][K]<<endl;
}