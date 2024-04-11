#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
#define pb push_back
typedef long long int llo;
llo mod=1000000007;
llo n,k;
vector<llo> adj[200001];
llo le[200001];
llo ss[200001];
llo vis[200001];
llo dfs(llo no,llo par=-1,llo lev=0){
	le[no]=lev;
	ss[no]=1;
	for(auto nn:adj[no]){
		if(nn!=par){
			dfs(nn,no,lev+1);
			ss[no]+=ss[nn];
		}
	}
}
llo tot=0;
llo dfs2(llo no,llo par=-1,llo lev=0){
	if(vis[no]==1){
		tot+=lev;
	}
	for(auto nn:adj[no]){
		if(nn!=par){
			if(vis[no]==1){
				dfs2(nn,no,lev);
			}
			else{
				dfs2(nn,no,lev+1);
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
		adj[aa-1].pb(bb-1);
		adj[bb-1].pb(aa-1);
	}
	dfs(0);
	vector<pair<pair<llo,llo>,llo>> kk;
	for(llo i=0;i<n;i++){
		kk.pb({{-(le[i]-(ss[i]-1)),0},i});
	}
	sort(kk.begin(),kk.end());
	for(llo i=0;i<n;i++){
		vis[i]=0;
	}

	for(llo i=0;i<k;i++){
		vis[kk[i].b]=1;
//		cout<<kk[i].b<<" ";
	}
	dfs2(0);
	cout<<tot<<endl;




	return 0;
}