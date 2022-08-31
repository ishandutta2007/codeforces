#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
int st[100001];
int endd[100001];
int par3[100001];
int lev[100001];
int par[100001][20];
vector<pair<int,int>> adj[100001];
int ww[100001];
int co=0;
int find(int no){
	if(par3[no]==no){
		return no;
	}
	par3[no]=find(par3[no]);
	return par3[no];
}
int ind[100001];
int ans[100001];
void dfs(int no,int par2=-1,int levv=0){
	lev[no]=levv;
	st[no]=co;
	par[no][0]=par2;
	ind[st[no]]=no;
	co++;
	for(auto j:adj[no]){
		if(j.a!=par2){
			ww[j.a]=j.b;
			dfs(j.a,no,levv+1);
		}
	}
	endd[no]=co-1;
}
int lca(int aa,int bb){
	if(lev[aa]>lev[bb]){
		swap(aa,bb);
	}
	int kk=lev[bb]-lev[aa]-1;
	for(int j=19;j>=0;j--){
		if(kk&(1<<j)){
			bb=par[bb][j];
		}
	}
	return bb;

}
int pre[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		par3[i]=i;
	}
	vector<pair<pair<int,int>,int>> ss;
	for(int i=0;i<m;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		int x=find(aa);
		int y=find(bb);
		if(x!=y){
			par3[x]=y;
			adj[aa].pb({bb,i});
			//cout<<aa<<":"<<bb<<endl;
			adj[bb].pb({aa,i});
		}
		else{
			ss.pb({{aa,bb},i});
		}
	}
	dfs(0);
	for(int j=1;j<20;j++){
		for(int i=0;i<n;i++){
			if(par[i][j-1]==-1){
				par[i][j]=-1;
				continue;
			}
			par[i][j]=par[par[i][j-1]][j-1];
		}
	}

	for(auto j:ss){
		int aa=j.a.a;
		int bb=j.a.b;
		int i=j.b;
		if(st[aa]>st[bb]){
			swap(aa,bb);
		}
		//cout<<aa<<":"<<bb<<":"<<i<<endl;
		if(st[aa]<=st[bb] and endd[bb]<=endd[aa]){
			int x=lca(aa,bb);
			//cout<<x<<":"<<endl;
			if(ww[bb]<i){
				pre[st[bb]]++;
				pre[endd[bb]+1]--;
			}
			if(ww[x]<i){
				pre[0]++;
				pre[st[x]]--;
				pre[endd[x]+1]++;

			}
		}
		else{
			if(ww[aa]<i){
				pre[st[aa]]++;
				pre[endd[aa]+1]--;
				

			}
			if(ww[bb]<i){
				pre[st[bb]]++;
				pre[endd[bb]+1]--;
				
				
			}

		}
	}
	for(int i=1;i<=n;i++){
		pre[i]+=pre[i-1];
	}
	for(int i=0;i<n;i++){
		if(pre[i]==ss.size()){
			ans[ind[i]]=1;
		}
	}

	for(int i=0;i<n;i++){
		cout<<ans[i];
	}
	cout<<endl;





	return 0;
}