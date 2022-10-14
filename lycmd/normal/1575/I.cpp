#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=400010;
int n,q,cur,a[N],sz[N],id[N],v[N],fa[N],hs[N],dep[N],top[N],tr[N];
vector<int>e[N];
void dfs1(int x,int pre){
	sz[x]=1;
	for(int y:e[x]){
		if(y==pre)continue;
		dep[y]=dep[x]+1,dfs1(y,fa[y]=x),sz[x]+=sz[y];
		if(!hs[x]||sz[hs[x]]<sz[y])
			hs[x]=y;
	}
}
void dfs2(int x,int tp){
	top[x]=tp,id[x]=++cur,v[cur]=abs(a[x]);
	if(!hs[x])return;
	dfs2(hs[x],tp);
	for(int y:e[x])
		if(y^fa[x]&&y^hs[x])
			dfs2(y,y);
}
void update(int x){
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
void build(int x,int l,int r){
	if(l==r){
		tr[x]=v[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
void modify(int x,int l,int r,int p,int k){
	if(l==r){
		tr[x]=abs(k);
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)modify(ls(x),l,mid,p,k);
	else modify(rs(x),mid+1,r,p,k);
	update(x);
}
int query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return tr[x];
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)res+=query(ls(x),l,mid,ql,qr);
	if(qr>mid)res+=query(rs(x),mid+1,r,ql,qr);
	return res;
}
int querychain(int x,int y){
	int res=-query(1,1,n,id[x],id[x])-query(1,1,n,id[y],id[y]);
	for(;top[x]^top[y];x=fa[top[x]]){
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		res+=2*query(1,1,n,id[top[x]],id[x]);
	}
	if(id[x]>id[y])
		swap(x,y);
	res+=2*query(1,1,n,id[x],id[y]);
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
	dfs1(1,0),dfs2(1,1),build(1,1,n);
	while(q--){
		int op,x,y;cin>>op>>x>>y;
		if(op<2)
			modify(1,1,n,id[x],y);
		else
			cout<<querychain(x,y)<<"\n";
	}
}