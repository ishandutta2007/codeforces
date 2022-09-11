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
const int MAXS = 4 * MAXN;

int n, lim;
char s[MAXN + 1];
int lc[MAXN], rc[MAXN];
char ans[2 * MAXN + 1];

int par[MAXN], dep[MAXN];
int tin[MAXN], tout[MAXN], nt;

int ord[MAXN], nord;

int state[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	tin[at] = nt++;
	REP(i, 2) {
		int to = i == 0 ? lc[at] : rc[at];
		if (to == -1) continue;
		par[to] = at;
		dfsinit(to);
	}
	tout[at] = nt - 1;
}
void dfsord(int at) {
	if (lc[at] != -1) dfsord(lc[at]);
	ord[nord++] = at;
	if (rc[at] != -1) dfsord(rc[at]);
}
void unmark(int at) {
	//printf("unmark(%d)\n", at + 1);
	if (state[at] == 0) return;
	assert(state[at] == -1);
	state[at] = 0;
	if (lc[at] != -1) unmark(lc[at]);
	if (rc[at] != -1) unmark(rc[at]);
}

namespace seg {
	int val[MAXS];
	void push(int x) {
		if (val[x] == -2) return;
		val[2 * x + 1] = val[2 * x + 2] = val[x];
		val[x] = -2;
	}
	void set(int x, int l, int r, int L, int R, int VAL) {
		if (L <= l && r <= R) {
			val[x] = VAL;
		} else {
			int m = l + (r - l) / 2;
			push(x);
			if (L <= m) set(2 * x + 1, l, m, L, R, VAL);
			if (m + 1 <= R) set(2 * x + 2, m + 1, r, L, R, VAL);
		}
	}
	int get(int x, int l, int r, int IDX) {
		if (l == r) {
			return val[x];
		} else {
			int m = l + (r - l) / 2;
			push(x);
			return IDX <= m ? get(2 * x + 1, l, m, IDX) : get(2 * x + 2, m + 1, r, IDX);
		}
	}
};

void solve() {
	par[0] = -1; nt = 0;
	dfsinit(0);

	nord = 0;
	dfsord(0);
	assert(nord == n);

	int rem = lim;
	REP(i, n) state[i] = -1;
	seg::set(0, 0, n - 1, 0, n - 1, -1);
	for (int l = 0, r = l; l < n; l = r) {
		char c = s[ord[l]];
		while (r < n && s[ord[r]] == c) ++r;
		if (r == n || c > s[ord[r]]) {
			FOR(i, l, r) {
				int at = ord[i];
				if (state[at] == -1) unmark(at);
			}
		} else {
			vector<int> roots;
			FOR(i, l, r) {
				int at = ord[i];
				while (SZ(roots) > 0 && dep[roots.back()] > dep[at]) roots.pop_back();
				roots.PB(at);
			}
			int idx = l;
			for (int root : roots) {
				if (state[root] == -1) {
					int marked = seg::get(0, 0, n - 1, tin[root]);
					int need = dep[root] - (marked == -1 ? -1 : dep[marked]);
					if (need <= rem) {
						int at = root, prv = -1;
						seg::set(0, 0, n - 1, tin[at], tout[at], at);
						while (at != marked) {
							assert(at != -1 && state[at] == -1);
							state[at] = 1, --rem;
							//printf("mark(%d)\n", at + 1);
							if (prv != -1) assert(prv == lc[at]);
							if (rc[at] != -1) seg::set(0, 0, n - 1, tin[rc[at]], tout[rc[at]], at);
							prv = at, at = par[at];
						}
					} else {
						unmark(root);
					}
				}
				vector<int> lst;
				while (true) {
					int at = ord[idx++];
					if (at == root) break;
					lst.PB(at);
				}
				sort(lst.begin(), lst.end(), [&](int u, int v) { return dep[u] < dep[v]; });
				for (int at : lst) {
					assert(par[at] != -1 && state[par[at]] != -1);
					if (state[at] == 0) continue;
					assert(state[par[at]] == 1);
					if (state[at] == 1) continue;
					if (rem > 0) {
						state[at] = 1, --rem;
						//printf("mark(%d)\n", at + 1);
						seg::set(0, 0, n - 1, tin[at], tout[at], at);
					} else {
						unmark(at);
					}
				}
			}
		}
	}

	int anslen = 0;
	REP(i, n) {
		int at = ord[i];
		ans[anslen++] = s[at];
		if (state[at] == 1) ans[anslen++] = s[at];
	}
	ans[anslen] = '\0';
}

void run() {
	scanf("%d%d", &n, &lim);
	scanf("%s", s);
	REP(i, n) scanf("%d%d", &lc[i], &rc[i]), --lc[i], --rc[i];
	solve();
	printf("%s\n", ans);
}

int main() {
	run();
	return 0;
}