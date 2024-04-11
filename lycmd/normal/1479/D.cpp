#include<bits/stdc++.h>
using namespace std;
int const N=1000010,B=404;
int n,q,cur,a[N],c[N],f[N],in[N],hs[N],bl[N],
	out[N],sz[N],dep[N],seq[N],top[N],ord[N],ans[N],cnt[N];
vector<int>e[N];
struct query{
	int l,r,a,id,ql,qr;
	int operator<(const query&rhs)const{
		return l/B<rhs.l/B||(l/B==rhs.l/B&&r<rhs.r);
	}
}p[N];
void dfs1(int x,int fa){
	f[x]=fa,sz[x]=1,dep[x]=dep[fa]+1,seq[in[x]=++cur]=a[x];
	for(int y:e[x]){
		if(y==fa)continue;
		dfs1(y,x),sz[x]+=sz[y];
		if(!hs[x]||sz[hs[x]]<sz[y])
			hs[x]=y;
	}
	seq[out[x]=++cur]=a[x];
}
void dfs2(int x,int tp){
	top[x]=tp;
	if(!hs[x])return;
	dfs2(hs[x],tp);
	for(int y:e[x])
		if(y^f[x]&&y^hs[x])
			dfs2(y,y);
}
int lca(int x,int y){
	for(;top[x]^top[y];x=f[top[x]])
		if(dep[top[x]]<dep[top[y]])swap(x,y);
	return dep[x]<dep[y]?x:y;
}
void upd(int x){
	if(cnt[seq[x]]^=1)bl[seq[x]/B]++;
	else bl[seq[x]/B]--;
}
int ask(int l,int r){
	if(l/B==r/B){
		for(int i=l;i<=r;i++)
			if(cnt[i])
				return i;
		return -1;
	}
	for(int i=l/B+1;i<r/B;i++)
		if(bl[i])
			for(int j=i*B;j<i*B+B;j++)
				if(cnt[j])
					return j;
	for(int i=l;i<l/B*B+B;i++)
		if(cnt[i])
			return i;
	for(int i=r/B*B;i<=r;i++)
		if(cnt[i])
			return i;
	return -1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs1(1,0),dfs2(1,1);
	for(int i=1;i<=q;i++){
		int l,r,x,y;cin>>l>>r>>x>>y;
		if(in[l]>in[r])swap(l,r);
		int t=lca(l,r);
		if(t==l)
			p[i]={in[l],in[r],0,i,x,y};
		else
			p[i]={out[l],in[r],in[t],i,x,y};
	}
	sort(p+1,p+1+q);
	int l=1,r=0;
	for(int i=1;i<=q;i++){
		while(l<p[i].l)upd(l++);
		while(l>p[i].l)upd(--l);
		while(r<p[i].r)upd(++r);
		while(r>p[i].r)upd(r--);
		if(p[i].a)upd(p[i].a);
		ans[p[i].id]=ask(p[i].ql,p[i].qr);
		if(p[i].a)upd(p[i].a);
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
}