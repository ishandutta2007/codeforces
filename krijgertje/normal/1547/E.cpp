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

const int MAXCELL = 300000;
const int MAXAIR = MAXCELL;
struct Air { int x, t; };

int ncell, nair;
Air air[MAXAIR];
int ans[MAXCELL];

Air act[MAXAIR]; int nact;

void solve() {
	sort(air, air + nair, [&](const Air& p, const Air& q) { return p.x < q.x; });
	nact = 0;
	REP(i, nair) {
		while (nact > 0 && air[i].t + abs(air[i].x - act[nact - 1].x) < act[nact - 1].t) --nact;
		if (nact == 0 || air[i].t < act[nact - 1].t + abs(air[i].x - act[nact - 1].x)) act[nact++] = air[i];
	}
	//printf("act:"); REP(i, nact) printf(" (%d,%d)", act[i].x, act[i].t); puts("");
	int pos = 0;
	REP(i, ncell) {
		if (pos < nact && act[pos].x <= i) ++pos;
		ans[i] = INT_MAX;
		if (pos - 1 >= 0) ans[i] = min(ans[i], act[pos - 1].t + abs(i - act[pos - 1].x));
		if (pos < nact) ans[i] = min(ans[i], act[pos].t + abs(i - act[pos].x));
	}
}

void run() {
	scanf("%d%d", &ncell, &nair);
	REP(i, nair) scanf("%d", &air[i].x), --air[i].x;
	REP(i, nair) scanf("%d", &air[i].t);
	solve();
	REP(i, ncell) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}