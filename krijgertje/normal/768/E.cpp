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

const int MAXN=1000000;
const int MAXVAL=60;

int n;
int x[MAXN];

map<ll,int> mem[MAXVAL+1];
int g[MAXVAL+1];

int go(int cnt,ll mask) {
	mask=mask&((1LL<<(cnt+1))-1);
	if(mem[cnt].count(mask)) return mem[cnt][mask];
	ll poss=0;
	FORE(i,1,cnt) {
		if(mask&(1LL<<i)) continue;
		poss|=1LL<<go(cnt-i,mask|(1LL<<i));
	}
	int ret=0; while(poss&(1LL<<ret)) ++ret; return mem[cnt][mask]=ret;
}

void precalc() {
	FORE(i,1,MAXVAL) g[i]=go(i,0);
	//FORE(i,1,MAXVAL) printf("%d=%d\n",i,g[i]);
}

void run() {
	precalc();
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	int ret=0; REP(i,n) ret^=g[x[i]];
	printf("%s\n",ret==0?"YES":"NO");
}

int main() {
	run();
	return 0;
}