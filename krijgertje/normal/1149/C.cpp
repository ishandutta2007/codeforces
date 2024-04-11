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
#include <bitset>
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

const int MAXNODE=100000;
const int MAXQ=100000;
const int MAXA=2*MAXNODE-1;
const int MAXS=4*MAXA;
struct S { int mxpath,mxpref,mxsuff,mxnode,mnnode; };

int nnode,nq;
char desc[2*(MAXNODE-1)+1];
int qa[MAXQ],qb[MAXQ],qans[MAXQ+1];

int a[MAXA],na;
S s[MAXS]; int slazy[MAXS];

S smake(int val) {
	S ret;
	ret.mxnode=ret.mnnode=val;
	ret.mxpref=ret.mxsuff=val-2*val;
	ret.mxpath=0;
	return ret;
}
S smerge(const S &a,const S &b) {
	S ret;
	ret.mxnode=max(a.mxnode,b.mxnode);
	ret.mnnode=min(a.mnnode,b.mnnode);
	ret.mxpref=max(max(a.mxpref,b.mxpref),b.mxnode-2*a.mnnode);
	ret.mxsuff=max(max(a.mxsuff,b.mxsuff),a.mxnode-2*b.mnnode);
	ret.mxpath=max(max(a.mxpath,b.mxpath),max(a.mxsuff+b.mxnode,a.mxnode+b.mxpref));
	return ret;
}
void sapply(int x,int by) { slazy[x]+=by; s[x].mxnode+=by; s[x].mnnode+=by; s[x].mxpref-=by; s[x].mxsuff-=by; }
void spull(int x) { s[x]=smerge(s[2*x+1],s[2*x+2]); }
void spush(int x) { if(slazy[x]!=0) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=0; }

void sinit(int x,int l,int r) {
	slazy[x]=0;
	if(l==r) {
		s[x]=smake(a[l]);
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		spull(x);
	}
}
void smod(int x,int l,int r,int L,int R,int BY) {
	//if(x==0) printf("smod(%d,%d..%d,%d..%d,%d)\n",x,l,r,L,R,BY);
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		int m=l+(r-l)/2; spush(x);
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		spull(x);
	}
}

void solve() {
	na=2*(nnode-1)+1; a[0]=0; REP(i,2*nnode-1) a[i+1]=a[i]+(desc[i]=='('?+1:-1);
	//printf("a:"); REP(i,na) printf(" %d",a[i]); puts("");

	sinit(0,0,na-1);
	qans[0]=s[0].mxpath;
	REP(i,nq) {
		int l=min(qa[i],qb[i]),r=max(qa[i],qb[i]);
		if(desc[l]!=desc[r]) {
			int by=desc[l]=='('?-2:+2;
			smod(0,0,na-1,l+1,r,by);
			swap(desc[l],desc[r]);
		}
		qans[i+1]=s[0].mxpath;
	}
}

void run() {
	scanf("%d%d",&nnode,&nq);
	scanf("%s",desc);
	REP(i,nq) scanf("%d%d",&qa[i],&qb[i]),--qa[i],--qb[i];
	solve();
	REPE(i,nq) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}