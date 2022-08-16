#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int n,k;
vector<int> adj[1000001];
pair<int,int> dp[1000001];
int dp2[1000001];
void dfs(int no,int lev=0){
	if(adj[no].size()==0){
		dp[no]={1,max(lev-k,0)};
		dp2[no]=1;
		return;
	}
	dp[no]={0,lev};
	int x=0;
	for(auto j:adj[no]){
		dfs(j,lev+1);
		if(dp[j].b<=lev){
			dp[no].a+=dp[j].a;
			x=max(x,dp2[j]-dp[j].a);
			dp[no].b=min(dp[no].b,dp[j].b);
		}
		else{
			x=max(x,dp2[j]);
		}
	}
	dp2[no]=dp[no].a+x;
//	cout<<no<<','<<dp[no].a<<","<<dp[no].b<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int aa;
		cin>>aa;
		adj[aa-1].pb(i+1);
	}
	dfs(0);
	cout<<dp2[0]<<endl;


	return 0;
}