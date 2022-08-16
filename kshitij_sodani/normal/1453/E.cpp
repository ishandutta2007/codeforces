//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int par[200001];
set<int> adj[200001];
int ma[200001];
//vector<int> ord;
int ans=0;
/*void dfs(int no,int par2=-1,int ba=-1,int levv=0){
	par[no]=par2;
	adj[no].erase(par2);
	if(ba!=-1){
		ans=max(ans,levv-ba+1);
	}
	else{
		ans=max(ans,levv);
	}
	ma[no]-le
	if(adj[no].size()){
		auto jj=adj[no].end();
		jj--;
		int k=*jj;
		for(auto j:adj[no]){
			if(j!=par2){
				if(j!=k){
					dfs(j,no,levv+1,levv+1);
				}
				else{
					dfs(j,no,ba,levv+1);
				}
			}
		}
	}
}*/
int n;
void dfs(int no,int par2=-1,int levv=0){
	par[no]=par2;

	if(adj[no].size()==1 and levv>0){
		ma[no]=levv;
		return;
	}
	else{
		ma[no]=n;
	}
	vector<int> ss;
	for(auto j:adj[no]){
		if(j!=par2){
			
			dfs(j,no,levv+1);
			ss.pb(ma[j]);
			ma[no]=min(ma[j],ma[no]);
		}
	}
	sort(ss.begin(),ss.end());
	deque<int> tt;
	for(auto j:ss){
		tt.pb(j);
	}
	vector<int> cur;
	llo cot=0;
	for(auto j:ss){
		cot++;
		if(no==0 and cot==ss.size()){
			ans=max(ans,j-levv);
			continue;
		}
		ans=max(ans,j-levv+1);
	}
	/*cout<<no<<"::"<<endl;
	for(auto j:ss){
		cout<<j<<",";
	}
	cout<<endl;*/
	/*while(tt.size()){

		cur.pb(tt.back());
		tt.pop_back();
		if(tt.size()){
			cur.pb(tt.front());
			tt.pop_front();
		}
	}
	for(int i=0;i<cur.size()-1;i++){
		ans=max(ans,cur[i]+cur[i+1]-2*levv);
	}*/
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		//=
		cin>>n;
		ans=0;
		for(int i=0;i<n;i++){
			adj[i].clear();
		}
		for(int i=0;i<n-1;i++){
			int aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].insert(bb);
			adj[bb].insert(aa);
		}
		dfs(0);
		ans=max(ans,ma[0]);
		cout<<ans<<endl;
	}






 
 
	return 0;
}