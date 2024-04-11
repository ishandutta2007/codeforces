
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

vector<llo> adj[100001];
llo ans[100001];
llo vis[100001];

llo ss[100001];
void dfs(llo no,llo par=-1){
	llo su=0;
	ss[no]=0;
	vector<pair<int,int>> tt;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			tt.pb({ss[j],j});
		}
	}
	if(tt.size()){
		ss[no]+=ss[tt[0].b];
	}
	for(int j=1;j<tt.size();j++){
		if(tt[j].a!=tt[0].a){
			vis[tt[j].b]+=1;
			ss[no]-=ss[tt[j].b];
		}
		else{
			ss[no]+=ss[tt[j].b];
		}
	}
	if(tt.size()==0){
		ans[no]=1;
	}
	else if(no==0){
		ans[no]=-(tt[0].a*(llo)tt.size());
	}
	else{
		ans[no]=((llo)tt.size()+1)*(-tt[0].a);
	}
	ss[no]+=ans[no];

}
void dfs2(int no,int par=-1,int col=0){
	col^=vis[no];
	if(col==1){
		ans[no]=-ans[no];
	}
	for(auto j:adj[no]){
		if(j!=par){
			dfs2(j,no,col);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			adj[i].clear();
			vis[i]=0;
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
		dfs2(0);
		for(llo i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;




	}






	return 0;
}