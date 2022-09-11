#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }


const int MAXSRCN = 100000;
const int MAXN = 2 * MAXSRCN - 4;
const int MAXM = MAXN - 1;
const int MAXDAY = 1000000;
struct E { int to, a, b; E() {} E(int to, int a, int b) :to(to), a(a), b(b) {} };

int srcn, nday;
int n, m;
E e[2 * MAXM];
vector<int> srcadj[MAXSRCN];
vector<int> adj[MAXN];
int src[MAXN];
ll ans[MAXDAY];

bool alive[MAXM];
int sz[MAXN];

void dfssz(int at, int par) {
	sz[at] = 1; REPSZ(i, adj[at]) { int x = adj[at][i], to = e[x].to; if (!alive[x >> 1] || to == par) continue; dfssz(to, at); sz[at] += sz[to]; }
}
int ecentroid(int rt) {
	dfssz(rt, -1);
	int at = rt, ret = -1;
	while (true) {
		bool found = false;
		REPSZ(i, adj[at]) { int x = adj[at][i], to = e[x].to; if (!alive[x >> 1] || (x >> 1) == ret) continue; if (sz[to] >= (sz[rt] + 2) / 3) { found = true; at = to; ret = x >> 1; break; } }
		if (!found) return ret;
	}
}

// a1*t+b1, a2*t+b2, a3*t+b3, a1<a2<a3, b1>b2>b3
// opt 2 better than 1 and 3: a1*t+b1>=a2*t+b2 -> (b1-b2)/(a2-a1)<t<(b2-b3)/(a3-a2) -> (a1-a2)*(b3-b2)>(b1-b2)*(a3-a2)

void mlt63(ull &a, ull &b) {
	ull ah = a >> 32, al = a & ((1ULL << 32) - 1), bh = b >> 32, bl = b & ((1ULL << 32) - 1);
	ll ch = ah*bh, cm = ah*bl + al*bh, cl = al*bl; 
	cm += cl >> 32; cl &= (1ULL << 32) - 1; ch = (ch << 1) + (cm >> 31); cm &= (1ULL << 31) - 1;
	a = ch, b = (cm << 32) + cl;
}

vector<pair<ll, ll>> loc[2];
vector<pair<ll, ll>> glob;
bool lefrac(ll num1, ll den1, ll num2, ll den2) {
	return num1*den2 <= num2*den1;
	ull a1 = num1, a2 = den2, b1 = num2, b2 = den1; mlt63(a1, a2); mlt63(b1, b2);
	return a1 < b1 || a1 == b1 && a2 <= b2;
}
void genloc(int id, int at, int par, ll a, ll b) {
	loc[id].PB(MP(a, b));
	REPSZ(i, adj[at]) { int x = adj[at][i], to = e[x].to; if (!alive[x >> 1] || to == par) continue; genloc(id, to, at, a + e[x].a, b + e[x].b); }
}
bool ok(const pair<ll, ll> &u, const pair<ll, ll> &v, const pair<ll, ll> &w) {
	ll da1 = v.first - u.first, db1 = u.second - v.second;
	ll da3 = w.first - v.first, db3 = v.second - w.second;
	return !lefrac(db3, da3, db1, da1);
}
void buildhull(vector<pair<ll,ll> > &p) {
	sort(p.begin(), p.end());
	{ int nsz = 0; REPSZ(i, p) { while (nsz > 0 && p[i].second >= p[nsz - 1].second) --nsz; p[nsz++] = p[i]; } p.resize(nsz); }
	{ int nsz = 0; REPSZ(i, p) { while (nsz >= 2 && !ok(p[nsz - 2], p[nsz - 1], p[i])) --nsz; p[nsz++] = p[i]; } p.resize(nsz); }
}
void printhull(vector<pair<ll, ll> > &p) {
	REPSZ(i, p) { if (i >= 1) printf(" %lf", 1.0*(p[i - 1].second - p[i].second) / (p[i].first - p[i - 1].first)); printf(" (%lld,%lld)", p[i].first, p[i].second); } puts("");
}

