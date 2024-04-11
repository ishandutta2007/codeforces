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

const int MAXN=300000;

int n,want;

int pmn[MAXN+1];
int ndiv[MAXN+1];

int qone[MAXN],qonehead,qonetail;
int qtwo[MAXN],qtwohead,qtwotail;
int qthr[MAXN],qthrhead,qthrtail;

void testcanmakealluptoincluding(int x,int lim) {
	int none=qonehead-qonetail,ntwo=qtwohead-qtwotail,nthr=qthrhead-qthrtail;
	if(none>=lim) return;
	if(none>=1&&ntwo>=1&&none>=lim-2) return;
	if(none>=2&&nthr>=1&&none>=lim-3) return;
	printf("%d: %d (%d,%d,%d)\n",x,lim,none,ntwo,nthr);
}

bool use[MAXN+1];
int ret[MAXN],nret;

void run() {
	memset(pmn,-1,sizeof(pmn)); FORE(i,2,MAXN) if(pmn[i]==-1) for(int j=i;j<=MAXN;j+=i) if(pmn[j]==-1) pmn[j]=i;
	ndiv[1]=1; FORE(i,2,MAXN) { int p=pmn[i]; int x=i,cnt=0; while(pmn[x]==p) x/=p,++cnt; ndiv[i]=(cnt+1)*ndiv[x]; }
	//printf("ndiv:"); FORE(i,1,100) printf(" %d",ndiv[i]); puts("");

	scanf("%d%d",&n,&want);
	REPE(i,n) use[i]=false; use[1]=true; int have=0;
	qonehead=qonetail=qtwohead=qtwotail=qthrhead=qthrtail=0;
	FORE(i,2,n) {
		while(qonetail<qonehead&&2*qone[qonetail]<=i) ++qonetail;
		while(qtwotail<qtwohead&&2*qtwo[qtwotail]<=i) ++qtwotail;
		while(qthrtail<qthrhead&&2*qthr[qthrtail]<=i) ++qthrtail;
		//testcanmakealluptoincluding(i,ndiv[i]-2);
		int extra=ndiv[i]-1;
		if(have+extra<want) {
			use[i]=true; have+=extra;
		} else {
			use[i]=true;
			int need=have+extra-want;
			//printf("need=%d\n",need);
			int none=qonehead-qonetail,ntwo=qtwohead-qtwotail,nthr=qthrhead-qthrtail;
			if(need>=3&&nthr>=1) need-=3,use[qthr[qthrtail]]=false;
			if(need>=2&&ntwo>=1) need-=2,use[qtwo[qtwotail]]=false;
			assert(none>=need); REP(i,need) use[qone[qonetail+i]]=false;
			printf("Yes\n");
			nret=0; FORE(j,1,n) if(use[j]) ret[nret++]=j;
			printf("%d\n",nret); REP(j,nret) { if(j!=0) printf(" "); printf("%d",ret[j]); } puts(""); return;
		}
		if(ndiv[i]==2) qone[qonehead++]=i;
		if(ndiv[i]==3) qtwo[qtwohead++]=i;
		if(ndiv[i]==4) qthr[qthrhead++]=i;
	}
	printf("No\n");
}

int main() {
	run();
	return 0;
}