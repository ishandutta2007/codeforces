//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int n;
int it[200001];
vector<int> adj[200001];
int vis[2000001];
vector<int> ss;
void dfs(int no){
	vis[no]=1;
	ss.pb(no);
	for(auto j:adj[no]){
		if(vis[j]==0){
			dfs(j);
		}
	}
}
vector<pair<int,int>> ans;
void merge(vector<int> aa,vector<int> bb){
	ans.pb({aa[0],bb[0]});
	vector<pair<int,int>> cc;
	for(int i=0;i<aa.size();i++){
		if(i==0){
			cc.pb({aa[i],1});
		}
		else{
			cc.pb({aa[i],0});
		}
	}
	for(int i=0;i<bb.size();i++){
		if(i==0){
			cc.pb({bb[i],1});
		}
		else{
			cc.pb({bb[i],0});
		}
	}
	for(int i=0;i+1<aa.size();i++){
		ans.pb({aa[i],aa[i+1]});
	}
	for(int i=0;i+1<bb.size();i++){
		ans.pb({bb[i],bb[i+1]});
	}
	ans.pb({aa.back(),bb.back()});

}
int ind[2000001];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
		it[i]--;
		ind[it[i]]=i;
		adj[i].pb(it[i]);
	}
	vector<vector<int>> tt;
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			ss.clear();
			dfs(i);
			tt.pb(ss);
		}
	}
	if(tt.size()==1){
		vector<int> aa=tt[0];
		ans.pb({aa[1],aa[2]});
		ans.pb({aa[1],aa[0]});
		int cur=aa[2];
		for(int i=3;i<aa.size();i++){
			ans.pb({cur,aa[i]});
			cur=aa[i];
		}
		ans.pb({cur,aa[1]});
		cur=aa[1];
		ans.pb({cur,aa[0]});


	}
	else{
		int x=(tt.size());
		for(int i=0;i<x/2;i++){
			merge(tt[2*i],tt[2*i+1]);
		}
		if(x%2==1){
			merge(tt.back(),{tt[0][0]});
		}
	}
	cout<<ans.size()<<endl;

	for(auto j:ans){
		cout<<ind[j.a]+1<<" "<<ind[j.b]+1<<endl;
		swap(ind[j.a],ind[j.b]);
		//cout<<j.a+1<<" "<<j.b+1<<endl;
	}

 
	return 0;
}