#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000



int main(){
    
	int n,k;
	cin>>n>>k;
	
	vector<vector<int>> dp(k,vector<int>(n+1,0));
	for(int i=1;i<=n;i++){
		dp[0][i]=1;
	}
	
	for(int i=0;i<k-1;i++){
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k+=j){
				dp[i+1][k] = mod(dp[i+1][k] + dp[i][j]);
			}
		}
	}
	
	int ans = 0;
	
	for(int i=0;i<=n;i++){
		ans = mod(ans + dp[k-1][i]);
	}
	
	cout<<ans<<endl;
    
    return 0;
}