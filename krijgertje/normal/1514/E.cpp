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

const int MAXN = 100;

int n;
vector<vector<int>> ans;

bool querydirection(int a, int b) {
	printf("1 %d %d\n", a, b); fflush(stdout);
	int ret; scanf("%d", &ret); if (ret == -1) exit(0); return ret == 1;
}
bool queryany(int a, vector<int> b) {
	printf("2 %d %d", a, SZ(b)); REPSZ(i, b) printf(" %d", b[i]); puts(""); fflush(stdout);
	int ret; scanf("%d", &ret); if (ret == -1) exit(0); return ret == 1;
}

vector<int> makepath(int l, int r) {
	if (l == r) return vector<int>{l};
	int m = l + (r - l) / 2;
	vector<int> a = makepath(l, m);
	vector<int> b = makepath(m + 1, r);
	vector<int> ret;
	int ai = 0, bi = 0;
	while (ai < SZ(a)) {
		if (!querydirection(a[ai], b[bi])) swap(a, b), swap(ai, bi);
		ret.PB(a[ai++]);
	}
	while (bi < SZ(b)) ret.PB(b[bi++]);
	return ret;
}

vector<vector<int>> calccomps(vector<int> path) {
	int at = SZ(path) - 1, to = at, first = SZ(path) - 1;
	vector<vector<int>> ret;
	while (at >= 0) {
		vector<int> before; REP(i, to) before.PB(path[i]);
		while (SZ(before) > 0 && queryany(path[at], before)) {
			--to;
			before.pop_back();
		}
		if (to == at) {
			vector<int> comp;
			FORE(i, at, first) comp.PB(path[i]);
			ret.PB(comp);
			to = first = at - 1;
		}
		--at;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

void solve() {
	vector<int> path = makepath(0, n - 1);
	//printf("path:"); REPSZ(i, path) printf(" %d", path[i]); puts("");

	auto comps = calccomps(path);
	//REPSZ(i, comps) { printf("comp%d:", i); for (int x : comps[i]) printf(" %d", x); puts(""); }

	ans = vector<vector<int>>(n, vector<int>(n));
	REPSZ(i, comps) for (int x : comps[i]) FORSZ(j, i, comps) for (int y : comps[j]) ans[x][y] = 1;
}

void run() {
	scanf("%d", &n);
	solve();
	printf("3\n");
	REP(i, n) { REP(j, n) printf("%d", ans[i][j]); puts(""); }
	fflush(stdout);
	int ret; scanf("%d", &ret); if (ret == -1) exit(0); assert(ret == 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}