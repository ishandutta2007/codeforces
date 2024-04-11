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

const int MAXN = 2000;

int n;
vector<int> adj[MAXN];
char res[100];

pair<int, int> query(vector<int> q) {
	printf("? %d", SZ(q)); REPSZ(i, q) printf(" %d", q[i] + 1); puts(""); fflush(stdout);
	int x, d; scanf("%d%d", &x, &d); if (x == -1 && d == -1) exit(0); --x; return MP(x, d);
}

int par[MAXN], dep[MAXN];
bool skip[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfsinit(to);
	}
}

pair<int, int> solve() {
	vector<int> all; REP(i, n) all.PB(i);
	int root, dist; tie(root, dist) = query(all);
	par[root] = -1; dfsinit(root);
	int mxdep = 0; REP(i, n) mxdep = max(mxdep, dep[i]);
	int lo = 1, hi = mxdep, a = root;
	while (lo <= hi) {
		int mi = lo + (hi - lo) / 2;
		vector<int> q; REP(i, n) if (dep[i] >= mi) q.PB(i);
		pair<int, int> res = query(q);
		if (res.second > dist) {
			hi = mi - 1;
		} else {
			a = res.first;
			lo = dep[a] + 1;
		}
	}

	REP(i, n) skip[i] = false;
	for (int x = a; x != root; x = par[x]) skip[x] = true;
	int want = dist - dep[a];
	vector<int> qlast; REP(i, n) if (!skip[i] && dep[i] == want) qlast.PB(i);
	pair<int, int> reslast = query(qlast);
	assert(reslast.second == dist);
	int b = reslast.first;
	return MP(a, b);
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	pair<int, int> ans = solve();
	REP(i, n) adj[i].clear();
	printf("! %d %d\n", ans.first + 1, ans.second + 1); fflush(stdout);
	scanf("%s", res); if (strcmp(res, "Correct") != 0) exit(0);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}