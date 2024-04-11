#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo t;
llo aa[100001];
llo bb[100001];
llo co=0;
llo vis[100001];
vector<llo> adj[100001];
void dfs(llo no){
	vis[no]=1;
	co++;
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
		llo n;
		cin>>n;
		deque<llo> ss;
		for(llo i=0;i<n;i++){
			ss.pb(i+1);
		}
		for(llo i=0;i<n;i++){
			cin>>aa[i];
			aa[i]--;
			adj[i].clear();
		}
		for(llo i=0;i<n;i++){
			cin>>bb[i];
			bb[i]--;
			adj[aa[i]].pb(bb[i]);
			adj[bb[i]].pb(aa[i]);
			vis[i]=0;
		}

		llo ans=0;
		for(llo i=0;i<n;i++){
			if(vis[i]==0){
				co=0;
				dfs(i);
				if(co>1){
					llo xx=co/2;
				//	cout<<co<<":"<<endl;
					for(llo j=0;j<xx;j++){
						ans-=ss.front();
						ss.pop_front();
						ans+=ss.back();
						ss.pop_back();
					}
				}
			}
		}

		ans*=2;

		cout<<ans<<endl;




	}







	return 0;
}