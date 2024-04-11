#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=2e5+9;

int n,m,ans,ss[N];
vector<pii> e[N];
char op[1];
set<int>s;

int dfn[N],tick,sz[N],son[N],top[N],fa[N],d[N],pos[N];
void adde(int u,int v,int w) {e[u].emplace_back(pii(v,w)), e[v].emplace_back(pii(u,w));}
void dfs1(int u) {
	d[u]=d[fa[u]]+1, sz[u]=1; int v;
	for(auto ed:e[u]) if((v=ed.fi)!=fa[u]) {
		fa[v]=u, ss[v]=ss[u]+ed.se, dfs1(v), sz[u]+=sz[v];
		if(sz[son[u]]<sz[v]) son[u]=v;
	}
}
void dfs2(int u,int tp) {
	dfn[u]=++tick, pos[tick]=u; top[u]=tp; if(son[u]) dfs2(son[u],tp);
	int v; for(auto ed:e[u]) if((v=ed.fi)!=fa[u]&&v!=son[u]) dfs2(v,v);
}
int lca(int x,int y) {
	for(;top[x]!=top[y];x=fa[top[x]]) if(d[top[x]]<d[top[y]]) swap(x,y);
	return d[x]<d[y]?x:y;
}
int qry(int x,int y) {
	int l=lca(x,y);
	return ss[x]+ss[y]-ss[l]*2;
}

void ins(int x) {
	if(s.empty()) {
		ans=0;
	} else if(s.size()==1) {
		int y=*s.begin(); ans+=2*qry(x,pos[y]);
	} else {
		set<int>::iterator t=s.lower_bound(dfn[x]), it1,it2; int y,z; it1=it2=t;
		if(t==s.begin()) it1=--s.end(); else --it1; y=pos[*it1];
		if(t==s.end()) it2=s.begin(); else it2=t; z=pos[*it2];
		ans+=qry(y,x)+qry(x,z)-qry(y,z);
	}
	s.insert(dfn[x]);
}
void del(int x) {
	if(s.size()==1) {
		ans=0;
	} else if(s.size()==2) {
		auto t=s.begin(); if(dfn[x]==*t) t++; int y=pos[*t];
		ans-=2*qry(x,y);
	} else {
		set<int>::iterator t=s.lower_bound(dfn[x]), it1,it2; int y,z; it1=it2=t; it2++;
		if(it1==s.begin()) it1=--s.end(); else --it1; y=pos[*it1];
		if(it2==s.end()) it2=s.begin(); z=pos[*it2];
		ans-=qry(y,x)+qry(x,z)-qry(y,z);
	}
	s.erase(dfn[x]);
}

signed main() {
	n=read();
	rep(i,2,n) {
		int u=read(), v=read(), w=read();
		adde(u,v,w);
	}
	dfs1(1); dfs2(1,1);
	m=read();
	while(m--) {
		scanf("%s",op);
		if(op[0]=='+') ins(read());
		else if(op[0]=='-') del(read());
		else printf("%lld\n",ans>>1);
	}
	return 0;
}