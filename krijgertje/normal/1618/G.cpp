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

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }
};

const int MAXN = 200000;
const int MAXQ = 200000;

int na, nb, nq;
int a[MAXN];
int b[MAXN];
int q[MAXQ];
ll qans[MAXQ];

pair<int, int> c[2 * MAXN]; int nc;
ll csum[2 * MAXN + 1];
int qord[MAXQ];

int best[2 * MAXN];
int cnt[2 * MAXN];
UF uf;


ll calc(int idx) {
	return csum[best[idx] + 1] - csum[best[idx] + 1 - cnt[idx]];
}

void solve() {
	nc = 0;
	REP(i, na) c[nc++] = MP(a[i], 1);
	REP(i, nb) c[nc++] = MP(b[i], 0);
	sort(c, c + nc);
	csum[0] = 0; REP(i, nc) csum[i + 1] = csum[i] + c[i].first;
	
	vector<pair<int, int>> e;
	REP(i, nc - 1) e.PB(MP(c[i + 1].first - c[i].first, i));
	sort(e.begin(), e.end());
	int eat = 0;

	uf.init(nc);
	REP(i, nc) best[i] = i, cnt[i] = c[i].second;
	ll curans = 0;
	REP(i, nc) curans += calc(i);

	REP(i, nq) qord[i] = i;
	sort(qord, qord + nq, [&](int i, int j) { return q[i] < q[j]; });
	REP(i, nq) {
		int qid = qord[i];
		while (eat < SZ(e) && e[eat].first <= q[qid]) {
			int idx = e[eat++].second;
			int a = uf.find(idx), b = uf.find(idx+1);
			if (uf.unite(a, b)) {
				curans -= calc(a);
				curans -= calc(b);
				int c = uf.find(a);
				best[c] = best[b];
				cnt[c] = cnt[a] + cnt[b];
				curans += calc(c);
			}
		}
		qans[qid] = curans;
	}
}

void run() {
	scanf("%d%d%d", &na, &nb, &nq);
	REP(i, na) scanf("%d", &a[i]);
	REP(i, nb) scanf("%d", &b[i]);
	REP(i, nq) scanf("%d", &q[i]);
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}