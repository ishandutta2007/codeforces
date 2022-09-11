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

const int MAXCOMP = 500;
const int MAXPERS = MAXCOMP;
struct Res { int ways, summaddness; Res() {} Res(int ways, int summaddness) :ways(ways), summaddness(summaddness) {} };

int ncomp, npers, MOD;
int choose[MAXCOMP + 1][MAXCOMP + 1];

int calcsum(int l, int r) { return (l + r) * (r - l + 1) / 2; }

bool done2[MAXCOMP + 1];
Res mem2[MAXCOMP + 1];

// no empty
Res go2(int n) {
	if (n == 1) return Res(2, 0);
	if (done2[n]) return mem2[n];
	Res ret(0, 0);
	REP(i, n) {
		int lcnt = i, rcnt = n - i - 1;
		Res lres = lcnt == 0 ? Res(1, 0) : go2(lcnt);
		Res rres = rcnt == 0 ? Res(1, 0) : go2(rcnt);
		int mways = (lcnt + 1) + (rcnt + 1);
		int msummaddness = calcsum(0, lcnt) + calcsum(0, rcnt);
		int mlt = choose[lcnt + rcnt][lcnt];
		ret.ways = (ret.ways + (ll)lres.ways * mways % MOD * rres.ways % MOD * mlt) % MOD;
		ret.summaddness = (ret.summaddness + (ll)lres.summaddness * mways % MOD * rres.ways % MOD * mlt + (ll)lres.ways * msummaddness % MOD * rres.ways % MOD * mlt + (ll)lres.ways * mways % MOD * rres.summaddness % MOD * mlt) % MOD;
	}
	//printf("go2(%d..%d): ways=%d summaddness=%d\n", l, r, ret.ways, ret.summaddness);
	done2[n] = true, mem2[n] = ret;
	return ret;
}

bool done1[MAXCOMP][MAXPERS + 1];
Res mem1[MAXCOMP][MAXPERS + 1];

// with empty
Res go1(int at, int cnt) {
	if (ncomp - at == cnt) return go2(cnt);
	if (done1[at][cnt]) return mem1[at][cnt];
	Res ret(0, 0);
	FOR(i, at, ncomp) {
		int lcnt = i - at;
		int rcnt = cnt - lcnt;
		if (rcnt<0 || rcnt>ncomp - i - 1) continue;
		Res lres = i == at ? Res(1, 0) : go2(lcnt);
		Res rres = i + 1 == ncomp ? Res(1, 0) : go1(i + 1, rcnt);
		int mlt = choose[lcnt + rcnt][lcnt];
		//printf("\tgo1(%d..%d): %d -> lres=(%d,%d) rres=(%d,%d) mlt=%d\n", at, cnt, i, lres.ways, lres.summaddness, rres.ways, rres.summaddness, mlt);
		ret.ways = (ret.ways + (ll)lres.ways * rres.ways % MOD * mlt) % MOD;
		ret.summaddness = (ret.summaddness + (ll)lres.summaddness * rres.ways % MOD * mlt + (ll)lres.ways * rres.summaddness % MOD * mlt) % MOD;
	}
	//printf("go1(%d..%d): ways=%d summaddness=%d\n", at, cnt, ret.ways, ret.summaddness);
	done1[at][cnt] = true, mem1[at][cnt] = ret;
	return ret;
}


int solve() {
	REPE(i, ncomp) { choose[i][0] = choose[i][i] = 1; FOR(j, 1, i) choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD; }
	REPE(i, ncomp) done2[i] = false;
	REP(i, ncomp) REPE(j, npers) done1[i][j] = false;
	return go1(0, npers).summaddness;
}

void run() {
	scanf("%d%d%d", &ncomp, &npers, &MOD);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}