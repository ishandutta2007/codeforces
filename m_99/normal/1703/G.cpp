#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		long long k;
		cin>>k;
		vector<long long> a(n);
		rep(i,n){
			scanf("%lld",&a[i]);
		}
		vector<long long> dp(31,0);
		rep(i,n){
			vector<long long> ndp(31,-Inf);
			rep(j,31){
				ndp[j] = max(ndp[j],dp[j] + (a[i]>>j) - k);
				ndp[min(j+1,30)] = max(ndp[min(j+1,30)],dp[j] + (a[i]>>(j+1)));
			}
			swap(dp,ndp);
		}
		long long ans = 0;
		rep(i,31)ans = max(ans,dp[i]);
		cout<<ans<<endl;
				
	}
	
    return 0;
}