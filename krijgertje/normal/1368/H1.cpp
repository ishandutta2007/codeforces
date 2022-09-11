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

const int MAXH = 100000;
const int MAXW = 100000;
const int MAXDIM = MAXH >= MAXW ? MAXH : MAXW;
const int MAXQ = 100000;
const int MAXS = 4 * MAXDIM;

int h, w, nq;
char initlft[MAXH + 1];
char initrgt[MAXH + 1];
char inittop[MAXW + 1];
char initbot[MAXW + 1];
char qside[MAXQ]; int ql[MAXQ], qr[MAXQ], qans[MAXQ + 1];


struct SegNode {
	int cost[2][2][2][2]; // cost[lftcol][rgtcol][topflip][botflip]
	bool lazyfliptop, lazyflipbot;
	int cntblue[2], cntred[2];
};
struct SegTree {
	int n;
	int crosscost, lftcost[2], rgtcost[2];
	char inittop[MAXDIM + 1];
	char initbot[MAXDIM + 1];

	SegNode sval[MAXS];

	void sfliptop(int x) {
		swap(sval[x].cntblue[0], sval[x].cntred[0]);
		REP(lftcol, 2) REP(rgtcol, 2) REP(botflip, 2) swap(sval[x].cost[lftcol][rgtcol][0][botflip], sval[x].cost[lftcol][rgtcol][1][botflip]);
		sval[x].lazyfliptop = !sval[x].lazyfliptop;
	}
	void sflipbot(int x) {
		swap(sval[x].cntblue[1], sval[x].cntred[1]);
		REP(lftcol, 2) REP(rgtcol, 2) REP(topflip, 2) swap(sval[x].cost[lftcol][rgtcol][topflip][0], sval[x].cost[lftcol][rgtcol][topflip][1]);
		sval[x].lazyflipbot = !sval[x].lazyflipbot;
	}
	void spush(int x) {
		if (sval[x].lazyfliptop) sfliptop(2 * x + 1), sfliptop(2 * x + 2), sval[x].lazyfliptop = false;
		if (sval[x].lazyflipbot) sflipbot(2 * x + 1), sflipbot(2 * x + 2), sval[x].lazyflipbot = false;
	}
	void spull(int x) {
		const SegNode &a = sval[2 * x + 1];
		const SegNode &b = sval[2 * x + 2];
		REP(side, 2) sval[x].cntblue[side] = a.cntblue[side] + b.cntblue[side];
		REP(side, 2) sval[x].cntred[side] = a.cntred[side] + b.cntred[side];
		REP(lftcol, 2) REP(rgtcol, 2) REP(topflip, 2) REP(botflip, 2) {
			int cur = INT_MAX;
			REP(midcol1, 2) REP(midcol2, 2) {
				int acost = a.cost[lftcol][midcol1][topflip][botflip];
				int bcost = b.cost[midcol2][rgtcol][topflip][botflip];
				int ccost = midcol1 == midcol2 ? 0 : crosscost;
				if (acost == INT_MAX || bcost == INT_MAX) continue;
				cur = min(cur, acost + bcost + ccost);
			}
			sval[x].cost[lftcol][rgtcol][topflip][botflip] = cur;
		}
	}
	void sinit(int x, int l, int r) {
		sval[x].lazyfliptop = sval[x].lazyflipbot = false;
		if (l == r) {
			int sa = inittop[l] == 'B' ? 0 : 1;
			int sb = initbot[l] == 'B' ? 0 : 1;
			sval[x].cntblue[0] = sa == 0 ? 1 : 0, sval[x].cntred[0] = 1 - sval[x].cntblue[0];
			sval[x].cntblue[1] = sb == 0 ? 1 : 0, sval[x].cntred[1] = 1 - sval[x].cntblue[1];
			REP(lftcol, 2) REP(rgtcol, 2) REP(topflip, 2) REP(botflip, 2) {
				int cur;
				if (lftcol == rgtcol) {
					int a = sa; if (topflip) a = 1 - a;
					int b = sb; if (botflip) b = 1 - b;
					cur = (a == lftcol ? 0 : 1) + (b == lftcol ? 0 : 1);
				} else {
					cur = INT_MAX;
				}
				sval[x].cost[lftcol][rgtcol][topflip][botflip] = cur;
			 }
		} else {
			int m = l + (r - l) / 2;
			sinit(2 * x + 1, l, m);
			sinit(2 * x + 2, m + 1, r);
			spull(x);
		}
	}
	void sflip(int x, int l, int r, int L, int R, bool istop) {
		if (L <= l && r <= R) {
			if (istop) sfliptop(x); else sflipbot(x);
		} else {
			int m = l + (r - l) / 2; spush(x);
			if (L <= m) sflip(2 * x + 1, l, m, L, R, istop);
			if (m + 1 <= R) sflip(2 * x + 2, m + 1, r, L, R, istop);
			spull(x);
		}
	}
	void init() {
		sinit(0, 0, n - 1);
	}
	void flip(int l, int r, bool istop) {
		sflip(0, 0, n-1, l, r, istop);
	}
	int calc() {
		int ret = INT_MAX;
		REP(lftcol, 2) REP(rgtcol, 2) {
			int cur = sval[0].cost[lftcol][rgtcol][0][0];
			if (cur == INT_MAX) continue;
			cur += lftcost[lftcol];
			cur += rgtcost[rgtcol];
			ret = min(ret, cur);
		}
		return ret;
	}
};

