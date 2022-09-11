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

const int MAXN = 20000;
const int MAXLG = 16;
const int MAXQ = 20000;
const int MAXKILL = 30;

int n, nq;
int a[MAXN];
int ql[MAXQ], qr[MAXQ], qkill[MAXQ];
int qans[MAXQ];

pair<int, int> jump[MAXN][MAXLG + 1][MAXKILL + 1]; // (upto,best-in-range)

struct RMQ {
	int lg[MAXN + 1];
	int val[MAXN][MAXLG + 1];
	void init() {
		lg[1] = 0; FORE(i, 2, n) lg[i] = lg[i >> 1] + 1;
		REP(i, n) val[i][0] = i;
		REP(k, MAXLG) REPE(i, n - (2 << k)) { int x = val[i][k], y = val[i + (1 << k)][k]; val[i][k + 1] = x + a[x] >= y + a[y] ? x : y; }
	}
	int get(int l, int r) { int k = lg[r - l + 1]; int x = val[l][k], y = val[r - (1 << k) + 1][k]; return x + a[x] >= y + a[y] ? x : y; }
};

RMQ rmq;

void solve() {
	rmq.init();
	REP(i, n) REPE(k, MAXLG) REPE(x, MAXKILL) jump[i][k][x] = MP(i, i);
	REP(i, n) REPE(x, MAXKILL) {
		int upto = min(n - 1, i + a[i] + x);
		jump[i][0][x] = MP(upto, rmq.get(i, upto));
	}
	REP(k, MAXLG) REP(i, n) REPE(x, MAXKILL) { int at = jump[i][k][x].second; REPE(y, MAXKILL - x) if (jump[at][k][y].first > jump[i][k + 1][x + y].first) jump[i][k + 1][x + y] = jump[at][k][y]; }
	//REP(i, n) REPE(k, 4) REPE(x, 1) printf("jump[%d][%d][%d]=(%d,%d)\n", i, k, x, jump[i][k][x].first, jump[i][k][x].second);

	REP(i, nq) {
		qans[i] = 0;
		if (ql[i] == qr[i]) continue;
		vector<int> best(qkill[i] + 1, ql[i]);
		for (int k = MAXLG; k >= 0; --k) {
			//printf("best%d", k); REPSZ(x, best) printf(" %d", best[x]); puts("");
			bool ok = false;
			REPE(x, qkill[i]) if (best[x] != -1 && jump[best[x]][k][qkill[i] - x].first >= qr[i]) ok = true;
			if (ok) continue;
			qans[i] += 1 << k;
			for (int x = qkill[i]; x >= 0; --x) {
				int at = best[x];
				best[x] = -1;
				if (at != -1) REPE(y, qkill[i] - x) { pair<int, int> cur = jump[at][k][y]; if (best[x + y] == -1 || cur.second + a[cur.second] > best[x + y] + a[best[x + y]]) best[x + y] = cur.second; }
			}
		}
		++qans[i];
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d%d", &ql[i], &qr[i], &qkill[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int qansstupid[MAXQ];

void solvestupid() {
	REP(i, nq) {
		vector<vector<int>> dp(n, vector<int>(qkill[i] + 1, INT_MAX));
		queue<pair<int, int>> q;
		auto relax = [&](int at, int x, int steps) { assert(at >= 0 && at < n); assert(x >= 0 && x <= qkill[i]); if (dp[at][x] != INT_MAX) return; dp[at][x] = steps; q.push(MP(at, x)); };
		relax(ql[i], 0, 0);
		qansstupid[i] = INT_MAX;
		while (!q.empty()) {
			int at = q.front().first, x = q.front().second; q.pop();
			if (at == qr[i]) qansstupid[i] = min(qansstupid[i], dp[at][x]);
			int lim = min(at + a[at] + qkill[i] - x, qr[i]);
			FORE(to, at + 1, lim) {
				relax(to, x + max(0, to - at - a[at]), dp[at][x] + 1);
			}
		}
	}
}

void stress() {
	int mxn = 100, mxq = MAXQ;
	REP(rep, 100) {
		n = rnd() % mxn + 1, nq = mxq;
		REP(i, n) a[i] = rnd() % 6 + 1;
		REP(i, nq) {
			ql[i] = rnd() % n, qr[i] = rnd() % n, qkill[i] = rnd() % (MAXKILL + 1);
			if (ql[i] > qr[i]) swap(ql[i], qr[i]);
		}
		solve();
		solvestupid();
		bool ok = true;
		REP(i, nq) if (qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("%d 1\n", n); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts(""); REP(i, nq) if (qans[i] != qansstupid[i]) { printf("%d %d %d\n", ql[i] + 1, qr[i] + 1, qkill[i]); printf("have=%d want=%d\n", qans[i], qansstupid[i]); break; }
	}
}

int main() {
	run();
	//stress();
	return 0;
}