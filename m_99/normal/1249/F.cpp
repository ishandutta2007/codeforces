#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int n,k;
vector<int> a;
vector<vector<int>> E;
vector<vector<int>> dp;

void dfs(int cur,int p){
	vector<int> x;
	rep(i,E[cur].size()){
		int to = E[cur][i];
		if(to==p)continue;
		dfs(to,cur);
		x.push_back(to);
	}
	
	dp[cur].resize(205,0);
	
	for(int i=1;i<=204;i++){
		if(i*2>k){
			rep(j,x.size()){
				dp[cur][i] += dp[x[j]][i];
			}
		}
		else{
			int maxi = 0;
			rep(j,x.size()){
				int sum = 0;
				rep(kk,x.size()){
					if(j==kk){
						sum += dp[x[kk]][i];
					}
					else{
						sum += dp[x[kk]][k+1-i];
					}
				}
				maxi = max(maxi,sum);
			}
			dp[cur][i] += maxi;
		}
	}
	dp[cur][0] = a[cur];
	rep(i,x.size()){
		if(dp[x[i]].size()>k+1){
			dp[cur][0] += dp[x[i]][k+1];
		}
	}
			
	
	dp[cur].insert(dp[cur].begin(),0);
	for(int i=dp[cur].size()-1;i>=0;i--){
		if(i==dp[cur].size()-1)continue;
		dp[cur][i] = max(dp[cur][i],dp[cur][i+1]);
	}
}

int main(){
	
	cin>>n>>k;
	
	a.resize(n);
	E.resize(n);
	
	rep(i,n){
		cin>>a[i];
	}
	
	rep(i,n-1){
		int u,v;
		cin>>u>>v;
		u--;v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	dp.resize(n);
	
	dfs(0,-1);
	
	int ans = 0;
	rep(i,dp.size()){
		rep(j,dp[i].size()){
			ans = max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}