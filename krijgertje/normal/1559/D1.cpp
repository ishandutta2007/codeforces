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

const int MAXN = 100000;

int n, ma, mb;
vector<int> aadj[MAXN];
vector<int> badj[MAXN];
vector<pair<int, int>> ans;

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }
};


void solve() {
	ans.clear();

	UF ufa; ufa.init(n);
	UF ufb; ufb.init(n);
	REP(at, n) for (int to : aadj[at]) if (at < to) assert(ufa.unite(at, to));
	REP(at, n) for (int to : badj[at]) if (at < to) assert(ufb.unite(at, to));

	FOR(at, 1, n) {
		if (ufa.find(at) == ufa.find(0)) continue;

		bool found = false;
		REP(to, at) {
			if (ufb.find(to) == ufb.find(at)) continue;
			found = true;
			ans.PB(MP(at, to));
			assert(ufa.unite(at, to));
			assert(ufb.unite(at, to));
			break;
		}
		if (found) continue;

		swap(ufa, ufb);
	}
}

void run() {
	scanf("%d%d%d", &n, &ma, &mb);
	REP(i, ma) { int a, b; scanf("%d%d", &a, &b); --a, --b; aadj[a].PB(b), aadj[b].PB(a); }
	REP(i, mb) { int a, b; scanf("%d%d", &a, &b); --a, --b; badj[a].PB(b), badj[b].PB(a); }
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	run();
	return 0;
}