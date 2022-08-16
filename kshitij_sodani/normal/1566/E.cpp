//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
vector<int> adj[200001];
int ss[200001];
int tt[200001];
void dfs(int no,int par=-1){
	ss[no]=0;
	if(par!=-1){
		tt[no]=2;
	}
	else{
		tt[no]=-1;
	}
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			if(tt[j]==2){
				continue;
			}
			ss[no]++;
			if(tt[j]!=0){
				tt[no]=1;
			}
		}
	}
	if(ss[no]==0){
		tt[no]=0;
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){	
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			adj[i].clear();
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
		int k=0;
		int st=0;
		for(int i=1;i<n;i++){
			if(tt[i]==2){
				k++;
			}
		}
		for(auto j:adj[0]){
			if(tt[j]==0){
				st=1;
			}
		}
		cout<<n-2*k-st<<endl;


	}


 
 
 
	return 0;
}