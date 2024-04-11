#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
#define endl "\n"
vector<int> adj[200001];
int lev[200001];
int ans[200001];
set<int> stac;
vector<pair<vector<int>,int>> cc[2000001];
int dfs(int no,int par=-1,int levv=0){
	lev[no]=levv;
	for(auto nn:adj[no]){
		if(nn==par){
			continue;
		}
		dfs(nn,no,levv+1);
	}
}
int dfs2(int no,int par=-1,int levv=0){

	for(auto nn:adj[no]){
		if(nn==par){
			continue;
		}
		stac.insert(nn);
	}
	
	for(auto nn:cc[no]){
		int so=1;
		for(auto np:nn.a){
			if(stac.find(np)==stac.end()){
				so=0;
				break;
			}
		}
		//cout<<nn.b<<" "<<so<<endl;
		ans[nn.b]=so;
	}
	for(auto nn:adj[no]){
		if(nn==par){
			continue;
		}
		dfs2(nn,no,levv+1);
	}

	for(auto nn:adj[no]){
		if(nn==par){
			continue;
		}
		stac.erase(nn);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int aa,bb;
	stac.insert(0);

	for(int i=0;i<n-1;i++){
		cin>>aa>>bb;
		adj[aa-1].pb(bb-1);
		adj[bb-1].pb(aa-1);
	}
	dfs(0);
	for(int i=0;i<m;i++){
		int co;
		cin>>co;
		int mi=-1;
		int ind=-1;
		vector<int> kk;
		for(int j=0;j<co;j++){
			cin>>aa;
			kk.pb(aa-1);
			if(lev[aa-1]>mi){
				mi=lev[aa-1];
				ind=aa-1;
			}
		}
	//	cout<<ind<<" "<<i<<endl;
		cc[ind].pb({kk,i});



	}
	dfs2(0);
	for(int i=0;i<m;i++){
		if(ans[i]==1){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}


	return 0;
}