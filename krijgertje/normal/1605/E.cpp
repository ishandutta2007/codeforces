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
const int MAXQ = 200000;

int n;
int a[MAXN+1];
int b[MAXN+1];
int nq;
int qval[MAXQ];
ll qans[MAXQ];

ll curcnst[MAXN + 1], curx[MAXN + 1];
ll qx[MAXQ];

void solve() {
	FORE(i, 2, n) curcnst[i] = b[i] - a[i], curx[i] = -1;
	FORE(i, 2, n) {
		for (int j = i + i; j <= n; j += i) {
			curcnst[j] -= curcnst[i];
			curx[j] -= curx[i];
		}
		//printf("%d: %lld+%lldx\n", i, curcnst[i], curx[i]);
	}
	FORE(i, 2, n) if (curx[i] > 0) curcnst[i] = -curcnst[i], curx[i] = -curx[i];
	ll fixed = 0;
	vector<ll> var;
	FORE(i, 2, n) if (curx[i] == 0) fixed += abs(curcnst[i]); else { assert(curx[i] == -1); var.PB(curcnst[i]); }
	sort(var.begin(), var.end());
	REP(i, nq) qx[i] = qval[i] - a[1];
	
	//REP(i, nq) { qans[i] = abs(qx[i]) + fixed; for (ll y : var) qans[i] += abs(y - qx[i]); }
	vector<ll> varsum(SZ(var) + 1); varsum[0] = 0; REPSZ(i, var) varsum[i + 1] = varsum[i] + var[i];
	REP(i, nq) {
		qans[i] = abs(qx[i]) + fixed;
		int idx = lower_bound(var.begin(), var.end(), qx[i]) - var.begin();
		qans[i] -= varsum[idx] - (ll)qx[i] * idx;
		qans[i] += varsum[SZ(var)] - varsum[idx] - (ll)qx[i] * (SZ(var) - idx);
	}
}

void run() {
	scanf("%d", &n);
	FORE(i, 1, n) scanf("%d", &a[i]);
	FORE(i, 1, n) scanf("%d", &b[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d", &qval[i]);
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

ll qansstupid[MAXQ];

void solvestupid() {
	REP(i, nq) {
		vector<ll> cur(n + 1); FORE(i, 1, n) cur[i] = a[i];
		qansstupid[i] = 0;
		FORE(j, 1, n) {
			int want = j == 1 ? qval[i] : b[j];
			ll delta = want - cur[j];
			qansstupid[i] += abs(delta);
			for (int k = j; k <= n; k += j) cur[k] += delta;
		}
	}
}

void stress() {
	int mxn = 100;
	REP(rep, 1000) {
		n = rnd() % mxn + 1;
		FORE(i, 1, n) a[i] = rnd() % 10 + 1;
		b[1] = -1; FORE(i, 2, n) b[i] = rnd() % 10 + 1;
		nq = 100;
		REP(i, nq) qval[i] = rnd() % 10 + 1;
		solve();
		solvestupid();
		bool ok = true; REP(i, nq) if (qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err rep=%d\n", rep);
		printf("have:"); REP(i, nq) printf(" %lld", qans[i]); puts("");
		printf("want:"); REP(i, nq) printf(" %lld", qansstupid[i]); puts("");
		printf("%d\n", n); FORE(i, 1, n) { if (i != 1) printf(" "); printf("%d", a[i]); } puts(""); FORE(i, 1, n) { if (i != 1) printf(" "); printf("%d", b[i]); } puts(""); printf("%d\n", nq); REP(i, nq) printf("%d\n", qval[i]);
		mxn = n - 1;
	}
}

int main() {
	run();
	//stress();
	return 0;
}