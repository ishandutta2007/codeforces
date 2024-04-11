#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=400010;
int n,q,r,tot,tr[N],a[N],v[N],top[N],dep[N],f[N],sz[N],hs[N],id[N];
vector<int>e[N],w[N];
vector<pair<int,int> >edge;
string op;
inline void update(int x){
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
inline void build(int x,int l,int r){
	if(l==r){
		tr[x]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	update(x);
}
inline void modifypoint(int x,int l,int r,int p,int k){
	if(l==r){
		tr[x]=k;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)modifypoint(ls(x),l,mid,p,k);
	else modifypoint(rs(x),mid+1,r,p,k);
	update(x);
}
inline int query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return tr[x];
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)
		res+=query(ls(x),l,mid,ql,qr);
	if(qr>mid)
		res+=query(rs(x),mid+1,r,ql,qr);
	return res;
}
inline void dfs1(int x,int fa,int d){
	dep[x]=d,sz[x]=1;
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		if(y^fa){
			dfs1(y,f[y]=x,d+1),v[y]=w[x][i],sz[x]+=sz[y];
			if(!hs[x]||sz[y]>sz[hs[x]])
				hs[x]=y;
		}
	}
}
inline void dfs2(int x,int tp){
	a[id[x]=++tot]=v[x],top[x]=tp;
	if(!hs[x])
		return;
	dfs2(hs[x],tp);
	for(int y:e[x])
		if(y^f[x]&&y^hs[x])
			dfs2(y,y);
}
inline void modifynode(int x,int k){
	if(dep[edge[x].first]<dep[edge[x].second])
		modifypoint(1,1,n,id[edge[x].second],k);
	else
		modifypoint(1,1,n,id[edge[x].first],k);
}
inline int querychain(int x,int y){
	int res=0;
	for(;top[x]^top[y];x=f[top[x]]){
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		res+=query(1,1,n,id[top[x]],id[x]);
	}
	if(dep[x]>dep[y])
		swap(x,y);
	res+=query(1,1,n,id[x]+1,id[y]);
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n,edge.push_back({0,0});
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
		w[x].push_back(1);
		w[y].push_back(1);
		edge.push_back({x,y});
	}
	dfs1(1,0,1),dfs2(1,1),build(1,1,n);
	for(cin>>q;q--;){ 
		int op,x,y;
		switch(cin>>op,op){
			case 1:
				cin>>x,modifynode(x,1);
				break;
			case 2:
				cin>>x,modifynode(x,N);
				break;
			case 3:{
				cin>>x>>y;
				int res=querychain(x,y);
				cout<<(res>=N?-1:res)<<"\n";
				break;
			}
		}
	}
}