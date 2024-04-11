#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	int n,k,s;
	cin>>n>>k>>s;
	vector<int> q(n);
	rep(i,n){
		scanf("%d",&q[i]);
	}

	int sum = 0;
	rep(i,k){
		sum += (n-1-i) - (k-1-i);
	}
	s = min(s,sum);
	
	vector<vector<int>> dp(k+1,vector<int>(s+1,Inf));
	dp[0][0] = 0;
	rep(i,n){
		vector<vector<int>> ndp(k+1,vector<int>(s+1,Inf));
		
		rep(j,k+1){
			rep(l,s+1){
				if(dp[j][l]==-Inf)continue;
				ndp[j][l] = min(ndp[j][l],dp[j][l]);
				if(j==k)continue;
				int nl = l + abs(j-i);
				if(nl>s)continue;
				ndp[j+1][nl] = min(ndp[j+1][nl],dp[j][l] + q[i]);
			}
		}
		swap(dp,ndp);
	}
	
	int ans = Inf;
	rep(i,s+1){
		ans = min(ans,dp.back()[i]);
	}
	
	cout<<ans<<endl;
	
    return 0;
}