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

const int MAXN = 5000;
const int MAXSTEP = 5000;
const int MAXQ = 200000;
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }

int n, nstep, nq;
int a[MAXN];
int qidx[MAXQ], qval[MAXQ], qans[MAXQ];

int ways[MAXN][MAXSTEP + 1];
int w[MAXN];

int curval[MAXN];

void solve() {
	REP(i, n) ways[i][0] = 1;
	FORE(j, 1, nstep) REP(i, n) {
		ways[i][j] = 0;
		if (i - 1 >= 0) inc(ways[i][j], ways[i - 1][j - 1]);
		if (i + 1 < n) inc(ways[i][j], ways[i + 1][j - 1]);
	}
	REP(i, n) {
		w[i] = 0;
		REPE(j, nstep) inc(w[i], (ll)ways[i][j] * ways[i][nstep - j] % MOD);
	}
	int curans = 0;
	REP(i, n) curval[i] = a[i], inc(curans, (ll)w[i] * curval[i] % MOD);
	REP(i, nq) {
		int idx = qidx[i], val = qval[i];
		dec(curans, (ll)w[idx] * curval[idx] % MOD);
		curval[idx] = val;
		inc(curans, (ll)w[idx] * curval[idx] % MOD);
		qans[i] = curans;
	}
}

void run() {
	scanf("%d%d%d", &n, &nstep, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}