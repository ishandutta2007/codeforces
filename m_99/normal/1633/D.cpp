#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	vector<int> cost;
	{
		vector<int> dp(1005,Inf);
		dp[1] = 0;
		
		for(int i=1;i<=1000;i++){
			for(int j=1;j<=i;j++){
				int t = i;
				t += i / j;
				if(t>1000)continue;
				dp[t]  =min(dp[t],dp[i] + 1);
			}
		}
		cost = dp;
	}
	
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		k = min(k,13 * n);
		vector<int> b(n),c(n);
		rep(i,n)cin>>b[i];
		rep(i,n)cin>>c[i];
		
		vector<int> dp(k+1,-Inf);
		dp[0] = 0;
		
		rep(i,n){
			vector ndp(k+1,-Inf);
			rep(j,k+1){
				if(dp[j]==-Inf)continue;
				ndp[j] = max(ndp[j],dp[j]);
				int jj = j+cost[b[i]];
				if(jj<=k){
					ndp[jj] = max(ndp[jj],dp[j] + c[i]);
				}
			}
			swap(dp,ndp);
		}
		int ans = 0;
		rep(i,k+1)ans = max(ans,dp[i]);
		cout<<ans<<endl;
	}
	
	return 0;
}