#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		
		vector<vector<int>> dp(n+1,vector<int>(2,Inf));
		dp[0][0] = 0;
		
		rep(i,n){
			dp[i+1][1] = min(dp[i+1][1],dp[i][0]+a[i]);
			if(i+2<=n)dp[i+2][1] = min(dp[i+2][1],dp[i][0]+a[i]+a[i+1]);
			dp[i+1][0] = min(dp[i+1][0],dp[i][1]);
			if(i+2<=n)dp[i+2][0] = min(dp[i+2][0],dp[i][1]);
		}
		
		cout<<min(dp.back()[0],dp.back()[1])<<endl;
		
	}
	
    return 0;
}