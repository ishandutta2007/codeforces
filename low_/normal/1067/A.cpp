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
#include<sstream>
#include<bitset>
#include<ctime>
using namespace std;
#define int long long
#define inf 444444444444444444
#define mn 100005
#define FLN "test"
#define mod 998244353

int dp[mn][205][2];
int n, a[mn];
int mcd[205][2];

//0 - A[i-1]<A[i], 1 - A[i-1]>=A[i]

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i];
	
	if (a[1]==-1) 
	{
		mcd[0][0]=mcd[0][1]=0;
		for (int i=1; i<=200; i++) 
		{
			dp[1][i][0]=1;
			mcd[i][0]=mcd[i-1][0]+1;
			mcd[i][1]=0;
		}
	}
	else 
	{
		dp[1][a[1]][0]=1;
		mcd[0][0]=mcd[0][1]=0;
		for (int i=1; i<=200; i++) mcd[i][0]=(i>=a[1]);
	}
	
	for (int i=2; i<=n; i++)
	{
		for (int j=1; j<=200; j++) if (a[i]==-1 || a[i]==j)
		{
			dp[i][j][0]=(mcd[j-1][0]+mcd[j-1][1])%mod;
			dp[i][j][1]=(dp[i-1][j][0]+mcd[200][1]-mcd[j-1][1]+mod)%mod;
		}
		
		mcd[0][0]=mcd[0][1]=0;
		for (int j=1; j<=200; j++)
		{
			mcd[j][0]=mcd[j-1][0]+dp[i][j][0];
			mcd[j][1]=mcd[j-1][1]+dp[i][j][1];
		}
	}
	
//	for (int i=1; i<=n; i++)
//	{
//		for (int j=1; j<=10; j++) cout<<dp[i][j][0]<<'-'<<dp[i][j][1]<<' ';
//		cout<<'\n';
//	}
	
	int ans=0;
	for (int i=1; i<=200; i++) ans=(ans+dp[n][i][1])%mod;
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_