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
#include <array>
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
const int MAXQ = 50000;

int n, nq;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int qkind[MAXQ], qidx[MAXQ], qval[MAXQ], qlim[MAXQ];
ll qans[MAXQ];

int oa[MAXN];
int bb[MAXN];
int cc[MAXN];

bool isfixed[MAXN];
vector<int> dyn;
vector<int> revdyn;

vector<pair<int, int>> qdpsumfixed[MAXN];
vector<pair<pair<int, int>, pair<int, int>>> qprefdpfixed[MAXN];
vector<pair<pair<int, int>, int>> qskipdpfixed[MAXN];
vector<pair<pair<int, int>, pair<int, pair<int, int>>>> qcntfixed[MAXN];
int cntfixed[MAXN][3];
ll dpfixed[MAXN][3];
ll sumdpfixed[3];
ll dpdyn[MAXN][3];

struct Change { int qid; array<ll,3> val; Change() {} Change(int qid, array<ll, 3> val) :qid(qid), val(val) {} };
vector<Change> changes;

void solve() {
	// u*nb*n+v*nq*bsz -> bsz=sqrt(u/v)*sqrt(n)
	int bsz = max(1, (int)sqrt(n));
	
	REP(i, n) oa[i] = a[i];
	REP(i, n) bb[i] = b[a[i]], cc[i] = c[a[i]];
	changes = vector<Change>(10 * bsz * bsz);
	for (int lq = 0, rq; lq < nq; lq = rq) {
		rq = min(lq + bsz, nq);

		REP(i, n) isfixed[i] = true;
		FOR(i, lq, rq) if (qkind[i] == 1) isfixed[qidx[i]] = false;
		dyn = vector<int>();
		REP(i, n) if (!isfixed[i]) dyn.PB(i);
		revdyn = dyn; reverse(revdyn.begin(), revdyn.end());
		//printf("q%d..%d\n", lq + 1, rq);
		//printf("fixed: "); REP(i, n) printf("%c", isfixed[i] ? 'V' : '.'); puts("");

		int nchanges = 0;
		REP(i, n) qdpsumfixed[i] = vector<pair<int, int>>(), qprefdpfixed[i] = vector<pair<pair<int, int>, pair<int, int>>>(), qskipdpfixed[i] = vector<pair<pair<int, int>, int>>(), qcntfixed[i] = vector<pair<pair<int, int>, pair<int, pair<int, int>>>>();
		FOR(qid, lq, rq) {
			if (qkind[qid] == 1) a[qidx[qid]] = qval[qid], bb[qidx[qid]] = b[qval[qid]], cc[qidx[qid]] = c[qval[qid]];
			if (qkind[qid] == 2) {
				qans[qid] = 0;
				int lim = qlim[qid];
				//FFF
				changes[nchanges++] = Change(qid, array<ll, 3>{0, 1, 1});
				qdpsumfixed[lim].PB(MP(nchanges - 1, 0));

				for (int i : dyn) REP(j, 3) dpdyn[a[i]][j] = dpdyn[bb[i]][j] = dpdyn[cc[i]][j] = 0;
				for (int i : dyn) if (i <= lim) {
					ll C = dpdyn[cc[i]][1], A = dpdyn[a[i]][0], B = 1, CC = dpdyn[cc[i]][0];
					dpdyn[cc[i]][2] += C;
					dpdyn[a[i]][1] += A;
					dpdyn[bb[i]][0] += B;
					//DDF
					changes[nchanges++] = Change(qid, array<ll, 3>{+A, 0, 1});
					qcntfixed[lim].PB(MP(MP(nchanges - 1, 1), MP(+1, MP(a[i], 2))));
					qcntfixed[i].PB(MP(MP(nchanges - 1, 1), MP(-1, MP(a[i], 2))));
					//DFF
					changes[nchanges++] = Change(qid, array<ll, 3>{+B, 0, 1});
					qskipdpfixed[lim].PB(MP(MP(nchanges - 1, 1), bb[i]));
					//printf("watch %d [%d]\n", nchanges - 1, bb[i] + 1);
					changes[nchanges++] = Change(qid, array<ll, 3>{-B, 0, 1});
					qskipdpfixed[i].PB(MP(MP(nchanges - 1, 1), bb[i]));
					//printf("watch %d\n", nchanges - 1);
					changes[nchanges++] = Change(qid, array<ll, 3>{-B, 0, 0});
					qcntfixed[i].PB(MP(MP(nchanges - 1, 1), MP(+1, MP(bb[i], 1))));
					qcntfixed[lim].PB(MP(MP(nchanges - 1, 2), MP(+1, MP(bb[i], 2))));
					qcntfixed[i].PB(MP(MP(nchanges - 1, 2), MP(-1, MP(bb[i], 2))));
					//printf("watch %d\n", nchanges - 1);
					//FDF
					if (i - 1 >= 0) {
						changes[nchanges++] = Change(qid, array<ll, 3>{0, 0, 1});
						qcntfixed[i - 1].PB(MP(MP(nchanges - 1, 0), MP(+1, MP(a[i], 0))));
						qcntfixed[lim].PB(MP(MP(nchanges - 1, 1), MP(+1, MP(a[i], 2))));
						qcntfixed[i].PB(MP(MP(nchanges - 1, 1), MP(-1, MP(a[i], 2))));
					}
					//DFD +
					if (i - 1 >= 0) {
						changes[nchanges++] = Change(qid, array<ll, 3>{+CC, 0, 1});
						qcntfixed[i - 1].PB(MP(MP(nchanges - 1, 1), MP(+1, MP(cc[i], 1))));
					}

				}
				for (int i : revdyn) REP(j, 3) dpdyn[a[i]][j] = dpdyn[bb[i]][j] = dpdyn[cc[i]][j] = 0;
				for (int i : revdyn) if (i <= lim) {
					ll B = dpdyn[bb[i]][1], A = dpdyn[a[i]][2], C = 1, BB = dpdyn[bb[i]][2];
					dpdyn[bb[i]][0] += B;
					dpdyn[a[i]][1] += A;
					dpdyn[cc[i]][2] += C;
					// DDD
					qans[qid] += B;
					// FDD
					if (i - 1 >= 0) {
						changes[nchanges++] = Change(qid, array<ll, 3>{A, 0, 1});
						qprefdpfixed[i - 1].PB(MP(MP(nchanges - 1, 1), MP(a[i], 0)));
					}
					//FFD
					if (i - 1 >= 0) {
						changes[nchanges++] = Change(qid, array<ll, 3>{C, 0, 1});
						qprefdpfixed[i - 1].PB(MP(MP(nchanges - 1, 1), MP(cc[i], 1)));
					}
					//DFD -
					changes[nchanges++] = Change(qid, array<ll, 3>{-BB, 0, 1});
					qcntfixed[i].PB(MP(MP(nchanges - 1, 1), MP(+1, MP(bb[i], 1))));
				}
			}
		}

		REP(i, n) REP(j, 3) dpfixed[i][j] = 0, cntfixed[i][j] = 0;
		REP(j, 3) sumdpfixed[j] = 0;
		REP(i, n) {
			if (isfixed[i]) {
				cntfixed[bb[i]][0] += 1;
				cntfixed[a[i]][1] += 1;
				cntfixed[cc[i]][2] += 1;
				dpfixed[cc[i]][2] += dpfixed[cc[i]][1];
				sumdpfixed[2] += dpfixed[cc[i]][1];
				dpfixed[a[i]][1] += dpfixed[a[i]][0];
				sumdpfixed[1] += dpfixed[a[i]][0];
				dpfixed[bb[i]][0] += 1;
				sumdpfixed[0] += 1;
				//printf("%d: dpfixed[%d][2]=%lld, dpfixed[%d][1]=%lld dpfixed[%d][0]=%lld\n", i + 1, cc[i] + 1, dpfixed[cc[i]][2], a[i] + 1, dpfixed[a[i]][1], bb[i] + 1, dpfixed[bb[i]][0]);
			}
			for (const auto& [cid, idx] : qdpsumfixed[i]) changes[cid].val[idx] = sumdpfixed[2];
			for (const auto& [key, value] : qprefdpfixed[i]) { const auto& [cid, idx] = key; const auto& [v, j] = value; changes[cid].val[idx] = dpfixed[v][j]; }
			for (const auto& [key, value] : qcntfixed[i]) { const auto& [cid, idx] = key; const auto& [mlt, value2] = value; const auto& [v, j] = value2; changes[cid].val[idx] += mlt * cntfixed[v][j]; }
		}
		REP(i, n) REP(j, 3) dpfixed[i][j] = 0;
		REP(i, n) {
			if (isfixed[i]) {
				dpfixed[cc[i]][2] += dpfixed[cc[i]][1];
				dpfixed[a[i]][1] += 1;
			}
			for (const auto& [key, v] : qskipdpfixed[i]) { const auto& [cid, idx] = key; changes[cid].val[idx] = dpfixed[v][2]; }
		}
		//REPSZ(i, changes) if (i == 3 || i == 4 || i == 5) { printf("WATCH:"); REPSZ(j, changes[i].val) printf(" %lld", changes[i].val[j]); puts(""); }
		REP(i, nchanges) { const auto& c = changes[i]; ll cur = c.val[0] * c.val[1] * c.val[2]; /*printf("%d by %lld (%d)\n", c.qid + 1, cur, SZ(c.val));*/ qans[c.qid] += cur; }
	}
	REP(i, n) a[i] = oa[i];
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	REP(i, n) scanf("%d", &b[i]), --b[i];
	REP(i, n) scanf("%d", &c[i]), --c[i];
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 1) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i], --qval[i];
		if (qkind[i] == 2) scanf("%d", &qlim[i]), --qlim[i];
	}
	solve();
	REP(i, nq) if (qkind[i] == 2) printf("%lld\n", qans[i]);
}