SegTree stopbot, slftrgt;

int calc() {
	stopbot.lftcost[0] = slftrgt.sval[0].cntred[0], stopbot.lftcost[1] = slftrgt.sval[0].cntblue[0];
	stopbot.rgtcost[0] = slftrgt.sval[0].cntred[1], stopbot.rgtcost[1] = slftrgt.sval[0].cntblue[1];
	slftrgt.lftcost[0] = stopbot.sval[0].cntred[0], slftrgt.lftcost[1] = stopbot.sval[0].cntblue[0];
	slftrgt.rgtcost[0] = stopbot.sval[0].cntred[1], slftrgt.rgtcost[1] = stopbot.sval[0].cntblue[1];
	return min(stopbot.calc(), slftrgt.calc());
}

void solve() {
	stopbot.n = w, stopbot.crosscost = h; REPE(i, w) stopbot.inittop[i] = inittop[i], stopbot.initbot[i] = initbot[i]; stopbot.init();
	slftrgt.n = h, slftrgt.crosscost = w; REPE(i, h) slftrgt.inittop[i] = initlft[i], slftrgt.initbot[i] = initrgt[i]; slftrgt.init();

	qans[0] = calc();
	REP(i, nq) {
		char side = qside[i]; int l = ql[i], r = qr[i];
		if (side == 'U') stopbot.flip(l, r, true);
		if (side == 'D') stopbot.flip(l, r, false);
		if (side == 'L') slftrgt.flip(l, r, true);
		if (side == 'R') slftrgt.flip(l, r, false);
		qans[i + 1] = calc();
	}
}

void run() {
	scanf("%d%d%d", &h, &w, &nq);
	scanf("%s", initlft);
	scanf("%s", initrgt);
	scanf("%s", inittop);
	scanf("%s", initbot);
	REP(i, nq) scanf(" %c%d%d", &qside[i], &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REPE(i, nq) printf("%d\n", qans[i]);
}

void stress() {
	h = MAXH, w = MAXW, nq = MAXQ;
	REP(i, h) initlft[i] = "BR"[rnd() % 2]; initlft[h] = '\0';
	REP(i, h) initrgt[i] = "BR"[rnd() % 2]; initrgt[h] = '\0';
	REP(i, w) inittop[i] = "BR"[rnd() % 2]; inittop[w] = '\0';
	REP(i, w) initbot[i] = "BR"[rnd() % 2]; initbot[w] = '\0';
	REP(i, nq) { qside[i] = "UDLR"[rnd() % 4]; int dim = qside[i] == 'U' || qside[i] == 'D' ? w : h; ql[i] = rnd() % dim, qr[i] = rnd() % dim; if (ql[i] > qr[i]) swap(ql[i], qr[i]); }
	solve();
	printf("done\n");
}

int main() {
	run();
	//stress();
	return 0;
}