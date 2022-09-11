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

const int MAXN = 10000;
const int OPAND = 0;
const int OPOR = 1;

int n, want;

int x[MAXN], y[MAXN];

bool local = false;
int xlocal[MAXN];

int query(int kind, int a, int b) {
	if (!local) {
		printf("%s %d %d\n", kind == OPAND ? "and" : "or", a + 1, b + 1); fflush(stdout);
		int ret; scanf("%d", &ret); if (ret == -1) assert(false); return ret;
	} else {
		return kind == OPAND ? xlocal[a] & xlocal[b] : xlocal[a] | xlocal[b];
	}
}

int solve() {
	assert(n >= 3);
	int AB = query(OPAND, 0, 1);
	int BC = query(OPAND, 1, 2);
	int CA = query(OPAND, 2, 0);
	int ab = query(OPOR, 0, 1);
	int bc = query(OPOR, 1, 2);
	int ca = query(OPOR, 2, 0);
	//printf("%x %x %x %x %x %x\n", AB, BC, CA, ab, bc, ca);
	REP(i, 3) x[i] = 0;
	int seen = 0;
	int all = ab | bc | ca;
	FOR(mask, 1, 1 << 3) {
		int bits = all;
		if ((mask & 1) != 0 && (mask & 2) != 0) bits &= AB; else bits &= ~AB;
		if ((mask & 2) != 0 && (mask & 4) != 0) bits &= BC; else bits &= ~BC;
		if ((mask & 4) != 0 && (mask & 1) != 0) bits &= CA; else bits &= ~CA;
		if ((mask & 1) != 0 || (mask & 2) != 0) bits &= ab; else bits &= ~ab;
		if ((mask & 2) != 0 || (mask & 4) != 0) bits &= bc; else bits &= ~bc;
		if ((mask & 4) != 0 || (mask & 1) != 0) bits &= ca; else bits &= ~ca;
		//printf("%x -> %x\n", mask, bits);
		assert((seen & bits) == 0);
		seen |= bits;
		REP(i, 3) if (mask & (1 << i)) x[i] |= bits;
	}
	assert(seen == all);
	FOR(i, 3, n) {
		int resand = query(OPAND, 0, i);
		int resor = query(OPOR, 0, i);
		x[i] = resand | (resor & ~x[0]);
	}
	REP(i, n) y[i] = x[i];
	sort(y, y + n);
	return y[want];
}

void run() {
	scanf("%d%d", &n, &want); --want;
	int ans = solve();
	printf("finish %d\n", ans); fflush(stdout);
}

void stress() {
	std::mt19937 rnd(2332);
	local = true;
	int lim = 1000000000;
	//lim = 7;
	REP(rep, 100) {
		n = rnd() % (10 - 3 + 1) + 3;
		want = rnd() % n;
		REP(i, n) xlocal[i] = rnd() % (lim + 1);
		//printf("xlocal:"); REP(i, n) printf(" %d", xlocal[i]); puts("");
		solve();
		REP(i, n) assert(x[i] == xlocal[i]);
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}