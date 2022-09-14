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

const int MAXN=18;

int n;
char nr[MAXN+1];
char g[MAXN][10+1];

void dbg() { printf("%d\n",n); printf("%s\n",nr); REP(j,10) printf("%s\n",g[j]); }

ll calca(int at) {
	int dig=nr[at]-'0';
	int ret=0;
	REP(i,10) if(i!=dig) {
		int cur;
		for(cur=0;cur<10;++cur) if(g[at][(dig+cur)%10]!=g[at][(i+cur)%10]) break;
		if(cur==10) return LLONG_MAX; if(cur>ret) ret=cur;
	}
	return ret;
}
ll calcb(int at) {
	int dig=nr[at]-'0';
	int ret=0;
	REP(i,10) if(i!=dig) {
		int cur;
		for(cur=0;cur<10;++cur) if((dig+cur>=10?'$':g[at][dig+cur])!=(i+cur>=10?'$':g[at][i+cur])) break;
		assert(cur!=10); if(cur>ret) ret=cur;
	}
	return ret;
}
bool knowall(int at,ll incs,ll parincs) {
	int dig=nr[at]-'0';
	if(dig+incs>=10*parincs+10) return true;
	for(int cur=1;cur<10&&cur<=incs;++cur) if(g[at][(dig+cur)%10]!=g[at][dig]) return true;
	return false;
}

// number of seconds we have to wait to know values of wheels at..n-1, given that we need to increase our parent at least parincs, and increasing it one more rings a bell
ll calc(int at,ll parincs) {
	if(at>=n) return parincs;
	int dig=nr[at]-'0';

	ll a=calca(at); //a!=LLONG_MAX -> after a increases we know value of at, only because of this wheel
	ll b=calcb(at); //             -> after b increases we know value of at, provided a single increase of the next significant wheel is also ok

	ll incs=max(10*parincs-dig,min(a,10*parincs+b));
	//printf("\t%lld %lld %lld -> %lld\n",parincs,a,b,incs);
	if(knowall(at,incs,parincs)) {
		ll ret=incs; FOR(i,at+1,n) ret=ret*10-(nr[i]-'0'); return ret;
	} else {
		return calc(at+1,incs);
	}
}

void run(int casenr) {
	scanf("%d",&n); scanf("%s",nr); REP(i,n) scanf("%s",g[i]);

	// find most significant digit with multiple options
	// calculate how long we have to wait to know this digit
	// if in that time, we also get to know all lesser significant digits because of this wheel (the value changed at least once) we have the answer
	// otherwise, 

	ll ret=calc(0,0);
	printf("%lld\n",ret);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}