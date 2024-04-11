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

const int MAXN = 1000;

int n;
int target[MAXN];
char g[MAXN][MAXN + 1];

int targetedby[MAXN];
bool done[MAXN];

int solve() {
	REP(x, n) { REP(y, n) g[x][y] = '.'; g[x][n] = '\0'; }
	bool identity = true; REP(i, n) if (target[i] != i) identity = false; if (identity) return n;

	REP(i, n) targetedby[target[i]] = i;
	int last = n - 1; while (last >= 0 && target[last] == last) --last; assert(last >= 0);
	int row = n - 1;
	REP(i, n) done[i] = target[i] == i;
	{
		int to = targetedby[last]; done[to] = true;
		while (!done[targetedby[to]]) {
			int from = targetedby[to];
			if (from < to) g[row][from] = g[row][to] = '/'; else if (from > to) g[row][from] = g[row][to] = '\\'; else assert(false);
			done[from] = true, to = from, --row;
		}
	}
	for (int i = n - 1; i >= 0; --i) if (!done[i]) {
		int to = i;
		while (!done[targetedby[to]]) {
			int from = targetedby[to];
			int realfrom = from != i ? from : last;
			if (realfrom < to) g[row][realfrom] = g[row][to] = '/'; else if (realfrom > to) g[row][realfrom] = g[row][to] = '\\'; else assert(false);
			if (to == i) { assert(from < to); g[row][last] = '/'; }
			done[from] = true, to = from, --row;
		}
	}
	return n - 1;
}


void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &target[i]), --target[i];
	printf("%d\n", solve());
	REP(x, n) printf("%s\n", g[x]);
}

const int DX[] = { -1,0,+1,0 }, DY[] = { 0,-1,0,+1 };
int walk(int x, int y, int k) {
	while (true) {
		//printf("\t(%d,%d) [%d]\n", x, y, k);
		x += DX[k], y += DY[k];
		if (x < 0 || x >= n || y < 0 || y >= n) break;
		if (g[x][y] == '\\') k ^= 1; else if (g[x][y] == '/') k = 3 - k;
	}
	//printf("(%d,%d) [%d]\n", x, y, k);
	return x == -1 ? y : -1;
}

void stress() {
	REP(rep, 10000) {
		n = MAXN; REP(i, n) target[i] = i; REP(i, n) { int idx = rand() % (i + 1); swap(target[i], target[idx]); }
		int have = solve();
		int cnt = 0; REP(i, n) if (walk(n, i, 0) == target[i]) ++cnt;
		if (have == cnt) { printf("."); continue; }
		printf("err\n");
		REP(i, n) { if (i != 0) printf(" "); printf("%d", target[i]); } puts("");
		printf("have=%d cnt=%d\n", have, cnt); REP(x, n) printf("%s\n", g[x]);
		exit(0);
	}
}

int main() {
	run();
	//stress();
	return 0;
}