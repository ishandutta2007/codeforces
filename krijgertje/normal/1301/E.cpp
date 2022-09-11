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

const int MAXH = 500;
const int MAXW = 500;
const int MAXQ = 300000;

int h, w, nq;
char g[MAXH][MAXW + 1];
int qlx[MAXQ], qly[MAXQ], qhx[MAXQ], qhy[MAXQ], qans[MAXQ];

int single[MAXH][MAXW];
int logo[MAXH + 1][MAXW + 1];

int cnt[MAXH + 1][MAXW + 1];

void solve() {
	for (int x = h - 1; x >= 0; --x) for (int y = w - 1; y >= 0; --y) {
		if (x + 1 >= h || y + 1 >= w || g[x][y] != g[x + 1][y] || g[x][y] != g[x][y + 1] || g[x][y] != g[x + 1][y + 1]) { single[x][y] = 1; continue; }
		single[x][y] = 1 + min(min(single[x + 1][y], single[x][y + 1]), single[x + 1][y + 1]);
	}
	//REP(x, h) { printf("single%d:", x); REP(y, w) printf(" %d", single[x][y]); puts(""); }
	REPE(x, h) REPE(y, w) {
		int lim = min(min(x, h - x), min(y, w - y));
		int sz = 0;
		while (sz < lim) { // RG YB
			char a = g[x - (sz + 1)][y - (sz + 1)]; int acnt = single[x - (sz + 1)][y - (sz + 1)];
			char b = g[x - (sz + 1)][y]; int bcnt = single[x - (sz + 1)][y];
			char c = g[x][y - (sz + 1)]; int ccnt = single[x][y - (sz + 1)];
			char d = g[x][y]; int dcnt = single[x][y];
			if (a != 'R' || b != 'G' || c != 'Y' || d != 'B' || acnt < sz + 1 || bcnt < sz + 1 || ccnt < sz + 1 || dcnt < sz + 1) break; else ++sz;
		}
		logo[x][y] = sz;
	}
	//REPE(x, h) { printf("logo%d:", x); REPE(y, w) printf(" %d", logo[x][y]); puts(""); }
	REP(i, nq) qans[i] = -1;
	int rem = nq;
	for (int sz = 1; rem > 0; ++sz) {
		REPE(x, h) REPE(y, w) cnt[x][y] = logo[x][y] >= sz ? 1 : 0;
		REPE(x, h) REPE(y, w) { if (x - 1 >= 0) cnt[x][y] += cnt[x - 1][y]; if (y - 1 >= 0) cnt[x][y] += cnt[x][y - 1]; if (x - 1 >= 0 && y - 1 >= 0) cnt[x][y] -= cnt[x - 1][y - 1]; }
		REP(i, nq) if (qans[i] == -1) {
			int lx = qlx[i] + sz, ly = qly[i] + sz, hx = qhx[i] + 1 - sz, hy = qhy[i] + 1 - sz; bool found = false;
			if (lx <= hx && ly <= hy) found = cnt[hx][hy] - cnt[lx - 1][hy] - cnt[hx][ly - 1] + cnt[lx - 1][ly - 1] > 0;
			if (!found) qans[i] = sz - 1, --rem;
		}
	}
	REP(i, nq) qans[i] = 4 * qans[i] * qans[i];
}

void run() {
	scanf("%d%d%d", &h, &w, &nq);
	REP(x, h) scanf("%s", g[x]);
	REP(i, nq) scanf("%d%d%d%d", &qlx[i], &qly[i], &qhx[i], &qhy[i]), --qlx[i], --qly[i], --qhx[i], --qhy[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}