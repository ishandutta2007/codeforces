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

// Optimized for many queries and few updates
struct RMQ {
	const int B = 4; // blocks of size 1<<B
	int n;
	vector<vector<vector<int>>> a;

	void init(int _n) {
		n = _n;
		a.clear();
		int sz = n;
		while (sz >= 1) {
			vector<vector<int>> cur(sz);
			REP(i, sz) cur[i] = vector<int>(min(sz - i, (1 << B) - (i & ((1 << B) - 1))), INT_MAX);
			a.PB(cur);
			sz >>= B;
		}
	}
	int get(int l, int r) {
		int ret = INT_MAX;
		for (int lvl = 0; l <= r; ++lvl) {
			int lto = (((l >> B) + 1) << B) - 1, rfrom = (r >> B) << B;
			if (lto >= r) return min(ret, a[lvl][l][r - l]);
			ret = min(ret, a[lvl][l][lto - l]);
			ret = min(ret, a[lvl][rfrom][r - rfrom]);
			l = (l >> B) + 1, r = (r >> B) - 1;
		}
		return ret;
	}
	void mod(int x, int by) {
		REPSZ(lvl, a) {
			if (x >= SZ(a[lvl])) break;
			int y = (x >> B) << B, z = x & ((1 << B) - 1);
			REPE(i, z) FORSZ(j, z - i, a[lvl][y + i]) a[lvl][y + i][j] = min(a[lvl][y + i][j], by);
			x >>= B;
		}
	}
}; 


const int MAXN = 25000;
const int MAXQ = 100000;

int n, nq;
int perm[MAXN];
int ql[MAXQ], qr[MAXQ];
int qans[MAXQ];

int pos[MAXN];

vector<pair<int, int>> cand;
vector<int> candstart;
vector<int> candend;

void findcand() {
	cand.clear();
	struct Q { int l, r, lblock; };
	int bsz = max(1, (int)sqrt(1.0 * n * n / (2 * nq)));
	//printf("bsz=%d\n", bsz);
	vector<Q> q(nq); REP(i, nq) q[i].l = ql[i], q[i].r = qr[i], q[i].lblock = q[i].l / bsz;
	sort(q.begin(), q.end(), [&](const Q& a, const Q& b) { if (a.lblock != b.lblock) return a.lblock < b.lblock; return a.lblock % 2 == 0 ? a.r<b.r : a.r>b.r; });

	set<int> haveval;
	auto addval = [&](int v) {
		auto it = haveval.insert(v).first;
		auto nit = next(it);
		if (it != haveval.begin()) cand.PB(MP(pos[*prev(it)], pos[*it]));
		if (nit != haveval.end()) cand.PB(MP(pos[*it], pos[*nit]));
	};
	auto remval = [&](int v) {
		auto it = haveval.find(v);
		assert(it != haveval.end());
		auto nit = next(it);
		if (it != haveval.begin() && nit != haveval.end()) cand.PB(MP(pos[*prev(it)], pos[*nit]));
		haveval.erase(it);
	};

	int l = 0, r = -1;
	for (Q cur : q) {
		while (r < cur.r) addval(perm[++r]);
		while (l > cur.l) addval(perm[--l]);
		while (r > cur.r) remval(perm[r--]);
		while (l < cur.l) remval(perm[l++]);
	}
	sort(cand.begin(), cand.end());
	cand.erase(unique(cand.begin(), cand.end()), cand.end());
	//printf("cand:"); REPSZ(i, cand) printf(" %d->%d", cand[i].first, cand[i].second); puts("");
}

void findranges() {
	struct E { int id, kind, l, r; E(int id, int kind, int u, int v) :id(id), kind(kind), l(min(u, v)), r(max(u, v)) {} };
	vector<E> e;
	REPSZ(i, cand) e.PB(E(i, +1, cand[i].first, cand[i].second));
	vector<vector<int>> candbyx(n);
	REPSZ(i, cand) candbyx[cand[i].first].PB(i);
	RMQ rmq;
	rmq.init(n);
	for (int i = n - 1; i >= 0; --i) {
		for (int id : candbyx[i]) {
			int best = rmq.get(perm[i], perm[cand[id].second] - 1);
			if (best != INT_MAX) e.PB(E(id, -1, min(i, cand[id].second), best));
		}
		rmq.mod(perm[i], i);
	}
	rmq.init(n);
	REP(i, n) {
		for (int id : candbyx[i]) {
			int best = rmq.get(perm[i], perm[cand[id].second] - 1);
			if (best != INT_MAX) e.PB(E(id, -1, max(i, cand[id].second), -best));
		}
		rmq.mod(perm[i], -i);
	}
	//printf("e:"); REPSZ(i, e) printf(" [%c%d,%d..%d]", e[i].kind < 0 ? '-' : '+', e[i].id, e[i].l, e[i].r); puts("");

	candstart = vector<int>(SZ(cand), INT_MIN);
	candend = vector<int>(SZ(cand), INT_MAX);
	vector<vector<int>> ebyl(n);
	REPSZ(i, e) ebyl[e[i].l].PB(i);
	vector<vector<int>> qbyl(n);
	REP(i, nq) qbyl[ql[i]].PB(i);
	rmq.init(n);
	REP(i, n) {
		for (int id : qbyl[i]) rmq.mod(qr[id], id);
		for (int id : ebyl[i]) {
			int t = rmq.get(e[id].r, n - 1);
			if (e[id].kind == +1) candstart[e[id].id] = max(candstart[e[id].id], t);
			else candend[e[id].id] = min(candend[e[id].id], t);
		}
	}
	//REPSZ(i, cand) printf("cand %d->%d: [%d..%d)\n", cand[i].first, cand[i].second, candstart[i], candend[i]);
}

void calcans() {
	vector<int> delta(nq, 0);
	REPSZ(i, cand) {
		if (candstart[i] == INT_MAX) continue;
		++delta[candstart[i]];
		if (candend[i] != INT_MAX) --delta[candend[i]];
	}
	int sum = 0;
	REP(i, nq) {
		sum += delta[i];
		qans[i] = sum;
	}
}


void solve() {
	REP(i, n) pos[perm[i]] = i;
	findcand();
	findranges();
	calcans();
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &perm[i]), --perm[i];
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

void research() {
	std::mt19937 rnd(125);
	int n = 25000;
	REP(rep, 1000) {
		RMQ rmq;
		rmq.init(n);
		vector<int> chk(n, INT_MAX);
		int val = 1000000;
		REP(q, 100000) {
			if (rnd() % 20 == 0) {
				int idx = rnd() % n;
				rmq.mod(idx, val);
				chk[idx] = min(chk[idx], val);
				//printf("upd %d with %d\n", idx, val);
				--val;
			} else {
				int l = rnd() % n, r = rnd() % n; if (l > r) swap(l, r);
				//if (l != 3 || r != 7) continue;
				int have = rmq.get(l, r);
				int want = INT_MAX; FORE(i, l, r) want = min(want, chk[i]);
				if (have != want) { printf("err q=%d..%d have=%d want=%d\n", l, r, have, want); exit(0); }
			}
		}
		printf(".");
	}
}

int main() {
	run();
	//research();
	return 0;
}