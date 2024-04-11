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

const int MAXN=500000;
const int MAXS=4*MAXN;
typedef struct S { int besta,bestb; int mna,mnb; int mna2,mnb2; int mnf,lazyf; } S;

int n,need;
int a[MAXN],b[MAXN];
S s[MAXS];

void updatea(int &pa,int na) { if(na!=-1&&(pa==-1||a[na]<a[pa])) pa=na; }
void updateb(int &pb,int nb) { if(nb!=-1&&(pb==-1||b[nb]<b[pb])) pb=nb; }
void updateab(int &pa,int &pb,int na,int nb) { if(na!=-1&&nb!=-1&&(pa==-1||pb==-1||a[na]+b[nb]<a[pa]+b[pb])) pa=na,pb=nb; }
void scalc(int x) {
	s[x].mnf=s[x].lazyf+min(s[2*x+1].mnf,s[2*x+2].mnf);
	s[x].besta=s[x].bestb=s[x].mna=s[x].mnb=s[x].mna2=s[x].mnb2=-1;
	bool lftmn=s[x].lazyf+s[2*x+1].mnf==s[x].mnf;
	bool rgtmn=s[x].lazyf+s[2*x+2].mnf==s[x].mnf;
	if(!lftmn) updateab(s[x].besta,s[x].bestb,s[2*x+1].mna,s[2*x+1].mnb); else updateab(s[x].besta,s[x].bestb,s[2*x+1].besta,s[2*x+1].bestb);
	if(!rgtmn) updateab(s[x].besta,s[x].bestb,s[2*x+2].mna,s[2*x+2].mnb); else updateab(s[x].besta,s[x].bestb,s[2*x+2].besta,s[2*x+2].bestb);
	updateab(s[x].besta,s[x].bestb,s[2*x+1].mna,s[2*x+2].mnb);
	updateab(s[x].besta,s[x].bestb,!rgtmn?s[2*x+2].mna:s[2*x+2].mna2,!lftmn?s[2*x+1].mnb:s[2*x+1].mnb2);
	updatea(s[x].mna,s[2*x+1].mna);
	updatea(s[x].mna,s[2*x+2].mna);
	updateb(s[x].mnb,s[2*x+1].mnb);
	updateb(s[x].mnb,s[2*x+2].mnb);
	updatea(s[x].mna2,!lftmn?s[2*x+1].mna:s[2*x+1].mna2);
	if(!lftmn) updatea(s[x].mna2,!rgtmn?s[2*x+2].mna:s[2*x+2].mna2);
	updateb(s[x].mnb2,!rgtmn?s[2*x+2].mnb:s[2*x+2].mnb2);
	if(!rgtmn) updateb(s[x].mnb2,!lftmn?s[2*x+1].mnb:s[2*x+1].mnb2);
	//printf("%d -> best=(%d,%d) mn=(%d,%d) mn2=(%d,%d) f=(%d,%d)\n",x,s[x].besta,s[x].bestb,s[x].mna,s[x].mnb,s[x].mna2,s[x].mnb2,s[x].mnf,s[x].lazyf);
}
void sapply(int x,int by,bool isleaf) {
	s[x].mnf+=by,s[x].lazyf+=by;
	if(!isleaf) scalc(x);
}
void spush(int x,int l,int m,int r) {
	if(s[x].lazyf==0) return;
	sapply(2*x+1,s[x].lazyf,l==m);
	sapply(2*x+2,s[x].lazyf,m+1==r);
	s[x].lazyf=0;
}

void sinit(int x,int l,int r) {
	s[x].lazyf=0;
	if(l==r) {
		s[x].mnf=0; s[x].besta=s[x].bestb=s[x].mna=s[x].mnb=s[x].mna2=l,s[x].mnb2=-1;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		scalc(x);
	}
}
void skilla(int x,int l,int r,int IDX) {
	//printf("skilla(%d,%d..%d,%d)\n",x,l,r,IDX);
	if(l==r) {
		s[x].besta=s[x].bestb=s[x].mna=s[x].mna2=-1;
	} else {
		int m=l+(r-l)/2;
		spush(x,l,m,r);
		if(IDX<=m) skilla(2*x+1,l,m,IDX);
		if(m+1<=IDX) skilla(2*x+2,m+1,r,IDX);
		scalc(x);
	}
}
void skillb(int x,int l,int r,int IDX) {
	if(l==r) {
		s[x].besta=s[x].bestb=s[x].mnb=s[x].mnb2=-1;
	} else {
		int m=l+(r-l)/2;
		spush(x,l,m,r);
		if(IDX<=m) skillb(2*x+1,l,m,IDX);
		if(m+1<=IDX) skillb(2*x+2,m+1,r,IDX);
		scalc(x);
	}
}
void smod(int x,int l,int r,int L,int R,int BY) {
	if(L<=l&&r<=R) {
		sapply(x,BY,l==r);
	} else {
		int m=l+(r-l)/2;
		spush(x,l,m,r);
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		scalc(x);
	}
}

