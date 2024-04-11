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
const int MAXM=MAXN-1;

int n;
int chead[MAXN],cnxt[MAXN],par[MAXN];
int sz[MAXN],heavy[MAXN],d[MAXN];
int hroot[MAXN],hidx[MAXN],nhidx;

int ret[MAXN],gmx;

int lmx1[MAXN],lto1[MAXN],lmx2[MAXN],lto2[MAXN];


int slazy[4*MAXN];
int smx[4*MAXN];

void sinit(int x,int l,int r) {
	if(l==r) {
		smx[x]=-n;
		slazy[x]=-n;
		return;
	}
	int m=l+(r-l)/2;
	sinit(2*x+1,l,m);
	sinit(2*x+2,m+1,r);
	smx[x]=max(smx[2*x+1],smx[2*x+2]);
	slazy[x]=-n;
}
void sset(int x,int l,int r,int IDX,int VAL) {
	//if(x==0) printf("sset(%d,%d)\n",IDX,VAL,VAL);
	if(l==r) {
		smx[x]=VAL;
		if(VAL+slazy[x]>gmx) {
			//printf("sset(%d,%d) -> %d+%d [%d] (%d..%d)\n",IDX,VAL,VAL,slazy[x],x,l,r);
			gmx=VAL+slazy[x];
		}
		return;
	}
	int m=l+(r-l)/2;
	if(slazy[x]>slazy[2*x+1]) slazy[2*x+1]=slazy[x];
	if(slazy[x]>slazy[2*x+2]) slazy[2*x+2]=slazy[x];
	if(IDX<=m) sset(2*x+1,l,m,IDX,VAL);
	if(IDX>=m+1) sset(2*x+2,m+1,r,IDX,VAL);
	smx[x]=max(smx[2*x+1],smx[2*x+2]);
}
void supdate(int x,int l,int r,int L,int R,int VAL) {
	//if(x==0) printf("supdate(%d,%d,%d)\n",L,R,VAL);
	if(L<=l&&r<=R) {
		if(VAL>slazy[x]) slazy[x]=VAL;
		if(VAL+smx[x]>gmx) {
			//printf("supdate(%d,%d,%d) -> %d+%d\n",L,R,VAL,VAL,smx[x]);
			gmx=VAL+smx[x];
		}
		return;
	}
	int m=l+(r-l)/2;
	if(slazy[x]>slazy[2*x+1]) slazy[2*x+1]=slazy[x];
	if(slazy[x]>slazy[2*x+2]) slazy[2*x+2]=slazy[x];
	if(L<=m) supdate(2*x+1,l,m,L,R,VAL);
	if(m+1<=R) supdate(2*x+2,m+1,r,L,R,VAL);
}


void lupdate(int at,int to,int val) {
	if(to==lto1[at]) { if(val>lmx1[at]) lmx1[at]=val; }
	else if(to==lto2[at]) { if(val>lmx2[at]) lmx2[at]=val; if(lmx2[at]>lmx1[at]) swap(lmx1[at],lmx2[at]),swap(lto1[at],lto2[at]); }
	else if(val>lmx1[at]) { lmx2[at]=lmx1[at]; lto2[at]=lto1[at]; lmx1[at]=val; lto1[at]=to; }
	else if(val>lmx2[at]) { lmx2[at]=val; lto2[at]=to; }
	int cur=lmx1[at]+lmx2[at]-2*d[at]; if(cur>gmx) gmx=cur;
	sset(0,0,n-1,hidx[at],lmx1[at]-2*d[at]);
}

void input() {
	scanf("%d",&n);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
}

void solve() {
	REP(i,n) chead[i]=-1;
	FOR(i,1,n) cnxt[i]=chead[par[i]],chead[par[i]]=i;
	REP(i,n) sz[i]=1;
	for(int i=n-1;i>=1;--i) sz[par[i]]+=sz[i];
	REP(i,n) heavy[i]=-1;
	FOR(i,1,n) if(heavy[par[i]]==-1||sz[i]>sz[heavy[par[i]]]) heavy[par[i]]=i;
	d[0]=0; FOR(i,1,n) d[i]=d[par[i]]+1;
	nhidx=0; REP(i,n) hidx[i]=hroot[i]=-1;
	REP(i,n) if(hroot[i]==-1) for(int x=i;x!=-1;x=heavy[x]) hroot[x]=i,hidx[x]=nhidx++;

	//REP(i,n) printf("%d: sz=%d, heavy=%d, d=%d, hidx=%d, hroot=%d\n",i,sz[i],heavy[i],d[i],hidx[i],hroot[i]);

	gmx=0; sinit(0,0,n-1);
	REP(i,n) lmx1[i]=d[i],lmx2[i]=d[i],lto1[i]=i,lto2[i]=i;
	sset(0,0,n-1,hidx[0],0);
	FOR(i,1,n) {
		int at=i;
		sset(0,0,n-1,hidx[at],-d[at]);
		while(at!=0) {
			if(at==heavy[par[at]]) {
				supdate(0,0,n-1,hidx[hroot[at]],hidx[par[at]],d[i]);
				at=hroot[at];
			} else {
				lupdate(par[at],at,d[i]);
				at=par[at];
			}
		}
		ret[i]=gmx;
		//printf("%d=%d\n",i,gmx);
	}
}

void output() {
	FOR(i,1,n) { if(i!=1) printf(" "); printf("%d",ret[i]); } puts("");
}

void run() {
	input();
	solve();
	output();
}

int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int q[MAXN],qhead,qtail;
int dst[MAXN];

pair<int,int> furthest(int s) {
	REP(i,n) dst[i]=INT_MAX;
	qhead=qtail=0; q[qhead++]=s; dst[s]=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x];
			if(dst[to]!=INT_MAX) continue;
			q[qhead++]=to; dst[to]=dst[at]+1;
		}
	}
	int lst=q[qhead-1];
	return MP(dst[lst],lst);
}

int diam() {
	int a=furthest(0).second;
	return furthest(a).first;
}

int main() {
	run(); return 0;
	/*while(true) {
		n=5000;
		par[0]=-1; FOR(i,1,n) par[i]=rand()%i;
		solve();
		REP(i,n) ghead[i]=-1;
		REP(i,n-1) {
			int a=i+1,b=par[i+1];
			gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
			gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
			int want=diam(),have=ret[i+1];
			if(want!=have) {
				printf("%d: err %d vs %d\n",i,want,have);
				printf("%d\n",n); FOR(i,1,n) printf("%d\n",par[i]+1);
				exit(0);
			}
		}
		printf(".");
	}*/
	return 0;
}