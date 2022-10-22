#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		
		vector<int> dp(27,Inf);
		dp[26] = 0;
		rep(i,s.size()){
			vector<int> ndp(27,Inf);
			rep(j,26){
				ndp[j] = min(ndp[j],dp[j]+1);
				if(j==s[i]-'a'){
					ndp[26] = min(ndp[26],dp[j]);
				}
			}
			ndp[s[i]-'a'] = min(ndp[s[i]-'a'], dp[26]);
			ndp[26] = min(ndp[26],dp[26]+1);
			swap(dp,ndp);
			
		}
		cout<<dp[26]<<endl;
		
	}
	
	return 0;
}