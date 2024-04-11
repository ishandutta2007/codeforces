//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int par[300001];
vector<pair<int,int>> adj[300001];
int find(int i){
	if(par[i]==i){
		return i;
	}
	par[i]=find(par[i]);
	return par[i];
}
vector<int> ss;
vector<int> tt;
vector<int> ee;
vector<int> ff;
int req;
int ans[300001];
void dfs(int no,int par=-1){
	//ss.pb(no);
	ee.pb(no);
	if(no==req){
		tt=ss;
		ff=ee;
	}

	for(auto j:adj[no]){
		if(j.a!=par){
			ss.pb(j.b);
			dfs(j.a,no);
			ss.pop_back();
		}
	}
	ee.pop_back();
}
int ans2=0;
void dfs2(int no,int par=-1,int val=0){
	int co=0;
	for(auto j:adj[no]){
		if(j.a!=par){
			if(ans[j.b]==1){
				co++;

			}
			if(ans[j.b]==1){
				dfs2(j.a,no,1);
			}
			else{
				dfs2(j.a,no,0);
			}
		}
	}
	if(co>0){
		if(val==1){
			ans2+=((co-1)+1)/2;
		}
		else{
			ans2+=(co+1)/2;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		par[i]=i;
	}
	int co=0;
	for(int i=0;i<m;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		int x=find(aa);
		int y=find(bb);
		if(par[x]!=par[y]){
			par[x]=par[y];
			adj[aa].pb({bb,co});
			adj[bb].pb({aa,co});
			//cout<<aa<<":"<<bb<<endl;
			co++;
		}
	}
	int q;
	cin>>q;
	vector<vector<int>> ans3;
	for(int i=0;i<q;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		req=bb;
		dfs(aa);
	/*	for(auto j:tt){
			cout<<j<<",";
		}
		cout<<endl;*/
		for(auto j:tt){
			ans[j]^=1;
		}
		ans3.pb(ff); 
	}
/*	for(int i=0;i<n-1;i++){
		cout<<ans[i]<<":";
	}
	cout<<endl;*/
	dfs2(0);
	if(ans2>0){
		cout<<"NO"<<endl;
		cout<<ans2<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(auto j:ans3){
		cout<<j.size()<<endl;
		for(auto i:j){
			cout<<i+1<<" ";
		}
		cout<<endl;
	}
	//cout<<ans2<<endl;
 
 
 

 
	return 0;
}