#include<iostream>
#include<algorithm>
using namespace std;
int A[3][1<<17],N;
long long dp[2][5];
void chmax(long long&a,long long b){if(a<b)a=b;}
main()
{
	cin>>N;
	for(int i=0;i<3;i++)for(int j=0;j<N;j++)cin>>A[i][j];
	int now=0;
	for(int j=1;j<5;j++)dp[now][j]=-1e18;
	for(int i=0;i<N;i++)
	{
		int nxt=1-now;
		for(int j=0;j<5;j++)dp[nxt][j]=-1e18;
		chmax(dp[nxt][0],dp[now][0]+A[0][i]);
		chmax(dp[nxt][1],dp[now][0]+A[0][i]+A[1][i]);
		chmax(dp[nxt][2],dp[now][0]+A[0][i]+A[1][i]+A[2][i]);
		chmax(dp[nxt][4],dp[now][0]+A[0][i]+A[1][i]+A[2][i]);
		chmax(dp[nxt][0],dp[now][1]+A[1][i]+A[0][i]);
		chmax(dp[nxt][1],dp[now][1]+A[1][i]);
		chmax(dp[nxt][2],dp[now][1]+A[1][i]+A[2][i]);
		chmax(dp[nxt][0],dp[now][2]+A[0][i]+A[1][i]+A[2][i]);
		chmax(dp[nxt][1],dp[now][2]+A[1][i]+A[2][i]);
		chmax(dp[nxt][2],dp[now][2]+A[2][i]);
		chmax(dp[nxt][3],dp[now][2]+A[0][i]+A[1][i]+A[2][i]);
		chmax(dp[nxt][0],dp[now][3]+A[0][i]);
		chmax(dp[nxt][1],dp[now][3]+A[0][i]+A[1][i]);
		chmax(dp[nxt][2],dp[now][3]+A[0][i]+A[1][i]+A[2][i]);
		chmax(dp[nxt][3],dp[now][3]+A[0][i]+A[1][i]+A[2][i]);
		chmax(dp[nxt][0],dp[now][4]+A[0][i]+A[1][i]+A[2][i]);
		chmax(dp[nxt][1],dp[now][4]+A[1][i]+A[2][i]);
		chmax(dp[nxt][2],dp[now][4]+A[2][i]);
		chmax(dp[nxt][4],dp[now][4]+A[0][i]+A[1][i]+A[2][i]);
		now=nxt;
	}
	cout<<max(dp[now][2],dp[now][4])<<endl;
}