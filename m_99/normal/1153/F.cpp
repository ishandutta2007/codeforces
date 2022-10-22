#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000

//ab
int beki(int a,int b,int M = modulo){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=((long long)x*a)%M;
		}
		a=((long long)a*a)%M;
		b>>=1;
	}
	return x;
}


//a
int gyakugen(int a){
	return beki(a,modulo-2);
}




int main() {
	
	int n,K,L;
	cin>>n>>K>>L;
	
	int dp[2*n+2][2*n+2][2];
	for(int i=0;i<2*n+2;i++){
		for(int j=0;j<2*n+2;j++){
			for(int k=0;k<2;k++){
				dp[i][j][k]=0;
			}
		}
	}
	
	//vector<vector<vector<int>>> dp(2*n+2,vector<vector<int>> (2*n+2,vector<int>(2,0)));
	
	dp[0][0][0] = 1;
	
	for(int i=0;i<2*n+1;i++){
		for(int j=0;j<=2*n+1;j++){
			for(int k=0;k<2;k++){
				if(dp[i][j][k]==0)continue;
				dp[i+1][j+1][k] = mod(dp[i+1][j+1][k]+dp[i][j][k]);
				if(j!=0){
					dp[i+1][j-1][k] = mod(dp[i+1][j-1][k]+mod(j*dp[i][j][k]));
				}
				if(k==0&&j>=K){
					dp[i+1][j][1] = mod(dp[i+1][j][1] + dp[i][j][k]);
				}
			}
		}
	}
	
	int ans = dp[2*n+1][0][1];
	//cout<<ans<<endl;
	ans = mod(ans * beki(2,n));
	for(int i=1;i<=n;i++)ans = mod(ans * i);
	
	for(int i=1;i<=2*n+1;i++){
		ans = mod(ans * gyakugen(i));
	}
	
	cout<<mod(L*ans)<<endl;
	
    return 0;
}