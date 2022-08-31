//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo t;
vector<llo> adj[100001];
llo ss[100001];
void dfs(llo no,llo par=-1){
	ss[no]=1;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			ss[no]+=ss[j];
		}
	}
}
const llo mod=998244353;
llo ans[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			adj[i].clear();
		}
		for(llo i=0;i<n-1;i++){
			llo aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].pb(bb);
			adj[bb].pb(aa);
		}
		dfs(0);
		vector<pair<llo,llo>> ss2;
		vector<llo> tt;
		for(llo i=1;i<=n;i++){
			ans[i]=0;
		}
		for(llo i=1;i<n;i++){
			ss2.pb({ss[i]-1,ss[i]});
		}

		for(llo i=1;i<=n-1;i++){
			if((n-1)%i==0){
				tt.pb(i);
			}
			
		}
		reverse(tt.begin(),tt.end());
		for(auto j:tt){
			ans[j]=1;
			for(auto k:ss2){
				llo co=0;
				if((k.a)%j==0){
					co++;
				}
				if((k.b)%j==0){
					co++;
				}

				ans[j]=(ans[j]*co)%mod;
			}
			for(auto i:tt){
				if(i>j){
					if((i%j)==0){
						ans[j]=(ans[j]-ans[i]+mod)%mod;
					}
				}
			}
		}

		for(llo i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;


	}
 
 

 
 
 
	return 0;
}