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
pair<int,int> bb;
vector<int> kk[2];
void dfs(int no,int par2=-1,int levv=0){
	par[no]=par2;
	vis[no]=1;
	kk[levv%2].pb(no);

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
				if(lev[no]-lev[j]<=k-1){
					aa={no,j};
				}
				else{
					bb={no,j};
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int ac,bc;
		cin>>ac>>bc;
		adj[ac-1].pb(bc-1);
		adj[bc-1].pb(ac-1);
	}
	aa={-1,-1};
	bb={-1,-1};
	dfs(0);

	swap(aa.a,aa.b);
	swap(bb.a,bb.b);

	if(aa.a!=-1){
		cout<<2<<endl;
		int no=aa.b;
		int co=0;
		vector<int> kk;
		while(true){
			co+=1;
			kk.pb(no);
			if(no==aa.a){
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
	else if(bb.a!=-1){
		cout<<1<<endl;
		int ap=0;
		int no=bb.b;
		int tt=0;
	//	cout<<bb.a<<","<<bb.b<<endl;
		while(true){
			ap=(ap+1)%2;
			if(ap==1){
				tt+=1;
				cout<<no+1<<" ";
				if(tt==(k+1)/2){
					break;
				}
			}
			if(no==bb.a){
				break;
			}
			no=par[no];
		}
		cout<<endl;
	}
	else{
		if(kk[0].size()<kk[1].size()){
			swap(kk[0],kk[1]);
		}
		cout<<1<<endl;
		for(int i=0;i<(k+1)/2;i++){
			cout<<kk[0][i]+1<<" ";
		}
		cout<<endl;
	}
	


	return 0;
}