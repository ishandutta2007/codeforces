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

const int MAXDIG=12;

int amx,bmx;
int a[MAXDIG],na;
int b[MAXDIG],nb;

void add(int &mask,bool &ok,int bit) { if((mask>>bit)&1) ok=false; else mask|=1<<bit; }
int bitcount(int mask) { int ret=0; REP(bit,7) if((mask>>bit)&1) ++ret; return ret; }
int C[8][8],fac[8];
void run() {
	REPE(i,7) { C[i][0]=C[i][i]=1; FOR(j,1,i) C[i][j]=C[i-1][j-1]+C[i-1][j]; }
	fac[0]=1; FORE(i,1,7) fac[i]=fac[i-1]*i;
	scanf("%d%d",&amx,&bmx); --amx,--bmx;
	{ na=0; int x=amx; do { a[na++]=x%7; x/=7; } while(x>0); reverse(a,a+na); }
	{ nb=0; int x=bmx; do { b[nb++]=x%7; x/=7; } while(x>0); reverse(b,b+nb); }
	//REP(i,na) printf("%d",a[i]); printf(" "); REP(i,nb) printf("%d",b[i]); puts("");

	ll ret=0;
	REPE(aeq,na) REP(ai,aeq==na?1:a[aeq]) REPE(beq,nb) REP(bi,beq==nb?1:b[beq]) {
		int used=0; bool ok=true;
		REP(i,aeq) add(used,ok,a[i]); if(aeq!=na) add(used,ok,ai);
		REP(i,beq) add(used,ok,b[i]); if(beq!=nb) add(used,ok,bi);
		if(!ok) continue;
		int have=7-bitcount(used),want=na-aeq-(aeq!=na?1:0)+nb-beq-(beq!=nb?1:0);
		//printf("%d %d %d %d [%d out of %d]\n",aeq,ai,beq,bi,want,have);
		if(want>have) continue;
		ret+=C[have][want]*fac[want];
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}