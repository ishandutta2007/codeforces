//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

vector<int> adj[300001];
int dist[3001];
int dist2[3001];
void dfs(int no,int par=-1,int lev=0){
	dist[no]=lev;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no,lev+1);
		}
	}

}
vector<int> pre[3001];
int fin[3001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			adj[i].clear();
			fin[i+1]=n;
		}
		for(int i=0;i<n-1;i++){
			int aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].pb(bb);
			adj[bb].pb(aa);
		}
		dfs(0);
		for(int i=0;i<n;i++){
			dist2[i]=dist[i];
		}
		for(int i=0;i<n;i++){
			dfs(i);
			multiset<int> cur;
			int ma=0;
			for(int j=0;j<=n;j++){
				pre[j].clear();
			}
			for(int j=0;j<n;j++){
				//dist[j]+x
				//dist2[j]
				if(dist[j]+1<dist2[j]){
					cur.insert(dist[j]);
					pre[dist2[j]-dist[j]].pb(j);
				}
				else{
					ma=max(ma,dist2[j]);
				}

			}
			for(int j=1;j<=n;j++){
				for(auto k:pre[j]){
					auto jj=cur.find(dist[k]);
					cur.erase(jj);
					ma=max(ma,dist2[k]);
				}
				int ans=ma;
				if(cur.size()){
					auto jj=cur.end();
					jj--;
					ans=max(ans,(*jj)+j);

				}
				fin[j]=min(fin[j],ans);

			}
		}
		for(int j=1;j<=n;j++){
			cout<<fin[j]<<" ";
		}
		cout<<endl;
	}




 
	return 0;
}