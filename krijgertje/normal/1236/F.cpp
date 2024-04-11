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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 500000;
const int MAXCOMP = MAXN - 1;
const int MOD = 1000000007;
const int INV2 = (MOD + 1) / 2;
const int KINDDEAD = 0;
const int KINDALIVE = 1;
const int KINDUSED = 2;
const int NKIND = 3;
const int MAXCHOOSE = 2;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%MOD; if ((n >>= 1) == 0) return ret; x = (ll)x*x%MOD; } }

struct Res {
	int ways[MAXCHOOSE+1][NKIND]; // ways[i][j] = #ways for subtree for selecting i connected components in the subtree, the root having state j
	Res() { memset(ways, 0, sizeof(ways)); }
};


int dp[MAXN][MAXCHOOSE + 2][NKIND][NKIND][2];
Res sub[MAXN]; int nsub;

Res calcsub() {
	//printf("calcsub:\n");
	//REP(i, nsub) REPE(j, MAXCHOOSE) REP(a, 3) { int cur = sub[i].ways[j][a]; if (cur != 0) printf("sub[%d].ways[%d][%d]=%d\n", i, j, a, cur); }
	REP(i, nsub) REPE(j, MAXCHOOSE + 1) REP(a, NKIND) REP(b, NKIND) REP(z,2) dp[i][j][a][b][z] = 0;
	REPE(j, MAXCHOOSE) REP(a, NKIND) inc(dp[0][j][a][a][a != KINDUSED ? 1 : 0], sub[0].ways[j][a]);
	FOR(i, 1, nsub) REPE(j, MAXCHOOSE + 1) REP(a, NKIND) REP(b, NKIND) REP(z,2) {
		int cur = dp[i - 1][j][a][b][z]; if (cur == 0) continue;
		REP(c, NKIND) {
			if (b != KINDDEAD && c != KINDDEAD && b  != c) continue;
			int cj = b != KINDUSED && c == KINDUSED ? 1 : 0;
			REPE(dj, MAXCHOOSE + 1 - j - cj) {
				int jj = (c == KINDUSED ? 1 : 0) + dj; if (jj > MAXCHOOSE) continue;
				int now = sub[i].ways[jj][c]; if (now == 0) continue;
				inc(dp[i][j + cj + dj][a][c][z == 1 || c != KINDUSED ? 1 : 0], (ll)cur*now%MOD);
			}
		}
	}
	/*REP(i, nsub) REPE(j, MAXCHOOSE + 1) REP(a, NKIND) REP(b, NKIND) REP(z, 2) {
		int cur = dp[i][j][a][b][z]; if (cur == 0) continue;
		printf("dp[%d][%d][%d][%d][%d]=%d\n", i, j, a, b, z, cur);
	}*/
	Res ret;
	REPE(j, MAXCHOOSE + 1) REP(a, NKIND) REP(b, NKIND) REP(z, 2) {
		if (a != KINDDEAD && b != KINDDEAD && a != b) continue;
		int cur = dp[nsub - 1][j][a][b][z]; if (cur == 0) continue;
		int nchoose = j - (a == KINDUSED && b == KINDUSED && z == 1 ? 1 : 0);
		if (nchoose <= MAXCHOOSE) inc(ret.ways[nchoose][a], cur);
	}
	return ret;
}

Res createleaf() {
	Res ret;
	inc(ret.ways[0][KINDDEAD], 1);
	inc(ret.ways[0][KINDALIVE], 1);
	inc(ret.ways[1][KINDUSED], 1);
	return ret;
}
Res combinechild(const Res &me, const Res &ch) {
	Res ret;
	REP(a, NKIND) {
		int cj = a == KINDUSED ? 1 : 0;
		REPE(mej, MAXCHOOSE - cj) REPE(chj, MAXCHOOSE - mej - cj) {
			int l = me.ways[mej + cj][a], r = ch.ways[chj + cj][a]; if (l == 0 || r == 0) continue;
			inc(ret.ways[mej + chj + cj][a], (ll)l*r%MOD);
		}
	}
	return ret;
}

Res noderes[MAXN];
Res compres[MAXCOMP];
vector<int> nodeincomps[MAXN];
vector<int> compnodes[MAXCOMP];

void sethead(int atcomp, int atnode) {
	int idx = -1; REPSZ(i, compnodes[atcomp]) if (compnodes[atcomp][i] == atnode) { idx = i; break; } assert(idx != -1);
	rotate(compnodes[atcomp].begin(), compnodes[atcomp].begin() + idx, compnodes[atcomp].end());
	assert(compnodes[atcomp][0] == atnode);
}
Res calccomp(int atcomp);
Res calcnode(int atnode, int atcomp) {
	Res ret = createleaf();
	REPSZ(i, nodeincomps[atnode]) {
		int tocomp = nodeincomps[atnode][i]; if (tocomp == atcomp) continue;
		sethead(tocomp, atnode);
		Res sub = calccomp(tocomp);
		ret = combinechild(ret, sub);
	}
	return noderes[atnode] = ret;
}

Res calccomp(int atcomp) {
	FORSZ(i, 1, compnodes[atcomp]) {
		int atnode = compnodes[atcomp][i];
		calcnode(atnode, atcomp);
	}
	nsub = 0;
	sub[nsub++] = createleaf();
	FORSZ(i, 1, compnodes[atcomp]) {
		int atnode = compnodes[atcomp][i];
		sub[nsub++] = noderes[atnode];
	}
	Res ret = calcsub();
	return compres[atcomp] = ret;
}

int n, m;
vector<int> adj[MAXN];

int ncomp;
int dep[MAXN], par[MAXN], mndep[MAXN]; bool been[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1, mndep[at] = dep[at]; been[at] = true;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		if (been[to]) {
			if (dep[to] > dep[at]) continue;
			mndep[at] = min(mndep[at], dep[to]);
			int compid = ncomp++;
			for (int x = at;; x = par[x]) {
				compnodes[compid].PB(x); nodeincomps[x].PB(compid);
				if (x == to) break;
			}
		} else {
			par[to] = at; dfsinit(to);
			mndep[at] = min(mndep[at], mndep[to]);
			if (mndep[to] > dep[at]) {
				int compid = ncomp++;
				compnodes[compid].PB(at); compnodes[compid].PB(to);
				nodeincomps[at].PB(compid); nodeincomps[to].PB(compid);
			}
		}
	}
}

int solve() {
	if (n == 1) return (ll)INV2*INV2%MOD;
	REP(i, n) been[i] = false;
	par[0] = -1; dfsinit(0);
	//REP(i, ncomp) { printf("comp%d:", i); REPSZ(j, compnodes[i]) printf(" %d", compnodes[i][j]); puts(""); }
	int rootnode = -1; REP(i, n) if (SZ(nodeincomps[i]) == 1) { rootnode = i; break; } assert(rootnode != -1);
	int rootcomp = nodeincomps[rootnode][0];
	sethead(rootcomp, rootnode);
	Res res = calccomp(rootcomp);
	int waysone = 0, waystwo = 0;
	REP(a, 3) {
		inc(waysone, res.ways[1][a]);
		inc(waystwo, ((ll)2 * res.ways[2][a] + res.ways[1][a]) % MOD);
	}
	//printf("waysone=%d waystwo=%d\n", waysone, waystwo);
	int Eone = (ll)waysone*pw(INV2, n) % MOD;
	int Etwo = (ll)waystwo*pw(INV2, n) % MOD;
	return (Etwo + MOD - (ll)Eone*Eone%MOD) % MOD;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}