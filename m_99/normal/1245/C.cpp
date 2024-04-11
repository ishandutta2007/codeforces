#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000




int main(){
	
	string S;
	cin>>S;
	
	vector<int> dp(S.size()+1,0);
	dp[0]=1;
	
	for(int i=0;i<S.size();i++){
		if(S[i]=='m'||S[i]=='w'){
			cout<<0<<endl;
			return 0;
		}
		dp[i+1] = mod(dp[i+1]+dp[i]);
		if(i==0)continue;
		if(S[i]=='u'||S[i]=='n'){
			if(S[i]==S[i-1]){
				dp[i+1] = mod(dp[i+1]+dp[i-1]);
			}
		}
	}
	
	cout<<dp[S.size()]<<endl;
		
	
    return 0;
}