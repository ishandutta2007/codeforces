#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo t;
llo it[200001];
llo ll[200001];
llo rr[200001];
vector<llo> adj[200001];
llo ans=0;
llo dfs(llo no){
	llo su=0;
	for(auto j:adj[no]){
		su+=dfs(j);
	}
	su=min(su,rr[no]);

	if(su<ll[no]){
		su=rr[no];
		ans++;
	}
	return su;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(int i=0;i<n;i++){
			adj[i].clear();
		}
		for(llo i=0;i<n-1;i++){
			llo aa;
			cin>>aa;
			aa--;
			adj[aa].pb(i+1);
		}
		for(llo i=0;i<n;i++){
			cin>>ll[i]>>rr[i];
		}
		ans=0;
		dfs(0);
		cout<<ans<<endl;
	}



 
 
 
	return 0;
}