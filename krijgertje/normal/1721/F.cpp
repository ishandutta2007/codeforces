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

	void findmincut(int s, int t) {
		solve(s, t);
		d = vector<int>(n, INT_MAX); q = queue<int>();
		d[s] = 0, q.push(s);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			for (int x = ghead[at]; x != -1; x = gnxt[x]) {
				int to = gto[x];
				if (gcap[x] == 0 || d[to] != INT_MAX) continue;
				d[to] = d[at] + 1, q.push(to);
			}
		}
	}

	
};


const int MAXN = 200000;
const int MAXM = 200000;

int na, nb, m, nq;
int e[MAXM][2];

MaxFlow mf;

void solve() {
	int sid = na + nb, tid = na + nb + 1;
	mf.init(2 + na + nb);
	REP(i, m) mf.addedge(e[i][0], na + e[i][1], 1);
	REP(i, na) mf.addedge(sid, i, 1);
	REP(i, nb) mf.addedge(na + i, tid, 1);
	mf.findmincut(sid, tid);
	vector<pair<int, int>> rem;
	REP(i, na) if (mf.d[i] == INT_MAX) {
		//printf("can remove left %d\n", i + 1);
		for (int x = mf.ghead[i]; x != -1; x = mf.gnxt[x]) {
			if (mf.gto[x] != sid && mf.gcap[x] == 0) {
				assert(x % 2 == 0);
				rem.PB(MP(i + 1, x / 2 + 1));
				//printf("-> %d\n", x / 2 + 1);
			}
		}
	}
	REP(i, nb) if (mf.d[na + i] != INT_MAX) {
		//printf("can remove right %d\n", i + 1);
		for (int x = mf.ghead[na + i]; x != -1; x = mf.gnxt[x]) {
			if (mf.gto[x] != tid && mf.gcap[x] == 1) {
				assert(x % 2 == 1);
				rem.PB(MP(-(i + 1), x / 2 + 1));
				//printf("-> %d\n", x / 2 + 1);
			}
		}
	}
	ll sum = 0;
	for (const auto& z : rem) sum += z.second;
	REP(i, nq) {
		int kind; scanf("%d", &kind);
		if (kind == 1) {
			const auto z = rem.back();
			rem.pop_back();
			sum -= z.second;
			printf("1\n%d\n%lld\n", z.first, sum);
			fflush(stdout);
		}
		if (kind == 2) {
			printf("%d\n", SZ(rem));
			REPSZ(j, rem) { if (j != 0) printf(" "); printf("%d", rem[j].second); } puts("");
			fflush(stdout);
		}
	}
}

void run() {
	scanf("%d%d%d%d", &na, &nb, &m, &nq);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	solve();
}

int main() {
	run();
	return 0;
}