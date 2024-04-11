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

const int MAXN=100000;
const int MAXS=4*(MAXN+1);

int n;
ll len[MAXN];
char kind[MAXN+1];

ll stamina[MAXN+1];

ll sval[MAXS],slazy[MAXS]; int sidx[MAXS];

void sapply(int x,ll by) { sval[x]+=by; slazy[x]+=by; }
void spush(int x) { if(slazy[x]!=0) sapply(2*x+1,slazy[x]),sapply(2*x+2,slazy[x]),slazy[x]=0; }
void spull(int x) { if(sval[2*x+1]<sval[2*x+2]) sval[x]=sval[2*x+1],sidx[x]=sidx[2*x+1]; else sval[x]=sval[2*x+2],sidx[x]=sidx[2*x+2]; }
void sinit(int x,int l,int r) {
	slazy[x]=0;
	if(l==r) {
		sval[x]=stamina[l]; sidx[x]=l;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		spull(x);
	}
}
void smod(int x,int l,int r,int L,int R,ll BY) {
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		int m=l+(r-l)/2; spush(x);
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		spull(x);
	}
}
ll sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2; spush(x);
		ll ret=LLONG_MAX;
		if(L<=m) ret=min(ret,sget(2*x+1,l,m,L,R));
		if(m+1<=R) ret=min(ret,sget(2*x+2,m+1,r,L,R));
		spull(x);
		return ret;
	}
}

ll solve() {
	stamina[0]=0; ll ret=0;
	REP(i,n) {
		stamina[i+1]=stamina[i]+(kind[i]=='L'?-1:+1)*len[i];
		ret+=(kind[i]=='L'?1:kind[i]=='W'?3:5)*len[i];
	}
	int firstwater=n; REP(i,n) if(kind[i]=='W') { firstwater=i; break; }
	int mnbeforewater=0; REPE(i,n) if(i<=firstwater&&stamina[i]<stamina[mnbeforewater]) mnbeforewater=i;
	if(stamina[mnbeforewater]<0) {
		assert(kind[0]=='G');
		ll need=-stamina[mnbeforewater];
		ret+=5*need;
		REPE(i,n) stamina[i]+=need;
	}
	int mnglob=0; REPE(i,n) if(stamina[i]<stamina[mnglob]) mnglob=i;
	if(stamina[mnglob]<0) {
		assert(firstwater<mnglob);
		ll need=-stamina[mnglob];
		ret+=3*need;
		FORE(i,firstwater,n) stamina[i]+=need;
	}
	REPE(i,n) assert(stamina[i]>=0);

	sinit(0,0,n+1);
	REP(i,n) if(kind[i]=='G') {
		ll mn=min(2*len[i],sget(0,0,n+1,i+1,n));
		assert(mn>=0);
		if(mn==0) continue;
		//printf("walk %lld\n",mn);
		ret-=2*mn;
		smod(0,0,n+1,i+1,n,-mn);
	}
	REP(i,n) if(kind[i]=='W') {
		ll mn=min(2*len[i],sget(0,0,n+1,i+1,n));
		assert(mn>=0);
		if(mn==0) continue;
		//printf("swim %lld\n",mn);
		ret-=1*mn;
		smod(0,0,n+1,i+1,n,-mn);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%lld",&len[i]);
	scanf("%s",kind);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}