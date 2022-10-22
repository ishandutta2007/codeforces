#include<cstdio>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=4e5+5;
int T,n,m,tot;
int fir[N],to[N<<1],eds,nxt[N<<1];
void addedge(int u,int v) {
	to[++eds]=v;
	nxt[eds]=fir[u];
	fir[u]=eds;
}
struct Edge {
	int u,v,w,id;
	bool operator < (const Edge &o) {
		return w<o.w;
	}
} e[N],e2[N];

int nds,ch[N][2],dfc,dfn[N],id[N],idfn[N],bz[N][18],dep[N];
int f[N]; int getf(int x) {return x==f[x]?x:f[x]=getf(f[x]);}
void dfs(int u) {
	if(u>n) dfs(ch[u][0]),dfs(ch[u][1]);
	else idfn[dfn[u]=++dfc]=u;
}
void Kruskal(Edge *e,int m) {
	sort(e+1,e+m+1);
	iota(f+1,f+n+1,1); nds=n; dfc=0;
	fr(i,1,m) {
		int u=getf(e[i].u),v=getf(e[i].v);
		if(u^v) {
			id[++nds]=i;
			ch[nds][0]=u; ch[nds][1]=v;
			f[u]=f[v]=f[nds]=nds;
			bz[u][0]=bz[v][0]=nds;
		}
	}
	rf(i,nds,1) {
		dep[i]=dep[bz[i][0]]+1;
		fr(j,1,17) bz[i][j]=bz[bz[i][j-1]][j-1];
	}
	dfs(nds);
}
int LCA(int u,int v) {
	if(dep[u]<dep[v]) swap(u,v);
	rf(i,17,0) if(dep[u]-dep[v]>>i&1) u=bz[u][i];
	if(u==v) return u;
	rf(i,17,0) if(bz[u][i]^bz[v][i]) u=bz[u][i],v=bz[v][i];
	return bz[u][0];
}

const int NN=1<<18;
int seg[NN<<1];
void add(int x,int v) {for(x+=NN;x;x>>=1) seg[x]+=v;}
#define lc (k<<1)
#define rc (lc|1)
int search1(int x) {
	int k,len;
	for(k=x+1+NN,len=1;k^1;k>>=1,len<<=1)
		if((k&1)&&seg[k^1]!=len) {k^=1; break;}
	for(;len^1;len>>=1) k=seg[rc]!=len>>1?rc:lc;
	return k-NN;
}
int search2(int x) {
	int k,len;
	for(k=x+NN-1,len=1;k^1;k>>=1,len<<=1)
		if((~k&1)&&seg[k^1]!=len) {k^=1; break;}
	for(;len^1;len>>=1) k=seg[lc]!=len>>1?lc:rc;
	return k-NN;
}
vector<int> buc[N],nd;
vector<Edge> tmp,tmp2;
void Brovuka() {
	int cps=n,p;
	iota(f+1,f+n+1,1);
	tot=0;
	while(cps>1) {
		fr(i,1,n) buc[i].clear();
		fr(i,1,n) buc[getf(i)].push_back(i);
		tmp.clear();
		fr(i,1,n) if(f[i]==i) {
			tmp2.clear();
			for(auto x:buc[i]) add(dfn[x],1);
			for(auto u:buc[i]) {
				nd.clear();
				foredge(_,u,v) if(!seg[dfn[v]+NN]) nd.push_back(v);
				for(auto x:nd) add(dfn[x],1);
				if(p=idfn[search1(dfn[u])],1<=p&&p<=n) tmp2.push_back((Edge){u,p,e[id[LCA(u,p)]].w});
				if(p=idfn[search2(dfn[u])],1<=p&&p<=n) tmp2.push_back((Edge){u,p,e[id[LCA(u,p)]].w});
				for(auto x:nd) add(dfn[x],-1);
			}
			for(auto x:buc[i]) add(dfn[x],-1);
			tmp.push_back(*min_element(tmp2.begin(),tmp2.end()));
		}
		for(auto x:tmp) {
			int u=getf(x.u),v=getf(x.v);
			if(u^v) f[u]=v,e2[++tot]=x,--cps;
		}
	}
}
int ans[N];
int main() {
	T=read();
	while(T--) {
		n=read(),m=read();
		fr(i,1,n) fir[i]=0; eds=0;
		for(int i=1,u,v,w;i<=m;++i) {
			u=read(),v=read(),w=read();
			addedge(u,v);
			addedge(v,u);
			e[i]=(Edge){u,v,w,i};
		}
		Kruskal(e,m);
		Brovuka();
		Kruskal(e2,tot);
		fr(i,1,m) ans[e[i].id]=e2[id[LCA(e[i].u,e[i].v)]].w;
		fr(i,1,m) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}

inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}