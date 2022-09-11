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

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return find(par[x]); }
	void unite(int x, int y) { x = find(x), y = find(y); if (x == y) return; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; }
};

const int MAXN = 100000;

int n, na;
int par[MAXN];
char ans[MAXN + 1];

vector<int> ch[MAXN];
int dep[MAXN];
vector<int> bydep[MAXN];
UF uf;
vector<int> bysz[MAXN + 1];

bool can[MAXN + 1];
pair<int, int> act[MAXN + 1];
int szrem[MAXN + 1];
bool use[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	for (int to : ch[at]) dfsinit(to);
}

int solve() {
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);
	dfsinit(0);
	
	REP(i, n) bydep[dep[i]].PB(i);
	uf.init(n);
	for (int d = n - 1; d >= 0; --d) {
		int fst = -1;
		for (int at : bydep[d]) if (fst == -1) fst = at; else uf.unite(at, fst);
	}
	REP(at, n) if (uf.find(at) == at) bysz[uf.sz[at]].PB(at);
	//printf("bysz:"); FORE(sz, 1, n) if (SZ(bysz[sz]) != 0) printf(" %d*%d", SZ(bysz[sz]), sz); puts("");

	REPE(i, na) can[i] = false;
	can[0] = true; act[0] = MP(-1, -1);
	FORE(sz, 1, n) if (SZ(bysz[sz]) != 0) {
		int lim = SZ(bysz[sz]);
		REP(offset, sz) {
			int need = INT_MAX;
			for (int i = offset; i <= na; i += sz) {
				if (can[i]) { need = 0; continue; }
				if (need != INT_MAX) ++need;
				if (need <= lim) can[i] = true, act[i] = MP(need, sz);
			}
		}
	}

	int ndep = 0;
	REP(i, n) if (SZ(bydep[i]) != 0) ++ndep;

	if (can[na]) {
		//printf("YES\n");
		vector<pair<int, int>> how;
		for (int i = na; i != 0; i -= act[i].first * act[i].second) how.PB(act[i]);
		//printf("how:"); REPSZ(i, how) printf(" %d*%d", how[i].first, how[i].second); puts("");
		FORE(i, 1, n) szrem[i] = 0;
		REPSZ(i, how) szrem[how[i].second] += how[i].first;
		REP(i, n) use[i] = false;
		REP(at, n) {
			int leader = uf.find(at), sz = uf.sz[leader];
			if (!use[leader] && szrem[sz] > 0) use[leader] = true, --szrem[sz];
			ans[at] = use[leader] ? 'a' : 'b';
		}
		return ndep;
	} else {
		int lastskip = -1;
		int arem = na;
		REP(i, n) ans[i] = 'b';
		REP(d, n) {
			if (SZ(bydep[d]) <= arem) {
				for (int at : bydep[d]) ans[at] = 'a', --arem;
			} else {
				lastskip = d;
			}
		}
		if (lastskip != -1) for (int at : bydep[lastskip]) if (SZ(ch[at]) == 0 && arem > 0) ans[at] = 'a', --arem;
		assert(arem == 0);
		return ndep + 1;
	}
}

void run() {
	scanf("%d%d", &n, &na);
	par[0] = -1; FOR(i, 1, n) scanf("%d", &par[i]), --par[i];
	printf("%d\n", solve());
	printf("%s\n", ans);
}

int main() {
	run();
	return 0;
}