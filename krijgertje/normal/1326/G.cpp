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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 100;
const int MOD = 998244353;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
ll operator^(const P& a, const P& b) { return (ll)a.x * b.y - (ll)a.y * b.x; }
int side(const P& a, const P& b, const P& c) { ll res = (b - a) ^ (c - a); return res < 0 ? -1 : res > 0 ? +1 : 0; }
bool operator<(const P& a, const P& b) {
	bool apos = a.y > 0 || a.y == 0 && a.x > 0, bpos = b.y > 0 || b.y == 0 && b.x > 0; if (apos != bpos) return apos;
	ll res = a ^ b; return res > 0;
}
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { if ((a -= b) < 0) a += MOD; }
void incprod(int& a, int b, int c) { a = (a + (ll)b * c) % MOD; }

int n;
P p[MAXN];
vector<int> adj[MAXN];

int par[MAXN];
vector<int> path[MAXN][MAXN];

void dfsinit(int at) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfsinit(to);
	}
}
void dfspath(int at,int prv,int root) {
	path[root][at] = prv == -1 ? vector<int>() : path[root][prv]; path[root][at].PB(at);
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == prv) continue;
		dfspath(to, at, root);
	}
}

int dp[MAXN];
int dpprod[MAXN];
int dpedge[MAXN][MAXN];
bool hasroot[MAXN][MAXN];

void ensuredpedge(int s, int t,int skip) {
	if (dpedge[s][t] != -1) return;
	//printf("ensuredpedge(%d,%d)\n", s + 1, t + 1);
	const vector<int>& curpath = path[s][t];
	REPSZ(i, curpath) {
		int at = curpath[i];
		if (at != s && at != t && side(p[s], p[t], p[at]) <= 0) return void(dpedge[s][t] = 0);
	}
	dpedge[s][t] = 1;
	REPSZ(i, curpath) {
		int at = curpath[i];
		REPSZ(j, adj[at]) {
			int to = adj[at][j]; if (to == skip) continue;
			if (i - 1 < 0) {
				if (side(p[at], p[curpath[i + 1]], p[to]) >= 0) continue;
			} else if (i + 1 >= SZ(curpath)) {
				if (side(p[curpath[i - 1]], p[at], p[to]) >= 0) continue;
			} else {
				int prv = curpath[i - 1], nxt = curpath[i + 1];
				if (side(p[prv], p[at], p[nxt]) <= 0 && (side(p[prv], p[at], p[to]) >= 0 || side(p[at], p[nxt], p[to]) >= 0)) continue;
				if (side(p[prv], p[at], p[nxt]) >= 0 && (side(p[prv], p[at], p[to]) >= 0 && side(p[at], p[nxt], p[to]) >= 0)) continue;
			}
			assert(dp[to] != -1);
			dpedge[s][t] = (ll)dpedge[s][t] * dp[to] % MOD;
		}
	}
	//printf("dpedge[%d][%d]=%d\n", s + 1, t + 1, dpedge[s][t]);
}

void dfsnodes(int at, vector<int>& nodes) {
	nodes.PB(at);
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		dfsnodes(to, nodes);
	}
}
void dfscalc(int at) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		dfscalc(to);
	}

	dpprod[at] = 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		dpprod[at] = (ll)dpprod[at] * dp[to] % MOD;
	}
	dp[at] = dpprod[at];
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		int cur = dpprod[to];
		REPSZ(j, adj[at]) if(j!=i) {
			int to2 = adj[at][j]; if (to2 == par[at]) continue;
			cur = (ll)cur * dp[to2] % MOD;
		}
		inc(dp[at], cur);
	}

	vector<int> nodes; // within subtree
	vector<pair<int, int>> leafedges; // (leaf,inner)
	vector<pair<int, int>> hulledges; // between two leafedges


	dfsnodes(at, nodes);
	REPSZ(i, nodes) {
		int to = nodes[i]; if (to == at) continue;
		leafedges.PB(MP(to, par[to]));
		if (par[to] == at) leafedges.PB(MP(par[to], to));
	}
	REPSZ(a, leafedges) REPSZ(b, leafedges) {
		int aa = leafedges[a].first, bb = leafedges[b].first;
		if (side(p[aa], p[bb], p[at]) < 0) continue;
		const vector<int>& curpath = path[aa][bb];
		if (SZ(curpath) < 3 || curpath[1] != leafedges[a].second || curpath[SZ(curpath) - 2] != leafedges[b].second) continue;
		ensuredpedge(aa, bb, par[at]);
		if (dpedge[aa][bb] != 0) {
			hulledges.PB(MP(a, b));
			hasroot[aa][bb] = false; REPSZ(i, curpath) if (curpath[i] == at) hasroot[aa][bb] = true;
		}
	}
	sort(hulledges.begin(), hulledges.end(), [&](const pair<int, int>& u, const pair<int, int>& v) {
		P udir = p[leafedges[u.second].first] - p[leafedges[u.first].first];
		P vdir = p[leafedges[v.second].first] - p[leafedges[v.first].first];
		return udir < vdir;
	});

	//printf("leafedges:"); REPSZ(i, leafedges) printf(" %d=(%d,%d)", i, leafedges[i].first + 1, leafedges[i].second + 1); puts("");
	//printf("hulledges:"); REPSZ(i, hulledges) printf(" (%d,%d)", hulledges[i].first, hulledges[i].second); puts("");
	REPSZ(i, leafedges) {
		REP(rep, 2) {
			vector<int> ways(SZ(leafedges), 0);
			inc(ways[i], 1);
			REPSZ(j, hulledges) {
				int a = hulledges[j].first, b = hulledges[j].second;
				int aa = leafedges[a].first, bb = leafedges[b].first;
				if (rep == 1 && hasroot[aa][bb]) continue;
				//if (at == 0 && i == 7 && rep == 0) printf("\t\twith (%d,%d) -> from ways[%d] to ways[%d] = %d*%d\n", a, b, a, b, ways[a], dpedge[aa][bb]);
				incprod(ways[b], ways[a], dpedge[aa][bb]);
			}
			dec(ways[i], 1);
			if (rep == 0) inc(dp[at], ways[i]); else dec(dp[at], ways[i]);
			//printf("\t%d: %d\n", i, ways[i]);
		}
	}
	//printf("dp[%d]=%d\n", at + 1, dp[at]);
}

