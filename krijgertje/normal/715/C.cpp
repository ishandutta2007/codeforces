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

const int MAXN=100000;
const int MAXM=MAXN-1;


int n,MOD;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],gdig[MAXM]; bool gdead[MAXM];
int p10[MAXN+1];
int invp10[MAXN+1];

int sz[MAXN],lst[MAXN],par[MAXN],nlst;
void dfs1(int at) {
	sz[at]=1,lst[nlst++]=at;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) if(!gdead[x>>1]) {
		int to=gto[x]; if(to==par[at]) continue;
		par[to]=at; dfs1(to); sz[at]+=sz[to];
	}
}
int center(int root) {
	nlst=0; par[root]=-1; dfs1(root);
	REP(i,nlst) {
		int at=lst[i],mxcsz=0;
		for(int x=ghead[at];x!=-1;x=gnxt[x]) if(!gdead[x>>1]) {
			int to=gto[x]; if(to==par[at]) continue;
			if(sz[to]>mxcsz) mxcsz=sz[to];
		}
		if(2*mxcsz<=sz[root]&&2*sz[at]>=sz[root]) return at;
	}
	assert(false);
}

int up[MAXN],dn[MAXN],d[MAXN];
void dfs2(int at) {
	lst[nlst++]=at;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) if(!gdead[x>>1]) {
		int to=gto[x]; if(to==par[at]) continue;
		par[to]=at; d[to]=d[at]+1; up[to]=(up[at]+(ll)p10[d[at]]*gdig[x>>1])%MOD; dn[to]=((ll)dn[at]*10+gdig[x>>1])%MOD;
		dfs2(to);
	}
}

int allup[MAXN],nallup,upidx[MAXN],cnt[MAXN];
void dfs3(int at,int by) {
	cnt[upidx[at]]+=by;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) if(!gdead[x>>1]) {
		int to=gto[x]; if(to==par[at]) continue;
		dfs3(to,by);
	}
}
// up[a]*p10[d[b]]+dn[b] = 0 (mod MOD)
// up[a] = -dn[b]*inv[p10[d[b]] (mod MOD)
ll dfs4(int at) {
	ll ret=0;
	int want=(ll)(MOD-dn[at])*invp10[d[at]]%MOD;
	int idx=lower_bound(allup,allup+nallup,want)-allup;
	if(idx<nallup&&allup[idx]==want) ret+=cnt[idx];
	if(up[at]==0) ++ret; if(dn[at]==0) ++ret;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) if(!gdead[x>>1]) {
		int to=gto[x]; if(to==par[at]) continue;
		ret+=dfs4(to);
	}
	return ret;
}

ll go(int root,int depth=0) {
	root=center(root);
	ll ret=0;
	
	nlst=0; par[root]=-1,d[root]=0,up[root]=dn[root]=0; dfs2(root);
	//REP(i,depth) printf("  "); printf("%d:",root); REP(i,nlst) printf(" %d=(%d,%d,%d)",lst[i],d[lst[i]],up[lst[i]],dn[lst[i]]); puts("");
	nallup=0; FOR(i,1,nlst) allup[nallup++]=up[lst[i]]; sort(allup,allup+nallup); nallup=unique(allup,allup+nallup)-allup;
	FOR(i,1,nlst) upidx[lst[i]]=lower_bound(allup,allup+nallup,up[lst[i]])-allup;
	REP(i,nallup) cnt[i]=0; FOR(i,1,nlst) ++cnt[upidx[lst[i]]];
	//REP(i,depth) printf("  "); REP(i,nallup) printf("%d times %d ",cnt[i],allup[i]); puts("");
	for(int x=ghead[root];x!=-1;x=gnxt[x]) if(!gdead[x>>1]) {
		int to=gto[x];
		dfs3(to,-1);
		ret+=dfs4(to);
		dfs3(to,+1);
	}

	for(int x=ghead[root];x!=-1;x=gnxt[x]) if(!gdead[x>>1]) {
		int to=gto[x];
		gdead[x>>1]=true; ret+=go(to,depth+1);
	}
	return ret;
}

// x*a+y*b=g
int egcd(int a,int b,int &x,int &y) {
	if(b==0) { x=1,y=0; return a; }
	int ret=egcd(b,a%b,x,y);
	swap(x,y); y-=x*(a/b);
	return ret;
}

void run() {
	scanf("%d%d",&n,&MOD);
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d%d",&a,&b,&gdig[i]); gdead[i]=false;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}
	p10[0]=1; FORE(i,1,n) p10[i]=(ll)p10[i-1]*10%MOD;
	int x,y,g=egcd(10,MOD,x,y); assert(g==1);
	int inv10=x; if(inv10<0) inv10+=MOD;
	invp10[0]=1; FORE(i,1,n) invp10[i]=(ll)invp10[i-1]*inv10%MOD;
	ll ret=go(0);
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}