#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

//ab
int beki(int a,int b){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=mod(x*a);
		}
		a=mod(a*a);
		b>>=1;
	}
	return x;
}

//a
int gyakugen(int a){
	return beki(a,modulo-2);
}

int main(){
	
	int n,m,k;
	cin>>n>>m>>k;
	
	vector<vector<int>> dp(k+1,vector<int>(k+1,0));
	dp[0][0] = 1;
	
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			dp[i][j] = mod(dp[i][j] + mod(dp[i-1][j] * j));
			dp[i][j] = mod(dp[i][j] + mod(dp[i-1][j-1] * max(0,n-j+1)));
		}
	}
	
	int ans = 0;
	
	for(int i=1;i<=k;i++){
		ans = mod(ans + mod(dp[k][i] * gyakugen(beki(m,i))));
	}
	
	cout<<ans<<endl;
	
	
	return 0;
}