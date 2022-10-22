#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	vector<vector<int>> dp(n,vector<int>(n,-1));
	
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			if(j==0){
				dp[i][j] = a[i];
				continue;
			}
			for(int k=0;k<j;k++){
				int x = k;
				int y = j-1-k;
				int v1 = dp[i][x];
				if(i+k+1>=n)break;
				int v2 = dp[i+k+1][y];
				if(v1==v2&&v1!=-1){
					dp[i][j] = v1+1;
					break;
				}
			}
		}
	}
	
	vector<int> dp2(n+1,Inf);
	dp2[0] = 0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dp[i][j]==-1)continue;
			dp2[i+j+1] = min(dp2[i+j+1],dp2[i]+1);
		}
	}
	
	cout<<dp2.back()<<endl;
	
    return 0;
}