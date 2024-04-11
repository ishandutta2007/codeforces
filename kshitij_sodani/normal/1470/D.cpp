//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int t;
vector<int> adj[300001];
int co=0;
int vis[300001];
void dfs(int no){
	vis[no]=1;
	co++;
	//cout<<no<<":"<<endl;
	for(auto j:adj[no]){
		if(vis[j]==0){
			dfs(j);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			adj[i].clear();
			vis[i]=0;
		}
		for(int i=0;i<m;i++){
			int aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].pb(bb);
			adj[bb].pb(aa);
		}
		co=0;
		dfs(0);
		//cout<<co<<endl;
		if(co<n){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			vis[i]=0;
		}
		vector<int> ans;
		queue<int> ss;
		ss.push(0);
		while(ss.size()){
			int no=ss.front();
			ss.pop();
			if(vis[no]==0){
				vis[no]=1;
				ans.pb(no);
				for(auto j:adj[no]){
					if(vis[j]==0){
						for(auto jj:adj[j]){
							if(vis[jj]==0){
								ss.push(jj);
							}
						}
						vis[j]=1;
					}
				}
			}
		}
		/*for(int i=0;i<n;i++){
			if(vis[i]==0){
				ans.pb(i);
				for(auto j:adj[i]){
					vis[j]=1;
				}
			}
		}*/
		cout<<"YES"<<endl;
		cout<<(ans.size())<<endl;
		for(auto j:ans){
			cout<<j+1<<" ";
		}
		cout<<endl;

	}





 
	return 0;
}