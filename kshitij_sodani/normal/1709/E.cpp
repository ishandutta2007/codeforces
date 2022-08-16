#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;

set<llo> ss[200001];
llo cc[200001];
vector<llo> adj[200001];
llo ans=0;
llo it[200001];
llo dfs(llo no,llo par=-1,llo ax=0){
	cc[no]=(it[no]^ax);
	vector<llo> tt;
	for(auto j:adj[no]){
		if(j!=par){
			tt.pb(dfs(j,no,cc[no]));
		}
	}
	if(tt.size()==0){
		ss[no].insert(cc[no]);
		return no;
	}
	pair<llo,llo> ma={-1,-1};
	for(auto j:tt){
		ma=max(ma,{(llo)ss[j].size(),j});
	}
	llo st=0;
	for(auto j:tt){
		if(ss[j].find(cc[no]^it[no])!=ss[j].end()){
			st=1;
		}
	}
	if(st==1){
		ans++;
		ss[ma.b].clear();
		return ma.b;
	}
	for(auto j:tt){
		if(j==ma.b){
			continue;
		}

		for(auto i:ss[j]){
			llo xx=i^it[no];
			if(ss[ma.b].find(xx)!=ss[ma.b].end()){
				st=1;
				break;
			}

		}
		if(st==1){
			break;
		}
		for(auto i:ss[j]){
			ss[ma.b].insert(i);
		}
	}
	if(st==1){
		ans++;
		ss[ma.b].clear();
		return ma.b;
	}
	ss[ma.b].insert(cc[no]);
	return ma.b;
}	
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];

	}
	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);
	cout<<ans<<endl;









	return 0;
}