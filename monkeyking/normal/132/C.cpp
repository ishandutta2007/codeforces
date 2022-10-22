#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
char c[105];
int dp[105][55][2];
int k;

int solve1()
{
//	freopen("input.txt","r",stdin);
	int n=strlen(c);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			dp[i][j][0]=dp[i][j][1]=-inf;
		}
	}
	for(int i=0;i<=k;i++)
	{
		if(c[0]=='F' && i&1 || c[0]=='T' && !(i&1)) dp[0][i][1]=0;
		if(c[0]=='F' && !(i&1) || c[0]=='T' && i&1) dp[0][i][0]=1;
	}
//	cout<<dp[0][2][1]<<' '<<dp[0][2][0]<<endl;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			for(int from=0;from<=j;from++)
			{
				if(c[i]=='F' && ((from-j)&1) || (c[i]=='T') && !((from-j)&1))
				{
					dp[i][j][1]=max(dp[i][j][1],dp[i-1][from][0]);
					dp[i][j][0]=max(dp[i][j][0],dp[i-1][from][1]);
				}
				else
				{
					dp[i][j][1]=max(dp[i][j][1],dp[i-1][from][1]-1);
					dp[i][j][0]=max(dp[i][j][0],dp[i-1][from][0]+1);
				}
			}
		}
	}
	return max(dp[n-1][k][0],dp[n-1][k][1]);
}

int solve2()
{
//	freopen("input.txt","r",stdin);
	int n=strlen(c);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			dp[i][j][0]=dp[i][j][1]=inf;
		}
	}
	for(int i=0;i<=k;i++)
	{
		if(c[0]=='F' && i&1 || c[0]=='T' && !(i&1)) dp[0][i][1]=0;
		if(c[0]=='F' && !(i&1) || c[0]=='T' && i&1) dp[0][i][0]=1;
	}
//	cout<<dp[0][2][1]<<' '<<dp[0][2][0]<<endl;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			for(int from=0;from<=j;from++)
			{
				if(c[i]=='F' && ((from-j)&1) || (c[i]=='T') && !((from-j)&1))
				{
					dp[i][j][1]=min(dp[i][j][1],dp[i-1][from][0]);
					dp[i][j][0]=min(dp[i][j][0],dp[i-1][from][1]);
				}
				else
				{
					dp[i][j][1]=min(dp[i][j][1],dp[i-1][from][1]-1);
					dp[i][j][0]=min(dp[i][j][0],dp[i-1][from][0]+1);
				}
			}
		}
	}
	return min(dp[n-1][k][0],dp[n-1][k][1]);
}

int main()
{
	scanf("%s%d",c,&k);
	int res=0;
	res=max(solve1(),-solve2());
	cout<<res<<endl;
	return 0;
}