int solve() {
	REP(i, n) dp[i] = -1;
	REP(i, n) REP(j, n) dpedge[i][j] = -1;

	par[0] = -1; dfsinit(0);
	REP(i, n) dfspath(i, -1, i);
	dfscalc(0);

	return dp[0];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
}

int solvestupid() {
	vector<bool> ok(1 << n, false);
	FOR(mask, 1, 1 << n) {
		vector<int> cur; REP(i, n) if (mask&(1 << i)) cur.PB(i);
		if (SZ(cur) == 1) { ok[mask] = true; continue; }
		sort(cur.begin(), cur.end(), [](const int &a, const int &b) { if (p[a].x != p[b].x) return p[a].x < p[b].x; return p[a].y < p[b].y; });
		vector<int> hull;
		REPSZ(i, cur) {
			while (SZ(hull) >= 2 && side(p[hull[SZ(hull) - 2]], p[hull[SZ(hull) - 1]], p[cur[i]]) < 0) hull.pop_back();
			hull.PB(cur[i]);
		}
		int fixed = SZ(hull);
		for (int i = SZ(cur) - 2; i >= 0; --i) {
			while (SZ(hull) >= fixed + 1 && side(p[hull[SZ(hull) - 2]], p[hull[SZ(hull) - 1]], p[cur[i]]) < 0) hull.pop_back();
			hull.PB(cur[i]);
		}
		hull.pop_back();
		//printf("%x: hull", mask); REPSZ(i, hull) printf(" %d", hull[i]); puts("");
		vector<int> deg(n, 0);
		queue<int> q; q.push(cur[0]);
		while (!q.empty()) { int at = q.front(); q.pop(); REPSZ(i, adj[at]) { int to = adj[at][i]; if (deg[to] != 0) continue; if ((mask&(1 << to)) == 0) continue; ++deg[at], ++deg[to], q.push(to); } }
		vector<bool> onhull(n, false); REPSZ(i, hull) onhull[hull[i]] = true;
		bool valid = true;
		REPSZ(i, cur) { 
			int at = cur[i]; 
			if (deg[at] == 0) valid = false; 
			if ((deg[at] == 1) != onhull[at]) valid = false;
		}
		ok[mask] = valid;
		//if (SZ(cur) >= 3 && valid) { printf("valid:"); REPSZ(i, cur) printf(" %d", cur[i] + 1); puts(""); }
		//printf("-> %s\n", valid ? "OK" : "ERR");
	}
	vector<int> ways(1 << n, 0); inc(ways[0], 1);
	FOR(mask, 1, 1 << n) {
		int fixed = 0; while ((mask&(1 << fixed)) == 0) ++fixed;
		for (int pmask = 0; pmask < mask; pmask = (pmask + (1 << n) - 1 - mask + 1)&mask) if ((pmask&(1 << fixed)) == 0 && ok[mask^pmask]) inc(ways[mask], ways[pmask]);
	}
	return ways[(1 << n) - 1];
}

void stress() {
	REP(rep, 100000) {
		n = rnd() % 15 + 1;
		REP(i, n) while (true) {
			p[i].x = rnd() % 100 + 1, p[i].y = rnd() % 100 + 1;
			bool ok = true;
			REP(j, i) if (p[j].x == p[i].x&&p[j].y == p[i].y) ok = false;
			REP(j, i) FOR(k, j + 1, i) if (side(p[j], p[k], p[i]) == 0) ok = false;
			if (ok) break;
		}
		vector<pair<int, int>> e;
		vector<int> col(n); REP(i, n) col[i] = i;
		REP(i, n - 1) while(true) {
			int a = rnd() % n, b = rnd() % n; if (col[a] == col[b]) continue;
			bool ok = true; REPSZ(j, e) { 
				P A = p[a], B = p[b], C = p[e[j].first], D = p[e[j].second];
				if (side(A, B, C)*side(A, B, D) == -1 && side(C, D, A)*side(C, D, B) == -1) ok = false;
			} if (!ok) continue;
			e.PB(MP(a, b)); int ocol = col[b]; REP(j, n) if (col[j] == ocol) col[j] = col[a]; break;
		}
		REP(i, n) adj[i].clear(); REPSZ(i, e) { int a = e[i].first, b = e[i].second; adj[a].PB(b), adj[b].PB(a); }
		int have = solve();
		int want = solvestupid();
		if (have == want) { if ((rep + 1) % 1000 == 0) printf("."); continue; }
		printf("have=%d want=%d\n", have, want);
		printf("%d\n", n);
		REP(i, n) printf("%d %d\n", p[i].x, p[i].y);
		REPSZ(i, e) printf("%d %d\n", e[i].first + 1, e[i].second + 1);
		break;
	}
}

int main() {
	run();
	//solvestupid();
	//stress();
	return 0;
}