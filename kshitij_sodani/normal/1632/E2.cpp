//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

vector<int> adj[300002];
int dist[300002];
int dist2[300002];
void dfs(int no,int par=-1,int lev=0){
	dist[no]=lev;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no,lev+1);
		}
	}

}
vector<int> pre[300002];
int fin[300002];
vector<int> pre2[300002];
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
		for(int j=0;j<n;j++){
			dist2[j]=dist[j];
		}
		pair<int,int> ma={-1,-1};
		for(int i=0;i<n;i++){
			ma=max(ma,{dist[i],i});
		}
		vector<pair<int,int>> cur;
		dfs(ma.b);
		for(int i=0;i<=n;i++){
			pre[i].clear();
			pre2[i].clear();
		}
		for(int i=0;i<n;i++){
			pre[dist2[i]].pb(dist[i]);
		}
		int ma2=-1;
		fin[n]=ma.a;
		for(int i=n;i>=1;i--){
			if(i<n){
				for(auto j:pre[i+1]){
					ma2=max(ma2,j);
				}
			}
			//diameter=j
			if(ma2==-1){

			}
			else{
				int zz=2*i-ma2;
				if(zz>=2){
					zz/=2;
					pre2[zz].pb(i);
					//cout<<i<<"::"<<zz<<endl;
				}
			}
		}

		for(int i=1;i<=n;i++){
			for(int j=0;j<n;j++){
				if(dist[j]>i){

				}
			}
		}
		for(int j=n;j>=1;j--){
			if(j<n){
				fin[j]=fin[j+1];
			}
			for(auto i:pre2[j]){
				fin[j]=min(fin[j],i);
			}
		}
		for(int j=1;j<=n;j++){
			cout<<fin[j]<<" ";
		}
		cout<<endl;
	}




 
	return 0;
}