#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;

llo n,k;
vector<llo> adj[2000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<4*n;i++){
			adj[i].clear();
		}
		for(int i=0;i<n-1;i++){
			int aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].pb(bb);
			adj[bb].pb(aa);
		}
		int nn=n;
		string s;
		cin>>s;
		for(int i=0;i<nn;i++){
			if(s[i]=='W'){
				adj[i].pb(n);
				adj[n].pb(n+1);
				adj[n].pb(n+2);
				adj[n].pb(i);
				adj[n+1].pb(n);
				adj[n+2].pb(n);
				n+=3;
			}
		}
		int st=1;
		int xx=0;
		for(int i=0;i<n;i++){
			if(adj[i].size()>3){
				st=0;
			}
			else if(adj[i].size()==3){
				xx++;
				int co=0;
				for(auto j:adj[i]){
					if(adj[j].size()>1){
						co++;
					}
				}
				if(co>=2){
					st=0;
				}
			}
		}
		if(st==0){
			cout<<"White"<<endl;
			continue;
		}
		if(xx==2){
			if(n>=6){
				if((n-6)%2==1){
					cout<<"White"<<endl;
					continue;
				}
			}

		}
		//else{
			cout<<"Draw"<<endl;
		//}

	}



	return 0;
}