#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
 
 
int main(){
	
	int n;
	long long k;
	cin>>n>>k;
	
	string s;
	cin>>s;
	
	vector dp(n+1,vector<long long>(n+1,0));
	{
		vector<bool> used(26,false);
		rep(i,n){
			int c = s[i]-'a';
			if(used[c])continue;
			used[c] = true;
			dp[i][1] = 1;
		}
	}
	//rep(i,n)dp[i][1] = 1;
	dp[n][0] = 1;
	
	rep(i,n){
		rep(j,n+1){
			if(dp[i][j]==0)continue;
			vector<bool> used(26,false);
			for(int l=i+1;l<n;l++){
				int c = s[l] - 'a';
				if(used[c])continue;
				used[c] = true;
				dp[l][j+1] = min(k,dp[l][j+1]+dp[i][j]);
			}
			dp[n][j] = min(k,dp[n][j]+dp[i][j]);
		}
	}
	/*
	for(int i=0;i<=n;i++){
		cout<<dp.back()[i]<<endl;
	}*/
	long long ans = 0LL;
	for(int i=n;i>=0;i--){
		long long c = n-i;
		if(k < dp.back()[i]){
			ans += k * c;
			k = 0;
			break;
		}
		else{
			ans += dp.back()[i]*c;
			k -= dp.back()[i];
		}
	}
	if(k!=0)ans = -1;
	cout<<ans<<endl;
		
	
	return 0;
}