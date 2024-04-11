#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b ssecond
llo n;
vector<llo> adj[100001];
//llo dp[1001][1001];
//vector<pair<llo,llo>> ord;
llo ss[100001];
void dfs(llo no,llo par=-1){
	ss[no]=1;
	for(auto j:adj[no]){
		if(j==par){
			continue;
		}
		dfs(j,no);
		ss[no]+=ss[j];
	}
}
vector<llo> ord;
llo dfs2(llo no,llo par=-1){
	for(auto j:adj[no]){
		if(j==par){
			continue;
		}
		if(ss[j]>n/2){
			return dfs2(j,no);
		}
	}
	return no;
}
llo ans=0;
void dfs3(llo no,llo par=-1,llo levv=0){
	ord.pb(no);
	ans+=levv*2;
	for(auto j:adj[no]){
		if(j==par){
			continue;
		}
		dfs3(j,no,levv+1);
	}
}
llo ans2[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);
	llo cen=dfs2(0);
	dfs3(cen);
	for(llo i=0;i<n;i++){
		ord.pb(ord[i]);
	}
	llo x=(n/2);
	cout<<ans<<endl;
	for(llo i=0;i<n;i++){
		ans2[ord[i]]=ord[i+x]+1;
	}
	for(llo i=0;i<n;i++){
		cout<<ans2[i]<<" ";
	}
	cout<<endl;




	return 0;
}