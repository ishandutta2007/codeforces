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

const int MAXN=2000;
const int MAXOP=MAXN*MAXN;
typedef struct Op { int ai,bi; ll val; } Op;
bool operator<(const Op &a,const Op &b) { return a.val<b.val; }

int na,nb;
int a[MAXN],b[MAXN];
Op op[MAXOP]; int nop;
int pra[MAXOP],nxa[MAXOP],prb[MAXOP],nxb[MAXOP];

ll retval;
int ret[2][2],nret;

void run() {
	scanf("%d",&na); REP(i,na) scanf("%d",&a[i]);
	scanf("%d",&nb); REP(i,nb) scanf("%d",&b[i]);
	//na=nb=1000; REP(i,na) a[i]=rand()%1000; REP(i,nb) b[i]=rand()%1000;

	ll have=0; REP(i,na) have+=a[i]; REP(i,nb) have-=b[i];
	nop=0; REP(i,na) REP(j,nb) op[nop].ai=i,op[nop].bi=j,op[nop].val=(ll)2*b[j]-(ll)2*a[i],++nop; sort(op,op+nop);
	REP(i,nop) pra[i]=i==0||op[i-1].ai==op[i].ai?i-1:pra[i-1];
	for(int i=nop-1;i>=0;--i) nxa[i]=i==nop-1||op[i+1].ai==op[i].ai?i+1:nxa[i+1];
	REP(i,nop) prb[i]=i==0||op[i-1].bi==op[i].bi?i-1:prb[i-1];
	for(int i=nop-1;i>=0;--i) nxb[i]=i==nop-1||op[i+1].bi==op[i].bi?i+1:nxb[i+1];

	//printf("%lld\n",have); REP(i,nop) printf("%d %d -> %lld\n",op[i].ai,op[i].bi,op[i].val);

	retval=abs(have),nret=0;
	REP(i,na) REP(j,nb) {
		ll cur=have+(ll)2*b[j]-(ll)2*a[i];
		if(abs(cur)<retval) retval=abs(cur),nret=1,ret[0][0]=i,ret[0][1]=j;
		ll want=-cur,now;
		int l=-1,h=nop,at; while(l+1<h) { int m=l+(h-l)/2; if(op[m].val>=want) h=m; else l=m; }
		at=h; while(at<nop) if(op[at].ai==i) at=nxa[at]; else if(op[at].bi==j) at=nxb[at]; else break;
		if(at<nop) { now=cur+op[at].val; if(abs(now)<retval) retval=abs(now),nret=2,ret[0][0]=i,ret[0][1]=j,ret[1][0]=op[at].ai,ret[1][1]=op[at].bi; }
		at=h-1; while(at>=0) if(op[at].ai==i) at=pra[at]; else if(op[at].bi==j) at=prb[at]; else break;
		if(at>=0) { now=cur+op[at].val; if(abs(now)<retval) retval=abs(now),nret=2,ret[0][0]=i,ret[0][1]=j,ret[1][0]=op[at].ai,ret[1][1]=op[at].bi; }
	}
	printf("%I64d\n%d\n",retval,nret); REP(i,nret) printf("%d %d\n",ret[i][0]+1,ret[i][1]+1);
}

int main() {
	run();
	return 0;
}