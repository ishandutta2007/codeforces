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
#include <intrin.h>
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

const int MAXBITS = 40;
const int MAXSTEPS = 10;

int nbits, nsteps;
vector<int> step[MAXSTEPS];

ll stepmask[MAXSTEPS];
ll known[MAXSTEPS + 1];
int extra[MAXSTEPS];
vector<ll> stepopt[MAXSTEPS];

int mypopcount(ll mask) {
	//int ret = 0; while (mask > 0) ret += mask & 1, mask >>= 1; return ret;
	return __builtin_popcountll(mask);
}

void printmask(ll mask) {
	REP(i, nbits) printf("%c", ((mask >> i) & 1) != 0 ? '1' : '0');
}

bool rec(int at, ll onemask, int onecount) {
	//printf("at=%d onemask=", at); printmask(onemask); printf(" onecount=%d\n", onecount);
	if (at == nsteps) return onemask == (((1LL << onecount) - 1) << (nbits - onecount));
	REPE(a, extra[at]) {
		int b = mypopcount(stepmask[at] & onemask);
		assert(a + b >= 0 && a + b <= SZ(step[at]));
		ll nonemask = (onemask & (~stepmask[at])) | stepopt[at][a + b];
		if (!rec(at + 1, nonemask, onecount + a)) return false;
	}
	return true;
}

bool solve() {
	if (nbits == 1) return true;
	REP(i, nsteps) { stepmask[i] = 0; for (int b : step[i]) stepmask[i] |= 1LL << b; }
	known[0] = 0; REP(i, nsteps) known[i + 1] = known[i] | stepmask[i];
	REP(i, nsteps) extra[i] = mypopcount(known[i + 1] ^ known[i]);
	REP(i, nsteps) {
		stepopt[i] = vector<ll>(SZ(step[i]) + 1, 0);
		REPSZ(j, stepopt[i]) REP(k, j) stepopt[i][j] |= 1LL << step[i][SZ(step[i]) - k - 1];
		//REPSZ(j, stepopt[i]) printf("%d %d: ", i, j), printmask(stepopt[i][j]), puts("");
	}
	if (known[nsteps] != (1LL << nbits) - 1) return false;

	return rec(0, 0, 0);
}

void run() {
	scanf("%d%d", &nbits, &nsteps);
	REP(i, nsteps) { int cnt; scanf("%d", &cnt); step[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &step[i][j]), --step[i][j]; }
	printf("%s\n", solve() ? "ACCEPTED" : "REJECTED");
}

int main() {
	run();
	return 0;
}