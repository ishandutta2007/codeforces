#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define pb push_back
typedef int64_t llo;
#define a first
#define  b second
#define endl "\n"
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m;
	cin>>n>>m;
	vector<llo> adj[n];
	vector<llo> adj2[n];

	for(llo i=0;i<m;i++){
		llo u,v;
		cin>>u>>v;
		adj[u-1].pb(v-1);
		adj2[v-1].pb(u-1);
	}
	llo k;
	cin>>k;
	llo it[k];
	for(llo i=0;i<k;i++){
		cin>>it[i];
		it[i]-=1;
	}
	llo mi=0;
	llo ma=0;
	llo dis[n];
	memset(dis,-1,sizeof(dis));
	//cout<<dis[n-1]<<endl;
	queue<llo> aa;
	//cout<<it[k-1]<<endl;
	aa.push(it[k-1]);
	dis[it[k-1]]=0;
	while(aa.size()>0){
		llo x=aa.front();
		aa.pop();
		for(llo j=0;j<adj2[x].size();j++){
			llo nn=adj2[x][j];
			if(dis[nn]==-1 or dis[nn]>dis[x]+1){
		//	//cout<<nn<<" "<<x<<endl;
				dis[nn]=dis[x]+1;
				aa.push(nn);
			}
		}
	}
	llo co=0;

	for(llo i=k-2;i>=0;i--){
		co+=1;
		//if(dis[it[i]]==co){
		int st=1;
		int stt=0;
			for(llo j=0;j<adj[it[i]].size();j++){
				llo nn=adj[it[i]][j];
				if(dis[nn]==dis[it[i]]-1 and nn!=it[i+1] and stt==0){
					ma+=1;
					stt=1;

				}
				else if(dis[nn]==dis[it[i]]-1 and nn==it[i+1]){
					st=0;
				}
			}
			mi+=st;
			//cout<<st<<endl;

		
		/*else{
			if(dis[it[i+1]]!=dis[it[i]]-1){
				mi+=1;
			}
			ma+=1;
		}*/
	}
//	cout<<(int)200000<<endl;
	cout<<mi<<" "<<ma<<endl;












	return 0;
}