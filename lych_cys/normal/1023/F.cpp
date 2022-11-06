#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 500009
using namespace std;

int n,m,tot,cnt,d[N],dad[N],fst[N],pnt[N<<1],nxt[N<<1],fa[N],anc[N];
bool vis[N]; pair<int,pii > a[N];
void add(int x,int y){
	pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;
}
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
void dfs(int x,int t){
	int i,y; anc[x]=t; vis[x]=1;
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (!vis[y]){
			fa[y]=x; d[y]=d[x]+1; dfs(y,t);
		}
	}
}
int getdad(int x){ return x==dad[x]?x:dad[x]=getdad(dad[x]); }
int getanc(int x){ return x==anc[x]?x:anc[x]=getanc(anc[x]); }
/*
void dvd(int x,int tp){
	int i,y; anc[x]=tp;
	if (son[x]) dvd(son[x],tp);
	for (i=fst[x]; i; i=nxt[i]){
		y=pnt[i];
		if (y!=fa[x] && y!=son[x]) dvd(y,y);
	}
}
int lca(int x,int y){
	for (; anc[x]!=anc[y]; x=fa[anc[x]])
		if (d[anc[x]]<d[anc[y]]) swap(x,y);
	return d[x]<d[y]?x:y;
}*/
ll ans; int now;
void calc(int x,int y,int z){
	//if (rt[x]!=rt[y]) continue;
	x=getdad(x); y=getdad(y);
	for (; x!=y; x=getdad(fa[x])){
		if (d[x]<d[y]) swap(x,y);
		ans+=z; dad[x]=fa[x]; now--;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&cnt);
	int i,x,z,y;
	for (i=1; i<=m; i++){
		x=read(); y=read();//bo[x]=bo[y]=1;
		add(x,y); add(y,x);	
	}
	for (i=1; i<=n; i++) if (!vis[i]){
		dfs(i,i); //dvd(i,i);	
	}
	for (i=1; i<=cnt; i++){
		a[i].se.fi=read();
		a[i].se.se=read(); a[i].fi=read();
	}
	//sort(a+1,a+cnt+1);
	//ll ans=0; int now=m;
	now=m;
	for (i=1; i<=n; i++) dad[i]=i;
	//for (i=1; i<=n; i++) anc[i]=i;
	int u,v;
	for (i=1; i<=cnt; i++){
		x=a[i].se.fi; y=a[i].se.se; z=a[i].fi;
		u=getanc(x); v=getanc(y);
		if (u==v) continue;
		anc[u]=v; ans-=z; now++; add(x,y); add(y,x);//if (bo[
		//calc(x,y,z);
	}
	memset(vis,0,sizeof(vis)); memset(fa,0,sizeof(fa));
	dfs(1,1);
	for (i=1; i<=cnt; i++){
		x=a[i].se.fi; y=a[i].se.se; z=a[i].fi;
		calc(x,y,z); 
	}
	printf("%lld\n",now?-1ll:ans);
	return 0;
}