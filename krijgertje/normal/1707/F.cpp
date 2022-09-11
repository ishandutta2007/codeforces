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

const int MAXN = 10000000;
const int MAXINIT = 100000;
const int MAXQ = 100000;

int n, ninit, nops, nbit;
int initpos[MAXINIT], initval[MAXINIT];
int nq;
int qpos[MAXQ], qval[MAXQ], qmod[MAXQ];
int qans[MAXQ];

int val[MAXN];
int bval[MAXN], bcnt[MAXN];

const int IMPOSSIBLE = -1;
const int UNCONSTRAINED = -2;
int sidx[MAXN];
int sval[2 * MAXN], sfree[2 * MAXN];
void calcsidx(int k, int offset, int step, int idx) {
	if (k == 0) { sidx[offset] = idx; return; }
	calcsidx(k - 1, offset, 2 * step, idx);
	calcsidx(k - 1, offset + step, 2 * step, idx + (1 << (k - 1)));
}

int pw(int x, int n, int mod) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % mod; if ((n >>= 1) == 0) return ret; x = (ll)x * x % mod; } }

void solve() {
	int nb = 1, lgnb = 0, bsz = n;
	while (bsz % 2 == 0) nb *= 2, ++lgnb, bsz /= 2;
	//printf("nb=%d bsz=%d\n", nb, bsz);

	REP(i, n) val[i] = -1;
	REP(i, nb) bval[i] = 0, bcnt[i] = 0;
	REP(i, ninit) {
		int pos = initpos[i], v = initval[i], b = pos & (nb - 1);
		assert(val[pos] == -1); val[pos] = v, bval[b] ^= v, ++bcnt[b];
	}

	if (nops < nb) {
		REP(i, nb) sidx[i] = -1;
		calcsidx(lgnb, 0, 1, 0);
		//printf("sidx:"); REP(b, nb) printf(" %d", sidx[b]); puts("");

		auto ssetleaf = [&](int b) {
			int idx = nb + sidx[b];
			if (bcnt[b] < bsz) {
				sval[idx] = UNCONSTRAINED; sfree[idx] = bsz - bcnt[b] - 1;
			} else {
				sval[idx] = bval[b]; sfree[idx] = 0;
			}
		};
		auto upd = [&](int idx, int k) {
			sfree[idx] = sfree[2 * idx + 0] + sfree[2 * idx + 1];
			if (sval[2 * idx + 0] == IMPOSSIBLE || sval[2 * idx + 1] == IMPOSSIBLE) { sval[idx] = IMPOSSIBLE; return; }
			if ((nops & (1 << k)) == 0) {
				sval[idx] = sval[2 * idx + 0] == UNCONSTRAINED || sval[2 * idx + 1] == UNCONSTRAINED ? UNCONSTRAINED : sval[2 * idx + 0] ^ sval[2 * idx + 1];
				if (sval[2 * idx + 0] == UNCONSTRAINED && sval[2 * idx + 1] == UNCONSTRAINED) ++sfree[idx];
			} else {
				if (sval[2 * idx + 0] == UNCONSTRAINED || sval[2 * idx + 1] == UNCONSTRAINED) {
					sval[idx] = sval[2 * idx + 0] != UNCONSTRAINED ? sval[2 * idx + 0] : sval[2 * idx + 1] != UNCONSTRAINED ? sval[2 * idx + 1] : UNCONSTRAINED;
				} else {
					if (sval[2 * idx + 0] == sval[2 * idx + 1]) {
						sval[idx] = sval[2 * idx + 0];
					} else {
						sval[idx] = IMPOSSIBLE;
					}
				}
			}
			//printf("\tidx=%d: sval=%d sfree=%d [%d,%d] <%d,%d> {%d,%d}\n", idx, sval[idx], sfree[idx], 2 * idx + 0, 2 * idx + 1, sval[2 * idx + 0], sval[2 * idx + 1], sfree[2 * idx + 0], sfree[2 * idx + 1]);
		};
		auto sset = [&](int b) {
			ssetleaf(b);
			//printf("setting b=%d -> sval=%d sfree=%d\n", b, sval[idx], sfree[idx]);
			int idx = nb + sidx[b];
			for (int k = lgnb - 1; k >= 0; --k) { idx /= 2; upd(idx, k); }
		};

		REP(b, nb) ssetleaf(b);
		for (int k = lgnb - 1; k >= 0; --k) REP(offset, 1 << k) upd((1 << k) + offset, k);

		//printf("sval=%d sfree=%d\n", sval[1], sfree[1]);
		REP(i, nq) {
			int pos = qpos[i], v = qval[i], b = pos & (nb - 1), mod = qmod[i];
			if (val[pos] != -1) bval[b] ^= val[pos], --bcnt[b], val[pos] = -1;
			if (v != -1) val[pos] = v, bval[b] ^= v, ++bcnt[b];
			sset(b);
			//printf("sval=%d sfree=%d\n", sval[1], sfree[1]);
			qans[i] = sval[1] == IMPOSSIBLE ? 0 : pw((1 << nbit) % mod, sfree[1] + (sval[1] == UNCONSTRAINED ? 1 : 0), mod);
		}
	} else {
		int nbad = 0, nfree = 0;
		REP(b, nb) if (bcnt[b] == bsz && bval[b] != 0) ++nbad; else if (bcnt[b] != bsz) nfree += bsz - bcnt[b] - 1;
		REP(i, nq) {
			int pos = qpos[i], v = qval[i], b = pos & (nb - 1), mod = qmod[i];
			if (bcnt[b] == bsz && bval[b] != 0) --nbad; else if (bcnt[b] != bsz) nfree -= bsz - bcnt[b] - 1;
			if (val[pos] != -1) bval[b] ^= val[pos], --bcnt[b], val[pos] = -1;
			if (v != -1) val[pos] = v, bval[b] ^= v, ++bcnt[b];
			if (bcnt[b] == bsz && bval[b] != 0) ++nbad; else if (bcnt[b] != bsz) nfree += bsz - bcnt[b] - 1;
			//printf("nbad=%d nfree=%d bval=%d bcnt=%d\n", nbad, nfree, bval[b], bcnt[b]);
			qans[i] = nbad > 0 ? 0 : pw((1 << nbit) % mod, nfree, mod);
		}
	}
}

