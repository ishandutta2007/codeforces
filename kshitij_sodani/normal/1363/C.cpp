//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
vector<int> adj[1001];
int x;
int ss[1001];
int cur=0;
void dfs(int no,int par=-1){
	ss[no]=1;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			if(no==x){
				cur^=ss[j];
			}
			ss[no]+=ss[j];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n>>x;
		x--;
		for(int i=0;i<n;i++){
			adj[i].clear();
		}
		cur=0;
		for(int i=0;i<n-1;i++){
			int aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].pb(bb);
			adj[bb].pb(aa);
		}
		if(adj[x].size()<=1){
			cout<<"Ayush"<<endl;
		}
		else{
			if((n-1)%2==0){
				cout<<"Ashish"<<endl;
			}
			else{
				cout<<"Ayush"<<endl;
			}
		}
	}



	return 0;
}