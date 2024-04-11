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

struct MaxFlow {
	int n;
	vector<int> ghead, gnxt, gto; vector<ll> gcap;
	vector<int> d; queue<int> q; vector<int> cur;

	void init(int _n) { n = _n; ghead = vector<int>(n, -1); gnxt = gto = vector<int>(); gcap = vector<ll>(); }
	int addedgewithflow(int a, int b, ll cap, ll flow) {
		gnxt.PB(ghead[a]); ghead[a] = SZ(gnxt) - 1; gto.PB(b); gcap.PB(cap - flow);
		gnxt.PB(ghead[b]); ghead[b] = SZ(gnxt) - 1; gto.PB(a); gcap.PB(flow);
		return SZ(gnxt) - 2;
	}
	int addedge(int a, int b, ll cap) { return addedgewithflow(a, b, cap, 0); }
	ll dfs(int at, int t, ll rem) {
		ll ret = 0;
		if (at == t) return rem;
		if (d[at] >= d[t]) return 0;
		for (; cur[at] != -1; cur[at] = gnxt[cur[at]]) {
			int to = gto[cur[at]]; ll cap = gcap[cur[at]];
			if (d[to] != d[at] + 1 || cap == 0) continue;
			ll now = dfs(to, t, min(cap, rem));
			rem -= now; ret += now;
			if (gcap[cur[at]] != LLONG_MAX) gcap[cur[at]] -= now;
			if (gcap[cur[at] ^ 1] != LLONG_MAX) gcap[cur[at] ^ 1] += now;
			if (rem == 0) return ret;
		}
		return ret;
	}
	ll solve(int s, int t) {
		ll ret = 0;
		while (true) {
			d = vector<int>(n, INT_MAX); q = queue<int>();
			d[s] = 0, q.push(s);
			while (!q.empty() && d[t] == INT_MAX) {
				int at = q.front(); q.pop();
				for (int x = ghead[at]; x != -1; x = gnxt[x]) {
					int to = gto[x];
					if (gcap[x] == 0 || d[to] != INT_MAX) continue;
					d[to] = d[at] + 1, q.push(to);
				}
			}
			if (d[t] == INT_MAX) return ret;
			cur = ghead;
			ret += dfs(s, t, LLONG_MAX);
		}
	}
	ll getflow(int x) { return gcap[x ^ 1]; }
};

struct FlowWithEdgeDemands {
	struct E { int a, b; ll lo, hi; E() {} E(int a, int b, ll lo, ll hi) :a(a), b(b), lo(lo), hi(hi) {} };

	int n;
	vector<E> e;
	MaxFlow feasible;

	void init(int _n) { n = _n; e = vector<E>(); }
	int addedge(int a, int b, ll lo, ll hi) { e.PB(E(a, b, lo, hi)); return SZ(e) - 1; }
	pair<bool, ll> solve(int s, int t) {
		vector<ll> excess(n, 0);
		REPSZ(i, e) excess[e[i].a] += e[i].lo, excess[e[i].b] -= e[i].lo;
		ll sumexcess = 0; REP(i, n) if (excess[i] > 0) sumexcess += excess[i];

		int ss = n, tt = n + 1;
		feasible.init(n + 2);
		REPSZ(i, e) feasible.addedge(e[i].a, e[i].b, e[i].hi - e[i].lo);
		feasible.addedge(t, s, sumexcess);
		REP(i, n) if (excess[i] < 0) feasible.addedge(ss, i, -excess[i]); else if (excess[i] > 0) feasible.addedge(i, tt, +excess[i]);
		if (feasible.solve(ss, tt) != sumexcess) return MP(false, LLONG_MIN);
		ll feasibleflow = feasible.getflow(2 * SZ(e));
		return MP(true, feasibleflow);
	}
	ll getflow(int x) { return e[x].lo + feasible.getflow(2 * x); }
};

const int MAXN = 10000;
const int MAXM = 10000;

int n, m;
int hasvalue[MAXN];
int value[MAXN];
int e[MAXM][2];
int flip[MAXM];

FlowWithEdgeDemands flow;
vector<int> adj[MAXN];

bool solve() {
	int s = n, t = n + 1;
	flow.init(n + 2);
	REP(i, m) flow.addedge(e[i][0], e[i][1], -1, +1);
	REP(i, n) {
		if (!hasvalue[i]) {
			flow.addedge(s, i, 0, m);
			flow.addedge(i, t, 0, m);
		} else {
			if (value[i] < 0) flow.addedge(s, i, -value[i], -value[i]);
			if (value[i] > 0) flow.addedge(i, t, +value[i], +value[i]);
		}
	}
	if (!flow.solve(s, t).first) return false;

	REP(i, m) {
		flip[i] = -1;
		int v = flow.getflow(i);
		assert(-1 <= v && v <= +1);
		if (v == -1) flip[i] = 1;
		if (v == +1) flip[i] = 0;
	}

	REP(i, m) { int a = e[i][0], b = e[i][1]; adj[a].PB(i); adj[b].PB(i); }
	REP(at, n) if (hasvalue[at]) {
		int cnt = 0;
		for (int id : adj[at]) {
			if (flip[id] == -1) ++cnt;
		}
		if (cnt % 2 != 0) return false;
	}
	REP(rep, 2) REP(i, n) {
		if (rep == 0 && hasvalue[i]) continue;
		int at = i;
		while (SZ(adj[at]) != 0) {
			int id = adj[at].back();
			adj[at].pop_back();
			if (flip[id] != -1) continue;
			int to = e[id][0] ^ e[id][1] ^ at;
			flip[id] = e[id][0] == at ? 0 : 1;
			at = to;
		}
		assert(!hasvalue[at] || at == i);
	}

	//printf("flip:"); REP(i, m) if (flip[i] == -1) printf(" ?"); else printf(" %d", flip[i]); puts("");
	return true;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, n) scanf("%d", &hasvalue[i]);
	REP(i, n) scanf("%d", &value[i]);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, m) { REP(j, 2) { if (j != 0) printf(" "); printf("%d", e[i][j ^ flip[i]] + 1); } puts(""); }
}

int main() {
	run();
	return 0;
}