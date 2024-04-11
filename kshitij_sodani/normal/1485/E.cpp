//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo t;
//llo par[200001];
vector<llo> adj[200001];
vector<llo> lev[200001];
llo dp[200001];
llo it[200001];
llo par[200001];
llo ma=0;
void dfs(llo no,llo par2=-1,llo levv=0){
	ma=max(ma,levv);
	par[no]=par2;
	lev[levv].pb(no);
	for(auto j:adj[no]){
		//cout<<no<<":"<<j<<endl;
		if(j!=par2){
			dfs(j,no,levv+1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ans=0;
		for(llo i=0;i<n;i++){
			adj[i].clear();
			dp[i]=0;
			lev[i].clear();
			dp[i]=0;
		}
		for(llo i=1;i<n;i++){
			llo aa;
			cin>>aa;
			aa--;
			adj[aa].pb(i);
			par[i]=aa;
		}
		for(llo i=1;i<n;i++){
			cin>>it[i];
		}
		ma=0;
		//continue;
		dfs(0);
		for(llo i=1;i<=ma;i++){
			llo mii=1e9;
			llo maa=0;
			llo ma2=-1e9;
			llo ma3=-1e9;
			for(auto j:lev[i]){
				maa=max(maa,it[j]);
				mii=min(mii,it[j]);
				ma2=max(ma2,dp[par[j]]+it[j]);
				ma3=max(ma3,dp[par[j]]-it[j]);
			}
		
			for(auto j:lev[i]){
				dp[j]=max(dp[j],dp[par[j]]+max(maa-it[j],it[j]-mii));
				dp[j]=max(dp[j],ma2-it[j]);
				dp[j]=max(dp[j],ma3+it[j]);
				ans=max(ans,dp[j]);
			}

		}

		cout<<ans<<endl;
	}









 
	return 0;
}