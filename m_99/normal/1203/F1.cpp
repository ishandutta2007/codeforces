#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf (long long)1000000000000000




int main(){
	
	int n,r;
	cin>>n>>r;
	
	vector<int> a(n),b(n);
	vector<pair<int,int>> P,M;
	rep(i,n){
		cin>>a[i]>>b[i];
		
		if(b[i]>=0){
			P.emplace_back(a[i],b[i]);
		}
		else{
			M.emplace_back(a[i],-b[i]);
		}
	}
	
	sort(P.begin(),P.end());
	int ans = 0;
	rep(i,P.size()){
		if(P[i].first > r)break;
		r += P[i].second;
		ans++;
	}
	
	sort(M.begin(),M.end(),[](pair<int,int> x,pair<int,int> y){
		return x.first-x.second > y.first-y.second;
	});
	
	vector dp(M.size()+1,vector<int>(r+1,-1));
	dp[0][r] = 0;
	
	rep(i,dp.size()-1){
		rep(j,r+1){
			if(dp[i][j]==-1)continue;
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			if(j-M[i].second<0)continue;
			if(j<M[i].first)continue;
			dp[i+1][j-M[i].second] = max(dp[i+1][j-M[i].second],dp[i][j]+1);
		}
	}
	
	int MM = 0;
	rep(i,r+1){
		MM = max(MM,dp.back()[i]);
	}
	
	ans += MM;
	
	if(ans==n)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	return 0;
}