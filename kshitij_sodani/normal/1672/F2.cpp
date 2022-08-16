#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo it[200001];
llo co[200001];
vector<llo> pre[200001];
llo ans[200001];
vector<llo> adj[200001];
llo tt[200001];
llo vis[200001];
llo vis2[200001];
llo cd=0;
void dfs(int no){
	vis[no]=1;
	vis2[no]=1;
	for(auto j:adj[no]){
		if(vis[j]==0){
			dfs(j);
		}
		else if(vis2[j]==1){
			cd++;
		}
	}
	vis2[no]=0;
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
			co[i]=0;
			adj[i].clear();
			pre[i].clear();
		}
		vector<pair<llo,llo>> dd;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			it[i]--;
			co[it[i]]++;
			pre[it[i]].pb(i);
		}
		for(int i=0;i<n;i++){
			dd.pb({co[i],i});
		}
		sort(dd.begin(),dd.end());
		for(int i=0;i<n;i++){
			cin>>tt[i];
			tt[i]--;
			if(it[i]!=dd.back().b and tt[i]!=dd.back().b){
				adj[tt[i]].pb(it[i]);
			}
		}
		for(int i=0;i<n;i++){
			vis[i]=0;
		}
		cd=0;
		for(int i=0;i<n;i++){
			if(vis[i]==0){
				dfs(i);
			}
		}
		if(cd>0){
			cout<<"WA"<<endl;
		}
		else{
			cout<<"AC"<<endl;
		}
		

	}







	return 0;
}