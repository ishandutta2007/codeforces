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

const int MAXVERT = 100000;
const int MAXN = 2 * MAXVERT - 1;
const int MAXLG = 17;
struct Circle { int cent, rad; Circle() {} Circle(int cent, int rad) :cent(cent), rad(rad) {} };

int nvert;
int e[MAXVERT - 1][2];

int n;
vector<int> adj[MAXN];

int par[MAXN];
int dep[MAXN];
int up[MAXN][MAXLG + 1];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

struct CentroidDecomposition {
	struct Level {
		vector<int> par;
		vector<int> root;
		vector<int> subtree;
		vector<int> dep;

		vector<int> cnt;
		vector<ll> sum;
		Level() { par = dep = root = subtree = vector<int>(n, -1); cnt = vector<int>(n, 0); sum = vector<ll>(n, 0); }

		void dfsinit(int at) {
			REPSZ(i, adj[at]) {
				int to = adj[at][i];
				if (to == par[at] || !alive[to]) continue;
				par[to] = at, subtree[to] = subtree[at], root[to] = root[at], dep[to] = dep[at] + 1;
				dfsinit(to);
			}
		}
		void precalc(int cent) {
			par[cent] = -1, root[cent] = cent, subtree[cent] = -1, dep[cent] = 0;
			REPSZ(i, adj[cent]) {
				int to = adj[cent][i];
				if (!alive[to]) continue;
				par[to] = cent, subtree[to] = to, root[to] = cent, dep[to] = 1;
				dfsinit(to);
			}
		}
		void mod(int at, int by) {
			if (root[at] == -1) return;
			cnt[root[at]] += by, sum[root[at]] += by*dep[at];
			if (subtree[at] != -1) cnt[subtree[at]] += by, sum[subtree[at]] += by*dep[at];
		}
		ll calc(int at) {
			if (root[at] == -1) return 0;
			ll ret = sum[root[at]] + (ll)cnt[root[at]] * dep[at];
			if (subtree[at] != -1) ret -= sum[subtree[at]] + (ll)cnt[subtree[at]] * dep[at];
			//printf("\troot=%d -> %lld\n", root[at] + 1, ret);
			return ret;
		}
	};

	vector<Level> levels;
	static vector<bool> alive;
	vector<int> sz;
	void init() {
		levels.clear();
		alive = vector<bool>(n, true);
		sz = vector<int>(n, -1);
		decompose(0, 0);
	}
	void dfssz(int at, int par) {
		sz[at] = 1;
		REPSZ(i, adj[at]) {
			int to = adj[at][i];
			if (to == par || !alive[to]) continue;
			dfssz(to, at);
			sz[at] += sz[to];
		}
	}
	int dfscentroid(int at, int par, int rootsz) {
		REPSZ(i, adj[at]) {
			int to = adj[at][i];
			if (to == par || !alive[to]) continue;
			if (2 * sz[to] > rootsz) return dfscentroid(to, at, rootsz);
		}
		return at;
	}
	int centroid(int at) {
		dfssz(at, -1);
		return dfscentroid(at, -1, sz[at]);
	}
	void decompose(int at,int lvl) {
		at = centroid(at);
		//REP(i, lvl) printf(" "); printf("%d\n", at + 1);
		while (lvl >= SZ(levels)) levels.PB(Level());
		levels[lvl].precalc(at);
		alive[at] = false;
		REPSZ(i, adj[at]) {
			int to = adj[at][i];
			if (!alive[to]) continue;
			decompose(to, lvl + 1);
		}
	}
	void mod(int at, int by) {
		REPSZ(i, levels) levels[i].mod(at, by);
	}
	ll calc(int at) {
		ll ret = 0;
		REPSZ(i, levels) ret += levels[i].calc(at);
		return ret;
	}
};
vector<bool> CentroidDecomposition::alive;

CentroidDecomposition cd;

int calclca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	assert(a != b&&par[a] == par[b]);
	return par[a];
}

int calcup(int a, int n) {
	REPE(k, MAXLG) if (n&(1 << k)) a = up[a][k];
	return a;
}

