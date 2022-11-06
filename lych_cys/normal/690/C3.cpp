#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1000000000
#define N 600005
#define M 2400005
using namespace std;

int sz,n,m,tot,cnt,fst[N],pnt[N],nxt[N],a[N],lgt[N],pos[N],c[M][2];
struct node{
	int u,v,len,l0,l1,r0,r1;
	void mdy(int x){
		len=l0=l1=r0=r1=-inf; u=v=0;
		if (x==-1) v=1; else if (x==-2) u=1;
		else if (!lgt[x]) l0=l1=r0=r1=0;
	}
}val[M];
int read(){
	int x=0; char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return x;
}
void add(int aa,int bb){
	pnt[++tot]=bb; nxt[tot]=fst[aa]; fst[aa]=tot;
}
void dfs(int x,int last){
	a[++cnt]=-1; a[pos[x]=++cnt]=x; int p;
	for (p=fst[x]; p; p=nxt[p])
		if (pnt[p]!=last) dfs(pnt[p],x);
	a[++cnt]=-2;
}
void maintain(int k){
	node x=val[k<<1],y=val[k<<1|1];
	val[k].len=max(x.r0+y.l1,x.r1+y.l0);
	val[k].len=max(val[k].len,max(x.len,y.len));
	if (x.v<y.u){ val[k].u=x.u-x.v+y.u; val[k].v=y.v; }
	else{ val[k].u=x.u; val[k].v=y.v-y.u+x.v; }
	val[k].l0=max(x.l0,x.v-x.u+y.l0);
	val[k].l1=max(x.l1,max(x.u-x.v+y.l1,x.u+x.v+y.l0));
	val[k].r0=max(y.r0,y.u-y.v+x.r0);
	val[k].r1=max(y.r1,max(y.v-y.u+x.r1,y.u+y.v+x.r0));
}
void build(int k,int l,int r){
	c[k][0]=l; c[k][1]=r; int mid=(l+r)>>1;
	if (l==r){ val[k].mdy(a[l]); return; }
	build(k<<1,l,mid); build(k<<1|1,mid+1,r); maintain(k);
}
void ins(int k,int x){
	int l=c[k][0],r=c[k][1],mid=(l+r)>>1;
	if (l==r){ val[k].mdy(a[l]); return; }
	if (x<=mid) ins(k<<1,x); else ins(k<<1|1,x); maintain(k);
}
int main(){
	sz=n=read(); int i; char ch;
	for (i=1; i<n; i++){
		int x=read(),y=i+1; add(x,y); add(y,x);
	}for (i=2; i<=n; i++)lgt[i]=1;
	dfs(1,0); build(1,1,cnt);
		for (i=2; i<=n; i++){
			
			int x=i;
			if (!lgt[x]) sz--; else sz++; lgt[x]^=1;
			ins(1,pos[x]);printf("%d\n",val[1].len);
		}
	return 0;
}