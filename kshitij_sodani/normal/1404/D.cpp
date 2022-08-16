
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n' 

llo n;
vector<llo> adj[1000001];
llo vis[1000001];
llo vis2[1000001];

vector<llo> pp;
void dfs(llo no){
	vis[no]=1;
	pp.pb(no);
	for(auto j:adj[no]){
		if(vis[j]==0){
			dfs(j);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	if(n%2==0){
		cout<<"First"<<endl;
		for(llo i=0;i<2*n;i++){
			cout<<i%n+1<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<"Second"<<endl;
		for(llo i=1;i<=2*n;i++){
			if(i<=n){
				adj[i].pb(i+n);
			}
			else{
				adj[i].pb(i-n);
			}
			llo aa;
			cin>>aa;
			if(vis[aa]==0){
				vis[aa]=i;
			}
			else{
				adj[vis[aa]].pb(i);
				adj[i].pb(vis[aa]);
			}
		}
		for(llo i=1;i<=2*n;i++){
			vis[i]=0;
		}
		llo su=0;
		for(llo i=1;i<=2*n;i++){
			if(vis[i]==0){
				pp.clear();

				dfs(i);
				/*for(auto j:pp){
					cout<<j<<",";
				}
				cout<<endl;*/
				for(llo j=0;j<pp.size();j+=2){
					su+=pp[j];
					vis2[pp[j]]=1;
				}
			}
		}
		if(su%(2*n)!=0){
			for(llo i=1;i<=2*n;i++){
				vis2[i]=1-vis2[i];
			}
		}
		for(llo i=1;i<=2*n;i++){
			if(vis2[i]==1){
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}