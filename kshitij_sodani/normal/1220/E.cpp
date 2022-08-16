//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n;
llo it[200001];
llo co[200001];
llo coo[200001];
vector<llo> adj[200001];
llo vis[200001];
llo vis2[200001];

set<llo> adj2[200001];

llo xx[200001];

llo x;
vector<llo> pp;
vector<llo> pp2;
void dfs(llo no,llo par=-1){
	pp.pb(no);
	if(no==vis[x]){
		pp2=pp;
	}
	for(auto j:adj2[no]){
		if(j!=par){

			dfs(j,no);
		}
	}
	pp.pop_back();
}
llo ma=0;

void dfs2(llo no,llo par=-1,llo lev=0){
	if(vis2[no]==0){
		lev+=coo[no];
	}
	ma=max(ma,lev);
	for(auto j:adj2[no]){
		if(j!=par){
			dfs2(j,no,lev);
		}
	}
}
llo ma2=0;
void dfs3(llo no,llo par=-1,llo lev=0){
	lev+=coo[no];
	ma2=max(ma2,lev);
	for(auto j:adj2[no]){
		if(j!=par){
			if(xx[j]==1){
				continue;
			}
			dfs3(j,no,lev);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	llo m;
	cin>>m;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}

	vector<pair<llo,llo>> ed;
	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		co[aa]++;
		co[bb]++;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
		ed.pb({aa,bb});
	}
	
	cin>>x;
	x--;
	if(co[x]==0){
		cout<<it[x]<<endl;
		return 0;
	}
	queue<llo> ss;
	for(llo i=0;i<n;i++){
		if(co[i]<=1){
			ss.push(i);
		}
	}
	for(llo i=0;i<n;i++){
		vis[i]=-1;
	}
	llo cot=0;
	while(ss.size()){
		llo no=ss.front();
		ss.pop();
		vis[no]=no;
		xx[no]=1;
		for(auto j:adj[no]){
			co[j]--;
			if(co[j]<=1 and vis[j]==-1){
				ss.push(j);
			}
		}
		cot+=it[no];
	}
	llo le=-1;
	for(llo i=0;i<n;i++){
		if(vis[i]==-1){
			le=i;
		}
	}
	for(llo i=0;i<n;i++){
		if(vis[i]==-1){
			vis[i]=le;
		}
	}
	for(llo i=0;i<n;i++){
		coo[vis[i]]+=it[i];
	}

	for(llo i=0;i<n;i++){
		for(auto j:adj[i]){
			if(vis[i]!=vis[j]){
				adj2[vis[i]].insert(vis[j]);
			}
		}
	}
	if(le==-1){
		le=vis[x];
	}
	dfs(le);
	//return 0;

	for(auto j:pp2){
		vis2[j]=1;
		//cout<<j<<",";
	}
	//cout<<endl;
	dfs2(le);
	for(auto j:pp2){
		ma+=coo[j];
	}
	dfs3(vis[x]);
	ma=max(ma,ma2);
	cout<<ma<<endl;



 
 
	return 0;
}