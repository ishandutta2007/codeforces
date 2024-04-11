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

const int DX[] = { -1,0,+1,0 }, DY[] = { 0,+1,0,-1 }; const char DC[] = { 'U','R','D','L' };

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

struct MaxFlowWithEdgeDemands {
	struct E { int a, b; ll lo, hi; E() {} E(int a, int b, ll lo, ll hi) :a(a), b(b), lo(lo), hi(hi) {} };

	int n;
	vector<E> e;
	MaxFlow feasible;
	MaxFlow maximal;

	void init(int _n) { n = _n; e = vector<E>(); }
	int addedge(int a, int b, ll lo, ll hi) { e.PB(E(a, b, lo, hi)); return SZ(e) - 1; }
	pair<bool,ll> solve(int s, int t) {
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

		maximal.init(n);
		REPSZ(i, e) {
			ll cur = feasible.getflow(2 * i);
			maximal.addedgewithflow(e[i].a, e[i].b, e[i].hi - e[i].lo, cur);
		}
		ll maximalflow = 0; // maximal.solve(s, t);
		return MP(true, feasibleflow + maximalflow);
	}
	ll getflow(int x) { return e[x].lo + maximal.getflow(2 * x); }
};

int h, w;
vector<vector<int>> sumreach;
vector<vector<int>> ansval;
vector<string> ansdir;

MaxFlowWithEdgeDemands g;

bool solve() {
	int sid = h * w, tid = h * w + 1;
	g.init(h * w + 2);
	vector<pair<int, pair<pair<int, int>, int>>> opt;
	REP(x, h) REP(y, w) {
		bool loweradj = false;
		REP(k, 4) {
			int nx = x + DX[k], ny = y + DY[k];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (sumreach[nx][ny] < sumreach[x][y]) loweradj = true;
		}
		int id = x * w + y;
		if ((x + y) % 2 == 0) {
			g.addedge(sid, id, loweradj ? 0 : 1, 1);
		} else {
			g.addedge(id, tid, loweradj ? 0 : 1, 1);
		}
	}
	REP(x, h) REP(y, w) if ((x + y) % 2 == 0) REP(k, 4) {
		int nx = x + DX[k], ny = y + DY[k];
		if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
		if (sumreach[x][y] == sumreach[nx][ny]) {
			int idx = g.addedge(x * w + y, nx * w + ny, 0, 1);
			opt.PB(MP(idx, MP(MP(x, y), k)));
		}
	}
	if (!g.solve(sid, tid).first) return false;
	ansval = vector<vector<int>>(h, vector<int>(w, 0));
	ansdir = vector<string>(h, string(w, '?'));
	REPSZ(i, opt) {
		int idx = opt[i].first, x = opt[i].second.first.first, y = opt[i].second.first.second, k = opt[i].second.second, nx = x + DX[k], ny = y + DY[k];
		ll cur = g.getflow(idx);
		if (cur == 0) continue;
		assert(cur == 1);
		assert(ansdir[x][y] == '?' && ansdir[nx][ny] == '?');
		assert(sumreach[x][y] == sumreach[nx][ny]);
		ansdir[x][y] = DC[k], ansdir[nx][ny] = DC[k ^ 2];
		ansval[x][y] = 1, ansval[nx][ny] = sumreach[x][y] - 1;
	}
	REP(x, h) REP(y, w) if (ansdir[x][y] == '?') {
		bool found = false;
		REP(k, 4) {
			int nx = x + DX[k], ny = y + DY[k];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (sumreach[nx][ny] < sumreach[x][y]) {
				ansdir[x][y] = DC[k], ansval[x][y] = sumreach[x][y] - sumreach[nx][ny];
				found = true; break;
			}
		}
		assert(found);
	}
	return true;
}


void run() {
	scanf("%d%d", &h, &w);
	sumreach = vector<vector<int>>(h, vector<int>(w)); REP(x, h) REP(y, w) scanf("%d", &sumreach[x][y]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(x, h) { REP(y, w) { if (y != 0) printf(" "); printf("%d", ansval[x][y]); } puts(""); }
	REP(x, h) { REP(y, w) { if (y != 0) printf(" "); printf("%c", ansdir[x][y]); } puts(""); }
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}