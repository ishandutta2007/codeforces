#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef  long long int llo ;
 
#define mp make_pair
#define pb push_back
#define a first
#define b second
llo p[2001];
llo c[2001];
vector<llo> adj[2001];
llo vis[2001];
llo size2[2001];
llo ans[2001];
llo st=1;
llo n;
llo dfs(llo no){
	size2[no]=1;
	llo co=0;
	for(llo i=0;i<n;i++){
		if(vis[i]==0){
			co+=1;
		}
		if(co==c[no]+1){
			//cout<<no<<" "<<i<<endl;
			ans[no]=i+1;
			vis[i]=1;
			break;
		}
	}
	for(llo j=0;j<adj[no].size();j++){
		dfs(adj[no][j]);
		size2[no]+=size2[adj[no][j]];
	}
	if(size2[no]<=c[no]){
		st=0;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	llo root;
	memset(vis,0,sizeof(vis));
	for(llo i=0;i<n;i++){
		cin>>p[i]>>c[i];
		if(p[i]==0){
			root=i;
			continue;
		}
		adj[p[i]-1].pb(i);
	}
	dfs(root);
	if(st==0){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		for(llo i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}


}