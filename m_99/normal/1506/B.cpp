#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		string s;
		cin>>n>>k>>s;
		
		while(s[0]=='.')s.erase(s.begin());
		while(s.back()=='.')s.pop_back();
		s.erase(s.begin());
		n = s.size();
		vector dp(k,Inf);
		dp[0] = 1;
		rep(i,n){
			vector ndp(k,Inf);
			rep(j,k){
				if(dp[j]==Inf)continue;
				if(s[i]=='.'){
					if(j!=k-1){
						ndp[j+1] = min(ndp[j+1],dp[j]);
					}
				}
				else{
					ndp[0] = min(ndp[0],dp[j]+1);
					if(j!=k-1){
						ndp[j+1] = min(ndp[j+1],dp[j]);
					}
				}
				
			}
			swap(dp,ndp);
		}
		printf("%d\n",dp[0]);
	}

    return 0;
}