#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200005
using namespace std;

int n,pt,cnt,q[N],h[N],pos[N];
int read(){
	int x=0; char cr=getchar();
	while (cr<'0' || cr>'9') cr=getchar();
	while (cr>='0' && cr<='9'){ x=x*10+cr-'0'; cr=getchar(); }
	return x;
}
bool cmp(int x,int y){ return h[x]<h[y]; }
struct tree{
	int tot,dfsclk,fst[N],pnt[N<<1],nxt[N<<1],a[N],na[N],b[N],c[N];
	int lf[N],rg[N],id[N],fa[N],d[N],sz[N],son[N],anc[N],val[N<<2];
	bool dlt[N];
	void add(int x,int y){
		pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
	}
	void dfs(int x){
		int i,y; sz[x]=1;
		for (i=fst[x]; i; i=nxt[i]){
			y=pnt[i];
			if (y!=fa[x]){
				fa[y]=x; d[y]=d[x]+1;
				dfs(y); sz[x]+=sz[y];
				if (sz[y]>sz[son[x]]) son[x]=y;
			}
		}
	}
	void dvd(int x,int tp){
		int i,y; id[lf[x]=++dfsclk]=x; anc[x]=tp;
		if (son[x]) dvd(son[x],tp);
		for (i=fst[x]; i; i=nxt[i]){
			y=pnt[i];
			if (y!=fa[x] && y!=son[x]) dvd(y,y);
		}
		rg[x]=dfsclk;
	}
	int lca(int x,int y){
		for (; anc[x]!=anc[y]; x=fa[anc[x]])
			if (d[anc[x]]<d[anc[y]]) swap(x,y);
		return (d[x]<d[y])?x:y;
	}
	void init(){
		int i;
		for (i=2; i<=n; i++){
			a[i]=read(); add(a[i],i); add(i,a[i]);
		}
		d[1]=1; dfs(1); dvd(1,1);
	}
	int ls(int x,int y){ return (b[c[x]]<b[c[y]])?x:y; }
	void ins(int x,int y){
		int i; x=lf[x]; add(x,y); c[x]=y;
		for (i=pos[x]>>1; i; i>>=1) val[i]=ls(val[i<<1],val[i<<1|1]);
	}
	void mdy(int x){
		int i; x=lf[x]; bool flag=dlt[c[x]];
		for (; dlt[c[x]]; c[x]=pnt[fst[x]=nxt[fst[x]]]);
		if (flag)
			for (i=pos[x]>>1; i; i>>=1) val[i]=ls(val[i<<1],val[i<<1|1]);
	}
	int qry(int k,int l,int r,int x,int y){
		if (x<=l && r<=y) return val[k];
		int mid=l+r>>1,z=0;
		if (x<=mid) z=ls(z,qry(k<<1,l,mid,x,y)); if (y>mid) z=ls(z,qry(k<<1|1,mid+1,r,x,y));
		return z;
	}
	void pwk(){
		int i,x;
		memset(fst,0,sizeof(fst)); tot=0;
		for (i=2; i<=n; i++) b[i]=d[lca(na[i],i)];
		for (i=2; i<=n; i++){ q[i]=i; h[i]=b[i]; }
		sort(q+2,q+n+1,cmp);
		b[0]=1000000000; for (i=1; i<=n; i++) ins(i,0);
		for (i=n; i>1; i--){
			x=q[i]; ins(x,x); ins(na[x],x);
		}
	}
	void solve(){
		int i,x,y,u;
		for (i=1; i<=pt; i++){
			x=q[i]; y=a[x];
			if (x==fa[y]) swap(x,y);
			for (; b[u=c[qry(1,1,n,lf[x],rg[x])]]<d[x]; mdy(u),mdy(na[u])) dlt[h[++cnt]=u]=1;
		}
	}
}B,R;
void build(int k,int l,int r){
	B.val[k]=R.val[k]=l;
	if (l==r){ pos[l]=k; return; }
	int mid=l+r>>1;
	build(k<<1,l,mid); build(k<<1|1,mid+1,r);
}
int main(){
	n=read();
	build(1,1,n); B.init(); R.init();
	int i;
	for (i=1; i<=n; i++){
		B.na[i]=R.a[i]; R.na[i]=B.a[i];
	}
	B.pwk(); R.pwk();
	q[pt=1]=read()+1; printf("Blue\n%d\n",q[1]-1);
	R.dlt[q[1]]=1; R.mdy(q[1]); R.mdy(B.a[q[1]]);
	bool now=0;
	for (; pt; now^=1){
		cnt=0;
		if (now) R.solve(); else B.solve();
		pt=cnt; for (i=1; i<=pt; i++) q[i]=h[i];
		if (pt){
			puts((now)?"Blue":"Red");
			sort(q+1,q+pt+1);
			for (i=1; i<=pt; i++) printf("%d%c",q[i]-1,(i<pt)?' ':'\n');
		}
	}
	return 0;
}