#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo n;
llo it[100002];
llo aa[100002];
llo par[100002][31];
vector<llo> adj[100002];
llo ans[100002];
vector<llo> pre[100002];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	set<llo> ss;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		it[i]--;
		ss.insert(it[i]);
		par[i][0]=it[i];
	}
	for(llo j=1;j<30;j++){
		for(llo i=0;i<n;i++){
			par[i][j]=par[par[i][j-1]][j-1];
		}
	}
	llo ma=0;
	set<llo> tt;
	for(llo i=0;i<n;i++){
		cin>>aa[i];

		ma=max(ma,aa[i]);
		aa[i]--;
		tt.insert(aa[i]);
	}
	llo le=n-ss.size();
	llo x=(ma-n)/le;
	if(x==0){
		for(llo i=0;i<n;i++){
			cout<<aa[i]+1<<" ";
		}
		cout<<endl;
		return 0;
	}
	for(llo i=0;i<n;i++){
		llo cur=i;
		for(llo j=0;j<30;j++){
			if((1<<j)&x){
				cur=par[cur][j];

			}
		}
		adj[cur].pb(i);
	}
	for(llo i=0;i<n;i++){
		if(adj[i].size()){
			sort(adj[i].begin(),adj[i].end());
			if(aa[i]<n){
				ans[adj[i][0]]=aa[i];
				//remaining values in adj have higher value
				for(auto j:adj[i]){
					if(j!=adj[i][0]){
						pre[aa[i]+1].pb(j);
					}
				}
			}
			else{
				for(auto j:adj[i]){
					pre[0].pb(j);
				}
			}
		}
	}
	set<llo> cur;
	for(llo i=0;i<n;i++){
		for(auto j:pre[i]){
			cur.insert(j);
		}
		if(tt.find(i)!=tt.end()){
			continue;
		}


		ans[*(cur.begin())]=i;
		cur.erase(cur.begin());
	}
	for(llo i=0;i<n;i++){
		cout<<ans[i]+1<<" ";
	}
	cout<<endl;


	return 0;
}