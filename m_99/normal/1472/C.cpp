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
		
		vector<long long> a(n);
		rep(i,n){
			scanf("%lld",&a[i]);
		}
		
		vector<long long> dp(n);
		for(int i=n-1;i>=0;i--){
			dp[i] = a[i];
			if(i+a[i]<n){
				dp[i] += dp[i+a[i]];
			}
		}
		
		long long ans = 0LL;
		rep(i,n)ans = max(ans,dp[i]);
		
		printf("%lld\n");
		
		
	}
	
    return 0;
}