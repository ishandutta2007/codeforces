#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 10000;

struct T {
	int n;
	vector<int> adj[MAXN];

	bool alive[MAXN]; int nalive;
	int deg[MAXN];
	int afst[MAXN], alst[MAXN], anxt[MAXN], aprv[MAXN]; // doubly-linked lists for leaves adjacent to a node
	int bfst, blst, bnxt[MAXN], bprv[MAXN]; // doubly-linked lists for nodes adjacent to at least one leaf
	priority_queue<pair<int, int> > pq;

	void init() {
		nalive = n; REP(i, n) alive[i] = true, deg[i] = SZ(adj[i]), afst[i] = alst[i] = -1; bfst = blst = -1;
		REP(at, n) if (deg[at] == 1) aappend(at, adj[at][0]);
		REP(at, n) if (afst[at] != -1) bappend(at);
		pq = priority_queue<pair<int, int> >(); REP(i, n) pq.push(MP(deg[i], i));
	}
	void killleaf(int at) {
		assert(deg[at] == 1); alive[at] = false; --nalive;
		int to = -1; REPSZ(i, adj[at]) if (alive[adj[at][i]]) { assert(to == -1); to = adj[at][i]; } assert(to != -1);
		--deg[at]; if (deg[at] == 0) { aremove(at, to); if (afst[to] == -1) bremove(to); }
		--deg[to]; pq.push(MP(deg[to], to)); if (deg[to] == 0) { aremove(to, at); if (afst[at] == -1) bremove(at); }
		if (deg[to] == 1) {
			int oth = -1; REPSZ(i, adj[to]) if (alive[adj[to][i]]) { assert(oth == -1); oth = adj[to][i]; } assert(oth != -1);
			aappend(to, oth);
			if (afst[oth] == to&&anxt[to] == -1) bappend(oth);
		}
	}
	void aappend(int at, int to) {
		aprv[at] = alst[to], anxt[at] = -1; if (aprv[at] == -1) afst[to] = at; else anxt[aprv[at]] = at; alst[to] = at;
	}
	void aremove(int at, int to) {
		if (aprv[at] == -1) afst[to] = anxt[at]; else anxt[aprv[at]] = anxt[at];
		if (anxt[at] == -1) alst[to] = aprv[at]; else aprv[anxt[at]] = aprv[at];
	}
	void bappend(int at) {
		bprv[at] = blst, bnxt[at] = -1; if (bprv[at] == -1) bfst = at; else bnxt[bprv[at]] = at; blst = at;
	}
	void bremove(int at) {
		if (bprv[at] == -1) bfst = bnxt[at]; else bnxt[bprv[at]] = bnxt[at];
		if (bnxt[at] == -1) blst = bprv[at]; else bprv[bnxt[at]] = bprv[at];
	}
	bool getleavesatleastthreeapart(pair<int,int> &u, pair<int,int> &v) {
		if (bfst == -1 || bnxt[bfst] == -1) return false;
		int x = bfst, y = bnxt[bfst], r = maxdeg().second; if (afst[r] != -1 && x != r) y = r;
		u = MP(afst[x], x), v = MP(afst[y], y); assert(u.first != -1 && v.first != -1); return true;
	}
	pair<int, int> maxdeg() { while (!pq.empty() && (!alive[pq.top().second] || deg[pq.top().second] != pq.top().first)) pq.pop(); return !pq.empty() ? pq.top() : MP(0, -1); }
	bool isstar() { return maxdeg().first == nalive - 1; }
	bool issemistar() { return maxdeg().first == nalive - 2; }
	bool ispath() { return maxdeg().first <= 2; }
	bool getsemistar1(vector<int> &rem) {
		if (!issemistar()) return false; assert(bfst != -1 && bnxt[bfst] != -1 && bnxt[bnxt[bfst]] == -1);
		int w = maxdeg().second; assert(bfst == w || bnxt[bfst] == w); int v = bfst + bnxt[bfst] - w; assert(afst[v] != -1 && anxt[afst[v]] == -1); int u = afst[v];
		rem.clear(); rem.PB(u); rem.PB(v); rem.PB(w); REP(i, n) if (alive[i] && i != u&&i != v&&i != w) rem.PB(i); return true;
	}
	bool getsemistar2(vector<int> &rem) {
		if (isstar()) return false; assert(bfst != -1 && bnxt[bfst] != -1); int u = bfst, w = afst[u], v = afst[bnxt[bfst]]; assert(w != -1 && u != -1);
		rem.clear(); rem.PB(u); rem.PB(v); rem.PB(w); REP(i, n) if (alive[i] && i != u&&i != v&&i != w) rem.PB(i); return true;
	}
	bool getpath1(vector<int> &rem) {
		if (!ispath()) return false;
		int at = -1; REP(i, n) if (alive[i] && deg[i] <= 1) { at = i; break; } assert(at != -1);
		rem.PB(at); while (true) { int to = -1; REPSZ(i, adj[at]) if (alive[adj[at][i]] && (SZ(rem) == 1 || adj[at][i] != rem[SZ(rem) - 2])) { assert(to == -1); to = adj[at][i]; } if (to == -1) break; at = to; rem.PB(at); } return SZ(rem) == 5;
	}
	bool getpath2(vector<int> &rem) {
		if (!getpath1(rem)) return false;
		swap(rem[0], rem[2]); swap(rem[0], rem[4]); swap(rem[0], rem[3]); swap(rem[0], rem[1]); return true;
	}
};

