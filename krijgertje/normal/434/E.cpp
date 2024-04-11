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
int mypow(int x,int n,int mod) { if(n==0) return 1; if(n%2==1) return (ll)mypow(x,n-1,mod)*x%mod; return mypow((ll)x*x%mod,n/2,mod); }

typedef struct Path { int node,G,len; Path() {} Path(int node,int G,int len):node(node),G(G),len(len) {} } Path;

int n,MOD,mult,want;
int val[100000];
bool dead[100000];
int pmult[100001];
int pinv[100001];

int fst[100000];
int nxt[200000];
int to[200000];

int sz[100000];
int maxchild[100000];
void getsize(int at,int par)  {
	sz[at]=1,maxchild[at]=0;
	for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=par&&!dead[to[x]]) { getsize(to[x],at); sz[at]+=sz[to[x]]; if(sz[to[x]]>maxchild[at]) maxchild[at]=sz[to[x]]; }
}

int dfscenter(int at,int par,int totsz) {
	int ret=at;
	for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=par&&!dead[to[x]]) {
		int cur=dfscenter(to[x],at,totsz);
		if(max(maxchild[cur],totsz-sz[cur])<max(maxchild[ret],totsz-sz[ret])) ret=cur;
	}
	return ret;
}

int center(int at) {
	getsize(at,-1);
	return dfscenter(at,-1,sz[at]);
}

int npath;
Path pfm[200000];
Path pto[200000];
void create(int at,int par,int Gfm,int Gto,int len) {
	pfm[npath]=Path(at,Gfm,len); pto[npath]=Path(at,Gto,len); ++npath;
	for(int x=fst[at];x!=-1;x=nxt[x]) if(to[x]!=par&&!dead[to[x]]) create(to[x],at,(val[to[x]]+(ll)Gfm*mult)%MOD,(Gto+(ll)pmult[len]*val[to[x]])%MOD,len+1);
}

int have[100000],nhave;
int cnt(int key) {
	int l=-1,h=nhave; // (l,h]
	while(l+1<h) { int m=l+(h-l)/2; if(have[m]>=key) h=m; else l=m; }
	int a=h;
	if(a==nhave||have[a]!=key) return 0;
	l=a,h=nhave; // [l,h)
	while(l+1<h) { int m=l+(h-l)/2; if(have[m]<=key) l=m; else h=m; }
	int b=l;
	return b-a+1;
}

int in[100000];
int out[100000];
int calcwantto(const Path &p) { return (ll)(MOD+want-p.G)*pinv[p.len-1]%MOD; }
void modify(int a,int b,int by) {
//	FOR(i,a,b) printf("%d:%d ",pfm[i].node,calcwantto(pfm[i])); puts("");
	nhave=0; FOR(i,a,b) have[nhave++]=pto[i].G; sort(have,have+nhave); //REP(i,nhave) printf("%d ",have[i]); puts("");
	FOR(i,a,b) {
		int cur=cnt(calcwantto(pfm[i])); out[pfm[i].node]+=cur*by;
//		if(cur!=0) printf("\tfound %d paths from %d (%d)\n",cur,pfm[i].node,by);
	}
	nhave=0; FOR(i,a,b) have[nhave++]=calcwantto(pfm[i]); sort(have,have+nhave); //REP(i,nhave) printf("%d ",have[i]); puts("");
	FOR(i,a,b) {
		int cur=cnt(pto[i].G); in[pto[i].node]+=cur*by;
//		if(cur!=0) printf("\tfound %d paths to %d (%d)\n",cur,pto[i].node,by);
	}
}

void go(int at) {
//	printf("go(%d)\n",at);
	at=center(at);
//	printf("center=%d\n",at,at);

	npath=0;
	pfm[npath]=Path(at,val[at],1); pto[npath]=Path(at,0,1); ++npath;
	for(int x=fst[at];x!=-1;x=nxt[x]) if(!dead[to[x]]) {
		int onpath=npath;
		create(to[x],at,(val[to[x]]+(ll)mult*val[at])%MOD,(ll)mult*val[to[x]]%MOD,2);
		modify(onpath,npath,-1);
	}
	modify(0,npath,+1);
//	printf("fm: "); REP(i,npath) printf("(%d,%d,%d)",pfm[i].node,pfm[i].G,pfm[i].len); puts("");
//	printf("to: "); REP(i,npath) printf("(%d,%d,%d)",pto[i].node,pto[i].G,pto[i].len); puts("");

	dead[at]=true;
	for(int x=fst[at];x!=-1;x=nxt[x]) if(!dead[to[x]]) go(to[x]);
}

void run() {
	scanf("%d%d%d%d",&n,&MOD,&mult,&want);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; to[2*i+0]=b; fst[a]=2*i+0;
		nxt[2*i+1]=fst[b]; to[2*i+1]=a; fst[b]=2*i+1;
	}

	REP(i,n) dead[i]=false;
	REP(i,n) in[i]=out[i]=0;
	pmult[0]=1; FORE(i,1,n) pmult[i]=(ll)pmult[i-1]*mult%MOD;
	pinv[0]=1; pinv[1]=mypow(mult,MOD-2,MOD); FORE(i,2,n) pinv[i]=(ll)pinv[i-1]*pinv[1]%MOD;

//	REP(i,n) { npath=0; create(i,-1,0,val[i],1); REP(j,npath) printf("%d-%d = %d (%d)\n",i,pto[j].node,pto[j].G,pto[j].len); }

	go(0);
//	REP(i,n) printf("%d: %d/%d\n",i,out[i],in[i]);

	ll twicebad=0;
	REP(i,n) twicebad+=(ll)2*out[i]*(n-out[i])+(ll)2*in[i]*(n-in[i])+(ll)out[i]*(n-in[i])+(ll)(n-out[i])*in[i];
//	printf("%lld\n",twicebad);
	ll ret=(ll)n*n*n-twicebad/2;
	cout<<ret<<endl;
//	REPE(i,n) printf("p%d: %d/%d\n",i,pmult[i],pinv[i]);
}

int main() {
	run();
	return 0;
}