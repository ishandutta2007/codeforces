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

const int MAXNP=1000;
const int MAXNK=2000;

int np,nk,dst;
int p[MAXNP];
int k[MAXNK];

ll dpbef[MAXNK+1]; // dpbef[i] = cost for all persons <  fstafter to get to dst with keys [0..i)
ll dpaft[MAXNK+1]; // dpaft[i] = cost for all persons >= fstafter to get to dst with keys [i..n)

void run() {
	scanf("%d%d%d",&np,&nk,&dst);
	REP(i,np) scanf("%d",&p[i]); sort(p,p+np);
	REP(i,nk) scanf("%d",&k[i]); sort(k,k+nk);

	int fstafter=0; while(fstafter<np&&p[fstafter]<=dst) ++fstafter;
	int nbef=fstafter,naft=np-nbef;

	REPE(i,nk) dpbef[i]=LLONG_MAX;
	REPE(i,nk-nbef) {
		ll cur=0;
		REP(j,nbef) cur=max(cur,(ll)abs(p[j]-k[i+j])+abs(k[i+j]-dst));
		dpbef[i+nbef]=cur;
	}
	//printf("bef:"); REPE(i,nk) if(dpbef[i]!=LLONG_MAX) printf(" %d:%lld",i,dpbef[i]); puts("");
	REP(i,nk) dpbef[i+1]=min(dpbef[i],dpbef[i+1]);

	REPE(i,nk) dpaft[i]=LLONG_MAX;
	REPE(i,nk-naft) {
		ll cur=0;
		REP(j,naft) cur=max(cur,(ll)abs(p[fstafter+j]-k[i+j])+abs(k[i+j]-dst));
		dpaft[i]=cur;
	}
	//printf("aft:"); REPE(i,nk) if(dpaft[i]!=LLONG_MAX) printf(" %d:%lld",i,dpaft[i]); puts("");
	for(int i=nk;i>=1;--i) dpaft[i-1]=min(dpaft[i-1],dpaft[i]);

	ll ret=LLONG_MAX;
	REPE(i,nk) if(dpbef[i]!=LLONG_MAX&&dpaft[i]!=LLONG_MAX) { ll cur=max(dpbef[i],dpaft[i]); if(cur<ret) ret=cur; }
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}