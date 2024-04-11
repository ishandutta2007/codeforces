//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

int n;
vector<int> adj[200001];
int co[2];
void dfs(int no,int par=-1,int levv=0){
	co[levv%2]+=1;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no,levv+1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);
	int ans=min(co[0],co[1])-1;
	cout<<ans<<endl;







 
	return 0;
}