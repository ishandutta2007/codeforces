#include<bits/stdc++.h>
using namespace std;
#define a first
#define b second
#define pb push_back
typedef int64_t llo;
vector<int> adj[100001];
int ma=0;
int mi=1;
int dfs(int no,int lev=0,int par=-1){
	if(adj[no].size()==1 and lev%2==1){
		mi=3;
	}
	for(auto nn:adj[no]){
		if(nn==par){
			continue;
		}
		dfs(nn,lev+1,no);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int aa,bb;
	for(int i=0;i<n-1;i++){
		cin>>aa>>bb;
		adj[aa-1].pb(bb-1);
		adj[bb-1].pb(aa-1);
	}
	int ind=0;
	for(int i=0;i<n;i++){
		if(adj[i].size()==1){
			ind=i;
			break;
		}
	}
//	ma=n-1;
	dfs(ind);
	cout<<mi<<" ";
	int ma=n-1;
	for(int i=0;i<n;i++){
		if(adj[i].size()==1){
			ma-=1;
		}
		int st=0;
		for(auto jj:adj[i]){
			if(adj[jj].size()==1){
				st=1;
			}
		}
		ma+=st;
	}
	cout<<ma<<endl;
	return 0;
}