#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){

	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> dp(2*m+1,vector<int>(n,0));
	
	dp[0][0] = 1;
	
	for(int i=1;i<=2*m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<=j;k++){
				dp[i][j] = mod(dp[i][j] + dp[i-1][k]);
			}
		}
	}
	
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = mod(ans + dp.back()[i]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}