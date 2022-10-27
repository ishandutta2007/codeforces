#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


llo t;
llo it[200001];
vector<int> adj[200001];
llo dp[200001][82];
map<pair<int,int>,int> ss;
vector<int> pre[200001];
llo ind=0;

llo n,k;
void dfs(llo no){
	if(no==0){
		pre[no].pb(k);
	}
	llo x=adj[no].size();
	for(llo j=0;j<pre[no].size();j++){
		ss[{no,pre[no][j]}]=j;
		dp[no][j]=it[no]*pre[no][j];
	}
	set<int> xx;
	if(x>1){
		for(auto i:pre[no]){
			xx.insert((i/x));
			xx.insert((i+x-1)/x);
		}
	}
	for(auto j:adj[no]){
		
		if(x>1){
			
			for(auto i:xx){
				pre[j].pb(i);
			}
		}
		else{
			for(auto i:pre[no]){
				pre[j].pb(i);
			}
		}
		dfs(j);
	}
	if(x!=0){
		vector<llo> tt;
		for(llo i=0;i<pre[no].size();i++){
			llo aa=pre[no][i]/x;
			llo bb=(pre[no][i]+x-1)/x;
			llo z=pre[no][i]%x;
			//zz is number of bb
			
			tt.clear();
			for(auto j:adj[no]){
				llo za=dp[j][ss[{j,aa}]];
				dp[no][i]+=za;
				tt.pb(dp[j][ss[{j,bb}]]-za);
			}
			sort(tt.begin(),tt.end());
			reverse(tt.begin(),tt.end());
			for(llo j=0;j<z;j++){
				dp[no][i]+=tt[j];
			}
		}
	}
	/*if(x==0){
		for(llo i=0;i<ind;i++){
			llo aa=tt[i]/x;
			llo bb=(tt[i]+x-1)/x;
			llo z=tt[i]%x;
			//zz is number of bb
			llo x=ss[aa];
			llo y=ss[bb];
			vector<llo> tt;
			for(auto j:adj[no]){
				dp[no][i]+=dp[j][x];
				tt.pb(dp[j][y]-dp[j][x]);
			}
			sort(tt.begin(),tt.end());
			reverse(tt.begin(),tt.end());
			for(llo j=0;j<zz;j++){
				dp[no][i]+=tt[j];
			}
		}
	}*/
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		
		cin>>n>>k;
		for(llo i=0;i<n;i++){
			adj[i].clear();
			pre[i].clear();
		}
		for(llo i=1;i<n;i++){
			llo aa;
			cin>>aa;
			aa--;
			adj[aa].pb(i);
		}
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		ss.clear();
		dfs(0);
		cout<<dp[0][ss[{0,k}]]<<endl;
	}






	return 0;
}