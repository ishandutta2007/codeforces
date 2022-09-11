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

const int MAXN = 50;
const int MAXM = 300;
const int MAXQ = 10000000;
struct E { int a, b, c, id; };

int n, m;
E e[MAXM];
int nq;
int q[MAXQ];
ll qans[MAXQ];

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }
};

void solve() {
	// better edge: first by lower abs(c-x), then by greater c, then by id
	vector<int> t;
	t.PB(0);
	REP(i, m) t.PB(e[i].c);
	REP(i, m) REP(j, m) if (e[i].c < e[j].c) { int d = e[j].c - e[i].c; t.PB(e[i].c + (d + 1) / 2); }
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	//printf("t:"); for (int x : t) printf(" %d", x); puts("");
	vector<pair<int, ll>> res(SZ(t));
	REPSZ(i, t) {
		int x = t[i];
		sort(e, e + m, [&](const E &u, const E &v) { int ucost = abs(u.c - x); int vcost = abs(v.c - x); if (ucost != vcost) return ucost < vcost; if (u.c != v.c) return u.c > v.c; return u.id < v.id; });
		UF uf;
		uf.init(n);
		int a = 0; ll b = 0;
		REP(j, m) {
			if (!uf.unite(e[j].a, e[j].b)) continue;
			//if (x == 0) printf("%d-%d %d\n", e[j].a + 1, e[j].b + 1, e[j].c);
			if (e[j].c <= x) {
				++a, b -= e[j].c;
			} else {
				--a, b += e[j].c;
			}
		}
		res[i] = MP(a, b);
	}
	//printf("res:"); for (auto z : res) printf(" (%d,%lld)", z.first, z.second); puts("");
	REP(i, nq) {
		int idx = upper_bound(t.begin(), t.end(), q[i]) - t.begin() - 1;
		qans[i] = (ll)res[idx].first * q[i] + res[idx].second;
	}
	//printf("q:"); REP(i, nq) printf(" %d", q[i]); puts("");
	//printf("qans:"); REP(i, nq) printf(" %lld", qans[i]); puts("");
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c), --e[i].a, --e[i].b, e[i].id = i;
	{ int nqgiven, a, b, c; scanf("%d%d%d%d%d", &nqgiven, &nq, &a, &b, &c); REP(i, nqgiven) scanf("%d", &q[i]); FOR(i, nqgiven, nq) q[i] = ((ll)q[i - 1] * a + b) % c; }
	solve();
	ll ans = 0; REP(i, nq) ans ^= qans[i]; printf("%lld\n", ans);
}

int main() {
	run();
	return 0;
}