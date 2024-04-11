#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 1000000000000000000ll
#define N 300005
#define M 1200005
using namespace std;

int n,m,tot,cnt,fa[N],bg[N],ed[N],pos[N],pnt[M],nxt[M]; ll dp[N],icr[M],mn[M];
struct node{ int x,y,z; }a[N];
int read(){
	int x=0; char cr=getchar();
	while (cr<'0' || cr>'9') cr=getchar();
	while (cr>='0' && cr<='9'){ x=x*10+cr-'0'; cr=getchar(); }
	return x;
}
struct graph{
	int fst[N];
	void add(int x,int y){
		pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
	}
}gh,e1,e2;
void ins(int k,int l,int r,int x,int y,ll z){
	if (x<=l && r<=y){
		icr[k]+=z; mn[k]=min(mn[k]+z,inf); return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) ins(k<<1,l,mid,x,y,z);
	if (y>mid) ins(k<<1|1,mid+1,r,x,y,z);
	mn[k]=min(min(mn[k<<1],mn[k<<1|1])+icr[k],inf);
}
void mdy(int k,int l,int r,int x,ll y){
	if (l==r){
		icr[k]=0; mn[k]=y; return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) mdy(k<<1,l,mid,x,y); else mdy(k<<1|1,mid+1,r,x,y);
	mn[k]=min(min(mn[k<<1],mn[k<<1|1])+icr[k],inf);
}
ll qry(int k,int l,int r,int x,int y){
	if (x<=l && r<=y) return mn[k];
	int mid=(l+r)>>1; ll ans=inf;
	if (x<=mid) ans=min(ans,qry(k<<1,l,mid,x,y));
	if (y>mid) ans=min(ans,qry(k<<1|1,mid+1,r,x,y));
	return ans;
}
void dfs(int x){
	int i,y;
	bg[x]=cnt+1;
	for (i=e1.fst[x]; i; i=nxt[i]) pos[pnt[i]]=++cnt;
	ed[x]=cnt;
	for (i=gh.fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (y!=fa[x]){
			fa[y]=x; dfs(y); ed[x]=max(ed[x],ed[y]);
		}
	}
}
void solve(int x){
	int y,i; ll tmp=0;
	for (i=gh.fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (y!=fa[x]){
			solve(y); tmp=min(tmp+dp[y],inf);
		}
	}
	if (x==1){
		printf("%lld\n",(tmp<inf)?tmp:-1); return;
	}
	if (bg[x]>ed[x]){
		dp[x]=inf; return;
	}
	for (i=e1.fst[x]; i; i=nxt[i]) mdy(1,1,cnt,pos[pnt[i]],a[pnt[i]].z);
	for (i=e2.fst[x]; i; i=nxt[i]) mdy(1,1,cnt,pos[pnt[i]],inf);
	ins(1,1,cnt,bg[x],ed[x],tmp);
	dp[x]=qry(1,1,cnt,bg[x],ed[x]);
	ins(1,1,cnt,bg[x],ed[x],-dp[x]);
}
int main(){
	n=read(); m=read();
	int i,x,y;
	for (i=1; i<n; i++){
		x=read(); y=read();
		gh.add(x,y); gh.add(y,x);
	}
	for (i=1; i<=m; i++){
		a[i].x=read(); a[i].y=read(); a[i].z=read();
		e1.add(a[i].x,i); e2.add(a[i].y,i);
	}
	dfs(1); solve(1);
	return 0;
}