#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int llo;
#define mp make_pair
llo co=0;
#define pb push_back
llo ii;
vector<llo> adj[3000];
llo vis[3000];
llo dp[3000][3000];
llo par[3000][3000];
llo ss[3000][3000];

void dfs(llo no){
	llo cc=co;
	co++;
	for(llo j=0;j<adj[no].size();j++){
		llo nn=adj[no][j];
		if(vis[nn]==1){
			continue;
		}
		vis[nn]=1;
		par[ii][nn]=no;
		dfs(nn);
	}
	ss[ii][no]=co-cc;
}
llo find(llo a,llo b){
	if(dp[a][b]==-1){
		dp[a][b]=ss[a][b]*ss[b][a]+max(find(par[b][a],b),find(a,par[a][b]));
		return dp[a][b];
	}
	else{
		return dp[a][b];
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	llo u,v;
	for(llo i=0;i<n-1;i++){
		cin>>u>>v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}
	
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){

			dp[i][j]=-1;
			if(i==j){
				dp[i][j]=0;
			}
		}
	}
	memset(par,0,sizeof(par));
	memset(ss,0,sizeof(ss));
	for(llo i=0;i<n;i++){
		ii=i;
		co=0;
		memset(vis,0,sizeof(vis));
		vis[ii]=1;
		dfs(ii);
	}
	
	llo ma=0;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			find(i,j);
			ma=max(ma,dp[i][j]);
	//		cout<<ma<<endl;
		}
	}
	cout<<ma<<endl;






	return 0;
}