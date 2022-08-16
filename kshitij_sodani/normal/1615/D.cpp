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
vector<pair<llo,llo>> adj[200001];
vector<pair<llo,llo>> adj2[200001];

llo val[200001];
llo st=1;
void dfs(llo no){
	for(auto j:adj[no]){
		if(val[j.a]==-1){
			val[j.a]=(j.b^val[no]);
			dfs(j.a);

		}
		else if(val[j.a]!=(j.b^val[no])){
			st=0;
		}
	}
}
void dfs2(llo no,llo par=-1){


	for(auto j:adj2[no]){
		if(j.a!=par){
			if(j.b>=0){
				cout<<no+1<<" "<<j.a+1<<" "<<j.b<<endl;
			}
			else{
				if(val[no]==val[j.a]){
					cout<<no+1<<" "<<j.a+1<<" "<<0<<endl;
				}
				else{
					cout<<no+1<<" "<<j.a+1<<" "<<1<<endl;
				}
			}
			dfs2(j.a,no);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		st=1;
		for(llo i=0;i<n;i++){
			adj[i].clear();
			adj2[i].clear();
			val[i]=-1;
		}
		for(llo i=0;i<n-1;i++){
			llo aa,bb,cc;
			cin>>aa>>bb>>cc;
			aa--;
			bb--;
			llo dd=cc;
			if(cc!=-1){
				cc=(__builtin_popcount(cc))%2;
				adj[aa].pb({bb,cc});
				adj[bb].pb({aa,cc});
			}
				adj2[aa].pb({bb,dd});
				adj2[bb].pb({aa,dd});
			
		}
		for(llo i=0;i<m;i++){
			llo aa,bb,cc;
			cin>>aa>>bb>>cc;
			aa--;
			bb--;
			adj[aa].pb({bb,cc});
			adj[bb].pb({aa,cc});
		}

		for(llo i=0;i<n;i++){
			if(val[i]==-1){
				val[i]=0;
				dfs(i);
			}
		}
		if(st==0){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		dfs2(0);
		
	}






 
	return 0;
}