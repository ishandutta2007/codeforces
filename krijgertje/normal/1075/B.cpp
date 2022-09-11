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

const int MAXRIDER=100000;
const int MAXTAXI=100000;
const int MAXTOT=MAXRIDER+MAXTAXI;

int nrider,ntaxi,ntot;
int x[MAXTOT];
int istaxi[MAXTOT];
int ans[MAXTOT];

int prv[MAXTOT],nxt[MAXTOT];

void solve() {
	REP(i,ntot) prv[i]=istaxi[i]?i:i==0?-1:prv[i-1];
	for(int i=ntot-1;i>=0;--i) nxt[i]=istaxi[i]?i:i==ntot-1?-1:nxt[i+1];
	REP(i,ntot) ans[i]=0;
	REP(i,ntot) if(!istaxi[i]) { if(prv[i]!=-1&&(nxt[i]==-1||x[i]-x[prv[i]]<=x[nxt[i]]-x[i])) ++ans[prv[i]]; else if(nxt[i]!=-1) ++ans[nxt[i]]; }
}

void run() {
	scanf("%d%d",&nrider,&ntaxi); ntot=nrider+ntaxi;
	REP(i,ntot) scanf("%d",&x[i]);
	REP(i,ntot) scanf("%d",&istaxi[i]);
	solve();
	bool fst=true; REP(i,ntot) if(istaxi[i]) { if(fst) fst=false; else printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}