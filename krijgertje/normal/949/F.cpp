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

const int MAXN = 2600;
const int MAXABSCOORD = 1000000;
const int MOD = 1057438801;
const int HMOD = 11833;
struct P { int x, y; P() {}P(int x, int y) :x(x), y(y) {} };
P operator-(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
ll operator^(const P &a, const P &b) { return (ll)a.x*b.y - (ll)a.y*b.x; }

int n;
P p[2 * MAXN];

int inv[2 * MAXABSCOORD + 1];
int xa = 4213, xb = 1232, xc = 9234;

P d[2 * MAXN][2 * MAXN];
int h[2 * MAXN][HMOD];
bool dok[2 * MAXN][2 * MAXN];
int nok[2 * MAXN];

int o[2 * MAXN];

P normdir(const P &p) { return p.y > 0 || p.y == 0 && p.x >= 0 ? p : P(-p.x, -p.y); }

P ans;

bool test(int u, int uu, int v, int vv) {
	ll num = (p[v] - p[u]) ^ (p[vv] - p[v]);
	ll den = (p[uu] - p[u]) ^ (p[vv] - p[v]);
	if (den == 0) return false;
	P du = p[uu] - p[u]; if (num*du.x%den != 0 || num*du.y%den != 0) return false;
	ll qx = p[u].x + num*du.x / den, qy = p[u].y + num*du.y / den;
	if (abs(qx) > MAXABSCOORD || abs(qy) > MAXABSCOORD) return false;
	P q(qx, qy);

	REP(i, 2 * n) {
		int at = o[i];
		if (p[at].x == q.x&&p[at].y == q.y) return false;
		if (at == u || at == uu || at == v || at == vv) continue;
		P dd = normdir(q - p[at]);
		int v = dd.y == 0 ? HMOD - 1 : (ll)(dd.x + MOD)*inv[dd.y] % MOD;
		int a = v%HMOD, b = v / HMOD%HMOD, c = v / HMOD / HMOD;
		int hv = (a*xa + b*xb + c*xc) % HMOD;
		bool found = false;
		while (h[at][hv] != -1) { if ((dd^d[at][h[at][hv]]) == 0) { if (!dok[at][h[at][hv]]) return false; found = true; break; }  hv = (hv + 1) % HMOD; }
		if (!found) return false;
	}

	ans = q; return true;
}

bool solve() {
	inv[1] = 1; FORE(i, 2, 2 * MAXABSCOORD) inv[i] = (ll)(MOD - MOD / i)*inv[MOD%i] % MOD;

	REP(i, 2 * n) {
		REP(j, 2 * n) d[i][j] = normdir(p[j] - p[i]), dok[i][j] = i != j;
		memset(h[i], -1, sizeof(h[i]));
		REP(j, 2 * n) if (j != i) {
			int v = d[i][j].y == 0 ? HMOD - 1 : (ll)(d[i][j].x + MOD)*inv[d[i][j].y] % MOD;
			int a = v%HMOD, b = v / HMOD%HMOD, c = v / HMOD / HMOD;
			int hv = (a*xa + b*xb + c*xc) % HMOD;
			while (h[i][hv] != -1) { if ((d[i][j] ^ d[i][h[i][hv]]) == 0) { dok[i][j] = dok[i][h[i][hv]] = false; break; } hv = (hv + 1) % HMOD; } h[i][hv] = j;
		}
		nok[i] = 0; REP(j, 2 * n) if (dok[i][j]) ++nok[i];
	}

	int u = -1, v = -1, w = -1;
	REP(i, 2 * n) if (u == -1 || nok[i] < nok[u]) w = v, v = u, u = i; else if (v == -1 || nok[i] < nok[v]) w = v, v = i; else if (w == -1 || nok[i] < nok[w]) w = i;
	
	REP(i, 2 * n) o[i] = i; random_shuffle(o, o + 2 * n);
	REP(ww, 2 * n) if (ww != u && ww != v && dok[w][ww]) if (test(u, v, w, ww)) return true;
	REP(uu, 2 * n) REP(vv, 2 * n) if (uu != v && vv != u && dok[u][uu] && dok[v][vv]) if (test(u, uu, v, vv)) return true;
	return false;
}

void run() {
	scanf("%d", &n); REP(i, 2 * n) scanf("%d%d", &p[i].x, &p[i].y);
	if (solve()) printf("Yes\n%d %d\n", ans.x, ans.y); else printf("No\n");
}

int myrandcoord() { return 2000 * rand() % 1000 + rand() % 2001 - 1000000; }
void stress() {
	n = MAXN; REP(i, 2 * n) p[i].x = myrandcoord(), p[i].y = myrandcoord();
	if (solve()) printf("Yes\n%d %d\n", ans.x, ans.y); else printf("No\n");
}

int main() {
	srand(time(NULL));
	run();
	//stress();
	return 0;
}