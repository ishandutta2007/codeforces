#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=4e5+9; 

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

struct edge {int to,nxt;} e[N*2]; int hd[N],tot=1;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]}; hd[u]=tot;}

int n,m,q,tick,dfn[N],low[N],ccnt,cc[N],dcnt,dc[N],d[N],f[N][29],tag[N][2];
vector<int>t[N];
bool cut[N];

void dfs(int u,int fa,int ccid) {
	low[u]=dfn[u]=++tick, cc[u]=ccid;
	for(int i=hd[u],v;i;i=e[i].nxt) if(i!=fa) {
		if(!dfn[v=e[i].to]) {
			dfs(v,i^1,ccid);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]) cut[i]=cut[i^1]=1;
		} else low[u]=min(low[u],dfn[v]);
	}
}
void dfs2(int u,int dcid) {
	dc[u]=dcid;
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if(cut[i]==0&&dc[v=e[i].to]==0)
			dfs2(v,dcid);
	}
}

void dfst(int u,int fa) {
	f[u][0]=fa, d[u]=d[fa]+1;
	rep(h,1,19) f[u][h]=f[f[u][h-1]][h-1];
	for(auto v:t[u]) if(v!=fa) dfst(v,u);
}
bool cfs(int u,int fa) {
	for(auto v:t[u]) if(v!=fa) {
		if(!cfs(v,u)||(tag[v][0]&&tag[v][1])) return 0;
		tag[u][0]+=tag[v][0], tag[u][1]+=tag[v][1];
	}
	return 1;
}

int lca(int u,int v) {
	if(d[u]<d[v]) swap(u,v);
	per(h,19,0) if(d[f[u][h]]>=d[v]) u=f[u][h];
	per(h,19,0) if(f[u][h]!=f[v][h]) u=f[u][h], v=f[v][h];
	return u==v?u:f[u][0];
}

int main() {
	n=read(), m=read(), q=read();
	rep(i,1,m) {
		int u=read(), v=read();
		add(u,v), add(v,u);
	}
	rep(i,1,n) if(!dfn[i]) dfs(i,0,++ccnt);
	rep(i,1,n) if(!dc[i]) dfs2(i,++dcnt);
	rep(u,1,n) for(int i=hd[u];i;i=e[i].nxt) if(cut[i]) t[dc[u]].push_back(dc[e[i].to]);
	rep(i,1,n) if(!d[i]) dfst(i,0);
	rep(i,1,q) {
		int u=read(), v=read();
		if(cc[u]!=cc[v]) return puts("No"), 0;
		int l=lca(u=dc[u],v=dc[v]);
		tag[u][0]++, tag[v][1]++, tag[l][0]--, tag[l][1]--;
	}
	rep(i,1,n) if(d[i]==1) {
		if(!cfs(i,0)) return puts("No"), 0;
	}
	puts("Yes");
	return 0;
}