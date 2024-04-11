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

const int MAXA = 10;
const int MAXB = 100;
const int MAXBVAL = 250;
const int MOD = 1000000007;
typedef struct State { vector<int> ways; State(int bmx) { ways = vector<int>(bmx, 0); } } State;

int na, nb; ll N;
int a[MAXA], b[MAXB];

int bmx;
int bcnt[MAXBVAL + 1];

void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
void inc(State &a, const State &b) { REP(i, bmx) inc(a.ways[i], b.ways[i]); }
void mlt(State &a, const State &b) {
	vector<int> ways(2 * bmx - 1, 0);
	REP(i, bmx) REP(j, bmx) ways[i + j] = (ways[i + j] + (ll)a.ways[i] * b.ways[j]) % MOD;
	for (int i = 2 * bmx - 2; i >= bmx; --i) if (ways[i] != 0) {
		REPE(j, bmx) if (bcnt[j] != 0) ways[i - j] = (ways[i - j] + (ll)bcnt[j] * ways[i]) % MOD;
		ways[i] = 0;
	}
	ways.resize(bmx); a.ways = ways;
}
int pw(int x, int n) { int a = 1; while (true) { if (n & 1) a = (ll)a*x%MOD; if ((n >>= 1) == 0) return a; x = (ll)x*x%MOD; } }
void pw(State &a, ll n) {
	State x = a; REP(i, bmx) a.ways[i] = i == 0 ? 1 : 0;
	while (true) { if (n & 1) mlt(a, x); if ((n >>= 1) == 0) break; mlt(x, x); }
}

int solve() {
	bmx = b[0]; FOR(i, 1, nb) if (b[i] > bmx) bmx = b[i];
	REPE(i, bmx) bcnt[i] = 0; REP(i, nb) ++bcnt[b[i]];

	State asum(bmx);
	REP(i, na) {
		State cur(bmx);
		if (1 < bmx) ++cur.ways[1]; else cur.ways[0] += bcnt[1];
		pw(cur, a[i]);
		inc(asum, cur);
	}
	pw(asum, N);
	{
		State cur(bmx);
		if (1 < bmx) ++cur.ways[1]; else cur.ways[0] += bcnt[1];
		pw(cur, bmx);
		mlt(asum, cur);
	}
	//printf("res:"); REP(i, bmx) printf(" %d", asum.ways[i]); puts("");
	int ret = (ll)asum.ways[0] * pw(bcnt[bmx], MOD - 2) % MOD;
	return ret;
}

int bf() {
	int amx = a[0]; FOR(i, 1, na) if (a[i] > amx) amx = a[i];
	int amxsum = amx*N;
	vector<int> aways(amxsum + 1, 0); aways[0] = 1; REP(i, N) for (int j = SZ(aways) - 1; j >= 0; --j) if (aways[j] != 0) { REP(k, na) inc(aways[j + a[k]], aways[j]); aways[j] = 0; }
	vector<int> bways(amxsum + 1, 0), bwayssum(amxsum + 1, 0); bways[0] = bwayssum[0] = 1;
	while (true) {
		bool any = false;
		for (int j = SZ(bways) - 1; j >= 0; --j) if (bways[j]) { any = true; REP(k, nb) if (j + b[k] < SZ(bways)) inc(bways[j + b[k]], bways[j]); bways[j] = 0; }
		if (!any) break;
		REPSZ(j, bways) inc(bwayssum[j], bways[j]);
		//printf("bways:"); REPSZ(i, bways) printf(" %d", bways[i]); puts("");
	}
	//printf("aways:"); REPSZ(i, aways) printf(" %d", aways[i]); puts("");
	//printf("bwayssum:"); REPSZ(i, bwayssum) printf(" %d", bwayssum[i]); puts("");
	int ret = 0; REPE(j, amxsum) ret = (ret + (ll)aways[j] * bwayssum[j]) % MOD; return ret;
}

void run() {
	scanf("%d%d%lld", &na, &nb, &N); REP(i, na) scanf("%d", &a[i]); REP(i, nb) scanf("%d", &b[i]);
	printf("%d\n", solve());
	//printf("want=%d\n", bf());
}

int main() {
	run();
	return 0;
}