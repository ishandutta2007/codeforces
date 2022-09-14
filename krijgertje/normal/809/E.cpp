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
const int MAXGN=MAXN;
const int MAXGM=MAXGN-1;
const int MOD=1000000007;

typedef struct G {
	int n,m;
	int ghead[MAXGN],gnxt[2*MAXGM],gto[2*MAXGM];

	int sz[MAXGN];
	bool dead[MAXGN];

	int c[MAXGN],nc;
	int lst[MAXGN],nlst;
	int off[MAXGN+1];
	int d[MAXGN];

	void (*process)(int root);

	void init(int _n) { n=_n,m=0; REP(i,n) ghead[i]=-1; }
	void addedge(int a,int b) {
		gnxt[m]=ghead[a],ghead[a]=m,gto[m]=b,++m;
		gnxt[m]=ghead[b],ghead[b]=m,gto[m]=a,++m;
	}
	void dfssz(int at,int par) {
		//printf("dfssz(%d,%d)\n",at,par);
		sz[at]=1;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x]; if(to==par||dead[to]) continue;
			dfssz(to,at); sz[at]+=sz[to];
		}
	}
	int dfsfind(int at,int par,int szroot) {
		//printf("dfsfind(%d,%d,%d)\n",at,par,szroot);
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x]; if(to==par||dead[to]) continue;
			if(2*sz[to]>=szroot) return dfsfind(to,at,szroot);
		}
		return at;
	}
	int centroid(int at) {
		dfssz(at,-1); return dfsfind(at,-1,sz[at]);
	}
	void decompose(int at) {
		at=centroid(at);
		process(at);
		dead[at]=true;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x]; if(dead[to]) continue;
			decompose(to);
		}
	}
	void decompose() {
		//REP(i,n) { printf("%d:",i); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d",gto[x]); puts(""); }
		REP(i,n) dead[i]=false;
		decompose(0);
	}
	void dfs(int at,int par) {
		d[at]=d[par]+1; lst[nlst++]=at;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x]; if(to==par||dead[to]) continue;
			dfs(to,at);
		}
	}
	void calcsubtrees(int root) {
		nc=0,nlst=0; d[root]=0; off[0]=0;
		for(int x=ghead[root];x!=-1;x=gnxt[x]) {
			int to=gto[x]; if(dead[to]) continue;
			c[nc++]=to; dfs(to,root); off[nc]=nlst;
		}
	}
} G;
G g;

vector<int> pr;
int pmn[MAXN+1];
vector<int> dv[MAXN+1];
int mu[MAXN+1];
int phi[MAXN+1];
int f[MAXN+1];
int inv[MAXN+1];

int mypow(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }
void precalcnumtheory() {
	pr.clear(); memset(pmn,0,sizeof(pmn));
	FORE(i,2,MAXN) { if(pmn[i]==0) { pmn[i]=i; pr.PB(i); } for(int j=0;j<SZ(pr)&&pr[j]<=pmn[i]&&i*pr[j]<=MAXN;++j) pmn[i*pr[j]]=pr[j]; }
	phi[1]=1,mu[1]=1; FORE(i,2,MAXN) { int j=i/pmn[i]; phi[i]=phi[j]*(pmn[j]==pmn[i]?pmn[i]:pmn[i]-1); mu[i]=pmn[j]==pmn[i]?0:-mu[j]; }
	dv[1].PB(1); FORE(i,2,MAXN) { int j=i/pmn[i],t=pmn[i]; REPSZ(k,dv[j]) dv[i].PB(dv[j][k]); while(j%pmn[i]==0) j/=pmn[i],t*=pmn[i]; REPSZ(k,dv[j]) dv[i].PB(t*dv[j][k]); }
	inv[1]=1; FORE(i,2,MAXN) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	FORE(i,1,MAXN) for(int j=i;j<=MAXN;j+=i) f[j]=(f[j]+MOD+(ll)i*inv[phi[i]]%MOD*mu[j/i])%MOD;
	//FORE(i,1,100) { printf("%3d: pmn=%2d phi=%2d mu=%2d dv=",i,pmn[i],phi[i],mu[i]); REPSZ(j,dv[i]) { if(j!=0) printf(","); printf("%d",dv[i][j]); } puts(""); }
}

int sum1[MAXN+1];
int sum2[MAXN+1];

int calc(int val,int depth) {
	//printf("calc(%d,%d)\n",val,depth);
	int ret=0;
	REPSZ(i,dv[val]) {
		int d=dv[val][i];
		//printf("\t%d: %d*(%d*%d+%d)\n",d,f[d],depth,sum1[d],sum2[d]);
		ret=(ret+(ll)f[d]*((ll)depth*sum1[d]%MOD+sum2[d]))%MOD;
	}
	ret=(ll)ret*phi[val]%MOD;
	//printf("->%d\n",ret);
	return ret;
}
void addtosum(int val,int depth) {
	//printf("addtosum(%d,%d)\n",val,depth);
	REPSZ(i,dv[val]) {
		int d=dv[val][i];
		sum1[d]=(sum1[d]+phi[val])%MOD;
		sum2[d]=(sum2[d]+(ll)phi[val]*depth%MOD)%MOD;
	}
}
void clearfromsum(int val) {
	REPSZ(i,dv[val]) {
		int d=dv[val][i];
		sum1[d]=sum2[d]=0;
	}
}

int n;
int a[MAXN];
int ans;

void processcentroid(int root) {
	//printf("processcentroid(%d)\n",root);
	addtosum(a[root],0);
	g.calcsubtrees(root);
	//REP(i,g.nc) { printf("%d:",g.c[i]); FOR(j,g.off[i],g.off[i+1]) printf(" %d",g.lst[j]); puts(""); }
	REP(i,g.nc) {
		int c=g.c[i];
		FOR(j,g.off[i],g.off[i+1]) {
			int x=g.lst[j];
			ans=(ans+calc(a[x],g.d[x]))%MOD;
		}
		FOR(j,g.off[i],g.off[i+1]) {
			int x=g.lst[j];
			addtosum(a[x],g.d[x]);
		}
	}
	clearfromsum(a[root]);
	REP(j,g.nlst) {
		int x=g.lst[j];
		clearfromsum(a[x]);
	}
}


void run() {
	precalcnumtheory();
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]); g.init(n); REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; g.addedge(a,b); }
	ans=0; g.process=&processcentroid; g.decompose();
	int ret=(ll)ans*mypow((ll)n*(n-1)/2%MOD,MOD-2)%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}