#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
const int MAXLGN=17;
const int MAXM=200000;
typedef struct E { int a,b,c,id,gid; bool onmst; } E;
bool operator<(const E &p,const E &q) { if(p.c!=q.c) return p.c<q.c; return p.id<q.id; }

typedef struct UF {
	int par[MAXN];
	int sz[MAXN];
	void init(int n) { REP(i,n) par[i]=i,sz[i]=1; }
	int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
	bool unite(int a,int b) {
		a=find(a),b=find(b); if(a==b) return false;
		if(sz[a]<sz[b]) swap(a,b);
		par[b]=a; sz[a]+=sz[b]; return true;
	}

} UF;
UF uf;

typedef struct G {
	int n,m;
	int ghead[MAXN],gnxt[2*(MAXN-1)],gto[2*(MAXN-1)],gcost[MAXN-1];
	void init(int _n) { n=_n,m=0; REP(i,n) ghead[i]=-1; }
	int addedge(int a,int b,int c) { gnxt[2*m+0]=ghead[a],ghead[a]=2*m+0,gto[2*m+0]=b; gnxt[2*m+1]=ghead[b],ghead[b]=2*m+1,gto[2*m+1]=a; gcost[m]=c; return m++; }

	int par[MAXN],d[MAXN],parcost[MAXN];
	int up[MAXN][MAXLGN+1];
	int upmx[MAXN][MAXLGN+1];
	int lazy[MAXN][MAXLGN+1];
	int lst[MAXN],nlst;
	void dfs(int at) {
		lst[nlst++]=at;
		up[at][0]=par[at]==-1?at:par[at]; upmx[at][0]=parcost[at];
		FORE(i,1,MAXLGN) up[at][i]=up[up[at][i-1]][i-1];
		FORE(i,1,MAXLGN) upmx[at][i]=max(upmx[at][i-1],upmx[up[at][i-1]][i-1]);
		REPE(i,MAXLGN) lazy[at][i]=INT_MAX;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x]; if(to==par[at]) continue;
			par[to]=at,d[to]=d[at]+1,parcost[to]=gcost[x>>1]; dfs(to);
		}
	}
	void buildforest() {
		REP(i,n) par[i]=-1,d[i]=0,parcost[i]=0; nlst=0;
		REP(i,n) if(par[i]==-1) dfs(i);
	}
	int lca(int a,int b) {
		if(d[a]<d[b]) swap(a,b);
		for(int k=MAXLGN;k>=0;--k) if(d[a]-(1<<k)>=d[b]) a=up[a][k];
		for(int k=MAXLGN;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
		assert(a==b||up[a][0]==up[b][0]);
		return a==b?a:up[a][0];
	}
	int pathmax(int a,int b) {
		int ret=INT_MIN;
		for(int k=MAXLGN;k>=0;--k) if(d[a]-(1<<k)>=d[b]) ret=max(ret,upmx[a][k]),a=up[a][k];
		return ret;
	}
	void setlazy(int a,int b,int c) {
		for(int k=MAXLGN;k>=0;--k) if(d[a]-(1<<k)>=d[b]) lazy[a][k]=min(lazy[a][k],c),a=up[a][k];
	}
	void calcres() {
		for(int i=nlst-1;i>=0;--i) {
			int a=lst[i];
			for(int k=MAXLGN;k>=1;--k) {
				lazy[a][k-1]=min(lazy[a][k-1],lazy[a][k]);
				lazy[up[a][k-1]][k-1]=min(lazy[up[a][k-1]][k-1],lazy[a][k]);
			}
		}
	}
	int getres(int id) {
		int a=gto[2*id+1],b=gto[2*id+0]; if(d[a]<d[b]) swap(a,b); assert(par[a]==b); return lazy[a][0]==INT_MAX?-1:lazy[a][0];
	}
} G;
G g;

int n,m;
E e[MAXM];
bool onmst[MAXM];
int ans[MAXN];


void run() {
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; e[i].a=a,e[i].b=b,e[i].c=c,e[i].id=i,e[i].onmst=false,e[i].gid=-1; ans[i]=-2; }
	sort(e,e+m);

	uf.init(n);
	g.init(n);
	REP(i,m) if(uf.unite(e[i].a,e[i].b)) {
		e[i].onmst=true;
		e[i].gid=g.addedge(e[i].a,e[i].b,e[i].c);
	}
	g.buildforest();
	REP(i,m) if(!e[i].onmst) {
		int a=e[i].a,b=e[i].b,z=g.lca(a,b);
		//printf("%d-%d (%d)\n",e[i].a+1,e[i].b+1,z+1);
		ans[e[i].id]=max(g.pathmax(a,z),g.pathmax(b,z))-1;
		g.setlazy(a,z,e[i].c-1); g.setlazy(b,z,e[i].c-1);
	}
	g.calcres();
	REP(i,m) if(e[i].onmst) ans[e[i].id]=g.getres(e[i].gid);
	REP(i,m) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}