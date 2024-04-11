#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long int llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
#define endl "\n"
int n;
vector<int> adj[200001];
int dp[200001];
int it[200001];
//int ma;
int ans[200001];
void dfs(int no,int par=-1){
	dp[no]=1;
	if(it[no]==0){
		dp[no]=-1;
	}
	for(auto nn:adj[no]){
		if(nn==par){
			continue;
		}
		dfs(nn,no);
		dp[no]+=max(dp[nn],0);
	}
}
int reroot(int no,int par=-1){
	ans[no]=dp[no];
	for(auto nn:adj[no]){
		if(nn==par){
			continue;
		}
		int aa=dp[no];
		int bb=dp[nn];
		dp[no]-=max(dp[nn],0);
		dp[nn]+=max(dp[no],0);
		//ma=max(ma,dp[nn]);
		reroot(nn,no);
		dp[no]=aa;
		dp[nn]=bb;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	int aa,bb;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	for(int i=0;i<n-1;i++){
		cin>>aa>>bb;
		adj[aa-1].pb(bb-1);
		adj[bb-1].pb(aa-1);
	}
	dfs(0);
	reroot(0);

	//cout<<ma<<endl;
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}