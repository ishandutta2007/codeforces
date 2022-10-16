//by MagicSpark
#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
int dp[5005][5005][2];
int n;
int a[5005];
int main(){
	memset(dp,inf,sizeof(dp));
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<=n;i++)dp[i][0][1]=0;
	dp[1][1][1]=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=(i+1)/2;j++){
			dp[i][j][0]=min(dp[i-1][j][1]+max(a[i]-a[i-1]+1,0),dp[i-1][j][0]);
			dp[i][j][1]=min(dp[i-2][j-1][1]+max(0,max(j==1?0:a[i-1]-a[i-2]+1,a[i-1]-a[i]+1)),dp[i-2][j-1][0]+max(a[i-1]-a[i]+1,0));
			//printf("i:%d j:%d dp[%d][%d][0]:%d dp[%d][%d][1]:%d\n",i,j,i,j,dp[i][j][0],i,j,dp[i][j][1]);
		}
	}
	for(int i=1;i<=(n+1)/2;i++)cout<<min(dp[n][i][0],dp[n][i][1])<<" ";cout<<endl;
	#ifndef ONLINE_JUDGE
        printf("Time: %d ms\n", (int)(clock() * 1000/ CLOCKS_PER_SEC));
    #endif
	return 0;
}