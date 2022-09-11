#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=500000;
const int MAXE=500000;
const int MAXLG=18;
struct E { int a,b,c; };
bool operator<(const E &u,const E &v) { return u.c<v.c; }

int n,nme,nopp;
E me[MAXE];
E opp[MAXE];

int ufpar[MAXN],ufsz[MAXN];
int uffind(int x) { if(ufpar[x]==x) return x; return ufpar[x]=uffind(ufpar[x]); }
bool ufunite(int x,int y) { x=uffind(x),y=uffind(y); if(x==y) return false; if(ufsz[x]<ufsz[y]) swap(x,y); ufpar[y]=x,ufsz[x]+=ufsz[y]; return true; }

vector<int> adj[MAXN];
int par[MAXN];
int dep[MAXN];
int up[MAXN][MAXLG+1];
int lim[MAXN][MAXLG+1];

void dfsinit(int at) {
	dep[at]=par[at]==-1?0:dep[par[at]]+1;
	up[at][0]=par[at]==-1?at:par[at]; REP(k,MAXLG) up[at][k+1]=up[up[at][k]][k];
	REPE(k,MAXLG) lim[at][k]=INT_MAX;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		par[to]=at; dfsinit(to);
	}
}

int lca(int a,int b) {
	if(dep[a]<dep[b]) swap(a,b);
	for(int k=MAXLG;k>=0;--k) if(dep[a]-(1<<k)>=dep[b]) a=up[a][k];
	for(int k=MAXLG;k>=0;--k) if(up[a][k]!=up[b][k]) a=up[a][k],b=up[b][k];
	return a==b?a:par[a];
}

void upd(int &a,int b) { a=min(a,b); }
void setlimit(int a,int b,int val) {
	int c=lca(a,b);
	for(int k=MAXLG;k>=0;--k) if(dep[a]-(1<<k)>=dep[c]) upd(lim[a][k],val),a=up[a][k]; assert(a==c);
	for(int k=MAXLG;k>=0;--k) if(dep[b]-(1<<k)>=dep[c]) upd(lim[b][k],val),b=up[b][k]; assert(b==c);
}

ll dfslimit(int at) {
	ll ret=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		ll cur=dfslimit(to);
		if(cur==LLONG_MAX||ret==LLONG_MAX) ret=LLONG_MAX; else ret+=cur;
	}
	for(int k=MAXLG;k>=1;--k) upd(lim[at][k-1],lim[at][k]),upd(lim[up[at][k-1]][k-1],lim[at][k]);
	if(par[at]!=-1) { if(lim[at][0]==INT_MAX||ret==LLONG_MAX) ret=LLONG_MAX; else ret+=lim[at][0]; }
	return ret;
}


ll solve() {
	sort(opp,opp+nopp);
	REP(i,n) ufpar[i]=i,ufsz[i]=1,adj[i].clear();
	REP(i,nme) { int a=me[i].a,b=me[i].b; assert(ufunite(a,b)); adj[a].PB(b),adj[b].PB(a); }
	ll sub=0; REP(i,nopp) { int a=opp[i].a,b=opp[i].b,c=opp[i].c; if(ufunite(a,b)) adj[a].PB(b),adj[b].PB(a),sub+=c; }

	par[0]=-1; dfsinit(0);
	REP(i,nopp) { int a=opp[i].a,b=opp[i].b,c=opp[i].c; setlimit(a,b,c); }
	//REP(i,n) { printf("%d: par=%d, lim:",i+1,par[i]==-1?-1:par[i]+1); REPE(k,MAXLG) if(lim[i][k]!=INT_MAX) printf(" %d=%d",k,lim[i][k]); puts(""); }
	ll sum=dfslimit(0);
	return sum==LLONG_MAX?-1:sum-sub;
}


void run() {
	scanf("%d%d%d",&n,&nme,&nopp);
	REP(i,nme) scanf("%d%d",&me[i].a,&me[i].b),--me[i].a,--me[i].b;
	REP(i,nopp) scanf("%d%d%d",&opp[i].a,&opp[i].b,&opp[i].c),--opp[i].a,--opp[i].b;
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}