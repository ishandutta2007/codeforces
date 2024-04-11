//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo mod=1e9+7;
llo t;
vector<llo> adj[100001];
llo ss[100001];
vector<llo> ee;
llo n;
void dfs(llo no,llo par=-1){
	ss[no]=1;

	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			ss[no]+=ss[j];
		}
	}
	if(no!=0){
		ee.pb(ss[no]*(n-ss[no]));
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		
		cin>>n;
		for(llo i=0;i<n;i++){
			adj[i].clear();
		}
		ee.clear();
		for(llo i=0;i<n-1;i++){
			llo aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].pb(bb);
			adj[bb].pb(aa);
		}
		dfs(0);
		sort(ee.begin(),ee.end());
		vector<llo> cc;
		llo ff;
		cin>>ff;
		if(ff<n-1){
			for(llo i=0;i<n-1-ff;i++){
				cc.pb(1);
			}
		}
		for(llo i=0;i<ff;i++){
			llo x;
			cin>>x;
			cc.pb(x);
		}
		sort(cc.begin(),cc.end());
			while(cc.size()>n-1){
				cc[cc.size()-2]=(cc.back()*cc[cc.size()-2])%mod;
				cc.pop_back();
			}
			llo ans=0;
			for(llo i=0;i<n-1;i++){
				ans=(ans+cc[i]*ee[i])%mod;
			}

				cout<<ans<<endl;

	}


 
 
	return 0;
}