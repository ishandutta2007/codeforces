//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
/*mt19937 rng;
rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());


#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ord tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>*/
int n;
vector<int> adj[100001];
int it[100001];
int par[100001];
void dfs(int no,int par2=-1){
	par[no]=par2;
	for(auto j:adj[no]){
		if(j!=par2){
			dfs(j,no);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n-1;i++){
				int aa;
				cin>>aa;
				aa--;
			adj[i+1].pb(aa);
			adj[aa].pb(i+1);
	}
	dfs(0);
	for(int i=0;i<n;i++){
		cin>>it[i];
	}


		int ans=1;
		for(int i=1;i<n;i++){
			if(it[par[i]]!=it[i]){
				ans+=1;
			}
		}
		cout<<ans<<endl;


 
 
	return 0;
}