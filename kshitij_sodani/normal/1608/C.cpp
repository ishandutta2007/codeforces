//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo aa[100001];
llo bb[100001];
vector<llo> adj[100001];
vector<llo> adj2[100001];
llo vis[100001];
vector<llo> ord;
void dfs(llo no){
	vis[no]=1;
	for(auto j:adj[no]){
		if(vis[j]==0){
			dfs(j);
		}
	}
	ord.pb(no);
}
void dfs2(llo no){
	vis[no]=1;
	for(auto j:adj2[no]){
		if(vis[j]==0){
			dfs2(j);
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
		vector<pair<llo,llo>> ss;
		for(llo i=0;i<n;i++){
			cin>>aa[i];
			ss.pb({aa[i],i});
		}
		sort(ss.begin(),ss.end());
		vector<pair<llo,llo>> tt;
		for(llo i=0;i<n;i++){
			cin>>bb[i];
			tt.pb({bb[i],i});
		}
		sort(tt.begin(),tt.end());
		for(llo i=0;i<n;i++){
			adj[i].clear();
			//ans[i]=0;
			adj2[i].clear();
			vis[i]=0;
		}
		for(llo i=0;i<n-1;i++){
			adj[ss[i+1].b].pb(ss[i].b);
			adj[tt[i+1].b].pb(tt[i].b);
			adj2[ss[i].b].pb(ss[i+1].b);
			adj2[tt[i].b].pb(tt[i+1].b);
		}
		ord.clear();

		for(llo i=0;i<n;i++){
			if(vis[i]==0){
				dfs(i);
			}
		}
		//cout<<ord.back()<<","<<endl;
		for(llo i=0;i<n;i++){
			vis[i]=0;
		}
		dfs2(ord.back());
		for(llo i=0;i<n;i++){
			cout<<vis[i]<<"";
		}
		cout<<endl;


	}



 
	return 0;
}