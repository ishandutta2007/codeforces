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
vector<int> adj[100001];
mt19937 rng;
int cot=0;
int vis[100001];
int vis2[100001];
vector<int> ss[100001];
multiset<int> tt[100001];
int ans[100001];
void dfs(int no){
	vis[no]=1;
	vis2[no]=1;
	for(auto j:adj[no]){
		if(vis[j]==0){
			dfs(j);
		}
		else{
			if(vis2[j]==0){
				cot=1;
			}
			ss[no].pb(j);			
		}
	}
	vis2[no]=0;
}
vector<int> ord;
int dfs2(int no,int yy=-1){
	vis[no]=1;
	ord.pb(no);
	pair<int,int> ma={-1,no};
	vector<int> xx;
	for(auto j:adj[no]){
		if(vis[j]==0){
			int x=dfs2(j,1);
			if(tt[x].size()>ma.a){
				ma={tt[x].size(),x};
			}
			xx.pb(x);
		}
		else{
			
		}
	}
	for(auto j:xx){
		if(j!=ma.b){
			for(auto ii:tt[j]){
				tt[ma.b].insert(ii);
			}
		}
	}
	if(tt[ma.b].find(no)!=tt[ma.b].end()){
		tt[ma.b].erase(no);
	}
	for(auto j:ss[no]){
		tt[ma.b].insert(j);
	}

	if(yy==1){
		if(tt[ma.b].size()>1){
			ans[ma.b]=-1;
		}
		else{
			ans[ma.b]=*(tt[ma.b].begin());
		}
	}

	
	return ma.b;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			adj[i].clear();

		}
		for(int i=0;i<m;i++){
			int aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].pb(bb);
		}
		int st=0;
		for(int ii=0;ii<100;ii++){
			int x=rng()%n;
			for(int i=0;i<n;i++){
				vis[i]=0;
				ans[i]=0;
				ss[i].clear();
				tt[i].clear();
			}
			cot=0;

			dfs(x);
			if(cot==1){
				continue;
			}
			st=1;
			for(int i=0;i<n;i++){
				vis[i]=0;
			}
			ans[x]=1;
			ord.clear();
			dfs2(x);
			for(auto i:ord){
				if(i!=x){
					if(ans[i]==-1){
						continue;
					}
					ans[i]=ans[ans[i]];
				}
			}
			vector<int> ans2;
			for(int i=0;i<n;i++){
				if(ans[i]==1){
					ans2.pb(i+1);
				}
			}
			if(ans2.size()*5>=n){
				for(auto j:ans2){
					cout<<j<<" ";
				}
				cout<<endl;

			}
			else{
				cout<<-1<<endl;
			}

			break;
			

		}
		if(st==0){
			cout<<-1<<endl;
		}

	}











	return 0;
}