#include<bits/stdc++.h>
#define ll long long
#define N 200009
using namespace std;

int n,m,dfsclk,tot,c[2][N],pa[N],pb[N],blk[N],id[N],f[N],g[N];
int fst[N],pnt[N<<1],nxt[N<<1],bin[N],fa[N][20],d[N];
bool vis[N]; ll ans[N],sum;
struct node{ int l,r,id; }a[N];
map<int,int> mp;
int read(){
	int x=0; char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return x;
}
void add(int x,int y){
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
}
void dfs(int x){
	f[x]=++dfsclk; id[dfsclk]=x; int i,p;
	for (i=1; bin[i]<=d[x]; i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (p=fst[x]; p; p=nxt[p]){
		int y=pnt[p];
		if (y!=fa[x][0]){
			fa[y][0]=x; d[y]=d[x]+1; dfs(y);
		}
	}
	g[x]=++dfsclk; id[dfsclk]=x;
}
int lca(int x,int y){
	if (d[x]<d[y]) swap(x,y); int tmp=d[x]-d[y],i;
	for (i=0; bin[i]<=tmp; i++)
		if (tmp&bin[i]) x=fa[x][i];
	for (i=19; i>=0; i--)
		if (fa[x][i]!=fa[y][i]){ x=fa[x][i]; y=fa[y][i]; }
	return (x==y)?x:fa[x][0];
}
bool cmp(node x,node y){
	return blk[x.l]<blk[y.l] || blk[x.l]==blk[y.l] && x.r<y.r;
}
void mdy(int x){
	if (vis[x]){
		sum+=c[pa[x]^1][pb[x]]; c[pa[x]][pb[x]]++;
	} else{
		sum-=c[pa[x]^1][pb[x]]; c[pa[x]][pb[x]]--;
	}
	vis[x]^=1;
}
int main(){
	n=read();
	int i,l,r;
	bin[0]=1; for (i=1; i<=20; i++) bin[i]=bin[i-1]<<1;
	for (i=1; i<=n; i++) pa[i]=read();
	int pt=0;
	for (i=1; i<=n; i++){
		pb[i]=read();
		if (!mp[pb[i]]) mp[pb[i]]=++pt; pb[i]=mp[pb[i]];
	}
	for (i=1; i<n; i++){
		l=read(); r=read(); add(l,r); add(r,l);
	}
	int sz=sqrt(n);
	dfs(1);
	for (i=1; i<=dfsclk; i++) blk[i]=(i-1)/sz;
	m=read();
	for (i=1; i<=m; i++){
		l=read(); r=read();
		if (f[l]>f[r]) swap(l,r);
		a[i].r=f[r]; a[i].id=i;
		a[i].l=(lca(l,r)==l)?f[l]:g[l];
	}
	sort(a+1,a+m+1,cmp); l=1; r=0;
	for (i=1; i<=m; i++){
		while (l>a[i].l) mdy(id[--l]); while (r<a[i].r) mdy(id[++r]);
		while (r>a[i].r) mdy(id[r--]); while (l<a[i].l) mdy(id[l++]);
		int x=id[l],y=id[r],tmp=lca(x,y);
		if (x!=tmp && y!=tmp){ mdy(tmp); ans[a[i].id]=sum; mdy(tmp); }
		else ans[a[i].id]=sum;
	}
	for (i=1; i<=m; i++) printf("%lld\n",ans[i]);
	return 0;
}