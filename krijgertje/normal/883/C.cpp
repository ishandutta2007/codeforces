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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

int bneed, thave, t0;
int a1, t1, c1;
int a2, t2, c2;

void run() {
	scanf("%d%d%d", &bneed, &thave, &t0);
	scanf("%d%d%d", &a1, &t1, &c1);
	scanf("%d%d%d", &a2, &t2, &c2);
	if (t1 > t2) { swap(a1, a2); swap(t1, t2); swap(c1, c2); }
	ll ret = LLONG_MAX;
	for (int n1 = 0;; ++n1) {
		int lim1 = min(bneed, thave / t1);
		int b1 = min(n1*a1, lim1);
		int brem = bneed - b1, trem = (int)max(0LL, thave - (ll)n1*a1*t1);
		if (t2 < t0) {
			// b2*t2+(brem-b2)*t0<=trem -> b2>=(brem*t0-trem)/(t0-t2)
			ll b2 = (ll)brem*t0 - trem < 0 ? 0 : ((ll)brem*t0 - trem + t0 - t2 - 1) / (t0 - t2);
			if (b2 <= brem) {
				int n2 = (b2 + a2 - 1) / a2;
				ll cur = (ll)n1*c1 + (ll)n2*c2;
				//printf("n1=%d n2=%d -> cur = %lld (b1=%d,b2=%lld,b0=%lld->%lld)\n", n1, n2, cur, b1, b2, brem - b2, (ll)b1*t1 + (ll)b2*t2 + (ll)(brem - b2)*t0);
				ret = min(ret, cur);
			}
		} else {
			// brem*t0<=trem
			if ((ll)brem*t0 <= trem) {
				ll cur = (ll)n1*c1;
				//printf("n1=%d > cur = %lld\n", n1, cur);
				ret = min(ret, cur);
			}
		}
		if (n1*a1 >= lim1) break;
	}
	printf("%lld\n", ret == LLONG_MAX ? -1 : ret);
}

int main() {
	run();
	//stress();
	return 0;
}