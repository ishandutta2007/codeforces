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

const int MAXN = 200000;

int n, extremity[2];
vector<int> adj[MAXN];

int par[MAXN];
int pathlen[MAXN][3], pathvia[MAXN][3];
int snake[MAXN], nsnake;
bool issnake[MAXN];
int snakemx[MAXN];
bool snakeok[MAXN];

void dfsinit(int at) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfsinit(to);
	}
}

void updpath(int at, int len, int via) {
	REP(i, 3) if (len > pathlen[at][i]) {
		for (int j = 3 - 1; j > i; --j) pathlen[at][j] = pathlen[at][j - 1], pathvia[at][j] = pathvia[at][j - 1];
		pathlen[at][i] = len, pathvia[at][i] = via; break;
	}
}
void dfsdn(int at) {
	REP(i, 3) pathlen[at][i] = 0, pathvia[at][i] = -1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		dfsdn(to);
		updpath(at, pathlen[to][0] + 1, to);
	}
}
void dfsup(int at) {
	if (par[at] != -1) updpath(at, pathlen[par[at]][pathvia[par[at]][0] != at ? 0 : 1] + 1, par[at]);
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		dfsup(to);
	}
}
int dfsmx(int at) {
	int ret = 0;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at] || issnake[to]) continue;
		ret = max(ret, dfsmx(to) + 1);
	}
	return ret;
}
bool dfsok(int at) {
	if (pathlen[at][2] >= nsnake - 1) return true;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at] || issnake[to]) continue;
		if (dfsok(to)) return true;
	}
	return false;
}


bool solve() {
	int root = extremity[0];
	par[root] = -1; dfsinit(root);
	dfsdn(root);
	dfsup(root);
	nsnake = 0;
	for (int at = extremity[1]; at != -1; at = par[at]) snake[nsnake++] = at;
	reverse(snake, snake + nsnake);
	REP(i, n) issnake[i] = false;
	REP(i, nsnake) issnake[snake[i]] = true;
	REP(i, nsnake) snakemx[i] = dfsmx(snake[i]);
	REP(i, nsnake) snakeok[i] = dfsok(snake[i]);
	//printf("ok: "); REP(i, nsnake) printf("%c", snakeok[i] ? 'v' : '-'); puts("");
	//printf("mx:"); REP(i, nsnake) printf(" %d", snakemx[i]); puts("");
	//REP(at, n) { printf("%d:", at + 1); REP(i, 3) printf(" %d via %d |", pathlen[at][i], pathvia[at][i] + 1); puts(""); }

	bool any = false; REP(i, nsnake) if (snakeok[i]) any = true; if (!any) return false;
	int llim = 0, rlim = nsnake - 1, l = 0, r = nsnake - 1;
	while (l <= llim || r >= rlim) {
		if (l <= llim) {
			if (snakeok[l]) return true;
			rlim = min(rlim, l + max(0, nsnake - 1 - snakemx[l]));
			++l;
		} else {
			if (snakeok[r]) return true;
			llim = max(llim, r - max(0, nsnake - 1 - snakemx[r]));
			--r;
		}
	}
	return false;
}

void run() {
	scanf("%d%d%d", &n, &extremity[0], &extremity[1]); --extremity[0], --extremity[1];
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%s\n", solve() ? "YES" : "NO");
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}