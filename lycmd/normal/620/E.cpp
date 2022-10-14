#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=2333333;
int n,q,cur,a[N],id[N],seq[N],sz[N],tr[N],lt[N];
vector<int>e[N];
void dfs(int x,int fa){
	sz[x]=1,id[x]=++cur,seq[cur]=a[x];
	for(int y:e[x])
		if(y^fa)
			dfs(y,x),sz[x]+=sz[y];
}
void update(int x){
	tr[x]=tr[ls(x)]|tr[rs(x)];
}
void download(int x){
	int&t=lt[x];
	if(!t)return;
	tr[ls(x)]=tr[rs(x)]=1ll<<t;
	lt[ls(x)]=lt[rs(x)]=t;
	t=0;
}
void build(int x,int l,int r){
	if(l==r){
		tr[x]=1ll<<seq[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void cover(int x,int l,int r,int ql,int qr,int k){
	if(ql<=l&&r<=qr){
		tr[x]=1ll<<k,lt[x]=k;
		return;
	}
	download(x);
	int mid=(l+r)>>1;
	if(ql<=mid)cover(ls(x),l,mid,ql,qr,k);
	if(qr>mid)cover(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
int query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return tr[x];
	download(x);
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)res|=query(ls(x),l,mid,ql,qr);
	if(qr>mid)res|=query(rs(x),mid+1,r,ql,qr);
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0),build(1,1,n);
	while(q--){
		int op,x,y;cin>>op>>x;
		if(op<2){
			cin>>y,cover(1,1,n,id[x],id[x]+sz[x]-1,y);
		}else{
			cout<<__builtin_popcountll
				(query(1,1,n,id[x],id[x]+sz[x]-1))<<"\n";
		}
	}
}