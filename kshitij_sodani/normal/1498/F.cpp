//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
 
 
 
llo n,k;
vector<llo> adj[100001];
llo dp[100001][41];
llo ans[100001];
llo it[100001];
void dfs(llo no,llo par=-1,llo lev=0){

	dp[no][0]^=it[no];

	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no,lev+1);
			for(llo i=0;i<2*k;i++){
				dp[no][(i+1)%(2*k)]^=dp[j][i];
			}
		}
	}
}

void dfs2(llo no,llo par2=-1){
	for(llo i=k;i<2*k;i++){
		ans[no]^=dp[no][i];
	}
	/*cout<<no<<":"<<endl;
	for(llo i=0;i<2*k;i++){
		cout<<dp[no][i]<<",";
	}
	cout<<endl;*/
	for(auto j:adj[no]){
		if(j!=par2){
			vector<llo> ss;
			for(llo i=0;i<2*k;i++){
				ss.pb(dp[j][i]);
			}
			/*for(auto i:ss){
				cout<<i<<".";
			}
			cout<<endl;*/
			for(llo i=0;i<2*k;i++){
				dp[j][i]=(dp[j][i]^dp[no][(i-1+2*k)%(2*k)])^(ss[(i-2+2*k)%(2*k)]);
			}
			dfs2(j,no);

			for(llo i=0;i<2*k;i++){
				dp[j][i]=(dp[j][i]^dp[no][(i-1+2*k)%(2*k)])^(ss[(i-2+2*k)%(2*k)]);
			}

		}

	}


}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;

	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	dfs(0);
	dfs2(0);

	for(llo i=0;i<n;i++){
		llo cur=ans[i];
		if(cur==0){
			cout<<0<<" ";
		}
		else{
			cout<<1<<" ";
		}
	}
	cout<<endl;
 

 
 
 
 
 
 
 
	return 0;
}