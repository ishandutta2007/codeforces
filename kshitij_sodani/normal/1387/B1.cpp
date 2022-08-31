#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b ssecond
llo n;
vector<llo> adj[100001];

int par2[100001];
vector<int> ord;
void dfs(llo no,llo par=-1){
	ord.pb(no);
	par2[no]=par;
	for(auto j:adj[no]){
		if(j==par){
			continue;
		}
		dfs(j,no);
	}
}
int ans[100001];
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
	for(int i=0;i<n;i++){
		ans[i]=i;

	}
	reverse(ord.begin(),ord.end());
	int ans2=0;
	for(auto j:ord){
		if(ans[j]!=j){
			continue;
		}
		ans2+=2;
		if(par2[j]==-1){
			swap(ans[j],ans[adj[j][0]]);
		}
		else{
			swap(ans[par2[j]],ans[j]);
		}
	}
	cout<<ans2<<endl;
	for(int i=0;i<n;i++){
		cout<<ans[i]+1<<" ";
	}
	cout<<endl;

	

	return 0;
}