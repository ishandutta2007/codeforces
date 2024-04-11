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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 500000;

int n;
int a[2 * MAXN - 1];
int b[2 * MAXN - 1];

int c[2 * MAXN - 1], nc; // stack of matched positions
int d[2 * MAXN - 1], nd; // stack of positions to process
int e[2 * MAXN - 1], ne;
int f[2 * MAXN - 1], nf;
int g[2 * MAXN - 1], ng;

int fst[MAXN], nxt[2 * MAXN - 1];
int unused[MAXN], nunused;

bool solveE(int par) {
	//printf("%d:", par + 1); REP(i, ne) printf(" %d", b[e[i]] + 1); puts("");
	if (ne % 2 == 0) return false;
	int nempty = 0; REP(i, ne) if (b[e[i]] == -1) ++nempty;
	if (nempty < (ne - 1) / 2) return false;
	if (ne == 1) { if (b[e[0]] != -1) return true; if (nunused == 0) return false; b[e[0]] = unused[--nunused]; return true; }
	if (par == -1) {
		int l = b[e[0]], r = b[e[ne - 1]], split = -1;
		if (l != -1 && r != -1 && l != r) return false;
		if (l != -1) { assert(r == -1); r = b[e[ne - 1]] = l; }
		else if (r != -1) { assert(l == -1); l = b[e[0]] = r; }
		else if (nempty > (ne - 1) / 2) { if (nunused == 0) return false; l = r = b[e[0]] = b[e[ne - 1]] = unused[--nunused]; }
		else { int bal = 0; FOR(i, 1, ne - 1) if (b[e[i]] == -1) --bal; else if (bal <= 0) ++bal; else { split = i; break; } assert(split != -1); }
		nf = ne; REP(i, ne) f[i] = e[i];
		if (split == -1) {
			assert(l != -1 && l == r);
			ne = 0; FOR(i, 1, nf - 1) e[ne++] = f[i]; if (!solveE(l)) return false;
		} else {
			l = r = b[e[0]] = b[e[ne - 1]] = b[e[split]]; assert(l != -1 && l == r);
			ne = 0; FOR(i, 1, split) e[ne++] = f[i]; if (!solveE(l)) return false;
			ne = 0; FOR(i, split + 1, nf - 1) e[ne++] = f[i]; if (!solveE(l)) return false;
		}
	} else {
		ng = 0;
		int nextra = nempty - (ne - 1) / 2;
		REP(i, ne) if (nextra > 0 && b[e[i]] == -1) { if (nunused == 0) return false; b[e[i]] = unused[--nunused]; --nextra; }
		REP(i, ne) {
			g[ng++] = e[i];
			while (ng >= 3) {
				if (b[g[ng - 3]] == -1 && b[g[ng - 2]] != -1 && b[g[ng - 1]] != -1) { b[g[ng - 3]] = b[g[ng - 1]]; ng -= 2; continue; }
				if (b[g[ng - 3]] != -1 && b[g[ng - 2]] != -1 && b[g[ng - 1]] == -1) { b[g[ng - 1]] = b[g[ng - 3]]; ng -= 2; continue; }
				break;
			}
		}
		assert(ng % 2 == 1); REP(i, ng) assert((b[g[i]] == -1) == (i % 2 == 1));
		for (int i = 1; i < ng; i += 2) b[g[i]] = par;
	}
	return true;
}

bool solve() {
	REP(i, n) fst[i] = -1; for (int i = 2 * n - 2; i >= 0; --i) if (a[i] != -1) { nxt[i] = fst[a[i]]; fst[a[i]] = i; } else nxt[i] = -1;
	nunused = 0; REP(i, n) if (fst[i] == -1) unused[nunused++] = i;
	//printf("a:"); REP(i, 2 * n - 1) printf(" %d", a[i]); puts("");

	REP(i, 2 * n - 1) b[i] = a[i];
	nc = nd = 0;
	REP(i, 2 * n - 1) {
		if (nc>0 && nxt[c[nc - 1]] == i) {
			// close
			ne = 0; while (nd > 0 && d[nd - 1] != c[nc - 1]) e[ne++] = d[--nd]; assert(nd > 0 && d[nd - 1] == c[nc - 1]); --nc, --nd; reverse(e, e + ne);
			if (!solveE(a[i])) return false;
		}
		if (nxt[i] != -1) {
			// open
			if (nc > 0 && nxt[c[nc - 1]] < nxt[i]) return false;
			c[nc++] = i;
			d[nd++] = i;
		} else {
			// empty or last
			d[nd++] = i;
		}
	}
	assert(nc == 0); ne = 0; while (nd > 0) e[ne++] = d[--nd]; reverse(e, e + ne);
	if (!solveE(-1)) return false;
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, 2 * n - 1) scanf("%d", &a[i]), --a[i];
	if (!solve()) { printf("no\n"); return; }
	printf("yes\n");
	REP(i, 2 * n - 1) { if (i != 0) printf(" "); printf("%d", b[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}