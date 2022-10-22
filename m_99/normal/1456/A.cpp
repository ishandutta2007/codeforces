#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 2000000005


int main(){
	
	int _T;
	cin>>_T;
	
	rep(_,_T){
		
		int n,p,k;
		scanf("%d %d %d",&n,&p,&k);
		
		
		string S;
		cin>>S;
		reverse(S.begin(),S.end());
		int x,y;
		scanf("%d %d",&x,&y);
		vector<int> dp(n+1,Inf);
		
		rep(i,n+1){

			if(i-k<0){
				dp[i] = 0;
			}
			else{
				if(S[i-k]=='0'){
					dp[i] = min(dp[i],dp[i-k]+x);
				}
				else{
					dp[i] = min(dp[i],dp[i-k]);
				}
			}
		}
		
		
		reverse(S.begin(),S.end());
		int ans = Inf;
		
		for(int i=p;i<=n;i++){
			int t = (i-p)*y + dp[n-i];
			if(S[i-1]=='0')t += x;
			ans = min(ans,t);
		}
		
		//ans = min(ans,(n-p+1)*y);
		
		printf("%d\n",ans);
		
	}
	
    return 0;
}