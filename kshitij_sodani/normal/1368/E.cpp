#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int n,m;
vector<int> adj[200001];
vector<int> adj2[200001];
/*int co[200001];
int co2[200001];*/
int vis[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			adj[i].clear();
			adj2[i].clear();
		}
		for(int i=0;i<m;i++){
			int aa,bb;
			cin>>aa>>bb;
			adj[aa-1].pb(bb-1);
			adj2[bb-1].pb(aa-1);
		}
		for(int i=0;i<n;i++){
			vis[i]=0;
		}
		vector<int> ans;
		for(int i=0;i<n;i++){
			if(vis[i]){
				continue;
			}
			int co=0;
			for(auto j:adj2[i]){
				if(vis[j]==0){
					co+=1;
				}
			}
			if(co){
				for(auto j:adj[i]){
					if(vis[j]==0){
						vis[j]=1;
						ans.pb(j);
					}

					
				}
			}
		}
	/*	multiset<pair<int,int>> ss;
		for(int i=0;i<n;i++){
			co[i]=adj[i].size();
			co2[i]=adj2[i].size();
			if(co[i]>0 and co2[i]>0){
				ss.insert({-min(co[i],co2[i]),i});
			}
		}
		vector<int> ans;
		while(ss.size()){
			auto x=ss.begin();
			if((*x).a>-1){
				break;
			}
			co[(*x).b]=0;
			co2[(*x).b]=0;
			ans.pb((*x).b);

			for(auto j:adj2[(*x).b]){
				ss.erase({-(min(co[j],co2[j])),j});
				co[j]-=1;
				ss.insert({-(min(co[j],co2[j])),j});

			}
			for(auto j:adj[(*x).b]){
				ss.erase({-(min(co[j],co2[j])),j});
				co2[j]-=1;
				ss.insert({-(min(co[j],co2[j])),j});

			}
			ss.erase(x);
		}*/
		cout<<ans.size()<<endl;
		for(auto j:ans){
			cout<<j+1<<" ";
		}
		cout<<endl;
	}



	return 0;
}