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

int mxa, mxb;

ll solve() {
	ll mlt = 1;
	ll ret = 0;
	for (int bdig = 1;; ++bdig) {
		if (10 * mlt - 1 > mxb) break;
		// b>=mlt, b<10*mlt, b<=mxb, a>=1, a<=mxa, a*b+a+b=10*mlt*a+b -> b=10*mlt-1
		ll b = 10 * mlt - 1;
		if (b >= 1 && b <= mxb) ret += mxa;
		mlt *= 10;
	}
	return ret;
}

void run() {
	scanf("%d%d", &mxa, &mxb);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}