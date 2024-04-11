#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000



int main(){
	int n;
	cin>>n;
	string S;
	cin>>S;
	vector<vector<int>> dp(S.size()+1,vector<int>(4,0));
	dp[0][0] = 1;
	
	for(int i=0;i<S.size();i++){
		int x = 1;
		if(S[i]=='?')x*=3;
		for(int k=0;k<x;k++){
			for(int j=0;j<4;j++){
				dp[i+1][j] = mod(dp[i][j]+dp[i+1][j]);
			}
		}
		if(S[i]=='a'||S[i]=='?'){
			dp[i+1][1] = mod(dp[i+1][1]+dp[i][0]);
		}
		if(S[i]=='b'||S[i]=='?'){
			dp[i+1][2] = mod(dp[i+1][2]+dp[i][1]);
		}
		if(S[i]=='c'||S[i]=='?'){
			dp[i+1][3] = mod(dp[i+1][3]+dp[i][2]);
		}
	}
	/*
	for(int i=0;i<=S.size();i++){
		for(int j=0;j<4;j++){
			cout<<dp[i][j]<<',';
		}
		cout<<endl;
	}*/
	
	cout<<dp[S.size()][3]<<endl;
	
    return 0;
}