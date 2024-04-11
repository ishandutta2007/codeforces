#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second


int n;
int it[1000001];
int par[1000001];
int vis[1000001];
/*void dfs(int no,int par2==-1){
	for(auto j:adj[no]){

	}
}*/
//vector<pair<int,int>> pre[2][2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;

	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>it[i];
		//	adj[i+1-it[i]].pb(i+1);
		//	adj[i+1].pb(i+1-it[i]);
		}
		int st=0;
	//	set<int> cur;
		vis[1]=1;
		int la=1;
		vector<int> ans;
		ans.pb(1);
		while(true){
			int x=la-it[la-1];
		//	cout<<x<<endl;

			if(vis[x]==0){
				la=x;
				vis[la]=1;
				ans.pb(la);
			}
			else{
				int ind=0;
				for(int i=0;i<ans.size();i++){
					if(ans[i]==x){
						ind=i;
						break;
					}
				}
				cout<<ans.size()-ind<<'\n';
				for(int j=ind;j<ans.size();j++){
					cout<<ans[j]<<" ";
				}
				cout<<'\n';
				break;


			}
		}
		for(int i=1;i<n+1;i++){
			vis[i]=0;
		}
	}






	return 0;
}