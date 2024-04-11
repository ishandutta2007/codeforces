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

const int MAXN=1000;
const int MAXM=200000;
const int MAXQ=200000;
const int MAXVAL=(MAXN+63)/64;
typedef struct E { int a,b,pa,pb,na,nb; } E;
typedef struct Q { int l,r,s,t,ret; } Q;
typedef struct R {
	ull val[MAXVAL];
	void clear() { memset(val,0,sizeof(val)); }
	void setbit(int idx) { val[idx/64]|=1ULL<<(idx%64); }
	void setbits(const R &other) { REP(i,MAXVAL) val[i]|=other.val[i]; }
	bool intersect(const R &other) { REP(i,MAXVAL) if(val[i]&other.val[i]) return true; return false; }
} R;


int n,m,nq;
E e[MAXM];
Q q[MAXQ];
int deg[MAXN];
int off[MAXN+1],ee[2*MAXM];

int qnxt[MAXQ];
R canfrom[MAXM/2],canto[MAXM/2];
void solve(int qhead,int l,int m,int r) {
	// bit y is set in canfrom[x] -> from node y at time between m and m+1, we can reach edge m+1+x
	for(int i=m+1;i<=r;++i) {
		//printf("working on canfrom[%d]\n",i-m-1);
		canfrom[i-m-1].clear();
		if(e[i].pa!=-1&&e[i].pa>=m+1) canfrom[i-m-1].setbits(canfrom[e[i].pa-m-1]); 
		if(e[i].pb!=-1&&e[i].pb>=m+1) canfrom[i-m-1].setbits(canfrom[e[i].pb-m-1]);
		canfrom[i-m-1].setbit(e[i].a),canfrom[i-m-1].setbit(e[i].b);
		//REP(j,n) if((canfrom[i-m-1].val[j/64]>>(j%64))&1) printf(" %d",j); puts("");
	}
	for(int i=m;i>=l;--i) {
		//printf("working on canto[%d]\n",i-l);
		canto[i-l].clear();
		if(e[i].na!=-1&&e[i].na<=m) canto[i-l].setbits(canto[e[i].na-l]);
		if(e[i].nb!=-1&&e[i].nb<=m) canto[i-l].setbits(canto[e[i].nb-l]);
		canto[i-l].setbit(e[i].a),canto[i-l].setbit(e[i].b);
		//REP(j,n) if((canto[i-l].val[j/64]>>(j%64))&1) printf(" %d",j); puts("");
	}
	for(int x=qhead;x!=-1;x=qnxt[x]) q[x].ret=canto[q[x].l-l].intersect(canfrom[q[x].r-m-1])?1:0;
}
void solve(int qhead) {
	if(qhead==-1) return;
	int l=q[qhead].l,r=q[qhead].r; for(int x=qnxt[qhead];x!=-1;x=qnxt[x]) { if(q[x].l<l) l=q[x].l; if(q[x].r>r) r=q[x].r; }
	if(l==r) { for(int x=qhead;x!=-1;x=qnxt[x]) q[x].ret=1; return; }
	int m=l+(r-l)/2,lhead=-1,mhead=-1,rhead=-1;
	for(int x=qhead,nx,y;x!=-1;x=nx) {
		nx=qnxt[x];
		if(q[x].r<=m) qnxt[x]=lhead,lhead=x;
		else if(q[x].l>=m+1) qnxt[x]=rhead,rhead=x;
		else qnxt[x]=mhead,mhead=x;
	}
	//for(int x=lhead;x!=-1;x=qnxt[x]) printf("%d ",x); for(int x=mhead;x!=-1;x=qnxt[x]) printf(" %d",x); printf(" "); for(int x=rhead;x!=-1;x=qnxt[x]) printf(" %d",x); puts("");
	solve(mhead,l,m,r);
	solve(lhead);
	solve(rhead);
}

void run() {
	scanf("%d%d%d",&n,&m,&nq);
	REP(i,m) scanf("%d%d",&e[i].a,&e[i].b),--e[i].a,--e[i].b;
	REP(i,nq) scanf("%d%d%d%d",&q[i].l,&q[i].r,&q[i].s,&q[i].t),--q[i].l,--q[i].r,--q[i].s,--q[i].t,q[i].ret=-1;
	REP(i,n) deg[i]=0; REP(i,m) ++deg[e[i].a],++deg[e[i].b];
	off[0]=0; REP(i,n) off[i+1]=off[i]+deg[i];
	REP(i,m) ee[off[e[i].a]++]=i,ee[off[e[i].b]++]=i;
	off[0]=0; REP(i,n) off[i+1]=off[i]+deg[i];
	REP(i,n) REP(j,deg[i]) { int idx=ee[off[i]+j];
		if(e[idx].a==i) e[idx].pa=j==0?-1:ee[off[i]+j-1],e[idx].na=j+1>=deg[i]?-1:ee[off[i]+j+1];
		if(e[idx].b==i) e[idx].pb=j==0?-1:ee[off[i]+j-1],e[idx].nb=j+1>=deg[i]?-1:ee[off[i]+j+1];
	}
	//REP(i,m) printf("%d: %d-%d (%d,%d) (%d,%d)\n",i,e[i].a,e[i].b,e[i].pa,e[i].na,e[i].pb,e[i].nb);
	REP(i,nq) {
		int lidx=lower_bound(ee+off[q[i].s],ee+off[q[i].s+1],q[i].l)-ee-off[q[i].s];
		//printf("L %d,%d -> %d\n",q[i].s,q[i].l,lidx);
		if(lidx==deg[q[i].s]) { q[i].ret=0; continue; } else q[i].l=ee[off[q[i].s]+lidx];
		int ridx=upper_bound(ee+off[q[i].t],ee+off[q[i].t+1],q[i].r)-ee-off[q[i].t];
		//printf("R %d,%d -> %d\n",q[i].t,q[i].r,ridx);
		if(ridx==0) { q[i].ret=0; continue; } else q[i].r=ee[off[q[i].t]+ridx-1];
		if(q[i].l>q[i].r) q[i].ret=0;
	}
	//REP(i,n) printf("%d (deg=%d)\n",off[i],deg[i]);
	//REP(i,n) { REP(j,deg[i]) printf("%d ",ee[off[i]+j]); printf(" "); } puts("");
	//REP(i,nq) if(q[i].ret==-1) printf("%d: %d->%d = %d->%d\n",i,q[i].s,q[i].t,q[i].l,q[i].r);

	int qhead=-1; REP(i,nq) if(q[i].ret==-1) qnxt[i]=qhead,qhead=i;
	solve(qhead);
	REP(i,nq) printf("%s\n",q[i].ret?"Yes":"No");
}

int main() {
	run();
	return 0;
}