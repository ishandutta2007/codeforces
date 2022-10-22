#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){
	long long n,r1,r2,r3,d;
	cin>>n>>r1>>r2>>r3>>d;
	
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	
	vector<long long> planA(n),planB(n);
	
	for(int i=0;i<n;i++){
		planA[i] = min(r1*(a[i]+2),r2+r1);
		planB[i] = r1*a[i] + r3;
	}
	
	vector<long long> last(n);
	for(int i=n-1;i>=0;i--){
		if(i==n-1){
			last[i] = min(planB[i],planA[i]+d*2);
		}
		else{
			last[i] = last[i+1] + min(planA[i],planB[i]) + d*2;
		}
	}
	
	vector<vector<long long>> dp(n+1,vector<long long>(2,Inf));
	dp[0][0] = 0;
	
	for(int i=0;i<n;i++){
		dp[i+1][0] = min(dp[i+1][0],dp[i][0] + planB[i] + d);
		dp[i+1][1] = min(dp[i+1][1],dp[i][0] + planA[i] + d*3);
		dp[i+1][0] = min(dp[i+1][0],dp[i][1] + planB[i] + d);
		dp[i+1][0] = min(dp[i+1][0],dp[i][1] + planA[i] + d);
		dp[i+1][1] = min(dp[i+1][1],dp[i][1] + planA[i] + d*3);
	}
	
	long long ans = min(dp.back()[0]-d,dp.back()[1]-d);

	for(int i=0;i<n;i++){
		ans = min(ans,dp[i][0] + last[i]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}