#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
int n;
int par[100001];
set<int> adj[100001];
pair<int,int> dfs(int no){
	pair<int,int> ac={0,no};
	for(auto j:adj[no]){
		pair<int,int> cc=dfs(j);
		if(cc.a+1>ac.a){
			ac={cc.a+1,cc.b};
		}
	}
	return ac;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	int aa;
	par[0]=-1;
	for(int i=0;i<n-1;i++){
		cin>>aa;
		adj[aa].insert(i+1);
		par[i+1]=aa;
	}
	pair<int,int> ma=dfs(0);
	int ans=n-1-ma.a;
	int cur=ma.b;
	vector<int> ord;
	vector<int> ord2;
	ord.pb(cur);
	adj[par[cur]].erase(cur);
	while(cur!=0){
		if(adj[par[cur]].size()>0){
			break;
		}
		cur=par[cur];
		if(cur!=0){
			adj[par[cur]].erase(cur);
		}
		ord.pb(cur);
	}
	for(int i=0;i<ans;i++){
		while(cur!=0){
			if(adj[par[cur]].size()>0){
				break;
			}
			cur=par[cur];
			if(cur!=0){
				adj[par[cur]].erase(cur);
			}
			ord.pb(cur);
		}
		ord2.pb(cur);
		par[cur]=*(adj[par[cur]].begin());
	}
	while(cur!=0){
		cur=par[cur];
		ord.pb(cur);
	}
	reverse(ord.begin(),ord.end());
	for(auto j:ord){
		cout<<j<<" ";
	}
	cout<<endl;
	cout<<ans<<endl;
	reverse(ord2.begin(),ord2.end());
	for(auto j:ord2){
		cout<<j<<" ";
	}
	cout<<endl;
	return 0;
}