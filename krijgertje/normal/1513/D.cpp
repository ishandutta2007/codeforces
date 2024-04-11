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

const int MAXN = 200000;

int n, stepcost;
int a[MAXN];

pair<int, int> o[MAXN];
bool done[MAXN];

ll solve() {
	REP(i, n) done[i] = false;
	REP(i, n) o[i] = MP(a[i], i);
	sort(o, o + n);
	int ncomp = n;
	ll ret = 0;
	REP(i, n) {
		int at = o[i].second;
		if (done[at] || a[at] > stepcost) continue;
		int l = at, r = at;
		while (!done[l] && l - 1 >= 0 && a[l - 1] % a[at] == 0) --l;
		while (!done[r] && r + 1 < n && a[r + 1] % a[at] == 0) ++r;
		//printf("at=%d: %d..%d = %d\n", at, l, r, a[at]);
		int len = r - l + 1;
		ncomp -= len - 1;
		ret += (ll)(len - 1) * a[at];
		FORE(j, l, r) done[j] = true;
	}
	ret += (ll)(ncomp - 1) * stepcost;
	return ret;
}

void run() {
	scanf("%d%d", &n, &stepcost);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

vector<int> par, sz;
int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
bool unite(int x, int y) { x = find(x); y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }
ll solvestupid() {
	vector<pair<int,pair<int, int>>> e;
	REP(i, n) FOR(j, i + 1, n) {
		if (i + 1 == j) e.PB(MP(stepcost, MP(i, j)));
		int mn = a[i]; FORE(k, i + 1, j) mn = min(mn, a[k]);
		int g = a[i]; FORE(k, i + 1, j) g = gcd(g, a[k]);
		if (mn == g) e.PB(MP(mn, MP(i, j)));
	}
	par = sz= vector<int>(n);
	REP(i, n) par[i] = i, sz[i] = 1;
	ll ret = 0;
	sort(e.begin(), e.end());
	REPSZ(i, e) {
		int c = e[i].first, a = e[i].second.first, b = e[i].second.second;
		if (unite(a, b)) ret += c;
	}
	return ret;
}

void stress() {
	int mxn = 7, mxval = 100;
	REP(rep, 100000) {
		n = rnd() % mxn + 1, stepcost = rnd() % mxval + 1;
		REP(i, n) a[i] = rnd() % mxval + 1;
		ll have = solve();
		ll want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("err have=%lld want=%lld\n", have, want);
		printf("%d %d\n", n, stepcost);
		REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
		break;
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}