ll qansstupid[MAXQ];
void solvestupid() {
	REP(i, n) oa[i] = a[i];
	REP(qid, nq) {
		if (qkind[qid] == 1) a[qidx[qid]] = qval[qid];
		if (qkind[qid] == 2) {
			qansstupid[qid] = 0;
			int lim = qlim[qid];
			REPE(i, lim) FORE(j, i + 1, lim) if (b[a[i]] == a[j]) FORE(k, j + 1, lim) if (c[a[k]] == a[j]) ++qansstupid[qid];
		}
	}
	REP(i, n) a[i] = oa[i];
}

void stress() {
	REP(rep, 1000) {
		n = 100, nq = 1000;
		REP(i, n) a[i] = rnd() % n, b[i] = rnd() % n, c[i] = rnd() % n;
		REP(i, nq) {
			qkind[i] = rnd() % 2 + 1;
			if (qkind[i] == 1) qidx[i] = rnd() % n, qval[i] = rnd() % n; else qlim[i] = rnd() % n;
		}
		solve();
		solvestupid();
		bool ok = true; REP(i, nq) if (qkind[i] == 2 && qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("have:"); REP(i, nq) if (qkind[i] == 2) printf(" %lld", qans[i]); puts("");
		printf("want:"); REP(i, nq) if (qkind[i] == 2) printf(" %lld", qansstupid[i]); puts("");
		printf("%d %d\n", n, nq); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i] + 1); } puts(""); REP(i, n) { if (i != 0) printf(" "); printf("%d", b[i] + 1); } puts(""); REP(i, n) { if (i != 0) printf(" "); printf("%d", c[i] + 1); } puts(""); REP(i, nq) if (qkind[i] == 1) printf("%d %d %d\n", 1, qidx[i] + 1, qval[i] + 1); else if (qkind[i] == 2) printf("%d %d\n", 2, qlim[i] + 1);
	}
}

void stresstime() {
	REP(rep, 1) {
		n = MAXN, nq = MAXQ;
		REP(i, n) a[i] = rnd() % n, b[i] = rnd() % n, c[i] = rnd() % n;
		REP(i, nq) {
			qkind[i] = rnd() % 2 + 1;
			if (qkind[i] == 1) qidx[i] = rnd() % n, qval[i] = rnd() % n; else qlim[i] = rnd() % n;
		}
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	//stresstime();
	return 0;
}