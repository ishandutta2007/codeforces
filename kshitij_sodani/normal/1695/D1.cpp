#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

vector<llo> adj[200001];
llo vis[200001];
llo ans=0;
void dfs(llo no,llo par=-1){
	vis[no]=0;
	llo co=0;
	llo co2=0;
	llo co3=0;
	for(auto j:adj[no]){
		if(j!=par){
			co++;
			dfs(j,no);
			if(co>=2){
				vis[no]=1;
			}
			if(vis[j]==0){
				co2++;
			}
			else{
				co3++;
			}
		}	
	}
	if(co3>=1){
		vis[no]=1;
	}
	if(co2>=1){
		//cout<<no<<":"<<co2<<endl;
		ans+=(co2-1);
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
		for(llo i=0;i<n;i++){
			adj[i].clear();
		}
		for(llo i=0;i<n-1;i++){
			llo aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].pb(bb);
			adj[bb].pb(aa);
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		ans=0;
		int ind=-1;
		for(int i=0;i<n;i++){
			if(adj[i].size()>2){
				ind=i;
			}
		}
		if(ind==-1){
			cout<<1<<endl;
			continue;
		}
		dfs(ind);
		cout<<ans<<endl;
		
	}





	return 0;
}