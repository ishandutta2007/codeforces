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

const int MAXB=200000;
const int MOD=998244353;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int len,nb,nalph;
int b[MAXB];

int parts[MAXB],nparts;

int solve() {
	nparts=0; REP(i,nb) parts[nparts++]=b[i]-(i==0?0:b[i-1]);
	int ret=pw(nalph,len-2*b[nb-1]);
	REP(i,nparts) {
		int one=pw(nalph,parts[i]);
		int cur=(ll)one*(one+1)/2%MOD;
		ret=(ll)ret*cur%MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&len,&nb,&nalph);
	REP(i,nb) scanf("%d",&b[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}