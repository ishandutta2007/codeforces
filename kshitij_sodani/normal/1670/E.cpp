#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
const llo mod=1e9+7;
vector<pair<llo,llo>> adj[200001];;

int t;
int ans[200001];
int ans2[200001];
int ind=1;
int p;
void dfs(int no,int par=-1,int lev=0){
	if(par==-1){
		ans[no]=(1<<p);
	}
	for(auto j:adj[no]){
		if(j.a!=par){
			if(lev==0){
				ans2[j.b]=ind+(1<<p);
				ans[j.a]=ind;
			}
			else{
				ans[j.a]=ind+(1<<p);
				ans2[j.b]=ind;
			}
			ind++;
			dfs(j.a,no,lev^1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		
		cin>>p;
		int n=(1<<p);
		for(int i=0;i<n;i++){
			adj[i].clear();
		}
		ind=1;
		for(int i=0;i<n-1;i++){
			int aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].pb({bb,i});
			adj[bb].pb({aa,i});
		}
		dfs(0);


		cout<<1<<endl;
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<n-1;i++){
			cout<<ans2[i]<<" ";
		}
		cout<<endl;
	}



 
 
	return 0;
}