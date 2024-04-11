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

struct Trans {
	int n;
	int bsz, nb;
	vector<int> val, bval;
	void init(int _n) { n = _n, bsz = sqrt(n), nb = (n + bsz - 1) / bsz; val = vector<int>(n, 0), bval = vector<int>(nb, 0); }
	void addpoint(int x, int by) { val[x] += by; }
	void addrange(int l, int r, int by) {
		int lb = (l + bsz - 1) / bsz;
		while (l <= r && l < lb * bsz) val[l++] += by;
		int rb = (r + 1) / bsz - 1;
		while (l <= r && r >= (rb + 1) * bsz) val[r--] += by;
		FORE(b, lb, rb) bval[b] += by;
	}
	int get(int x) { return val[x] + bval[x / bsz]; }
};

const int MAXN = 100000;
const int MAXQ = 100000;

int n;
int initinv[MAXN];
int nq;
int qkind[MAXQ], qidx[MAXQ], qval[MAXQ];
int qans[MAXQ];

int curinv[MAXN];

int bsz, blg, nb;
vector<int> bl, br;

Trans btrans;
vector<int> bsuff;

vector<vector<int>> tree;
vector<vector<int>> treepos;
vector<int> nsuff;

void mergetree(int k, int offset) {
	int l = offset, m = offset + (1 << k), r = offset + (2 << k), have = 0;
	FOR(i, l, r) {
		if (m < r && (l >= offset + (1 << k) || tree[k][m] <= tree[k][l] + have)) {
			tree[k + 1][i] = tree[k][m];
			treepos[k + 1][i] = treepos[k][m];
			++m, ++have;
		} else {
			tree[k + 1][i] = tree[k][l] + have;
			treepos[k + 1][i] = treepos[k][l];
			++l;
		}
	}
}

void buildtree(int b) {
	tree = vector<vector<int>>(blg + 1, vector<int>(bsz, 0));
	treepos = vector<vector<int>>(blg + 1, vector<int>(bsz, -1));
	FOR(i, bl[b], br[b]) tree[0][i - bl[b]] = curinv[i], treepos[0][i - bl[b]] = i;
	REP(k, blg) for (int offset = 0; offset < bsz; offset += (2 << k)) mergetree(k, offset);
	nsuff = vector<int>(br[b] - bl[b]);
	REP(i, bsz) if (treepos[blg][i] != -1) nsuff[treepos[blg][i] - bl[b]] = tree[blg][i] - i;
}

void updatetree(int b, int idx) {
	tree[0][idx - bl[b]] = curinv[idx];
	REP(k, blg) mergetree(k, ((idx - bl[b]) >> (k + 1)) << (k + 1));
	nsuff = vector<int>(br[b] - bl[b]);
	REP(i, bsz) if (treepos[blg][i] != -1) nsuff[treepos[blg][i] - bl[b]] = tree[blg][i] - i;
}

void init(int b) {
	btrans.init(bl[b] + 1);
	REP(at, bl[b]) btrans.addpoint(at, at);
	buildtree(b);
	FOR(i, bl[b], br[b]) bsuff[i] = nsuff[i - bl[b]], btrans.addrange(bsuff[i], bl[b], +1);
}

void rebuild(int b,int changedidx) {
	updatetree(b, changedidx);
	FOR(i, bl[b], br[b]) {
		int at = nsuff[i - bl[b]];
		if (i == changedidx) {
			btrans.addrange(bsuff[i], bl[b], -1);
			btrans.addrange(at, bl[b], +1);
		} else {
			assert(abs(at - bsuff[i]) <= 1);
			if (at < bsuff[i]) btrans.addpoint(at, +1);
			if (at > bsuff[i]) btrans.addpoint(bsuff[i], -1);
		}
		bsuff[i] = at;
	}
}

int qpos[MAXQ];

void solve() {
	blg = 0; while ((1 << (2 * (blg + 1))) <= n) ++blg;
	bsz = 1 << blg;
	nb = (n + bsz - 1) / bsz;
	//printf("blg=%d bsz=%d\n", blg, bsz);
	bl = br = vector<int>(nb);
	bsuff = vector<int>(n, -1);
	REP(b, nb) bl[b] = b * bsz, br[b] = min(n, (b + 1) * bsz);

	REP(b, nb) {
		REP(i, n) curinv[i] = initinv[i];
		init(b);
		REP(i, nq) {
			int idx = qidx[i];
			if (qkind[i] == 1 && idx / bsz == b) {
				curinv[idx] = qval[i];
				rebuild(b, idx);
			}
			if (qkind[i] == 2 && idx / bsz == b) {
				qpos[i] = curinv[idx];
				FOR(j, idx + 1, br[b]) if (curinv[j] <= qpos[i]) ++qpos[i];
			}
			if (qkind[i] == 2 && idx / bsz < b) {
				qpos[i] = btrans.get(qpos[i]);
			}
		}
	}
	REP(i, nq) qans[i] = n - qpos[i] - 1;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &initinv[i]);
	scanf("%d", &nq);
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 1) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i];
		if (qkind[i] == 2) scanf("%d", &qidx[i]), --qidx[i];
	}
	solve();
	REP(i, nq) if (qkind[i] == 2) printf("%d\n", qans[i] + 1);
}

void stress() {
	int mxlim = 100;
	REP(rep, 10) {
		int lim = rnd() % mxlim + 1;
		n = MAXN;
		REP(i, n) initinv[i] = rnd() % min(i + 1, lim);
		nq = MAXQ;
		REP(i, nq) {
			qkind[i] = rnd() % 2 + 1;
			qidx[i] = rnd() % n;
			if (qkind[i] == 1) qval[i] = rnd() % min(qidx[i] + 1, lim);
		}
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}