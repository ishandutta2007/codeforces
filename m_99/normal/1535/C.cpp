#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int t;
	cin>>t;
	
	rep(_,t){
		string s;
		cin>>s;
		
		long long ans = 0LL;
		
		vector<long long> dp(2,0);
		
		rep(i,s.size()){
			vector<long long> ndp(2,0);
			ndp[0] = dp[1] + 1;
			ndp[1] = dp[0] + 1;
			if(s[i]=='0')ndp[1] = 0;
			if(s[i]=='1')ndp[0] = 0;
			swap(dp,ndp);
			ans += dp[0] + dp[1];
			//cout<<dp[0] + dp[1]<<',';
		}
		
		vector<int> sum(s.size()+1,0);
		rep(i,s.size()){
			if(s[i]=='?'){
				sum[i+1] = 1;
				sum[i+1] += sum[i];
			}
			ans -= sum[i+1];
		}
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}