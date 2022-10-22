#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int n,l,k;
	cin>>n>>l>>k;
	
	vector<int> d(n),a(n);
	rep(i,n)cin>>d[i];
	rep(i,n)cin>>a[i];
	d.push_back(l);
	vector dp(n+1,vector<int>(k+1,Inf));
	dp[0][0] = 0;
	
	rep(i,n){
		rep(j,k+1){
			for(int ii=i+1;ii<=n;ii++){
				int jj = j + (ii-(i+1));
				if(jj>k)break;
				dp[ii][jj] = min(dp[ii][jj],dp[i][j] + a[i] * (d[ii] - d[i]));
				
			}
		}
	}
	int ans = Inf;
	rep(i,k+1)ans = min(ans,dp.back()[i]);
	cout<<ans<<endl;
	
	return 0;
}