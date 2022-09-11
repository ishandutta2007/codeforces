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

const int MAXN = 100000;
const int MAXQ = 100000;
const int MAXS = 4 * MAXN;
struct SVal { int acnt, bcnt, ccnt; int acbest, cabest, abest, cbest,aabest,ccbest; };

int n, nq;
char s[MAXN + 1];
int qidx[MAXQ]; char qc[MAXQ];
int qans[MAXQ];

SVal sval[MAXS];

SVal smake(char c) {
	SVal ret;
	ret.acnt = c == 'a' ? 1 : 0;
	ret.bcnt = c == 'b' ? 1 : 0;
	ret.ccnt = c == 'c' ? 1 : 0;
	ret.acbest = INT_MAX;
	ret.cabest = INT_MAX;
	ret.abest = c == 'a' ? 0 : INT_MAX;
	ret.cbest = c == 'c' ? 0 : INT_MAX;
	ret.aabest = c == 'a' ? 0 : INT_MAX;
	ret.ccbest = c == 'c' ? 0 : INT_MAX;
	return ret;
}
SVal smerge(const SVal &x,const SVal &y) {
	SVal ret;
	ret.acnt = x.acnt + y.acnt;
	ret.bcnt = x.bcnt + y.bcnt;
	ret.ccnt = x.ccnt + y.ccnt;
	ret.acbest = INT_MAX;
	if (x.acbest != INT_MAX) ret.acbest = min(ret.acbest, x.acbest + y.ccnt);
	if (y.acbest != INT_MAX) ret.acbest = min(ret.acbest, x.acnt + y.acbest);
	if (x.abest != INT_MAX && y.cbest != INT_MAX) ret.acbest = min(ret.acbest, x.abest + y.cbest);
	ret.cabest = INT_MAX;
	if (x.cabest != INT_MAX) ret.cabest = min(ret.cabest, x.cabest + y.ccnt);
	if (y.cabest != INT_MAX) ret.cabest = min(ret.cabest, x.acnt + y.cabest);
	if (x.ccbest != INT_MAX && y.aabest != INT_MAX) ret.cabest = min(ret.cabest, x.ccbest + y.aabest);
	ret.abest = INT_MAX;
	if (x.abest != INT_MAX) ret.abest = min(ret.abest, x.abest + y.bcnt);
	if (y.abest != INT_MAX) ret.abest = min(ret.abest, x.acnt + y.abest);
	ret.cbest = INT_MAX;
	if (x.cbest != INT_MAX) ret.cbest = min(ret.cbest, x.cbest + y.ccnt);
	if (y.cbest != INT_MAX) ret.cbest = min(ret.cbest, x.bcnt + y.cbest);
	ret.aabest = INT_MAX;
	if (x.aabest != INT_MAX) ret.aabest = min(ret.aabest, x.aabest + y.ccnt);
	if (y.aabest != INT_MAX) ret.aabest = min(ret.aabest, x.acnt + x.ccnt + y.aabest);
	ret.ccbest = INT_MAX;
	if (x.ccbest != INT_MAX) ret.ccbest = min(ret.ccbest, x.ccbest + y.acnt + y.acnt);
	if (y.ccbest != INT_MAX) ret.ccbest = min(ret.ccbest, x.acnt + y.ccbest);
	return ret;
}

void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x] = smake(s[l]);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		sval[x] = smerge(sval[2 * x + 1], sval[2 * x + 2]);
	}
}
void smod(int x, int l, int r, int IDX, char C) {
	if (l == r) {
		sval[x] = smake(C);
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) smod(2 * x + 1, l, m, IDX, C); else smod(2 * x + 2, m + 1, r, IDX, C);
		sval[x] = smerge(sval[2 * x + 1], sval[2 * x + 2]);
	}
}

int calc(const SVal &x) {
	return min({ x.acnt, x.bcnt, x.ccnt, x.acbest, x.cabest });
}

void solve() {
	sinit(0, 0, n - 1);
	REP(i, nq) {
		smod(0, 0, n - 1, qidx[i], qc[i]);
		qans[i] = calc(sval[0]);
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	scanf("%s", s);
	REP(i, nq) scanf("%d %c", &qidx[i], &qc[i]), --qidx[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int qansstupid[MAXQ];

void solvestupid() {
	string cur = s;
	REP(i, nq) {
		cur[qidx[i]] = qc[i];
		qansstupid[i] = INT_MAX;
		REP(mask, 1 << n) {
			int other = (1 << n) - 1 - mask;
			for (int sub = 0;; sub = (sub + other + 1) & mask) {
				string tmp = cur;
				REP(j, n) if (mask & (1 << j)) {
					++tmp[j];
					if (tmp[j] == 'd') tmp[j] = 'a';
					if (sub & (1 << j)) {
						++tmp[j];
						if (tmp[j] == 'd') tmp[j] = 'a';
					}
				}
				int nxt = 0;
				REP(j, n) if (tmp[j] == 'a' + nxt) ++nxt;
				if (nxt != 3) {
					int cnt = 0;
					REP(j, n) if (mask & (1 << j)) ++cnt;
					//if (cnt == 0) printf("mask=%x sub=%x tmp=%s\n", mask, sub, tmp.c_str());
					qansstupid[i] = min(qansstupid[i], cnt);
				}
				if (sub == mask) break;
			}
		}
	}
}

void stress() {
	std::mt19937 rnd(3123);
	int mxn = 12, mxq = 10;
	REP(rep, 1000) {
		n = rnd() % mxn + 1;
		nq = rnd() % mxq + 1;
		REP(i, n) s[i] = 'a' + rnd() % 3;
		s[n] = '\0';
		REP(i, nq) qidx[i] = rnd() % n, qc[i] = 'a' + rnd() % 3;
		solve();
		solvestupid();
		bool ok = true;
		REP(i, nq) if (qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err rep=%d\n", rep);
		printf("%d %d\n", n, nq); printf("%s\n", s); REP(i, nq) printf("%d %c\n", qidx[i] + 1, qc[i]);
		printf("have:"); REP(i, nq) printf(" %d", qans[i]); puts("");
		printf("want:"); REP(i, nq) printf(" %d", qansstupid[i]); puts("");
	}
}

int main() {
	//stress();
	run();
	return 0;
}