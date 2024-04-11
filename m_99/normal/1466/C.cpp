#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		int n = s.size();
		vector dp(n+1,vector(2,vector(2,Inf)));
		
		dp[0][0][0] = 0;
		
		rep(i,n){
			rep(j,2){
				rep(k,2){
					if(dp[i][j][k]==Inf)continue;
					bool f0 = false,f1 = false;
					if(i!=0&&s[i-1]==s[i])f0 = true;
					if(i>=2&&s[i-2]==s[i])f1 = true;
					if(j==1)f0 = false;
					if(k==1)f1 = false;
					
					dp[i+1][1][j] = min(dp[i+1][1][j],dp[i][j][k]+1);
					
					if(!f0&&!f1){
						dp[i+1][0][j] = min(dp[i+1][0][j],dp[i][j][k]);
					}
				}
			}
		}
			
		int ans = Inf;
		rep(i,2){
			rep(j,2){
				ans = min(ans,dp.back()[i][j]);
			}
		}
		
		printf("%d\n",ans);
		
	}
	
    return 0;
}