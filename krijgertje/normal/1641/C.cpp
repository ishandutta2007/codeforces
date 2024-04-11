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

const int MAXN = 200000;
const int MAXQ = 200000;
const int MAXS = 4 * MAXN;
struct Res { int tlast, wholast, tlast2; Res() { tlast = tlast2 = INT_MIN; wholast = -1; } };

int n, nq;
int qkind[MAXQ], ql[MAXQ], qr[MAXQ], qval[MAXQ], qidx[MAXQ];
int qans[MAXQ];

Res s[MAXS];

Res smerge(const Res &a, const Res &b) {
	Res ret;
	ret.tlast = max(a.tlast, b.tlast);
	ret.wholast = a.tlast == ret.tlast && a.wholast != -1 ? a.wholast : b.tlast == ret.tlast && b.wholast != -1 ? b.wholast : -1;
	ret.tlast2 = max(a.tlast > b.tlast ? a.tlast2 : a.tlast, b.tlast > a.tlast ? b.tlast2 : b.tlast);
	return ret;
}
void spull(int x) {
	s[x] = smerge(s[2 * x + 1], s[2 * x + 2]);
}
void sinit(int x, int l, int r) {
	if (l == r) {
		s[x].tlast = INT_MAX, s[x].tlast2 = INT_MIN, s[x].wholast = l;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int T) {
	if (s[x].tlast <= T) return;
	if (l == r) {
		s[x].tlast = T;
	} else {
		int m = l + (r - l) / 2;
		if (L <= m) smod(2 * x + 1, l, m, L, R, T);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, T);
		spull(x);
	}
}
Res sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return s[x];
	} else {
		int m = l + (r - l) / 2;
		Res ret;
		if (L <= m) ret = smerge(ret, sget(2 * x + 1, l, m, L, R));
		if (m + 1 <= R) ret = smerge(ret, sget(2 * x + 2, m + 1, r, L, R));
		return ret;
	}
}

void solve() {
	sinit(0, 0, n - 1);
	REP(i, nq) if (qkind[i] == 0 && qval[i] == 0) smod(0, 0, n - 1, ql[i], qr[i], i);
	vector<int> knowsick(n, INT_MAX);
	vector<int> knowhealthy(n, INT_MAX);
	REP(i, nq) if (qkind[i] == 0 && qval[i] == 1) {
		Res cur = sget(0, 0, n - 1, ql[i], qr[i]);
		//printf("q%d: %d %d %d\n", i, cur.tlast, cur.tlast2, cur.wholast + 1);
		assert(cur.tlast == INT_MAX);
		if (cur.tlast2 == INT_MAX) continue;
		knowsick[cur.wholast] = min(knowsick[cur.wholast], max(i, cur.tlast2));
	}
	REP(i, n) {
		Res cur = sget(0, 0, n - 1, i, i);
		if (cur.tlast == INT_MAX) continue;
		knowhealthy[cur.wholast] = cur.tlast;
	}
	//printf("knowsick:"); REP(i, n) printf(" %d", knowsick[i] != INT_MAX ? knowsick[i] : -1); puts("");
	//printf("knowhealthy:"); REP(i, n) printf(" %d", knowhealthy[i] != INT_MAX ? knowhealthy[i] : -1); puts("");
	REP(i, n) assert(knowhealthy[i] == INT_MAX || knowsick[i] == INT_MAX);
	REP(i, nq) if (qkind[i] == 1) {
		int who = qidx[i];
		qans[i] = -1;
		if (knowhealthy[who] != INT_MAX) qans[i] = knowhealthy[who] < i ? 0 : -1;
		if (knowsick[who] != INT_MAX) qans[i] = knowsick[who] < i ? 1 : -1;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 0) scanf("%d%d%d", &ql[i], &qr[i], &qval[i]), --ql[i], --qr[i];
		if (qkind[i] == 1) scanf("%d", &qidx[i]), --qidx[i];
	}
	solve();
	REP(i, nq) if (qkind[i] == 1) printf("%s\n", qans[i] == 0 ? "NO" : qans[i] == 1 ? "YES" : "N/A");
}

int main() {
	run();
	return 0;
}