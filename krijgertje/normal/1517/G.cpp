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
	int addedge(int a, int b, ll cap) { /*printf("addedge(%d,%d,%lld)\n", a, b, cap);*/ return addedgewithflow(a, b, cap, 0); }
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

const int MAXN = 1000;
struct P { int x, y, w; };

int n;
P p[MAXN];

int col[MAXN];

MaxFlow g;

ll solve() {
	REP(i, n) { int a = (p[i].x % 2 + 2) % 2, b = (p[i].y % 2 + 2) % 2; col[i] = 2 * b + (b == 0 ? 1 - a : a); }

	int nid = 0;
	int sid = nid++, tid = nid++;
	vector<int> lid(n), rid(n);
	REP(i, n) lid[i] = nid++, rid[i] = nid++;
	g.init(nid);
	REP(i, n) if (col[i] == 0) g.addedge(sid, lid[i], LLONG_MAX);
	REP(i, n) REP(j, n) if (col[j] == col[i] + 1 && abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y) == 1) g.addedge(rid[i], lid[j], LLONG_MAX);
	REP(i, n) if (col[i] == 3) g.addedge(rid[i], tid, LLONG_MAX);
	REP(i, n) g.addedge(lid[i], rid[i], p[i].w);

	ll flow = g.solve(sid, tid);
	//printf("flow=%lld\n", flow);
	ll ret = 0; REP(i, n) ret += p[i].w; ret -= flow; return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].w);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}