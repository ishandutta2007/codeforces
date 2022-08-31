
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

int n,m,q;
int it[300001];
vector<pair<int,int>> ed;
int par[300001];
int ss[300001];
int find(int no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
int vis[300001];
vector<int> adj[300001];
int co[300001];
void merge(int aa,int bb){
	int x=find(aa);
	int y=find(bb);
	if(x!=y){
		par[x]=y;
		adj[y].pb(x);

		ss[y]+=ss[x];
		co[x]+=1;
	}
}
int cur=0;
int st[300001];
int ind[300001];
void dfs(int no){
	st[no]=cur;
	ind[cur]=no;
	cur++;
	for(auto j:adj[no]){
		dfs(j);
	}
}
pair<int,int> tree[4*300001];
void build(int no,int l,int r){
	if(l==r){
		tree[no]={it[ind[l]],l};
	}
	else{
		int mid=(l+r)/2;
		build(no*2+1,l,mid);
		build(no*2+2,mid+1,r);
		if(tree[no*2+1].a>tree[no*2+2].a){
			tree[no]=tree[no*2+1];
		}
		else{
			tree[no]=tree[no*2+2];
		}
		
	}
}
pair<int,int> query(int no,int l,int r,int aa,int bb){
	if(r<aa or l>bb){
		return {0,0};
	}
	if(aa<=l and r<=bb){
		return tree[no];
	}
	int mid=(l+r)/2;
	pair<int,int> xx=query(no*2+1,l,mid,aa,bb);
	pair<int,int> yy=query(no*2+2,mid+1,r,aa,bb);
	if(xx.a>yy.a){
		return xx;
	}
	return yy;
}
void update(int no,int l,int r,int i){
	if(l==r){
		tree[no]={0,i};
	}
	else{
		int mid=(l+r)/2;
		if(i<=mid){
			update(no*2+1,l,mid,i);
		}
		else{
			update(no*2+2,mid+1,r,i);
		}
		if(tree[no*2+1].a>tree[no*2+2].a){
			tree[no]=tree[no*2+1];
		}
		else{
			tree[no]=tree[no*2+2];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		cin>>it[i];
	}
	for(int i=0;i<m;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		ed.pb({aa,bb});
	}
	for(int i=0;i<n;i++){
		par[i]=i;
		ss[i]=1;
	}	
	vector<pair<int,int>> qq;
	for(int i=0;i<q;i++){
		int aa,bb;
		cin>>aa>>bb;
		bb--;
		qq.pb({aa,bb});
		if(aa==2){
			vis[bb]=1;
		}
	}
	for(int i=0;i<m;i++){
		if(vis[i]==0){
			merge(ed[i].a,ed[i].b);
		}
	}
	vector<pair<int,int>> kk;
	for(int i=q-1;i>=0;i--){
		if(qq[i].a==1){
			kk.pb({find(qq[i].b),ss[find(qq[i].b)]});
		}
		else{
			merge(ed[qq[i].b].a,ed[qq[i].b].b);
		}
	}

	for(int i=0;i<n;i++){
		if(co[i]==0){
			adj[n].pb(i);
		}
	}
	dfs(n);
	reverse(kk.begin(),kk.end());
	build(0,0,n);
	for(auto j:kk){
		pair<int,int> pp={st[j.a],st[j.a]+j.b-1};
		pair<int,int> xx=query(0,0,n,pp.a,pp.b);
		update(0,0,n,xx.b);
		cout<<xx.a<<endl;
	}






	return 0;
}