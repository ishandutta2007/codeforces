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

const int MAXN = 200000;

int n;
int p[MAXN];
int xperc, xperiod;
int yperc, yperiod;
ll zperiod;
ll want;

bool can(int cnt) {
	if (xperc < yperc) { swap(xperc, yperc); swap(xperiod, yperiod); }
	int nz = cnt / zperiod, nx = cnt / xperiod - nz, ny = cnt / yperiod - nz;
	assert(nx + ny + nz <= n);
	ll have = 0; int at = 0;
	REP(i, nz) have += p[at++] / 100 * (xperc + yperc);
	REP(i, nx) have += p[at++] / 100 * (xperc);
	REP(i, ny) have += p[at++] / 100 * (yperc);
	//printf("cnt=%d -> (%d,%d,%d) (%d,%d) -> %lld\n", cnt, nx, ny, nz, xperc, yperc,have);
	return have >= want;
}

int solve() {
	sort(p, p + n);
	reverse(p, p + n);
	zperiod = (ll)xperiod / gcd(xperiod, yperiod) * yperiod;

	int lo = 0, hi = n + 1;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) hi = mi; else lo = mi;
	}
	return hi <= n ? hi : -1;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &p[i]);
	scanf("%d%d", &xperc, &xperiod);
	scanf("%d%d", &yperc, &yperiod);
	scanf("%lld", &want);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}