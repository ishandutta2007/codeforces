#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	string s;
	cin>>s;
	int n = s.size();
	vector<int> v(n);
	rep(i,n){
		v[i] = s[i]-'a';
	}
	
	vector<int> dp(1<<20,0);
	dp[0] = 0;
	rep(i,n){
		int cur = 0;
		rep(j,20){
			if(i+j>=n)break;
			if(cur&(1<<v[i+j]))break;
			cur ^= 1<<v[i+j];
			dp[cur] = __builtin_popcount(cur);
		}
	}
	auto ddp = dp;
	rep(i,1<<20){
		rep(j,20){
			if((i>>j)&1)continue;
			ddp[i|(1<<j)] = max(ddp[i|(1<<j)], ddp[i]);
		}
	}
	
	int t = 1<<20;
	t--;
	
	int ans = 0;
	rep(i,dp.size()){
		ans = max(ans,dp[i] + ddp[i^t]);
	}
	
	cout<<ans<<endl;
			
	
	return 0;
}