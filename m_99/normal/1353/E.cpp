#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		
		string s;
		cin>>s;
		vector<int> S(n+1,0);
		rep(i,n){
			int b = s[i]-'0';
			S[i+1] += b;
			S[i+1] += S[i];
		}
		
		int ans = S.back();
		vector<int> dp(n,Inf);
		dp[0] = 0;
		rep(i,n){
			int c = 0;
			if(s[i]=='0')c++;
			dp[i] = c + S[i];
			if(i-k>=0){
				dp[i] = min(dp[i],dp[i-k] + c + S[i] - S[i+1-k]);
			}
		}
		rep(i,n){
			//cout<<dp[i]<<',';
			ans = min(ans,dp[i] + S.back() - S[i+1]);
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}