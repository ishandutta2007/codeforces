#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	vector<vector<vector<int>>> dp(n,vector<vector<int>> (n+1,vector<int>(2,Inf)));
	
	if(a[0]==0){
		dp[0][0][0] = 0;
		dp[0][1][1] = 0;
	}
	else{
		if(a[0]%2==0){
			dp[0][0][0] = 0;
		}
		else{
			dp[0][1][1] = 0;
		}
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<2;k++){
				if(dp[i][j][k] == Inf)continue;
				if(a[i+1]==0){
					int X = 0;
					if(k==1)X=1;
					dp[i+1][j][0] = min(dp[i][j][k]+X,dp[i+1][j][0]);
					if(k==0)X=1;
					else X=0;
					if(j!=n)dp[i+1][j+1][1] = min(dp[i][j][k]+X,dp[i+1][j+1][1]);
				}
				else{
					if(a[i+1]%2==0){
						int X = 0;
						if(k==1)X = 1;
						dp[i+1][j][0] = min(dp[i+1][j][0],dp[i][j][k]+X);
					}
					else{
						int X = 0;
						if(k==0)X = 1;
						if(j!=n)dp[i+1][j+1][1] = min(dp[i+1][j+1][1],dp[i][j][k]+X);
					}
				}
			}
		}
	}
	
	cout<<min(dp.back()[(n+1)/2][0],dp.back()[(n+1)/2][1])<<endl;
	
    return 0;
}