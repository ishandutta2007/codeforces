#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
int st[200001];
int endd[200001];
int par3[200001];
int lev[200001];
int par[200001][20];
vector<pair<int,int>> adj[200001];
int ww[200001];
int co=0;

int ind[200001];
void dfs(int no,int par2=-1,int levv=0){
	lev[no]=levv;
	st[no]=co;
	par[no][0]=par2;
	ind[st[no]]=no;
	co++;
	for(auto j:adj[no]){
		if(j.a!=par2){
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
pair<int,int> tree[4*200001];
int lazy[4*200001];
void build(int no,int l,int r){
	tree[no]={0,r-l+1};
	if(l<r){
		int mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
	}
}
void push(int no,int l,int r){
	tree[no].a+=lazy[no];
	if(l<r){
		lazy[no*2+1]+=lazy[no];
		lazy[no*2+2]+=lazy[no];
	}
	lazy[no]=0;
}

void update(int no,int l,int r,int aa,int bb,int x){
	push(no,l,r);
	
	if(r<aa or l>bb or aa>bb){
		return ;
	}
	if(aa<=l and r<=bb){
		lazy[no]=x;
		push(no,l,r);
	}
	else{
		int mid=(l+r)/2;
		update(no*2+1,l,mid,aa,bb,x);
		update(no*2+2,mid+1,r,aa,bb,x);
		tree[no]=tree[no*2+1];
		if(tree[no].a<tree[no*2+2].a){
			tree[no]=tree[no*2+2];
		}
		else if(tree[no].a==tree[no*2+2].a){
			tree[no].b+=tree[no*2+2].b;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n,m;
	cin>>n>>m;

	vector<pair<pair<int,int>,int>> ss;
	for(int i=0;i<n-1+m;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
	
		if(i<n-1){
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
 	set<pair<int,int>> tt;
 	build(0,0,n-1);
 	int ac=0;
	for(auto j:ss){
		int aa=j.a.a;
		int bb=j.a.b;
		if(aa>bb){
			swap(aa,bb);
		}
		int y=1;
		if(tt.find({aa,bb})==tt.end()){
			tt.insert({aa,bb});

			ac++;
		}
		else{
			y=-1;
			tt.erase({aa,bb});
				ac--;
		}
		int i=j.b;
		if(st[aa]>st[bb]){
			swap(aa,bb);
		}
		//cout<<aa<<":"<<bb<<":"<<i<<endl;
		if(st[aa]<=st[bb] and endd[bb]<=endd[aa]){
			int x=lca(aa,bb);
			//cout<<x<<":"<<endl;
			update(0,0,n-1,st[bb],endd[bb],y);
			update(0,0,n-1,0,n-1,y);
			update(0,0,n-1,st[x],endd[x],-y);
			//if(ww[bb]<i){
				/*pre[st[bb]]++;
				pre[endd[bb]+1]--;*/
			//}
			//if(ww[x]<i){
			/*	pre[0]++;
				pre[st[x]]--;
				pre[endd[x]+1]++;*/
 
			//}
		}
		else{
			update(0,0,n-1,st[aa],endd[aa],y);
			update(0,0,n-1,st[bb],endd[bb],y);
			/*if(ww[aa]<i){
				pre[st[aa]]++;
				pre[endd[aa]+1]--;
				
 
			}
			if(ww[bb]<i){
				pre[st[bb]]++;
				pre[endd[bb]+1]--;
				
				
			}*/
 
		}
		if(tree[0].a==ac){
			cout<<tree[0].b<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}

 
 
	return 0;
}