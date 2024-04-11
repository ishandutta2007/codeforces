#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo it[2001][2001];
llo n;
llo dist[2001];
llo ans[2001];
llo vis[2001];
void solve(){
	for(llo i=0;i<n;i++){
		vis[i]=0;
	}
	for(llo i=0;i<n;i++){
		pair<llo,llo> mi={1e18,-1};
		for(llo j=0;j<n;j++){
			if(vis[j]==0){
				mi=min(mi,{dist[j],j});
			}
		}
		for(llo j=0;j<n;j++){
			if(j==mi.b){
				continue;
			}
			dist[j]=min(dist[j],it[j][mi.b]+mi.a);
		}
		vis[mi.b]=1;
	}
	for(int i=0;i<n;i++){
		ans[i]=min(ans[i],dist[i]);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	pair<llo,pair<llo,llo>> ma={1e9+1,{-1,-1}};
	for(llo i=0;i<n;i++){
		for(llo j=i+1;j<n;j++){
			llo aa;
			cin>>aa;
			it[i][j]=aa;
			it[j][i]=aa;
			ma=min(ma,{it[i][j],{i,j}});
		}
	}
	llo su=ma.a*(n-1);
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			if(i!=j){
				it[i][j]-=ma.a;
			}
		}
	}
	for(llo i=0;i<n;i++){
		ans[i]=(llo)1e18;
	}
	for(llo i=0;i<n;i++){
		dist[i]=(llo)1e18;
	}
	dist[ma.b.a]=0;
	solve();
	for(llo i=0;i<n;i++){
		dist[i]=(llo)1e18;
	}
	dist[ma.b.b]=0;
	solve();
	for(llo i=0;i<n;i++){
		llo mi=1e9+1;
		for(llo j=0;j<n;j++){
			if(i!=j){
				mi=min(mi,it[i][j]);
			}
		}
		dist[i]=2*mi;
	}
	solve();
		for(int i=0;i<n;i++){
			cout<<ans[i]+su<<endl;
		}



	return 0;
}