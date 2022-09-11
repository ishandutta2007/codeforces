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
#include <chrono>
#include <random>
#include <functional>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 200000;
const int MAXS = 4 * MAXN;

int n;
int a[MAXN];

int smx[MAXS]; // lazy
int smxcnt[MAXS];
int smx2[MAXS];

void spush(int x) {
	smx[2 * x + 1] = min(smx[2 * x + 1], smx[x]);
	smx[2 * x + 2] = min(smx[2 * x + 2], smx[x]);
}
void spull(int x) {
	smx[x] = max(smx[2 * x + 1], smx[2 * x + 2]);
	smxcnt[x] = (smx[2 * x + 1] == smx[x] ? smxcnt[2 * x + 1] : 0) + (smx[2 * x + 2] == smx[x] ? smxcnt[2 * x + 2] : 0);
	smx2[x] = max(smx[2 * x + 1] != smx[x] ? smx[2 * x + 1] : smx2[2 * x + 1], smx[2 * x + 2] != smx[x] ? smx[2 * x + 2] : smx2[2 * x + 2]);
}
void sinit(int x, int l, int r) {
	if (l == r) {
		smx[x] = a[l], smxcnt[x] = 1, smx2[x] = -1;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int OLDMX, int PREFMAX, int SUFFMAX) {
	if (smx[x] != OLDMX) return;
	//printf("smod %d..%d from %d (%d/%d) [mx=%d,mxcnt=%d,mx2=%d]\n", l, r, OLDMX, PREFMAX, SUFFMAX, smx[x], smxcnt[x], smx2[x]);
	if (min(PREFMAX, SUFFMAX) > smx2[x]) { smx[x] = min(PREFMAX, SUFFMAX); return; }
	assert(l != r);
	int m = l + (r - l) / 2; spush(x);
	int NPREFMAX = max(PREFMAX, smx[2 * x + 1] != OLDMX ? smx[2 * x + 1] : smx2[2 * x + 1]);
	int NSUFFMAX = max(SUFFMAX, smx[2 * x + 2] != OLDMX ? smx[2 * x + 2] : smx2[2 * x + 2]);
	smod(2 * x + 1, l, m, OLDMX, PREFMAX, NSUFFMAX);
	smod(2 * x + 2, m + 1, r, OLDMX, NPREFMAX, SUFFMAX);
	spull(x);
}

ll solve() {
	sinit(0, 0, n - 1);
	ll ret = 0;
	while (smx[0] != 0) {
		//printf("%d times %d\n", smxcnt[0], smx[0]);
		ret += smxcnt[0];
		smod(0, 0, n - 1, smx[0], 0, 0);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}