#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5,M=3e5+5,Q=5e5+5;
int n,m,q,p[N];
int vis[M];
struct Edge {int u,v;} e[M];
struct Query {
	int op,v;
} a[Q];
int f[N<<1]; int getf(int x) {return f[x]==x?x:f[x]=getf(f[x]);}
int nds,ch[N<<1][2],bz[N<<1][20],L[N<<1],R[N<<1],dfc,idfn[N<<1],tim[N<<1];
void dfs(int u) {
	fr(i,1,19) bz[u][i]=bz[bz[u][i-1]][i-1];
	if(ch[u][0]) {
		dfs(ch[u][0]);
		dfs(ch[u][1]);
		L[u]=L[ch[u][0]];
		R[u]=R[ch[u][1]];
	} else idfn[L[u]=R[u]=++dfc]=u;
}
int seg[N<<3];
#define lc (k<<1)
#define rc (lc|1)
#define left lc,l,mid
#define right rc,mid+1,r
void pushup(int k) {
	if(p[seg[lc]]>p[seg[rc]]) seg[k]=seg[lc];
	else seg[k]=seg[rc];
}
void build(int k,int l,int r) {
	if(l==r) {
		seg[k]=idfn[l];
		return;
	}
	int mid=l+r>>1;
	build(left);
	build(right);
	pushup(k);
}
void change(int k,int l,int r,int pos) {
	if(l==r) return seg[k]=0,void();
	int mid=l+r>>1;
	if(pos<=mid) change(left,pos);
	else change(right,pos);
	pushup(k);
}
int query(int k,int l,int r,int x,int y) {
	if(x<=l&&r<=y) return seg[k];
	int r1=0,r2=0,mid=l+r>>1;
	if(x<=mid) r1=query(left,x,y);
	if(y>mid) r2=query(right,x,y);
	return p[r1]>p[r2]?r1:r2;
}
int main() {
	scanf("%d%d%d",&n,&m,&q);
	fr(i,1,n) scanf("%d",p+i);
	fr(i,1,m) scanf("%d%d",&e[i].u,&e[i].v);
	fr(i,1,q) {
		scanf("%d%d",&a[i].op,&a[i].v);
		if(a[i].op==2) vis[a[i].v]=1;
	}
	fr(i,1,2*n) f[i]=i;
	nds=n;
	fr(i,1,m) if(!vis[i]) {
		int u=getf(e[i].u);
		int v=getf(e[i].v);
		if(u!=v) {
			tim[++nds]=q+1; f[u]=f[v]=nds;
			ch[nds][0]=u;
			ch[nds][1]=v;
			bz[u][0]=bz[v][0]=nds;
		}
	}
	rf(i,q,1) if(a[i].op==2) {
		int u=getf(e[a[i].v].u);
		int v=getf(e[a[i].v].v);
		if(u!=v) {
			tim[++nds]=i; f[u]=f[v]=nds;
			ch[nds][0]=u;
			ch[nds][1]=v;
			bz[u][0]=bz[v][0]=nds;
		}
	}
	rf(i,nds,1) if(!L[i]) dfs(i);
	build(1,1,dfc);
	fr(i,1,q) if(a[i].op==1) {
		int u=a[i].v;
		rf(k,19,0) if(bz[u][k]&&tim[bz[u][k]]>=i) u=bz[u][k];
		int ans=query(1,1,dfc,L[u],R[u]);
		printf("%d\n",p[ans]);
		if(p[ans]) p[ans]=0,change(1,1,dfc,L[ans]);
	}
	return 0;
}