ll solve() {
	sinit(0,0,n-1);
	ll ret=0;
	REP(i,need) {
		int ai=s[0].besta,bi=s[0].bestb;
		//printf("ai=%d bi=%d\n",ai,bi);
		assert(ai!=-1&&bi!=-1);
		ret+=a[ai]+b[bi];
		//printf("killing a\n");
		skilla(0,0,n-1,ai);
		//printf("killing b\n");
		skillb(0,0,n-1,bi);
		//printf("updating flow\n");
		if(ai<bi) smod(0,0,n-1,ai,bi-1,+1);
		if(ai>bi) smod(0,0,n-1,bi,ai-1,-1);
	}
	return ret;
}



void run() {
	scanf("%d%d",&n,&need);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);
	printf("%lld\n",solve());	
}

const int MAXTN=2200;
const int MAXGN=2*MAXTN+2;
const int MAXGM=4*MAXTN;

typedef struct MCMF {
	int n,m;
	int ghead[MAXGN],gnxt[2*MAXGM],gto[2*MAXGM],gcap[2*MAXGM],gcost[2*MAXGM];
	ll d[MAXGN]; int bck[MAXGN];
	ll pot[MAXGN];

	void init(int _n) { n=_n,m=0; REP(i,n) ghead[i]=-1,pot[i]=0; }
	void addedge(int a,int b,int c,int d) { gnxt[m]=ghead[a],ghead[a]=m,gto[m]=b,gcap[m]=c,gcost[m]=d,++m; gnxt[m]=ghead[b],ghead[b]=m,gto[m]=a,gcap[m]=0,gcost[m]=-d,++m; }
	pair<int,ll> solve(int s,int t,int lim) {
		pair<int,ll> ret=MP(0,0);
		while(ret.first<lim) {
			REP(i,n) d[i]=LLONG_MAX,bck[i]=-1; d[s]=0,bck[s]=-2;
			priority_queue<pair<ll,int> > q; q.push(MP(-d[s],s));
			while(!q.empty()) {
				ll cost=-q.top().first; int at=q.top().second; q.pop();
				if(cost>d[at]) continue;
				for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gcap[x]>0) {
					int to=gto[x]; ll rcost=gcost[x]-pot[at]+pot[to]; if(d[at]+rcost>=d[to]) continue;
					d[to]=d[at]+rcost; bck[to]=x^1; q.push(MP(-d[to],to));
				}
			}
			if(d[t]==LLONG_MAX) break;
			++ret.first,ret.second+=d[t]-pot[t];
			REP(i,n) if(d[i]!=LLONG_MAX) pot[i]-=d[i];

			for(int at=t;at!=s;at=gto[bck[at]]) {
				++gcap[bck[at]]; --gcap[bck[at]^1];
			}
		}
		return ret;
	}
} MCMF;
MCMF g;

ll solveflow() {
	g.init(2*n+2); int s=2*n,t=s+1;
	REP(i,n) g.addedge(s,i,1,0);
	REP(i,n) g.addedge(i,n+i,1,a[i]);
	REP(i,n) g.addedge(n+i,t,1,b[i]);
	REP(i,n-1) g.addedge(n+i,n+i+1,n,0);
	pair<int,ll> res=g.solve(s,t,need);
	return res.second;
}

void stress() {
	while(true) {
		n=100,need=50;
		REP(i,n) a[i]=rand()%1000+1;
		REP(i,n) b[i]=rand()%1000+1;
		ll have=solve(),want=solveflow();
		printf("have=%lld want=%lld\n",have,want);
		if(have==want) continue;
		printf("%d %d\n",n,need);
		REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
		REP(i,n) { if(i!=0) printf(" "); printf("%d",b[i]); } puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}