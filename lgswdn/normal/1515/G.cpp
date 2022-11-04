#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

struct edge {int to,nxt,w;} e[N<<1]; int hd[N],tot;
void add(int u,int v,int w) {e[++tot]=(edge){v,hd[u],w};hd[u]=tot;}

int n,m,q,tick,dfn[N],low[N],cnt,scc[N],d[N],g[N];
bool in[N],vst[N];

int gcd(int x,int y) {
	if(y==0) return x;
	else return gcd(y,x%y);
}

stack<int>st;
void dfs(int u) {
	dfn[u]=low[u]=++tick, st.push(u), in[u]=1;
	for(int i=hd[u],v;i;i=e[i].nxt) {
		if(!dfn[v=e[i].to]) dfs(v), low[u]=min(low[u],low[v]);
		else if(in[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]) {
		++cnt; int x=u;
		do {
			x=st.top(), st.pop(); in[x]=0, scc[x]=cnt;
		} while(x!=u);
	}
}

void dfs2(int u,int ccs) {
	vst[u]=1;
	for(int i=hd[u],v;i;i=e[i].nxt) if(scc[v=e[i].to]==ccs) {
		if(!vst[v]) d[v]=d[u]+e[i].w,dfs2(v,ccs);
		else {int x=abs(d[u]-d[v]+e[i].w); g[ccs]=(g[ccs]?gcd(g[ccs],x):x);}
	}
}

signed main() {
	n=read(), m=read();
	rep(i,1,m) {
		int u=read(), v=read(), w=read();
		add(u,v,w);
	}
	rep(i,1,n) if(!dfn[i]) dfs(i);
	rep(i,1,n) if(!vst[i]) dfs2(i,scc[i]);
	q=read();
	rep(i,1,q) {
		int u=read(),s=read(), t=read();
		if(!g[scc[u]]) puts(s?"NO":"YES");
		else puts(s%gcd(g[scc[u]],t)?"NO":"YES");
	} 
	return 0;
}