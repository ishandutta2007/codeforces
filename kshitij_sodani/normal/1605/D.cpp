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
vector<int> co[200001];
int ans[200001];
void dfs(int no,int par2=-1,int xx=0){
	co[xx].pb(no);
	for(auto j:adj[no]){
		if(j!=par2){
			dfs(j,no,xx^1);
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
		cin>>n;
		for(int i=0;i<n;i++){
			adj[i].clear();
			co[i].clear();
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
		if(co[0].size()>co[1].size()){
			swap(co[0],co[1]);
			
		}
		int yy=co[0].size();
			set<int> cur;

			for(int i=1;i<=n;i++){
				int x=-1;
				for(int j=20;j>=0;j--){
					if((1<<j)&i){
						x=j;
						break;
					}
				}
				//cout<<x<<":"<<yy<<endl;;
				//continue;
				if((1<<x)&(yy)){
					ans[co[0].back()]=i;
					co[0].pop_back();
				}
				else{
					ans[co[1].back()]=i;
					co[1].pop_back();
				}
			}
			for(int i=0;i<n;i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
	}



 
	return 0;
}