#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 92233720368547757
#define mod 998244353
#define mn 100005
#define FLN "test"

int dp[1005][2005][5]; //1 - BB, 2 - WW, 3 - BW, 4 - WB

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<1005; i++) for (int j=0; j<2005; j++) for (int k=0; k<5; k++) dp[i][j][k]=0;
	int n, k;
	cin>>n>>k;
	
	dp[1][1][1]=1;
	dp[1][1][2]=1;
	dp[1][2][3]=1;
	dp[1][2][4]=1;
	for (int i=2; i<=n; i++) for (int j=1; j<=2000; j++) 
	{
		dp[i][j][1]=(dp[i-1][j][1]+dp[i-1][j-1][2]+dp[i-1][j][3]+dp[i-1][j][4])%mod;
		dp[i][j][2]=(dp[i-1][j-1][1]+dp[i-1][j][2]+dp[i-1][j][3]+dp[i-1][j][4])%mod;
		dp[i][j][3]=(dp[i-1][j-1][1]+dp[i-1][j-1][2]+dp[i-1][j][3]+dp[i-1][j-2][4])%mod;
		dp[i][j][4]=(dp[i-1][j-1][1]+dp[i-1][j-1][2]+dp[i-1][j-2][3]+dp[i-1][j][4])%mod;
	}
	cout<<(dp[n][k][1]+dp[n][k][2]+dp[n][k][3]+dp[n][k][4])%mod;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_