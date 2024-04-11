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

const int MAXQ=100000;
const int MAXT=2*MAXQ;
const int MAXS=4*MAXT;

int nq;
int qkind[MAXQ],qt[MAXQ],qs[MAXQ],ql[MAXQ],qr[MAXQ],qv[MAXQ]; double qans[MAXQ];

int allt[MAXT],nallt;
map<int,int> have;


ll sdelta[MAXS],smn[MAXS]; bool slazy[MAXS]; int slazyval[MAXS];

void sapply(int x,int l,int r,int val) {
	sdelta[x]=(ll)val*(allt[r+1]-allt[l]),smn[x]=min(0LL,sdelta[x]),slazy[x]=true,slazyval[x]=val;
	//printf("\tsapply(%d,%d..%d,%d) [smn=%lld, sdelta=%lld] <%d,%d>\n",x,l,r,val,smn[x],sdelta[x],allt[r+1],allt[l]);
}
void spush(int x,int l,int m,int r) {
	if(slazy[x]) sapply(2*x+1,l,m,slazyval[x]),sapply(2*x+2,m+1,r,slazyval[x]),slazy[x]=false;
}
void spull(int x) {
	sdelta[x]=sdelta[2*x+1]+sdelta[2*x+2]; smn[x]=min(smn[2*x+1],sdelta[2*x+1]+smn[2*x+2]);
}

void sinit(int x,int l,int r) {
	sdelta[x]=smn[x]=0; slazy[x]=false;
	if(l<r) {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		spull(x);
	}
}
void sset(int x,int l,int r,int L,int R,int VAL) {
	//printf("sset(%d,%d..%d,%d..%d,%d)\n",x,l,r,L,R,VAL);
	if(L<=l&&r<=R) {
		sapply(x,l,r,VAL);
	} else {
		int m=l+(r-l)/2; spush(x,l,m,r);
		if(L<=m) sset(2*x+1,l,m,L,R,VAL);
		if(m+1<=R) sset(2*x+2,m+1,r,L,R,VAL);
		spull(x);
	}
	//printf("sset(%d,%d..%d,%d..%d,%d) [smn=%lld sdelta=%lld]\n",x,l,r,L,R,VAL,smn[x],sdelta[x]);
}
double sget(int x,int l,int r,int L,int R,ll &VAL) {
	//printf("sget(%d,%d..%d,%d..%d,%lld) [smn=%lld sdelta=%lld]\n",x,l,r,L,R,VAL,smn[x],sdelta[x]);
	if(L<=l&&r<=R) {
		if(VAL+smn[x]>0) { VAL+=sdelta[x]; return -1; }
	}
	if(l==r) {
		assert(smn[x]<0);
		double frac=1.0*VAL/-smn[x];
		return allt[l]+frac*(allt[l+1]-allt[l]);
	}
	int m=l+(r-l)/2; spush(x,l,m,r);
	if(L<=m) {
		double sub=sget(2*x+1,l,m,L,R,VAL);
		if(sub!=-1) return sub;
	}
	if(m+1<=R) {
		double sub=sget(2*x+2,m+1,r,L,R,VAL);
		if(sub!=-1) return sub;
	}
	assert(L>l||R<r);
	return -1;
}

void solve() {
	nallt=0; REP(i,nq) if(qkind[i]==1||qkind[i]==2) allt[nallt++]=qt[i]; else allt[nallt++]=ql[i],allt[nallt++]=qr[i];
	sort(allt,allt+nallt); nallt=unique(allt,allt+nallt)-allt;
	//printf("allt:"); REP(i,nallt) printf(" %d",allt[i]); puts("");
	have.clear(); sinit(0,0,nallt-2);
	REP(i,nq) {
		if(qkind[i]==1) {
			int tidx=lower_bound(allt,allt+nallt,qt[i])-allt; if(tidx==nallt-1) continue;
			auto it=have.lower_bound(tidx); assert(it==have.end()||it->first!=tidx);
			sset(0,0,nallt-2,tidx,it==have.end()?nallt-2:it->first-1,qs[i]);
			have[tidx]=qs[i];
		}
		if(qkind[i]==2) {
			int tidx=lower_bound(allt,allt+nallt,qt[i])-allt; if(tidx==nallt-1) continue;
			auto it=have.lower_bound(tidx); assert(it!=have.end()&&it->first==tidx);
			sset(0,0,nallt-2,tidx,next(it)==have.end()?nallt-2:next(it)->first-1,it==have.begin()?0:prev(it)->second);
			have.erase(it);
		}
		if(qkind[i]==3) {
			int lidx=lower_bound(allt,allt+nallt,ql[i])-allt;
			int ridx=lower_bound(allt,allt+nallt,qr[i])-allt;
			ll val=qv[i];
			if(val==0) { qans[i]=ql[i]; continue; }
			auto it=have.lower_bound(lidx);
			if(it==have.end()||it->first>=ridx) { qans[i]=-1; continue; }
			qans[i]=sget(0,0,nallt-2,it->first,ridx-1,val);
		}
	}

}

void run() {
	scanf("%d",&nq);
	REP(i,nq) {
		scanf("%d",&qkind[i]);
		if(qkind[i]==1) scanf("%d%d",&qt[i],&qs[i]);
		if(qkind[i]==2) scanf("%d",&qt[i]);
		if(qkind[i]==3) scanf("%d%d%d",&ql[i],&qr[i],&qv[i]);
	}
	solve();
	REP(i,nq) if(qkind[i]==3) printf("%.15lf\n",qans[i]);
}

int main() {
	run();
	return 0;
}