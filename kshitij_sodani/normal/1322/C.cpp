
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 
vector<llo> adj[500001];
llo it[500001];
llo gcd(llo aa,llo bb){
	if(aa==0){
		return bb;
	}
	return gcd(bb%aa,aa);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		for(llo i=0;i<n;i++){
			adj[i].clear();
		}
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		for(llo i=0;i<m;i++){
			llo aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[bb].pb(aa);
		}
		map<vector<llo>,llo> ss;
		for(llo i=0;i<n;i++){
			if(adj[i].size()){
				sort(adj[i].begin(),adj[i].end());
				ss[adj[i]]+=it[i];
			}
		}
		llo ans=-1;
		for(auto j:ss){
			if(ans==-1){
				ans=j.b;
			}
			ans=gcd(ans,j.b);
		}
		cout<<ans<<endl;






	}











	return 0;
}