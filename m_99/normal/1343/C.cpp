#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
 
 
int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		
		vector<long long> a(n);
		rep(i,n)cin>>a[i];
		
		vector<pair<int,long long>> dp(2,make_pair(0,0LL));
		
		rep(i,n){
			vector<pair<int,long long>> ndp(2,make_pair(0,0LL));
			
			rep(j,2){
				ndp[j] = max(ndp[j],dp[j]);
			}
			if(a[i]>0){
				ndp[0] = max(ndp[0],make_pair(dp[1].first+1,dp[1].second+a[i]));
			}
			else{
				ndp[1] = max(ndp[1],make_pair(dp[0].first+1,dp[0].second+a[i]));
			}
			swap(dp,ndp);
		}
		auto ans = max(dp[0],dp[1]);
		cout<<ans.second<<endl;
		
	}
	
	return 0;
}