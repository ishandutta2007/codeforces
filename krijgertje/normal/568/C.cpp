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

const int MAXALPH=26;
const int MAXLEN=200;
const int MAXN=2*MAXLEN;
const int MAXRULE=4*MAXLEN*(MAXLEN-1);
const int MAXM=2*MAXRULE+MAXLEN;


char alph[MAXALPH+1]; int alphlen;
int wlen,nrule;
char s[MAXLEN+1];

int n,m;
int head[MAXN];
int nxt[MAXM],from[MAXM],to[MAXM];

int comp[MAXN],ncomp;
int d[MAXN],dmin[MAXN];
int stck[MAXN],nstck;
void tarjan(int at,int par) {
	d[at]=dmin[at]=par==-1?0:d[par]+1;
	stck[nstck++]=at;
	for(int x=head[at];x!=-1;x=nxt[x]) {
		if(d[to[x]]==-1) {
			tarjan(to[x],at);
			if(dmin[to[x]]<dmin[at]) dmin[at]=dmin[to[x]];
		} else if(comp[to[x]]==-1) {
			if(d[to[x]]<dmin[at]) dmin[at]=d[to[x]];
		}
	}
	if(dmin[at]==d[at]) { while(stck[nstck-1]!=at) comp[stck[--nstck]]=ncomp; comp[stck[--nstck]]=ncomp; ++ncomp; }
}

bool ok() {
	//printf("checking %d:",m); REP(i,m) printf(" %d->%d",from[i],to[i]); puts("");
	REP(i,n) comp[i]=d[i]=dmin[i]=-1; ncomp=nstck=0;
	REP(i,n) if(comp[i]==-1) tarjan(i,-1);
	//REP(i,n) printf("%d ",comp[i]); puts("");
	REP(i,wlen) if(comp[2*i]==comp[2*i+1]) return false;
	return true;
}
void addedge(int ai,int bi) { nxt[m]=head[ai]; head[ai]=m; from[m]=ai; to[m]=bi; ++m; }
void remedge() { --m; head[from[m]]=nxt[head[from[m]]]; }

void run() {
	scanf("%s",alph); alphlen=strlen(alph);
	scanf("%d%d",&wlen,&nrule);
	n=2*wlen,m=0;
	REP(i,n) head[i]=-1;
	REP(i,nrule) {
		int a; char ac; int b; char bc; scanf("%d %c %d %c",&a,&ac,&b,&bc),--a,--b; int ai=2*a+(ac=='V'?0:1),bi=2*b+(bc=='V'?0:1);
		addedge(ai,bi);
		addedge(bi^1,ai^1);
	}
	scanf("%s",s);
	REP(i,wlen) {
		int a=i; char ac=alph[s[i]-'a']; int ai=2*a+(ac=='V'?0:1);
		addedge(ai^1,ai);
	}
	int clen=wlen;
	while(!ok()) {
		if(clen==0) { printf("-1\n"); return; }
		--clen; remedge();
	}
	if(clen==wlen) { printf("%s\n",s); return; }
	while(true) {
		int donemask=0; bool found=false;
		FOR(i,s[clen]-'a'+1,alphlen) {
			int a=clen; char ac=alph[i]; int ai=2*a+(ac=='V'?0:1); if(donemask&(1<<(ac=='V'?0:1))) continue;
			addedge(ai^1,ai);
			if(ok()) { s[clen++]='a'+i; found=true; break; }
			remedge(); donemask|=1<<(ac=='V'?0:1);
		}
		if(found) break;
		if(clen==0) { printf("-1\n"); return; }
		--clen, remedge();
	}
	while(clen<wlen) {
		int donemask=0; bool found=false;
		REP(i,alphlen) {
			int a=clen; char ac=alph[i]; int ai=2*a+(ac=='V'?0:1); if(donemask&(1<<(ac=='V'?0:1))) continue;
			addedge(ai^1,ai);
			if(ok()) { s[clen++]='a'+i; found=true; break; }
			remedge(); donemask|=1<<(ac=='V'?0:1);
		}
		if(!found) { printf("-1\n"); return; }
	}
	printf("%s\n",s);
}

int main() {
	run();
	return 0;
}