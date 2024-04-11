//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
const llo mod=998244353;

llo it[1001];
vector<llo> adj[1001];
llo n,m;
llo dist[1001][1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			dist[i][j]=-1;
		}
		dist[i][i]=0;
		queue<llo> ss;
		ss.push(i);
		while(ss.size()){
			llo no=ss.front();
			ss.pop();
			for(auto j:adj[no]){
				if(dist[i][j]==-1){
					dist[i][j]=dist[i][no]+1;
					ss.push(j);
				}
			}
		}
	}
	for(llo i=0;i<n;i++){
		
		for(llo j=0;j<n;j++){
			llo ans=1;
			llo cot=0;
			for(llo ii=0;ii<n;ii++){
			
				if(dist[i][ii]+dist[j][ii]==dist[i][j]){
					cot++;
					continue;
				}
			}
			if(cot>dist[i][j]+1){
				cout<<0<<" ";
				continue;
			}
			for(llo ii=0;ii<n;ii++){
				llo co=0;
				if(dist[i][ii]+dist[j][ii]==dist[i][j]){
					continue;
				}
				for(auto jj:adj[ii]){
					
					if(dist[i][jj]+1==dist[i][ii] and dist[j][jj]+1==dist[j][ii]){
						
						co+=1;
					}
				}
				/*if(i==0 and j==1){
					cout<<ii<<":"<<co<<endl;
				}*/
				ans=(ans*co)%mod;
				if(ans==0){
					break;
				}
			}
			cout<<ans<<" ";
		}
		cout<<endl;
	}







 
	return 0;
}