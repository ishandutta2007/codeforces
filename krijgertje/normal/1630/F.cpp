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
	int addedge(int a, int b, ll cap) { /*printf("adding (%d,%d)\n", a, b);*/ return addedgewithflow(a, b, cap, 0); }
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

const int MAXN = 50000;
const int MAXVAL = 50000;

int n;
int a[MAXN];


int solve() {
	MaxFlow g;
	g.init(4 * n + 2);
	int s = 4 * n, t = 4 * n + 1;
	REP(i, 2 * n) g.addedge(s, i, 1);
	REP(i, 2 * n) g.addedge(2 * n + i, t, 1);
	REP(i, n) g.addedge(i, 3 * n + i, 1);
	int lg = 1; while ((1 << lg) < n) ++lg;
	if ((ll)n * n <= (ll)MAXVAL * lg * lg) {
		REP(i, n) REP(j, n) if (a[j] < a[i] && a[i] % a[j] == 0) {
			g.addedge(0 + j, 2 * n + i, 1);
			g.addedge(n + j, 3 * n + i, 1);
		}
	} else {
		map<int, int> mp;
		REP(i, n) mp[a[i]] = i;
		REP(i, n) {
			int x = a[i];
			for (int y = 2 * x; y <= MAXVAL; y += x) {
				auto it = mp.find(y);
				if (it == mp.end()) continue;
				int j = it->second;
				g.addedge(0 + j, 2 * n + i, 1);
				g.addedge(n + j, 3 * n + i, 1);
			}
		}
	}
	int flow = g.solve(s, t);
	//printf("flow=%d\n", flow);
	int chains = 2 * n - flow;
	return n - chains;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

void stresstime1() {
	n = MAXN;
	REP(i, n) a[i] = 1 + i;
	printf("%d\n", solve());
}

void stresstime2() {
	n = 5;
	int nrep = MAXN / n;
	REP(rep, nrep) {
		REP(i, n) a[i] = 1 + i;
		solve();
	}
	printf("done\n");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stresstime1();
	//stresstime2();
	return 0;
}