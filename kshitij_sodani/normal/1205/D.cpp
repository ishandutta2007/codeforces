#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;

int n;
vector<int> adj[1001];
int ss[1001];
void dfs(int no,int par=-1){
	ss[no]=1;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			ss[no]+=ss[j];
		}
	}
}
int find(int no,int par=-1){
	for(auto j:adj[no]){
		if(j!=par){
			if(ss[j]>(n/2)){
				return find(j,no);
			}
		}
	}
	return no;
}
vector<int> val;
int lev[1001];
int vis[1001];
void dfs2(int no,int par=-1){
	int x=val.back();
	val.pop_back();

	lev[no]=x;
	if(par!=-1){
		x-=lev[par];
	}
	
	if(par>=0){
		cout<<no+1<<" "<<par+1<<" "<<x<<endl;
	}
	for(auto j:adj[no]){
		if(j!=par and vis[j]){
			dfs2(j,no);
		}
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	if(n==1){
		return 0;
	}
	dfs(0);
	int x=find(0);
	vector<pair<int,int>> xx;
	dfs(x);
	for(auto j:adj[x]){
		xx.pb({ss[j],j});
	}
	sort(xx.begin(),xx.end());
	reverse(xx.begin(),xx.end());
	vector<int> aa;
	vector<int> bb;
	int su=0;
	int st=0;
	for(auto j:xx){
		if(su>=((n-1)/3)){
			st=1;	
		}
		if(st==0){
			su+=j.a;
		}
		if(st==0){
			aa.pb(j.b);
		}
		else{
			bb.pb(j.b);
		}
	}
	for(int i=0;i<n;i++){
		vis[i]=1;
	}
	for(auto j:bb){
		vis[j]=0;
	}
	val.pb(0);
	for(int i=0;i<su;i++){
		val.pb(i+1);
	}

	reverse(val.begin(),val.end());
	dfs2(x);
	/*for(auto j:aa){
		cout<<j<<",";
	}
	cout<<endl;
	for(auto j:bb){
		cout<<j<<",";
	}
	cout<<endl;*/

	for(int i=0;i<n;i++){
		vis[i]=1;
	}
	for(auto j:aa){
		vis[j]=0;
	}
	val.clear();
	val.pb(0);
	for(int i=0;i<n-1-su;i++){
		val.pb((su+1)*(i+1));
	}
	reverse(val.begin(),val.end());
	dfs2(x);









	return 0;
}