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
vector<int> adj2[300001];

int co=0;
int st[300001];
int endd[300001];
void dfs2(int no,int par=-1){
	st[no]=co;
	co++;
	for(auto j:adj2[no]){
		if(j!=par){
			dfs2(j,no);
		}
	}
	endd[no]=co-1;
}
int ans=0;
set<pair<int,int>> xx;
void dfs(int no,int par=-1){
	auto j=xx.lower_bound({st[no],endd[no]});
	int stt=0;
	if(j!=xx.end()){
		if((*j).b<=endd[no]){
			stt=1;
		}
	}
	vector<pair<int,int>> yy;
	if(stt==0){
		if(j!=xx.begin()){
			j--;
			if((*j).b>=endd[no]){
				yy.pb((*j));
				xx.erase(j);
			}

		}
		xx.insert({st[no],endd[no]});
	}
	/*cout<<no<<","<<stt<<endl;
	for(auto j:xx){
		cout<<j.a<<":"<<j.b<<endl;
	}
	cout<<endl;*/
	ans=max(ans,(int)xx.size());
	for(auto j:adj[no]){
		dfs(j);
	}
	if(stt==0){
		xx.erase({st[no],endd[no]});
	}
	for(auto j:yy){
		xx.insert(j);
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			adj[i].clear();
			adj2[i].clear();
		}
		for(int i=1;i<n;i++){
			int aa;
			cin>>aa;
			aa--;
			adj[aa].pb(i);
		}
		for(int i=1;i<n;i++){
			int aa;
			cin>>aa;
			aa--;
			adj2[aa].pb(i);
		}
		co=0;
		dfs2(0);
		ans=0;
		dfs(0);
		cout<<ans<<endl;
	}








	return 0;
}