void run() {
	scanf("%d%d%d%d", &n, &ninit, &nops, &nbit);
	REP(i, ninit) scanf("%d%d", &initpos[i], &initval[i]), --initpos[i];
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d%d", &qpos[i], &qval[i], &qmod[i]), --qpos[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int qansstupid[MAXQ];

void solvestupid() {
	vector<int> c(n, -1);
	REP(i, ninit) c[initpos[i]] = initval[i];
	REP(i, nq) {
		c[qpos[i]] = qval[i];
		set<vector<int>> can;
		REP(amask, 1 << (nbit * n)) {
			vector<int> a(n);
			REP(j, n) a[j] = (amask >> (j * nbit)) & ((1 << nbit) - 1);
			REP(k, nops) { int a0 = a[0]; REP(i, n - 1) a[i] ^= a[i + 1]; a[n - 1] ^= a0; }
			bool ok = true;
			REP(i, n) if (c[i] != -1 && c[i] != a[i]) ok = false;
			if (ok) can.insert(a);
		}
		qansstupid[i] = SZ(can);
	}
}

void stress() {
	int mxprod = 16;
	REP(rep, 10000) {
		n = rnd() % mxprod + 1, ninit = 0 /* rnd() % (n + 1)*/, nops = rnd() % (n + 1), nbit = rnd() % (mxprod / n) + 1;
		REP(i, ninit) initpos[i] = rnd() % (n - ninit + 1);
		sort(initpos, initpos + ninit);
		REP(i, ninit) initpos[i] += i;
		REP(i, ninit) initval[i] = rnd() % (1 << nbit);
		nq = 1;
		REP(i, nq) qpos[i] = rnd() % n, qval[i] = rnd() % (1 << nbit), qmod[i] = 1000000007;
		solve();
		solvestupid();
		bool ok = true; REP(i, nq) if (qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("have:"); REP(i, nq) printf(" %d", qans[i]); puts("");
		printf("want:"); REP(i, nq) printf(" %d", qansstupid[i]); puts("");
		printf("%d %d %d %d\n", n, ninit, nops, nbit); REP(i, ninit) printf("%d %d\n", initpos[i] + 1, initval[i]); printf("%d\n", nq); REP(i, nq) printf("%d %d %d\n", qpos[i] + 1, qval[i], qmod[i]);
		mxprod = n * nbit - 1; if (mxprod == 0) break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}