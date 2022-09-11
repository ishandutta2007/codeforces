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

const int MAXBIT = 12;
const int MAXVAR = 30000;
const int MAXGATE = 50000;
const int MAXTRI = 531441;

int nbit, nvar, ngate;
int var[MAXVAR];
char gate[MAXGATE][MAXBIT + 1];
ll ans[MAXGATE];

int p3[MAXBIT + 1];
int mask2tri[1 << MAXBIT];
int tricnt[MAXTRI];

void printtri(int id) { for (int j = nbit - 1; j >= 0; --j) printf("%c", "01?"[id / p3[j] % 3]); }

ll rec(char *s, int at, int id1, int id2, bool matches) {
	if (at >= nbit) return matches && false ? (ll)tricnt[id1] * (tricnt[id2] - 1) : (ll)tricnt[id1] * tricnt[id2];
	if (s[nbit - at - 1] == 'A') return rec(s, at + 1, id1 + 0 * p3[at], id2 + 2 * p3[at], matches) + rec(s, at + 1, id1 + 1 * p3[at], id2 + 0 * p3[at], false);
	if (s[nbit - at - 1] == 'O') return rec(s, at + 1, id1 + 0 * p3[at], id2 + 0 * p3[at], matches);
	if (s[nbit - at - 1] == 'X') return rec(s, at + 1, id1 + 0 * p3[at], id2 + 0 * p3[at], matches) + rec(s, at + 1, id1 + 1 * p3[at], id2 + 1 * p3[at], matches);
	if (s[nbit - at - 1] == 'a') return rec(s, at + 1, id1 + 1 * p3[at], id2 + 1 * p3[at], matches);
	if (s[nbit - at - 1] == 'o') return rec(s, at + 1, id1 + 1 * p3[at], id2 + 2 * p3[at], matches) + rec(s, at + 1, id1 + 0 * p3[at], id2 + 1 * p3[at], false);
	if (s[nbit - at - 1] == 'x') return rec(s, at + 1, id1 + 0 * p3[at], id2 + 1 * p3[at], false) + rec(s, at + 1, id1 + 1 * p3[at], id2 + 0 * p3[at], false);
	assert(false); return -1;
}

// 101111
// 001100
// AOXaox


void solve() {
	p3[0] = 1; REP(i, nbit) p3[i + 1] = p3[i] * 3;
	mask2tri[0] = 0; FOR(i, 1, 1 << nbit) mask2tri[i] = 3 * mask2tri[i >> 1] + (i & 1);

	REP(i, p3[nbit]) tricnt[i] = 0; REP(i, nvar) ++tricnt[mask2tri[var[i]]];
	REP(i, nbit) REP(prefmask, 1 << (nbit - i)) REP(sufftri, p3[i]) {
		int oldtri = mask2tri[prefmask] * p3[i] + sufftri;
		int newtri = (mask2tri[prefmask - (prefmask & 1)] + 2)*p3[i] + sufftri;
		//printtri(oldtri); printf(" -> "); printtri(newtri); puts("");
		tricnt[newtri] += tricnt[oldtri];
	}
	//REP(i, p3[nbit]) if (tricnt[i] != 0) { printtri(i); printf(" = %d\n", tricnt[i]); }

	REP(i, ngate) {
		ans[i] = rec(gate[i], 0, 0, 0, true);
	}
}

void run() {
	scanf("%d%d%d", &nbit, &nvar, &ngate);
	REP(i, nvar) scanf("%d", &var[i]);
	REP(i, ngate) scanf("%s", gate[i]);
	solve();
	REP(i, ngate) printf("%lld\n", ans[i]);
}

int main() {
	run();
	return 0;
}