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

const int MAXN=250;
const int MOD=998244353;

int n;
int p[MAXN],pinv[MAXN]; bool pdone[MAXN];
int q[MAXN],qinv[MAXN]; bool qdone[MAXN];

int fac[MAXN+1];
int C[MAXN+1][MAXN+1];
int s1[MAXN+1][MAXN+1];
int f[MAXN+1];
int ret[MAXN+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&p[i]),--p[i]; REP(i,n) scanf("%d",&q[i]),--q[i];
	memset(pinv,-1,sizeof(pinv)); REP(i,n) if(p[i]!=-1) pinv[p[i]]=i; memset(pdone,false,sizeof(pdone));
	memset(qinv,-1,sizeof(qinv)); REP(i,n) if(q[i]!=-1) qinv[q[i]]=i; memset(qdone,false,sizeof(qdone));
	// i->p[i]->qinv[p[i]]->...
	int pp=0,pq=0,qp=0,qq=0,cyc=0;
	REP(i,n) if(q[i]==-1) { int at=i; while(true) { pdone[at]=true;  if(p[at]==-1) { ++pp; break; } at=p[at]; qdone[at]=true; if(qinv[at]==-1) { ++pq; break; } at=qinv[at]; } }
	REP(i,n) if(pinv[i]==-1) { int at=i; while(true) { qdone[at]=true; if(qinv[at]==-1) { ++qq; break; } at=qinv[at]; pdone[at]=true; if(p[at]==-1) { ++qp; break; } at=p[at]; } }
	REP(i,n) if(!pdone[i]) { int at=i; do { pdone[at]=true; assert(p[at]!=-1); at=p[at]; qdone[at]=true; assert(qinv[at]!=-1); at=qinv[at]; } while(at!=i); ++cyc; }
	fprintf(stderr,"pp=%d pq=%d qp=%d qq=%d cyc=%d\n",pp,pq,qp,qq,cyc);
	if(pp!=qq) fprintf(stderr,"pp!=qq\n");

	fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;
	REPE(i,n) { C[i][0]=C[i][i]=1; FOR(j,1,i) if((C[i][j]=C[i-1][j-1]+C[i-1][j])>=MOD) C[i][j]-=MOD; }
	memset(s1,0,sizeof(s1)); s1[0][0]=1; REP(i,n) FORE(j,1,n) s1[i+1][j]=((ll)i*s1[i][j]+s1[i][j-1])%MOD;

	memset(f,0,sizeof(f)); memset(ret,0,sizeof(ret));
	if(pp!=0) REPE(cqp,qp) FORE(nqp,cqp,qp) f[cqp]=(f[cqp]+(ll)fac[qq]*C[qp][nqp]%MOD*fac[qp-nqp]%MOD*C[qp-nqp+pp-1][pp-1]%MOD*s1[nqp][cqp])%MOD;
	if(pp==0) REPE(cqp,qp) f[cqp]=(f[cqp]+(ll)fac[qq]*s1[qp][cqp])%MOD;
	REPE(cpq,pp+pq) REPE(cqp,qp) ret[n-cyc-cpq-cqp]=(ret[n-cyc-cpq-cqp]+(ll)f[cqp]*s1[pp+pq][cpq])%MOD;

	REPE(i,n-1) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}