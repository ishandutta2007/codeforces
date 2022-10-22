#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001

int main(){
	
	int n;
	cin>>n;
	
	vector<string> s(2);
	rep(i,2)cin>>s[i];
	
	vector dp(2,vector<int>(2,-Inf32));
	dp[0][0] = 0;
	if(s[1][0]=='1'){
		dp[1][1] = 1;
	}
	
	for(int i=1;i<n;i++){
		vector ndp(2,vector<int>(2,-Inf32));
		rep(j,2){
			rep(k,2){
				if(dp[j][k]==-Inf32)continue;
				ndp[j][0] = max(ndp[j][0],dp[j][k]);
				if(s[j][i]=='1'){
					ndp[j][0] = max(ndp[j][0],dp[j][k]+1);
				}
				if(s[j^1][i]=='1'&&k==0){
					ndp[j^1][1] = max(ndp[j^1][1],dp[j][k]+1);
				}
				if(s[j^1][i]=='1'&&s[j][i]=='1'&&k==0){
					ndp[j^1][1] = max(ndp[j^1][1],dp[j][k]+2);
				}
			}
		}
		swap(dp,ndp);		
	}
	int ans = 0;
	rep(i,2){
		rep(j,2)ans = max(ans,dp[i][j]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}