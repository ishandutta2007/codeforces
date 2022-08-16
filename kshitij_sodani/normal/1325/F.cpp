#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
int n,m,k;
int st[100001];
int vis[100001];
int par[100001];
vector<int> adj[100001];
int co=0;
int lev[100001];
pair<int,int> aa;
vector<int> kk[100000];
int cc;
void dfs(int no,int par2=-1,int levv=0){
	par[no]=par2;
	vis[no]=1;
	kk[(levv)%(cc-1)].pb(no);
	co+=1;	
	st[no]=co;
	lev[no]=levv;
	for(auto j:adj[no]){
		if(j==par2){
			continue;
		}
		if(vis[j]==0){
			dfs(j,no,levv+1);
		}
		else{
			if(st[j]<st[no]){
				if(lev[no]-lev[j]>=cc-1){
					aa={no,j};
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	cc=0;
	for(int i=1;i<1000;i++){
		if(i*i<n){
			cc=max(cc,i+1);
		}
		else if(i*i==n){
			cc=max(cc,i);
		}
	}

	for(int i=0;i<m;i++){
		int ac,bc;
		cin>>ac>>bc;
		adj[ac-1].pb(bc-1);
		adj[bc-1].pb(ac-1);
	}
	aa={-1,-1};
	dfs(0);
	if(aa.a!=-1){
		cout<<2<<endl;
		int no=aa.a;
		vector<int> kk;
		while(true){
			kk.pb(no);
			if(no==aa.b){
				break;
			}
			no=par[no];
		}
		cout<<kk.size()<<endl;
		for(auto j:kk){
			cout<<j+1<<" ";
		}
		cout<<endl;
	}
	else{
		cout<<1<<endl;
		int ma=0;
		int ind=0;
		for(int i=0;i<n;i++){
			if(kk[i].size()>ma){
				ma=kk[i].size();
				ind=i;
			}
		}

		for(int i=0;i<cc;i++){
		//	cout<<i<<endl;
			cout<<kk[ind][i]+1<<" ";
		}
		cout<<endl;
	}


	


	return 0;
}