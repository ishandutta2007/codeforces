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

const int MAXN = 50;
const int MAXWAVE = MAXN - 1;

int n, m, nwave;
vector<int> out[MAXN];
int wavegain[MAXWAVE], wavecost[MAXWAVE];
vector<int> ans;

MaxFlow mf;

ll dp[MAXWAVE + 1][MAXN + 1];
int act[MAXWAVE + 1][MAXN + 1];
int kill[MAXWAVE];

void solve() {
	int sid = 2 * n, tid = 2 * n + 1;
	mf.init(2 * n + 2);
	REP(i, n) mf.addedge(sid, i, 1), mf.addedge(n + i, tid, 1);
	REP(i, n) for (int j : out[i]) mf.addedge(i, n + j, 1);
	int flow = mf.solve(sid, tid);
	int need = n - flow;
	//printf("need=%d\n", need);
	vector<int> cutout, cutin;
	REP(i, n) if (mf.d[i] == INT_MAX) cutout.PB(i);
	REP(i, n) if (mf.d[n + i] != INT_MAX) cutin.PB(i);
	//printf("cutout:"); for (int x : cutout) printf(" %d", x + 1); puts("");
	//printf("cutin:"); for (int x : cutin) printf(" %d", x + 1); puts("");

	auto relax = [&](int i, int j, ll val, int a) { if (val <= dp[i][j]) return; dp[i][j] = val; act[i][j] = a; };
	REPE(i, nwave) REPE(j, n) dp[i][j] = LLONG_MIN, act[i][j] = -2;
	relax(0, need, 0, -1);
	REP(i, nwave) REPE(j, n) {
		ll cur = dp[i][j];
		if (cur == LLONG_MIN) continue;
		//printf("dp[%d][%d]=%lld\n", i, j, cur);
		REPE(k, n - j) if (j + k > i + 1) relax(i + 1, j + k, cur + max(0LL, wavegain[i] - (ll)k * wavecost[i]), k);
	}
	int bestj = -1;
	REPE(j, n) if (dp[nwave][j] != LLONG_MIN && (bestj == -1 || dp[nwave][j] > dp[nwave][bestj])) bestj = j;
	//printf("bestj=%d best=%lld\n", bestj, dp[nwave][bestj]);
	{
		int i = nwave, j = bestj;
		while (act[i][j] >= 0) {
			kill[i - 1] = act[i][j];
			j -= act[i][j], --i;
		}
	}
	//printf("kill:"); REP(i, nwave) printf(" %d", kill[i]); puts("");
	vector<int> killopt;
	for (int x : cutout) killopt.PB(+(x + 1));
	for (int x : cutin) killopt.PB(-(x + 1));
	int at = 0;
	ans.clear();
	REP(i, nwave) {
		REP(j, kill[i]) { assert(at < SZ(killopt)); ans.PB(killopt[at++]); }
		ans.PB(0);
	}
}

void run() {
	scanf("%d%d%d", &n, &m, &nwave);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; out[a].PB(b); }
	REP(i, nwave) scanf("%d%d", &wavegain[i], &wavecost[i]);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}