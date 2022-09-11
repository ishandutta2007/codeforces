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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXQ=10000;

ll a,b; int nq;
int qx[MAXQ][2]; ll qy[MAXQ][2]; bool qans[MAXQ];

void solve() {
	ll g=gcd(a,b);
	REP(i,nq) {
		ll spart=qy[i][0]/(qx[i][0]==0?(a/g):(b/g));
		ll tpart=qy[i][1]/(qx[i][1]==0?(a/g):(b/g));
		qans[i]=spart==tpart;
	}
}

void run() {
	scanf("%lld%lld%d",&a,&b,&nq);
	REP(i,nq) scanf("%d%lld%d%lld",&qx[i][0],&qy[i][0],&qx[i][1],&qy[i][1]),--qx[i][0],--qy[i][0],--qx[i][1],--qy[i][1];
	solve();
	REP(i,nq) printf("%s\n",qans[i]?"YES":"NO");
}

int main() {
	run();
	return 0;
}