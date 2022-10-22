#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int n,c;
	cin>>n>>c;
	
	vector<int> a(n),b(n);
	rep(i,n-1)scanf("%d",&a[i]);
	rep(i,n-1)scanf("%d",&b[i]);
	
	vector dp(n,vector<int>(2,Inf));
	dp[0][0] = 0;
	
	rep(i,n-1){
		dp[i+1][0] = min(dp[i+1][0],dp[i][0] + a[i]);
		dp[i+1][1] = min(dp[i+1][1],dp[i][0] + c + b[i]);
		dp[i+1][1] = min(dp[i+1][1],dp[i][1] + b[i]);
		dp[i+1][0] = min(dp[i+1][0],dp[i][1] + a[i]);
	}
	
	rep(i,n){
		int ans = min(dp[i][0],dp[i][1]);
		if(i!=0)printf(" ");
		printf("%d",ans);
	}
	cout<<endl;
	
	return 0;
}