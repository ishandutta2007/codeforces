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

const int MOD=1000000007;
const int MAXLEN=1000000;


int len,nidx;
char p[MAXLEN+1]; int plen;
int idx[MAXLEN];

int nxt[MAXLEN+1]; // nxt[i]=length of longest border of p[0..i]
bool ok[MAXLEN];

void precalc() {
	nxt[0]=nxt[1]=0;
	FORE(i,2,plen) {
		nxt[i]=nxt[i-1]; while(nxt[i]>0&&p[nxt[i]]!=p[i-1]) nxt[i]=nxt[nxt[i]];
		if(p[nxt[i]]==p[i-1]) ++nxt[i];
	}
	memset(ok,false,sizeof(ok)); ok[0]=true;
	for(int x=nxt[plen];x!=0;x=nxt[x]) ok[x]=true;
	//REPE(i,plen) printf("%d ",nxt[i]); puts("");
}

bool isborder(int x) {
	//printf("testing %d\n",x);
	return ok[x];
}

void run() {
	scanf("%d%d",&len,&nidx);
	scanf("%s",p); plen=strlen(p);
	REP(i,nidx) { scanf("%d",&idx[i]); --idx[i]; }

	precalc();

	int nxtunknown=0,cntunknown=0;
	REP(i,nidx) {
		if(idx[i]>nxtunknown) { cntunknown+=idx[i]-nxtunknown; nxtunknown=idx[i]; }
		if(!isborder(nxtunknown-idx[i])) { printf("0\n"); return; }
		nxtunknown=idx[i]+plen;
	}
	if(len>nxtunknown) { cntunknown+=len-nxtunknown; nxtunknown=len; }
	int ret=1; REP(i,cntunknown) ret=(ll)ret*26%MOD; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}