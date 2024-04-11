#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000
int n,m,k;

vector<int> get(vector<int> a){
	vector<vector<int>> dp(m/2+1,vector<int>(k,-Inf));
	dp[0][0] = 0;
	
	rep(i,m){
		vector<vector<int>> ndp(m/2+1,vector<int>(k,-Inf));
		rep(j,m/2+1){
			rep(l,k){
				if(dp[j][l]==-Inf)continue;
				ndp[j][l] = max(ndp[j][l],dp[j][l]);
				if(j!=m/2){
					ndp[j+1][(l+a[i])%k] = max(ndp[j+1][(l+a[i])%k],dp[j][l]+a[i]);
				}
			}
		}
		swap(dp,ndp);
	}
	vector<int> ret(k,-Inf);
	rep(i,dp.size()){
		rep(j,k){
			ret[j] = max(ret[j],dp[i][j]);
		}
	}
	return ret;
}

int main(){	
	
	
	cin>>n>>m>>k;
	
	vector<vector<int>> a(n,vector<int>(m));
	rep(i,n){
		rep(j,m)cin>>a[i][j];
	}
	
	vector<vector<int>> X(n);
	rep(i,n){
		X[i] = get(a[i]);
	}
	
	vector<int> dp(k,-Inf);
	dp[0] = 0;
	rep(i,n){
		vector<int> ndp = dp;
		rep(j,k){
			if(dp[j]==-Inf)continue;
			rep(l,k){
				if(X[i][l]==-Inf)continue;
				ndp[(j+l)%k] = max(ndp[(j+l)%k],dp[j]+X[i][l]);
			}
		}
		swap(dp,ndp);
	}
	
	cout<<dp[0]<<endl;
		
    return 0;
}