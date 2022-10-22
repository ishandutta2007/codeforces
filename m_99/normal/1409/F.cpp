#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000300



int main(){
	
	int n,k;
	cin>>n>>k;
	
	string s,t;
	cin>>s>>t;
	
	if(t[0]==t[1]){
		int c = 0;
		rep(i,n){
			if(s[i]==t[0])c++;
		}
		c += k;
		if(c>n)c = n;
		cout<<c*(c-1)/2<<endl;
		return 0;
	}
	
	vector dp(n+1,vector(n+1,vector<int>(k+1,-Inf)));
	dp[0][0][0] = 0;
	rep(i,n){
		rep(j,n+1){
			rep(l,k+1){
				if(dp[i][j][l]==-Inf)continue;
				if(s[i]==t[0]){
					dp[i+1][j+1][l] = max(dp[i+1][j+1][l],dp[i][j][l]);
				}
				else{
					if(l!=k){
						dp[i+1][j+1][l+1] = max(dp[i+1][j+1][l+1],dp[i][j][l]);
					}
				}
				
				if(s[i]==t[1]){
					dp[i+1][j][l] = max(dp[i+1][j][l],dp[i][j][l] + j);
				}
				else{
					if(l!=k){
						dp[i+1][j][l+1] = max(dp[i+1][j][l+1],dp[i][j][l]+j);
					}
				}
				
				dp[i+1][j][l] = max(dp[i+1][j][l],dp[i][j][l]);
				
			}
		}
	}
	
	int ans = 0;
	rep(i,n+1){
		rep(j,k+1){
			ans = max(ans,dp.back()[i][j]);
		}
	}
	
	cout<<ans<<endl;
	
    return 0;
}