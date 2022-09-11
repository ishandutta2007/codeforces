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
	vector<int> findpath(int s, int t) {
		if (s == t) return vector<int>();
		vector<int> back(n, -2);
		queue<int> q;
		back[s] = -1, q.push(s);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			if (at == t) break;
			for (int x = ghead[at]; x != -1; x = gnxt[x]) {
				if (gcap[x ^ 1] == 0 || back[gto[x]] != -2) continue;
				back[gto[x]] = x ^ 1, q.push(gto[x]);
			}
		}
		assert(back[t] != -2);
		vector<int> ret;
		for (int x = back[t]; x != -1; x = back[gto[x]]) ret.PB(x ^ 1);
		reverse(ret.begin(), ret.end());
		for (int x : ret) { ++gcap[x], --gcap[x ^ 1]; }
		return ret;
	}
	ll removeedge(int s, int t, int x) {
		//printf("removing flow %d--->%d->%d--->%d (%lld)\n", s, gto[x ^ 1], gto[x], t, gcap[x ^ 1]);
		ll ret = gcap[x ^ 1]; gcap[x] = gcap[x ^ 1] = 0;
		assert(ret <= 1);
		REP(i, ret) {
			findpath(s, gto[x ^ 1]);
			findpath(gto[x], t);
		}
		return ret;
	}
};

const int MAXN = 200;
const int DX[] = { -1,0,+1,0 }, DY[] = { 0,+1,0,-1 };

int n;
vector<vector<int>> a;

vector<int> v;

MaxFlow mf;


ll solve() {
	v.clear();
	REP(i, n) REP(j, n) if (a[i][j] == 0) a[i][j] = -2;
	REP(i, n) REP(j, n) if (a[i][j] >= 0) v.PB(a[i][j]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	REP(i, n) REP(j, n) if (a[i][j] >= 0) a[i][j] = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
	//REP(i, n) { printf("a:"); REP(j, n) printf(" %2d", a[i][j]); puts(""); }

	int nid = 0;
	int sid = nid++, tid = nid++;
	vector<vector<int>> id(n, vector<int>(n, -1));
	REP(x, n) REP(y, n) if (a[x][y] != -1) id[x][y] = nid++;
	vector<vector<int>> who(SZ(v)); REP(x, n) REP(y, n) if (a[x][y] >= 0) who[a[x][y]].PB(id[x][y]);

	ll ret = 0;
	mf.init(nid);
	REP(x, n) REP(y, n) REP(k, 2) if(a[x][y]!=-1) {
		int nx = x + DX[k], ny = y + DY[k];
		if (nx < 0 || ny >= n || ny < 0 || ny >= n || a[nx][ny] == -1) continue;
		if ((x == 0 || x == n - 1 || y == 0 || y == n - 1) && (nx == 0 || nx == n - 1 || ny == 0 || ny == n - 1)) {
			ret += abs(v[a[x][y]] - v[a[nx][ny]]);
		} else {
			mf.addedgewithflow(id[x][y], id[nx][ny], 2, 1);
		}
	}
	vector<int> edge(nid, -1);
	REP(x, n) REP(y, n) if (a[x][y] >= 0) edge[id[x][y]] = mf.addedge(id[x][y], tid, 1);
	int flow = 0;
	REP(i, SZ(v) - 1) {
		REPSZ(j, who[i]) {
			int at = who[i][j];
			assert(edge[at] != -1);
			flow -= mf.removeedge(sid, tid, edge[at]);
			mf.addedge(sid, at, 1);
			edge[at] = -1;
		}
		flow += mf.solve(sid, tid);
		//printf("between %d and %d: %d\n", i, i + 1, flow);
		ret += (ll)flow * (v[i + 1] - v[i]);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	a = vector<vector<int>>(n, vector<int>(n));
	REP(i, n) REP(j, n) scanf("%d", &a[i][j]);
	printf("%lld\n", solve());
}

void stresstime() {
	int mxn = 10;
	REP(rep, 10) {
		n = MAXN;
		a = vector<vector<int>>(n, vector<int>(n, 0));
		int freq = rnd() % 40 + 1;
		REP(i, n) REP(j, n) {
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1) a[i][j] = rnd() % 1000 + 1;
			else if (rnd() % freq == 0) a[i][j] = -1;
		}
		//printf("%d\n", n); REP(i, n) { REP(j, n) { if (j != 0) printf(" "); printf("%d", a[i][j]); } puts(""); }
		solve();
		printf(".");
	}
}

int main() {
	//stresstime();
	run();
	return 0;
}