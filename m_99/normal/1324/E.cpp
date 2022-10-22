#include <bits/stdc++.h>
using namespace std;
#define modulo h
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n,h,l,r;
	cin>>n>>h>>l>>r;
	
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	
	vector<vector<int>> dp(n+1,vector<int>(h,-Inf));
	dp[0][0] = 0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<h;j++){
			if(dp[i][j]==-Inf)continue;
			for(int k=0;k<2;k++){
				int ind = mod(j+a[i]-1+k);
				dp[i+1][ind] = max(dp[i+1][ind],dp[i][j] + ((ind<=r&&ind>=l)?1:0));
			}
		}
	}
	
	int ans = 0;
	for(int i=0;i<h;i++){
		ans = max(dp.back()[i],ans);
	}
	cout<<ans<<endl;
	
	return 0;
}