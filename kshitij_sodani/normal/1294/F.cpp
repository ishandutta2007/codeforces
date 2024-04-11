#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef  long long int llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
int ma=0;
int ind=0;
int cc=-1;
queue<pair<int,int>> bfs;
vector<int> path;
vector<int> adj[200001];
vector<int> st;
int vis[200001];
void dfs(int no,int lev){
	if(no==cc){
		for(int i=0;i<st.size();i++){
			path.pb(st[i]);
		}
	}

	for(int j=0;j<adj[no].size();j++){
		int nn=adj[no][j];
		if(vis[nn]==1){
			continue;
		}
		vis[nn]=1;
		if(lev+1>ma){
			ma=lev+1;
			ind=nn;
		}
		st.pb(nn);
		dfs(nn,lev+1);
		st.pop_back();

	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int u,v;
	
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	dfs(0,0);
	int b=ind;
	ma=0;
	memset(vis,0,sizeof(vis));
	vis[b]=1;
	dfs(b,0);
	cc=ind;
	memset(vis,0,sizeof(vis));
	vis[b]=1;
	path.pb(b);
	dfs(b,0);

	memset(vis,0,sizeof(vis));
	for(int i=0;i<path.size();i++){
		bfs.push(mp(path[i],0));
		vis[path[i]]=1;
	//	cout<<path[i]<<" ";
	
	}
	//cout<<endl;
	int tot=bfs.size()-1;
	int maa=0;
	int ind2=path[1];
	while(bfs.size()>0){
		pair<int,int> node=bfs.front();
		bfs.pop();
		for(int j=0;j<adj[node.a].size();j++){
			int nn=adj[node.a][j];
			if(vis[nn]==0){
				vis[nn]=1;
				bfs.push(mp(nn,node.b+1));
				if(node.b+1>maa){
					ind2=nn;
				}
				maa=max(maa,node.b+1);

			}
		}
	}
	tot+=maa;
	cout<<tot<<endl;
	cout<<b+1<<" "<<cc+1<<" "<<ind2+1<<endl;

	return 0;
}