//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,m;
vector<llo> adj[201];
llo dist[201][201];
//vector<llo> adj[201];
llo st=1;
llo val[201];
void dfs(llo no,llo par=-1,llo co=1){
	val[no]=co;
	for(auto j:adj[no]){
		if(val[j]==0){
			dfs(j,no,3-co);
		}
		else{
			if(val[j]==val[no]){
				st=0;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			dist[i][j]=n;
		}
		dist[i][i]=0;
	}
	vector<vector<llo>> ed;
	for(llo i=0;i<m;i++){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
		if(cc==1){
			dist[aa][bb]=1;
			dist[bb][aa]=-1;
		}
		else{
			dist[aa][bb]=1;
			dist[bb][aa]=1;
		}
		ed.pb({aa,bb,cc});
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);
	if(st==0){
		cout<<"NO"<<endl;
		return 0;
	}
	for(llo k=0;k<n;k++){
		for(llo i=0;i<n;i++){
			for(llo j=0;j<n;j++){
				
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				
			}
		}
	}
	for(llo i=0;i<n;i++){
		if(dist[i][i]<0){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	llo ma=-1;
	pair<llo,llo> cur;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			if(dist[i][j]>ma){
				ma=dist[i][j];
				cur={i,j};
			}
		}
	}
	/*for(auto j:ed){
		if(j[2]==1){
			if(dist[0][j[0]]!=dist[0][j[1]]-1){
				cout<<j[0]<<":"<<j[1]<<":"<<j[2]<<endl;
				cout<<"NO"<<endl;
				return 0;
			}
		}
		else{
			if(abs(dist[0][j[0]]-dist[0][j[1]])!=1){
				cout<<j[0]<<":"<<j[1]<<":"<<j[2]<<endl;
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}*/
	cout<<"YES"<<endl;

	llo ans=0;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			ans=max(ans,abs(dist[i][j]));
		}
	}
	//cout<<ans<<endl;
	vector<llo> ans2;
	llo mi=0;
	for(llo i=0;i<n;i++){
		ans2.pb(dist[cur.a][i]);
		 mi=min(mi,ans2.back());
	}
	
	cout<<ans<<endl;
	for(auto j:ans2){
		cout<<j+mi<<" ";
	}
	cout<<endl;













 
	return 0;
}