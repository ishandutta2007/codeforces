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

template<class T> struct RMQSparse {
	const T* a; int n;
	vector<int> lg;
	vector<vector<int>> jmp;
	void init(const T* _a, int _n) {
		a = _a; n = _n; if (n < 1) return;
		lg = vector<int>(n + 1); lg[1] = 0; FORE(i, 2, n) lg[i] = lg[i >> 1] + 1;
		jmp = vector<vector<int>>(lg[n] + 1); jmp[0] = vector<int>(n); REP(i, n) jmp[0][i] = i;
		FORE(k, 1, lg[n]) { jmp[k] = vector<int>(n - (1 << k) + 1); REPE(i, n - (1 << k)) { int x = jmp[k - 1][i], y = jmp[k - 1][i + (1 << (k - 1))]; jmp[k][i] = a[y] < a[x] ? y : x; } }
	}
	void init(const vector<T>& a) { init(a.data(), SZ(a)); }
	int query(int l, int r) { int k = lg[r - l + 1]; int x = jmp[k][l], y = jmp[k][r - (1 << k) + 1]; return a[y] < a[x] ? y : x; }
};

const int MAXN = 100000;
const ll MAXANS = (ll)MAXN * (MAXN - 1) / 2 - 1; // 4999949999 (very conservative upper bound)
const int MAXLGANS = 32;
const int MAXQ = 100000;

int n, nq;
int a[MAXN];
int ql[MAXQ], qr[MAXQ];
ll qans[MAXQ];

int ljmp[MAXLGANS + 1][MAXN - 1];
int rjmp[MAXLGANS + 1][MAXN - 1];
int negrjmp[MAXLGANS + 1][MAXN - 1];
RMQSparse<int> lrmq[MAXLGANS + 1];
RMQSparse<int> rrmq[MAXLGANS + 1];

void solve() {
	REP(i, n - 1) ljmp[0][i] = min(a[i], a[i + 1]), rjmp[0][i] = max(a[i], a[i + 1]), negrjmp[0][i] = -rjmp[0][i];
	lrmq[0].init(ljmp[0], n - 1), rrmq[0].init(negrjmp[0], n - 1);
	FORE(k, 1, MAXLGANS) {
		REP(i, n - 1) {
			int l = ljmp[k - 1][i], r = rjmp[k - 1][i];
			if (l == r) { ljmp[k][i] = l, rjmp[k][i] = r; continue; }
			ljmp[k][i] = ljmp[k - 1][lrmq[k - 1].query(l, r - 1)];
			rjmp[k][i] = rjmp[k - 1][rrmq[k - 1].query(l, r - 1)];
			negrjmp[k][i] = -rjmp[k][i];
		}
		lrmq[k].init(ljmp[k], n - 1); rrmq[k].init(negrjmp[k], n - 1);
	}
	REP(i, nq) {
		int l = ql[i], r = qr[i];
		if (l == 0 && r == n - 1) { qans[i] = 0; continue; }
		ll steps = 0; bool ok = false;
		for (int k = MAXLGANS; k >= 0; --k) {
			if (l == r) continue;
			int nl = ljmp[k][lrmq[k].query(l, r - 1)];
			int nr = rjmp[k][rrmq[k].query(l, r - 1)];
			if (nl == 0 && nr == n - 1) { ok = true; continue; }
			steps += 1 << k, l = nl, r = nr;
		}
		qans[i] = ok ? steps + 1 : -1;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

void stresstime() {
	REP(rep, 1) {
		n = MAXN;
		REP(i, n) a[i] = rnd() % n;
		nq = MAXQ;
		REP(i, nq) { ql[i] = rnd() % n, qr[i] = rnd() % n; if (ql[i] > qr[i]) swap(ql[i], qr[i]); }
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stresstime();
	return 0;
}