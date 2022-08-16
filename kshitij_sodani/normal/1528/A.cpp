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
llo aa[100001];
llo bb[100001];
vector<llo> adj[100001];
llo dp[100001][2];
void dfs(llo no,llo par=-1){
	dp[no][0]=0;
	dp[no][1]=0;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			dp[no][0]+=max(dp[j][0]+abs(aa[j]-aa[no]),dp[j][1]+abs(bb[j]-aa[no]));
			dp[no][1]+=max(dp[j][0]+abs(aa[j]-bb[no]),dp[j][1]+abs(bb[j]-bb[no]));
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>aa[i]>>bb[i];
			adj[i].clear();
		}
		for(llo i=0;i<n-1;i++){
			llo cc,dd;
			cin>>cc>>dd;
			cc--;
			dd--;
			adj[cc].pb(dd);
			adj[dd].pb(cc);
		}
		dfs(0);

		cout<<max(dp[0][0],dp[0][1])<<endl;
	}








	return 0;
}