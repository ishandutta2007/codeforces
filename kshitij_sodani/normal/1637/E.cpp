//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[300001];
llo vis[300001];
llo co[300001];
vector<pair<llo,llo>> pre[300001];
vector<llo> adj[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		llo ans=0;
		map<llo,llo> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i];

			ss[it[i]]++;
		}
		map<llo,llo> tt;
		map<llo,llo> tt2;
		llo ind=0;
		for(auto j:ss){
			tt[j.a]=ind;
			tt2[ind]=j.a;
			ind++;
		}
		for(llo i=0;i<n;i++){
			it[i]=tt[it[i]];
		}
		for(llo i=0;i<=n;i++){
			co[i]=0;

			pre[i].clear();
			adj[i].clear();
		}
		for(llo i=0;i<n;i++){
			co[it[i]]++;
			
		}
		for(int i=0;i<ind;i++){
			pre[co[i]].pb({-tt2[i],i});
		}


		for(llo i=0;i<m;i++){
			llo aa,bb;
			cin>>aa>>bb;
			aa=tt[aa];
			bb=tt[bb];
			adj[aa].pb(bb);
			adj[bb].pb(aa);
		}
		vector<llo> xx;
		for(llo i=0;i<=n;i++){
			if(pre[i].size()>0){
				xx.pb(i);
				sort(pre[i].begin(),pre[i].end());
			}
		}
		for(llo i=0;i<ind;i++){
			for(auto j:adj[i]){
				vis[j]=1;
			}
			vis[i]=1;
			pair<llo,llo> yy={tt2[i],co[i]};
			for(auto j:xx){
				for(auto jj:pre[j]){
					if(vis[jj.b]==0){
						ans=max(ans,(yy.a-jj.a)*(j+co[i]));
						break;
					}
				}
			}
			for(auto j:adj[i]){
				vis[j]=0;
			}
			vis[i]=0;
			
		}
		cout<<ans<<endl;

	}



	


 
	return 0;
}