#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define a first
#define b second
typedef long long int llo;

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
vector<llo> adj[200001];
llo vis[200001];
llo co[200001][2];
llo ind,x;
llo dfs(llo no){
	for(llo j=0;j<adj[no].size();j++){
		llo i=adj[no][j];

		if(vis[i]==1){
			continue;
		}
		if(i==x){
			continue;
		}
		//cout<<i<<" ";
		vis[i]=1;
		co[i][ind]++;
		dfs(i);
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m,aa,bb;
		cin>>n>>m>>aa>>bb;
		llo ac,bc;
		aa--;
		bb--;
		for(llo i=0;i<n;i++){
			adj[i].clear();
		}
		for(llo i=0;i<m;i++){
			cin>>ac>>bc;
			adj[ac-1].pb(bc-1);
			adj[bc-1].pb(ac-1);
		}
		
		for(llo i=0;i<n;i++){
			vis[i]=0;
			co[i][0]=0;
			co[i][1]=0;
		}
		x=bb;
		ind=0;
		vis[aa]=1;
	//	cout<<x<<endl;
		dfs(aa);
	//	cout<<",,"<<endl;
		for(llo i=0;i<n;i++){
			vis[i]=0;
		}
		x=aa;
		ind=1;
		vis[bb]=1;
	//	cout<<x<<endl;
		dfs(bb);
	//	cout<<",,,"<<endl;
		llo coo[2];
		coo[0]=0;
		coo[1]=0;
		for(llo i=0;i<n;i++){
//			cout<<i<<" "<<co[i][0]<<" "<<co[i][1]<<endl;
			if(co[i][0]==1 and co[i][1]==1){
				continue;
			}

			coo[0]+=co[i][0];
			coo[1]+=co[i][1];
		}
		cout<<coo[0]*coo[1]<<endl;
	}
	








	return 0;
}