//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[100001];
vector<llo> adj[100001];
llo x=0;
llo ss[100001];
llo st=1;
llo tt=0;
void dfs(llo no,llo par=-1){
	ss[no]=it[no];
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			ss[no]^=ss[j];
			if(ss[j]==(x^ss[j])){
				st=0;
			}
		}
	}


	
}
void dfs2(int no,int par=-1,int yy=0){
	if(ss[no]==x and tt==1){
		st=0;
	}
	if(ss[no]==x and yy==1){
		st=0;
	}
	//cout<<no<<":"<<ss[no]<<endl;
	if(ss[no]==0){
		yy=1;
	}
	for(auto j:adj[no]){
		if(j!=par){
			dfs2(j,no,yy);
		}
	}
	if(ss[no]==x){
		tt=1;
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		x=0;
		llo xx=1;
		tt=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			x^=it[i];
		/*	if(it[i]!=it[0]){
				xx=0;
			}*/
			adj[i].clear();
		
		}
		st=1;
		/*if(xx==1){
			st=0;
		}*/
		for(llo i=0;i<n-1;i++){
			llo aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].pb(bb);
			adj[bb].pb(aa);
		}
		dfs(0);
		if(k>2){
			dfs2(0);
		}
		if(st==1){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}



 
 
 
	return 0;
}