Circle merge(Circle a, Circle b) {
	int c = calclca(a.cent, b.cent);
	int d = dep[a.cent] + dep[b.cent] - 2 * dep[c];
	if (d + b.rad <= a.rad) return a;
	if (d + a.rad <= b.rad) return b;
	int steps = d + b.rad - a.rad; assert(steps % 2 == 0); steps /= 2;
	int nrad = d + b.rad + a.rad; assert(nrad % 2 == 0); nrad /= 2;
	int ncent; if (steps <= dep[a.cent] - dep[c]) ncent = calcup(a.cent, steps); else if (steps <= d) ncent = calcup(b.cent, d - steps); else assert(false);
	//printf("\t\tmerge (%d,%d) with (%d,%d) -> (%d,%d)\n", a.cent + 1, a.rad, b.cent + 1, b.rad, ncent + 1, nrad);
	return Circle(ncent, nrad);
}

bool inside(Circle a, Circle b) {
	int c = calclca(a.cent, b.cent);
	int d = dep[a.cent] + dep[b.cent] - 2 * dep[c];
	return d + a.rad <= b.rad;
}

int mlt[MAXN];

void mod(int at, int by) {
	//printf("mod(%d,%d)\n", at + 1, by);
	//mlt[at] += by;
	cd.mod(at, by);
}
ll dfscalc(int at, int par, int dep) {
	ll ret = (ll)dep*mlt[at];
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (to == par) continue;
		ret += dfscalc(to, at, dep + 1);
	}
	return ret;
}
ll calc(int at) {
	ll ret = cd.calc(at);
	//ll chk = dfscalc(at, -1, 0);
	//if (ret != chk) { printf("calc(%d): %lld vs %lld\n", at + 1, ret, chk); exit(0); }
	return ret;
}

Circle pref[MAXVERT];
ll radsum[MAXVERT];

ll rec(int l, int r) {
	if (l == r) return 0;
	int m = l + (r - l) / 2;
	ll ret = 0;
	ret += rec(l, m);
	ret += rec(m + 1, r);

	FORE(i, l, r) pref[i] = Circle(i, 0);
	for (int i = m - 1; i >= l; --i) pref[i] = merge(pref[i + 1], pref[i]);
	for (int i = m + 2; i <= r; ++i) pref[i] = merge(pref[i - 1], pref[i]);
	radsum[m] = 0; FORE(i, m + 1, r) radsum[i] = radsum[i - 1] + pref[i].rad;
	int a = m + 1, b = m + 1;
	//printf("processing %d..%d with %d..%d\n", l+1, m+1, m + 2, r+1);
	//FORE(i, l, r) printf("%d: (%d,%d)\n", i+1, pref[i].cent + 1, pref[i].rad);
	for (int i = m; i >= l; --i) {
		while (a <= r && inside(pref[a], pref[i])) mod(pref[a++].cent, -1);
		while (b <= r && !inside(pref[i], pref[b])) mod(pref[b++].cent, +1);
		ll now = 0;
		// [m+1..a) -> pref[i].rad
		now += (ll)(a - (m + 1))*pref[i].rad;
		// [a..b) -> (dist(i,j)+pref[i].rad+pref[j].rad)/2
		ll cur = (ll)(b - a)*pref[i].rad + (radsum[b - 1] - radsum[a - 1]) + calc(pref[i].cent);
		assert(cur % 2 == 0);
		now += cur / 2;
		// [b..r] -> pref[j].rad
		now += (radsum[r] - radsum[b - 1]);
		//printf("\t%d -> %lld (a=%d b=%d) [%lld (%lld+%lld+%lld)/2 %lld]\n", i + 1, now, a + 1, b + 1, (ll)(a - (m + 1))*pref[i].rad, (ll)(b - a)*pref[i].rad, radsum[b - 1] - radsum[a - 1], calc(pref[i].cent), radsum[r] - radsum[b - 1]);
		ret += now;
	}
	while (a > m + 1) mod(pref[--a].cent, +1);
	while (b > m + 1) mod(pref[--b].cent, -1);

	return ret;
}

ll solve() {
	n = 2 * nvert - 1;
	REP(i, n) adj[i].clear();
	REP(i, nvert - 1) { int a = e[i][0], b = e[i][1]; int mid = nvert + i; adj[a].PB(mid); adj[mid].PB(a); adj[b].PB(mid); adj[mid].PB(b); }

	par[0] = -1; dfsinit(0);
	cd.init();

	REP(i, n) mlt[i] = 0;
	return rec(0, nvert - 1);
}

void run() {
	scanf("%d", &nvert);
	REP(i, nvert - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; e[i][0] = a, e[i][1] = b; }
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}