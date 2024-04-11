#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000





int main(){
	
	int n,l,r;
	cin>>n>>l>>r;
	
	vector<int> num(3,r/3);
	if(r%3==2){
		num[2]++;
		num[1]++;
	}
	if(r%3==1)num[1]++;
	
	l--;
	num[0]-=l/3;
	num[1]-=l/3;
	num[2]-=l/3;
	if(l%3==2){
		num[2]--;
		num[1]--;
	}
	if(l%3==1){
		num[1]--;
	}
	
	vector<vector<int>> dp(n+1,vector<int>(3,0));
	dp[0][0]=1;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				int a = (j+k)%3;
				dp[i+1][a] = mod(dp[i+1][a] + mod(dp[i][j] * num[k]));
			}
		}
	}
	
	cout<<dp[n][0]<<endl;
	
    return 0;
}