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

const int MAXQ=100000;
const ll INF=1LL<<32;

int nq;
char qkind[MAXQ][10]; int qpar[MAXQ];

ll solve() {
	ll ret=0;
	vector<ll> stck; stck.PB(1LL);
	REP(i,nq) {
		if(strcmp(qkind[i],"add")==0) {
			ret+=stck.back(); if(ret>=INF) return -1;
		}
		if(strcmp(qkind[i],"for")==0) {
			ll nval=min(INF,stck.back()*qpar[i]);
			stck.PB(nval);
		}
		if(strcmp(qkind[i],"end")==0) {
			stck.pop_back();
		}
	}
	return ret;
}

void run() {
	scanf("%d",&nq);
	REP(i,nq) { scanf("%s",qkind[i]); if(strcmp(qkind[i],"for")==0) scanf("%d",&qpar[i]); }
	ll ans=solve();
	if(ans==-1) printf("OVERFLOW!!!\n"); else printf("%lld\n",ans);
}

int main() {
	run();
	return 0;
}