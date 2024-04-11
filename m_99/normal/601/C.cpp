#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int n,m;
	cin>>n>>m;
	if(m==1){
		cout<<1<<endl;
		return 0;
	}
	vector<int> X(n);
	int sum = 0;
	rep(i,n){
		cin>>X[i];
		sum += X[i];
	}
	
	vector<double> dp(n*m+1,0.0);
	dp[0] = 1.0;
	
	rep(i,n){
		rep(j,n*m){
			dp[j+1] += dp[j];
		}
		vector<double> ndp(n*m+1,0.0);
		rep(j,n*m+1){
			
			if(j!=0){
				ndp[j] += dp[j-1]/((double)m-1);
			}
			if(j-m-1>=0)ndp[j] -= dp[j-m-1]/((double)m-1);
			if(j-X[i]>=0)ndp[j] -= dp[j-X[i]]/((double)m-1);
			if(j-X[i]-1>=0)ndp[j] += dp[j-X[i]-1]/((double)m-1);
			
		}
		swap(dp,ndp);
	}
	double ans = 1.0;
	rep(i,sum){
		ans += dp[i] * (m-1);
	}
	
	cout<<fixed<<setprecision(15)<<ans<<endl;
	
    return 0;
}