#include <bits/stdc++.h>
#define maxn 200005
int n,q,head[maxn]={0},tail=0,size[maxn]={0},dfn[maxn],idx=0,fa[maxn],p[maxn],opt,
anc[maxn][19]={0},depth[maxn]={0};
struct edge {
	int v,next;
}edges[maxn<<1];
void add_edge(int u,int v) {
	edges[++tail].v=v;
	edges[tail].next=head[u];
	head[u]=tail;
}

void dfs(int u) {
	dfn[u]=++idx;size[u]=1;anc[u][0]=fa[u];depth[u]=depth[fa[u]]+1;
	for (int i=1;i<=18;++i) anc[u][i]=anc[anc[u][i-1]][i-1];
	for (int i=head[u];i;i=edges[i].next) {
		int v=edges[i].v;
		dfs(v);size[u]+=size[v];
	}
}

int lca(int u,int v) {
	if (depth[u]<depth[v]) std::swap(u,v);
	for (int i=18;i>=0;i--) 
		if (depth[anc[u][i]]>=depth[v])u=anc[u][i];
	if (u==v) return u;
	for (int i=18;i>=0;i--) 
		if (anc[u][i]!=anc[v][i]) {u=anc[u][i];v=anc[v][i];}
	return fa[u];
}

int sub(int a,int b) {
	return dfn[b]<=dfn[a]&&dfn[a]<=dfn[b]+size[b]-1;
}

int in(int a,int b,int c) {
	return (sub(a,c)^sub(b,c))||(a==c)||(b==c)||lca(a,b)==c;
}

struct data {
	int x,y;
};data merge(data a,data b) {
	if (a.x==-1) return b;
	data c;c.x=c.y=0;
	if (!a.x||!b.x) c.x=c.y=0;
	else {
		int xa=a.x,ya=a.y,xb=b.x,yb=b.y;
		if (in(xa,xb,ya)&&in(xa,xb,yb)) {c.x=xa;c.y=xb;return c;}
		if (in(xa,ya,xb)&&in(xa,ya,yb)) {c.x=xa;c.y=ya;return c;}
		if (in(xa,yb,ya)&&in(xa,yb,xb)) {c.x=xa;c.y=yb;return c;}
		if (in(xb,ya,xa)&&in(xb,ya,yb)) {c.x=xb;c.y=ya;return c;}
		if (in(xb,yb,ya)&&in(xb,yb,xa)) {c.x=xb;c.y=yb;return c;}
		if (in(ya,yb,xa)&&in(ya,yb,xb)) {c.x=ya;c.y=yb;return c;}
	}return c;
}data datE(int x,int y) {
	data c;c.x=x;c.y=y;return c;
}

struct segmentTree {
	data dat[maxn<<2];
	void update(int u) {
		dat[u]=merge(dat[u<<1],dat[u<<1|1]);
	}
	void modify(int l,int r,int p,int v,int rt) {
		if (l==r) {dat[rt].x=dat[rt].y=v;return;}
		int mid=(l+r)>>1;
		if (p<=mid) modify(l,mid,p,v,rt<<1);
		else modify(mid+1,r,p,v,rt<<1|1);
		update(rt);
	}int query(int l,int r,int rt,data d=datE(-1,-1)) {
	//	printf("%d<->%d: (%d-%d) %d-%d\n",l,r,d.x,d.y,dat[rt].x,dat[rt].y);
		if (l==r) return merge(d,dat[rt]).x?l:0;
		int mid=(l+r)>>1;
		if (merge(d,dat[rt<<1]).x) return std::max(mid,query(mid+1,r,rt<<1|1,merge(d,dat[rt<<1])));
		else return query(l,mid,rt<<1,d);
	}
}sgt;

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		scanf("%d",&p[i]);p[i]++;
	}for (int i=2;i<=n;++i) {
		scanf("%d",&fa[i]);
		add_edge(fa[i],i);
	}dfs(1);
	for (int i=1;i<=n;++i) sgt.modify(1,n,p[i],i,1);
	scanf("%d",&q);
	while (q--) {
		scanf("%d",&opt);
		if (opt==1){
			int u,v;
			scanf("%d%d",&u,&v);
			sgt.modify(1,n,p[u],v,1);
			sgt.modify(1,n,p[v],u,1);
			std::swap(p[u],p[v]);
		}if (opt==2) {
			printf("%d\n",sgt.query(1,n,1));
		}
	}
	return 0;
}