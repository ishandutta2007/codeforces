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
vector<pair<llo,llo>> adj[200001];
llo dist[200001][4];
priority_queue<pair<llo,pair<llo,llo>>> ss;
void remin(llo aa,llo bb,llo cc){
	if(dist[aa][bb]>cc){
		dist[aa][bb]=cc;
		ss.push({-cc,{aa,bb}});
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<4;j++){
			dist[i][j]=1e18;
		}
	}
	dist[0][0]=0;
	for(llo i=0;i<m;i++){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		if(aa>bb){
			swap(aa,bb);
		}
		adj[aa].pb({bb,cc});
		adj[bb].pb({aa,cc});
	}
	
	ss.push({0,{0,0}});
	while(ss.size()){
		pair<llo,pair<llo,llo>> no=ss.top();
		ss.pop();
		no.a=-no.a;
		if(no.a>dist[no.b.a][no.b.b])continue;
		for(auto j:adj[no.b.a]){
			remin(j.a,no.b.b,j.b+no.a);
			if((no.b.b&1)==0){
				remin(j.a,no.b.b|1,no.a);
			}
			if((no.b.b&2)==0){
				remin(j.a,no.b.b|2,no.a+2*j.b);
			}
			if(no.b.b==0){
				remin(j.a,3,no.a+j.b);
			}
		}
	}

	
	for(int i=1;i<n;i++){
		llo ans=dist[i][3];
		cout<<ans<<" ";
	}
	cout<<endl;
 
 
	
 
	return 0;
}