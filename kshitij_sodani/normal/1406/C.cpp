//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int t;
int n;
vector<int> adj[100001];
int ss[100001];
pair<int,int> cur;
void dfs(int no,int par=-1){

	ss[no]=1;
	for(auto j:adj[no]){
		if(j==par){
			continue;
		}
		dfs(j,no);
		ss[no]+=ss[j];
	}
	if(ss[no]==n/2){
		cur={no,par};
	}
}
pair<int,int> cot={-1,-1};
void dfs2(int no,int par=-1){
	int st=1;
	for(auto j:adj[no]){
		if(j==par){
			continue;
		}
		st=0;
		dfs2(j,no);
	}
	if(st){
		cot={no,par};
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		cin>>n;
		vector<pair<int,int>> ed;
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
			ed.pb({aa,bb});
		}

		cur={-1,-1};
		if(n%2==0){
			dfs(0);
		}
		if(cur.a==-1){
			cout<<ed[0].a+1<<" "<<ed[0].b+1<<endl;
			cout<<ed[0].a+1<<" "<<ed[0].b+1<<endl;
		}
		else{
			dfs2(cur.a,cur.b);
			cout<<cot.a+1<<" "<<cot.b+1<<endl;
			cout<<cot.a+1<<" "<<cur.b+1<<endl;
		}
	}






 
	return 0;
}