//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
/*bool solve(llo l,llo r){
	if(l==r){
		return true;
	}
	if(((l%2)==(r%2))){
		return solve(l/2,r/2);
	}
	if((r%2==1)){
		return false;
	}


}*/
vector<llo> adj[1001];
llo vis[10001];
void dfs(llo no){
	vis[no]=1;
	for(auto j:adj[no]){
		if(vis[j]==0){
			dfs(j);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo q;
	cin>>q;
	/*int n=5;
	for(llo i=0;i<(1<<n);i++){
		for(llo j=1;j<(1<<n);j++){
			if((i&j)==j){
				if(i+j<(1<<n)){
					adj[i].pb(i+j);
				}
			}
		}
	}
	for(llo i=0;i<(1<<n);i++){
		for(llo j=0;j<(1<<n);j++){
			vis[j]=0;
		}
		dfs(i);
		cout<<i<<"::";

		for(llo j=0;j<(1<<n);j++){
			if(vis[j]==1){
				for(int jj=0;jj<n;jj++){
					if((1<<jj)&j){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				cout<<",";
				//cout<<j<<",";
			}
		}
		cout<<endl;
	}*/
	while(q--){
		llo u,v;
		cin>>u>>v;
		if(v<u){
			cout<<"NO"<<endl;
		}
		else if(u==v){
			cout<<"YES"<<endl;
		}
		else{
			if(__builtin_popcount(u)<__builtin_popcount(v)){
				cout<<"NO"<<endl;
				continue;
			}
			
			llo ind=0;
			llo ind2=0;
			vector<int> ss;
			vector<int> tt;
			for(llo i=0;i<30;i++){
				if((1LL<<i)&u){
					ind=i;
					ss.pb(i);
				}
				if((1LL<<i)&v){
					tt.pb(i);
					ind2=i;
				}
			}
			int st=0;
			for(int i=0;i<tt.size();i++){
				if(tt[i]<ss[i]){
					st=1;
				}
			}
			if(st==1){
				cout<<"NO"<<endl;
				continue;
			}
			else{
				cout<<"YES"<<endl;
			}

		}

	}


 
	return 0;
}