bool better(const pair<ll, ll> &u1, const pair<ll, ll> &u2, const pair<ll, ll> &v1, const pair<ll, ll> &v2) {
	ll uda = u2.first - u1.first, udb = u1.second - u2.second, vda = v2.first - v1.first, vdb = v1.second - v2.second;
	return lefrac(udb, uda, vdb, vda);
}
void decompose(int rt) {
	int cent = ecentroid(rt);
	if (cent == -1) return;
	int u = e[2 * cent + 1].to, v = e[2 * cent + 0].to, centa = e[2 * cent + 0].a, centb = e[2 * cent + 0].b;
	//printf("cent=%d-%d (%d,%d)\n", u + 1, v + 1, centa, centb);
	alive[cent] = false;

	loc[0].clear(); genloc(0, u, -1, 0, 0);
	loc[1].clear(); genloc(1, v, -1, 0, 0);
	REP(k, 2) buildhull(loc[k]);
	//REP(k, 2) { printf("loc%d:", k); printhull(loc[k]); }
	int i = 0, j = 0;
	while (true) {
		glob.PB(MP(centa + loc[0][i].first + loc[1][j].first, centb + loc[0][i].second + loc[1][j].second));
		if (i + 1 < SZ(loc[0]) && (j + 1 >= SZ(loc[1]) || better(loc[0][i], loc[0][i + 1], loc[1][j], loc[1][j + 1]))) ++i; else if (j + 1 < SZ(loc[1])) ++j; else break;
	}

	decompose(u);
	decompose(v);
}

void solve() {
	REP(i, srcn) src[i] = i;
	//REP(i, n) { printf("%d(%d):", i + 1, src[i] + 1); REPSZ(j, srcadj[i]) printf(" %d", e[srcadj[i][j]].to + 1); puts(""); }
	REP(i, srcn) if (SZ(srcadj[i]) >= 4) {
		int cur = i;
		FORSZ(j, 2, srcadj[i]) {
			if (j != SZ(srcadj[i]) - 1) {
				int nxt = n++;
				e[2 * m + 0] = E(nxt, 0, 0), e[2 * m + 1] = E(cur, 0, 0), ++m;
				src[nxt] = i; cur = nxt;
			}
			e[srcadj[i][j] ^ 1].to = cur;
		}
	}
	REP(i, n) adj[i].clear();
	REP(i, 2 * m) adj[e[i].to].PB(i ^ 1);
	//REP(i, n) { printf("%d(%d):", i + 1, src[i] + 1); REPSZ(j, adj[i]) printf(" %d", e[adj[i][j]].to + 1); puts(""); }
	REP(i, n) assert(SZ(adj[i]) <= 3);

	REP(i, m) alive[i] = true;
	glob.clear(); glob.PB(MP(0, 0));
	decompose(0);
	buildhull(glob);
	//printf("glob:"); printhull(glob);
	int at = 0;
	REP(t, nday) {
		while (at + 1 < SZ(glob) && glob[at + 1].first*t + glob[at + 1].second >= glob[at].first*t + glob[at].second) ++at;
		ans[t] = glob[at].first*t + glob[at].second;
	}
}


void run() {
	scanf("%d%d", &srcn, &nday); n = srcn, m = 0;
	REP(i, srcn - 1) { int u, v, a, b; scanf("%d%d%d%d", &u, &v, &a, &b); --u, --v; e[2 * m + 0] = E(v, a, b), srcadj[u].PB(2 * m + 0), e[2 * m + 1] = E(u, a, b), srcadj[v].PB(2 * m + 1), ++m; }
	solve();
	REP(i, nday) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

void stress() {
	REP(rep, 100) {
		srcn = 100, nday = 100; n = srcn, m = 0; REP(i, srcn) srcadj[i].clear();
		REP(i, srcn - 1) { int u = i + 1, v = rand() % u, a = rand() % 100, b = rand() % 100; e[2 * m + 0] = E(v, a, b), srcadj[u].PB(2 * m + 0), e[2 * m + 1] = E(u, a, b), srcadj[v].PB(2 * m + 1), ++m; }
		solve();
	}
}

int main() {
	run();
	//stress();
	return 0;
}