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


llo adj[601][601];
llo vis[601*601];
llo val[601][601];
vector<pair<llo,llo>> pre[601*601];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			adj[i][j]=-1;

		}
		adj[i][i]=0;
	}
	vector<pair<pair<llo,llo>,llo>> ed;
	for(llo i=0;i<m;i++){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		
		adj[aa][bb]=cc;
		adj[bb][aa]=cc;	
		ed.pb({{aa,bb},cc});
	}
	for(llo k=0;k<n;k++){
		for(llo i=0;i<n;i++){
			for(llo j=0;j<n;j++){
				if(adj[i][k]>-1 and adj[k][j]>-1){
					llo cur=adj[i][k]+adj[k][j];
					if(adj[i][j]==-1){
						adj[i][j]=cur;
					}
					adj[i][j]=min(adj[i][j],cur);
				}
			}
		}
	}

/*	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<adj[i][j]<<",";
		}
		cout<<endl;
	}*/
	llo q;
	cin>>q;
	while(q--){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		pre[aa].pb({bb,cc});
		pre[bb].pb({aa,cc});
	}
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			val[i][j]=-(llo)1e18;
			for(auto aa:pre[i]){
				if(adj[j][aa.a]==-1){
					continue;
				}
				val[i][j]=max(val[i][j],aa.b-adj[j][aa.a]);
			}
		}
	}

	llo ind=-1;
	llo ans=0;
	for(auto j:ed){
		ind++;
		if(true){
			llo xx=j.a.a;
			llo yy=j.a.b;
			for(llo i=0;i<n;i++){
				if(adj[i][xx]>-1){
					if(adj[i][xx]+j.b<=val[i][yy]){
						vis[ind]=1;
					}
				}
			}
		}
		if(true){
			llo xx=j.a.b;
			llo yy=j.a.a;
			for(llo i=0;i<n;i++){
				if(adj[i][xx]>-1){
					if(adj[i][xx]+j.b<=val[i][yy]){
						vis[ind]=1;
					}
				}
			}
		}
		ans+=vis[ind];
	}
	cout<<ans<<endl;







 
	return 0;
}