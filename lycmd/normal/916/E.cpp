#include<bits/stdc++.h>
#define int long long
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
int const N=400010,B=19;
int n,q,m,rt,a[N],in[N],out[N],v[N],tr[N],lt[N],
	f[N][B],dep[N];
vector<int>e[N];
void update(int x){
	tr[x]=tr[ls(x)]+tr[rs(x)];
}
void add(int x,int k,int d){
	tr[x]+=k*d,lt[x]+=k;
}
void download(int x,int l,int r){
	int&t=lt[x],mid=(l+r)>>1;
	if(!t)return;
	add(ls(x),t,mid-l+1),add(rs(x),t,r-mid);
	t=0;
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
void modify(int x,int l,int r,int ql,int qr,int k){
	if(ql<=l&&r<=qr){
		add(x,k,r-l+1);
		return;
	}
	download(x,l,r);
	int mid=(l+r)>>1;
	if(ql<=mid)modify(ls(x),l,mid,ql,qr,k);
	if(qr>mid)modify(rs(x),mid+1,r,ql,qr,k);
	update(x);
}
int query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)
		return tr[x];
	download(x,l,r);
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)res+=query(ls(x),l,mid,ql,qr);
	if(qr>mid)res+=query(rs(x),mid+1,r,ql,qr);
	return res;
}
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	for(int i=1;;i++)
		if(!(f[x][i]=f[f[x][i-1]][i-1]))
			break;
	v[in[x]=++m]=a[x];
	for(int y:e[x])
		if(y^fa)dfs(y,f[y][0]=x);
	out[x]=m;
}
int intr(int x,int y){
	return in[y]<=in[x]&&in[x]<=out[y];
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=B-1;~i;i--)
		if(dep[f[x][i]]>=dep[y])
			x=f[x][i];
	if(x==y)return x;
	for(int i=B-1;~i;i--)
		if(f[x][i]^f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int jump(int x,int y){
	for(int i=B-1;~i;i--)
		if(y>>i&1)x=f[x][i];
	return x;
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
		int op,x,y,k;
		cin>>op>>x;
		switch(op){
			case 1:rt=x;break;
			case 2:{
				cin>>y>>k;
				int a=lca(x,y);
				if(!intr(rt,a))
					modify(1,1,n,in[a],out[a],k);
				else{
					modify(1,1,n,1,n,k);
					int p1=lca(rt,x),p2=lca(rt,y),
						p=dep[p1]<dep[p2]?p2:p1;
					if(p^rt)
						p=jump(rt,dep[rt]-dep[p]-1),
						modify(1,1,n,in[p],out[p],-k);
				}
				break;
			}
			case 3:{
				if(!intr(rt,x))
					cout<<query(1,1,n,in[x],out[x])<<"\n";
				else if(rt==x)
					cout<<tr[1]<<"\n";
				else
					x=jump(rt,dep[rt]-dep[x]-1),
					cout<<tr[1]-query(1,1,n,in[x],out[x])<<"\n";
				break;
			}
		}
	}
}