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

const int MAXN = 1000;
const int MAXM = 1000;

int n, m;
int a[MAXN];
int e[MAXM][2];
int ans[MAXN];

vector<int> v;
vector<int> out[MAXN];

int id[MAXN];

void rec(vector<int> who, int l, int r) {
	//printf("%d..%d: ", v[l], v[r]); for (int x : who) printf(" %d", x + 1); puts("");
	if (l == r) {
		for (int x : who) ans[x] = v[l];
		return;
	}
	int m = l + (r - l) / 2;
	int nid = 0;
	REPSZ(i, who) id[who[i]] = nid++;
	int sid = nid++;
	int tid = nid++;
	MaxFlow g;
	g.init(nid);
	for (int x : who) if (a[x] <= v[m]) g.addedge(id[x], tid, v[m + 1] - v[m]); else g.addedge(sid, id[x], v[m + 1] - v[m]);
	for (int x : who) for (int y : out[x]) if (id[y] != -1) g.addedge(id[x], id[y], LLONG_MAX);
	g.solve(sid, tid);
	vector<int> lwho, rwho;
	for (int x : who) if (g.d[id[x]] == INT_MAX) lwho.PB(x); else rwho.PB(x);
	REPSZ(i, who) id[who[i]] = -1;
	rec(lwho, l, m);
	rec(rwho, m + 1, r);
}

void solve() {
	v.clear();
	REP(i, n) v.PB(a[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	REP(i, n) out[i].clear();
	REP(i, m) out[e[i][0]].PB(e[i][1]);

	REP(i, n) id[i] = -1;
	REP(i, n) ans[i] = -1;
	vector<int> who;
	REP(i, n) who.PB(i);
	rec(who, 0, SZ(v) - 1);
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}