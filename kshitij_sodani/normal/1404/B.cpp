
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n' 

vector<int> adj[100001];
int n,aa,bb,da,db;
int cur;
pair<int,int> ma={-1,-1};
void dfs(int no,int par=-1,int levv=0){
	if(no==bb){
		cur=levv;
	}
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no,levv+1);
		}
	}
}
void dfs2(int no,int par=-1,int levv=0){
	if(levv>ma.a){
		ma={levv,no};
	}
	for(auto j:adj[no]){
		if(j!=par){
			dfs2(j,no,levv+1);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		
		cin>>n>>aa>>bb>>da>>db;
		aa--;
		bb--;
		for(int i=0;i<n;i++){
			adj[i].clear();
		}
		for(int i=0;i<n-1;i++){
			int cc,dd;
			cin>>cc>>dd;
			cc--;
			dd--;
			adj[cc].pb(dd);
			adj[dd].pb(cc);
		}
		dfs(aa);
		if(cur<=da){
			cout<<"Alice"<<endl;
			continue;
		}
		if(da>db){
			cout<<"Alice"<<endl;
			continue;
		}
	
		ma={-1,-1};
		dfs2(bb);
		int xx=ma.b;
		ma={-1,-1};
		dfs2(xx);


		db=min(db,ma.a);
		if(db>2*da){
			cout<<"Bob"<<endl;
			continue;
		}
		cout<<"Alice"<<endl;
		continue;
/*
		cout<<"Bob"<<endl;
		continue;

*/


	}


	return 0;
}