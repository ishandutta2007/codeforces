#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=2e5+5;
int n,p[N],dep[N];
int to[N],nxt[N],eds,fir[N];
void addedge(int u,int v) {
	to[++eds]=v;
	nxt[eds]=fir[u];
	fir[u]=eds;
}
int fa[N],siz[N],son[N],top[N];
void dfs1(int u) {
	dep[u]=dep[fa[u]]+1;
	siz[u]=1;
	foredge(i,u,v) {
		dfs1(v),siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u) {
	if(son[u]) {
		top[son[u]]=top[u];
		dfs2(son[u]);
		foredge(i,u,v) if(v!=son[u])
			top[v]=v,dfs2(v);
	}
}
int LCA(int u,int v) {
	while(top[u]^top[v]) {
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
struct Line {
	int u,v;
	Line() {u=-1,v=-1;}
	Line(int u,int v):u(u),v(v) {}
} seg[N<<2],ret,nret;
Line calc(int u,int v,int w) {
	if(u==v) return Line{u,w};
	if(dep[u]>dep[v]) swap(u,v);
	int lca=LCA(u,v);
	if(lca==u) {
		lca=LCA(v,w);
		if(dep[lca]<=dep[u]) return Line{w,v};
		if(lca==v) return Line{u,w};
		if(lca==w) return Line{u,v};
		return Line{-1,-1};
	}
	if(LCA(lca,w)!=lca) return Line{-1,-1};
	lca=LCA(u,w);
	if(lca==u) return Line{w,v};
	if(lca==w) return Line{u,v};
	lca=LCA(v,w);
	if(lca==v) return Line{w,u};
	if(lca==w) return Line{u,v};
	return Line{-1,-1};
}
Line operator + (const Line &a,const Line &b) {
	if(a.u==-1||b.u==-1) return Line{-1,-1};
	if(a.u==0||b.u==0) return Line{a.u|b.u,a.v|b.v};
	Line c=calc(a.u,a.v,b.u);
	return c.u==-1?c:calc(c.u,c.v,b.v);
}
#define lc (k<<1)
#define rc (lc|1)
#define left lc,l,mid
#define right rc,mid+1,r
void change(int k,int l,int r,int pos,int val) {
	if(l==r) return seg[k]=Line{val,val},void();
	int mid=l+r>>1;
	if(pos<=mid) change(left,pos,val);
	else change(right,pos,val);
	seg[k]=seg[lc]+seg[rc];
}
int query(int k,int l,int r) {
	if(l==r) return l;
	int mid=l+r>>1;
	nret=ret+seg[lc];
	if(nret.u==-1) return query(left);
	return ret=nret,query(right);
}
int main() {
	n=read();
	fr(i,1,n) p[i]=read();
	fr(i,2,n) addedge(fa[i]=read(),i);
	dfs1(1); top[1]=1; dfs2(1);
	fr(i,1,n) change(1,0,n,p[i],i);
	calc(4,7,5);
	for(int q=read(),op,i,j;q--;) {
		op=read();
		if(op==1) {
			i=read(),j=read();
			swap(p[i],p[j]);
			change(1,0,n,p[i],i);
			change(1,0,n,p[j],j);
		} else {
			ret=Line{0,0};
			printf("%d\n",query(1,0,n));
		}
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}