int n;
T a, b;
int mp[MAXN];
struct Op { pair<int, int> au, av, bu, bv; };
vector<Op> ops;


void run() {
	scanf("%d", &n);
	a.n = n; REP(i, n - 1) { int u, v; scanf("%d%d", &u, &v); --u, --v; a.adj[u].PB(v); a.adj[v].PB(u); } a.init();
	b.n = n; REP(i, n - 1) { int u, v; scanf("%d%d", &u, &v); --u, --v; u -= n; v -= n; b.adj[u].PB(v); b.adj[v].PB(u); } b.init();

	if (a.isstar() || b.isstar()) { printf("No\n"); return; }
	REP(i, n) mp[i] = -1; ops.clear();
	while (true) {
		//printf("maxdeg: (%d,%d) (%d,%d)\n", a.maxdeg().first, a.maxdeg().second + 1, b.maxdeg().first, b.maxdeg().second + 1 + n);
		if (a.issemistar()) {
			//printf("a semistar\n");
			vector<int> arem; assert(a.getsemistar1(arem));
			vector<int> brem; assert(b.getsemistar2(brem));
			assert(a.nalive == b.nalive&&SZ(arem) == a.nalive&&SZ(brem) == b.nalive);
			REPSZ(i, arem) mp[arem[i]] = brem[i];
			break;
		}
		if (b.issemistar()) {
			//printf("b semistar\n");
			vector<int> arem; assert(a.getsemistar2(arem));
			vector<int> brem; assert(b.getsemistar1(brem));
			assert(a.nalive == b.nalive&&SZ(arem) == a.nalive&&SZ(brem) == b.nalive);
			REPSZ(i, arem) mp[arem[i]] = brem[i];
			break;
		}
		if (a.nalive == 5 || b.nalive == 5) {
			assert(a.nalive == 5 && b.nalive == 5 && a.ispath() && b.ispath());
			//printf("5 path\n");
			vector<int> arem; assert(a.getpath1(arem));
			vector<int> brem; assert(b.getpath2(brem));
			assert(a.nalive == b.nalive&&SZ(arem) == a.nalive&&SZ(brem) == b.nalive);
			REPSZ(i, arem) mp[arem[i]] = brem[i];
			break;
		}
		assert(a.nalive >= 6 && b.nalive >= 6);
		//printf("general case: ");
		pair<int,int> au, av; assert(a.getleavesatleastthreeapart(au, av));
		pair<int,int> bu, bv; assert(b.getleavesatleastthreeapart(bu, bv));
		//printf("(%d,%d) and (%d,%d)\n", au.first + 1, av.first + 1, bu.first + n + 1, bv.first + n + 1);
		a.killleaf(au.first); a.killleaf(av.first);
		b.killleaf(bu.first); b.killleaf(bv.first);
		Op op; op.au = au, op.av = av, op.bu = bu, op.bv = bv; ops.PB(op);
	}
	for (int i = SZ(ops) - 1; i >= 0; --i) {
		pair<int, int> au = ops[i].au, av = ops[i].av, bu = ops[i].bu, bv = ops[i].bv;
		if (mp[au.second] != bu.second&&mp[av.second] != bv.second) { mp[au.first] = bu.first; mp[av.first] = bv.first; continue; }
		if (mp[au.second] != bv.second&&mp[av.second] != bu.second) { mp[au.first] = bv.first; mp[av.first] = bu.first; continue; }
		assert(false);
	}
	printf("Yes\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", mp[i] == -1 ? -1 : mp[i] + n + 1); } puts("");
}

int main() {
	run();
	return 0;
}