#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;
int aa[400001];
int bb[400001];
int vis[400001];
vector<int> adj[400001];
const int mod=1e9+7;
void dfs(int no){
	vis[no]=1;
	for(auto j:adj[no]){
		if(vis[j]==0){
			dfs(j);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>aa[i];
		}
		for(int i=0;i<n;i++){
			cin>>bb[i];
		}
		for(int i=0;i<n;i++){
			adj[i].clear();
			vis[i]=0;
		}
		for(int i=0;i<n;i++){
			adj[aa[i]-1].pb(bb[i]-1);
		}
		llo ans=1;
		for(int i=0;i<n;i++){
			if(vis[i]==0){
				dfs(i);

				ans=(ans*2)%mod;
			}
		}

		cout<<ans<<endl;


	}





	return 0;
}