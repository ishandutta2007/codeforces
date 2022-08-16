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
#define ord tree<llo,null_type,less<llo>,rb_tree_tag,tree_order_statistics_node_update>*/

llo n,m,s,k;
llo it[100001];
vector<llo> adj[100001];
vector<llo> tt[100001];
llo dist[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k>>s;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		it[i]--;
	}
	for(llo i=0;i<m;i++){
		llo aa;llo bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);


	}
	for(llo i=0;i<k;i++){
		queue<llo> ss;
		for(llo j=0;j<n;j++){
			dist[j]=-1;
			if(it[j]==i){
				dist[j]=0;
				ss.push(j);
			}
		}
		while(ss.size()){
			llo no=ss.front();
			ss.pop();
			tt[no].pb(dist[no]);
			for(auto j:adj[no]){
				if(dist[j]==-1){
					dist[j]=dist[no]+1;
					ss.push(j);
				}
			}
		}
	}
	llo ans=-1;
	for(llo i=0;i<n;i++){
		sort(tt[i].begin(),tt[i].end());
		llo co=0;
		for(llo j=0;j<s;j++){
			co+=tt[i][j];
		}
		cout<<co<<" ";
	}
	cout<<endl;




 
 
	return 0;
}