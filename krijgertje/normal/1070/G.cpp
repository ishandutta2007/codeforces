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


const int MAXW = 100;
const int MAXN = 100;

int w, n;
int sx[MAXN], sh[MAXN];
int a[MAXN];

int tx;
int p[MAXN], np;

int who[MAXW];

bool solve() {
	REP(i, w) who[i] = -1; REP(i, n) who[sx[i]] = i;
	
	int lx = 0; while (lx < w && who[lx] == -1) ++lx; assert(lx < w && who[lx] != -1);
	int lh = sh[who[lx]];
	deque<int> lp; lp.PB(who[lx]);
	while (lx + 1 < w && lh + a[lx + 1] >= 0) {
		++lx; lh += a[lx];
		if (who[lx] != -1) {
			int idx = who[lx];
			if (sh[idx] > lh) lh = sh[idx], lp.push_front(idx); else lp.PB(idx);
		}
	}
	//printf("%d: %d\n", lx, lh);
	int rx = w - 1; while (rx > lx && who[rx] == -1) --rx;
	if (rx == lx) { tx = lx, np = 0; for (auto it = lp.begin(); it != lp.end(); ++it) p[np++] = *it; return true; } else assert(rx > lx && who[rx] != -1);
	int rh = sh[who[rx]];
	deque<int> rp; rp.PB(who[rx]);
	while (rx - 1 > lx && rh + a[rx - 1] >= 0) {
		--rx; rh += a[rx];
		if (who[rx] != -1) {
			int idx = who[rx];
			if (sh[idx] > rh) rh = sh[idx], rp.push_front(idx); else rp.PB(idx);
		}
	}
	//printf("%d: %d\n", rx, rh);
	//printf("%d vs %d\n", SZ(lp), SZ(rp));
	if (rx - lx != 1) return false;
	tx = lx, np = 0; for (auto it = lp.begin(); it != lp.end(); ++it) p[np++] = *it; for (auto it = rp.begin(); it != rp.end(); ++it) p[np++] = *it; return true;
}

void run() {
	scanf("%d%d", &w, &n);
	REP(i, n) scanf("%d%d", &sx[i], &sh[i]), --sx[i];
	REP(i, w) scanf("%d", &a[i]);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", tx + 1);
	REP(i, n) { if (i != 0) printf(" "); printf("%d", p[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}