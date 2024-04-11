#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		vector<int> dp(200001,0);
		rep(i,n){
			int a;
			scanf("%d",&a);
			dp[a]++;
		}
		vector<int> cnt = dp;
		
		for(int i=1;i<=200000;i++){
			for(int j=i*2;j<=200000;j+=i){
				dp[j] = max(dp[j],dp[i] + cnt[j]);
			}
		}
		
		int ans = 0;
		rep(i,dp.size()){
			ans = max(ans,dp[i]);
		}
		
		printf("%d\n",n-ans);
		
	}
	
    return 0;
}