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

const int MAXN = 10000;
struct P { int x, y, id; };
P operator-(const P &a, const P &b) { P ret; ret.x = a.x - b.x, ret.y = a.y - b.y; return ret; }
ll operator^(const P &a, const P &b) { return (ll)a.x*b.y - (ll)a.y*b.x; }
bool pcmp(const P &a, const P &b) {
	bool aorig = a.x == 0 && a.y == 0, borig = b.x == 0 && b.y == 0;
	if (aorig != borig) return aorig;
	bool atop = a.y > 0 || a.y == 0 && a.x > 0, btop = b.y > 0 || b.y == 0 && b.x > 0;
	if (atop != btop) return atop;
	ll side = a^b;
	if (side != 0) return side > 0;
	return a.id < b.id;
}

void partition(vector<P> va, vector<P> vb, const P piv, vector<P> &va1, vector<P> &va2, vector<P> &vb1, vector<P> &vb2) {
	//printf("partition on %d items on (%d,%d)\n", SZ(va), piv.x, piv.y);
	REPSZ(i, va) va[i].x -= piv.x, va[i].y -= piv.y;
	REPSZ(i, vb) vb[i].x -= piv.x, vb[i].y -= piv.y;
	sort(va.begin(), va.end(), pcmp);
	sort(vb.begin(), vb.end(), pcmp);
	vector<P> aorig; REPSZ(i, va) if (va[i].x == 0 && va[i].y == 0) aorig.PB(va[i]); REP(i, SZ(va) - SZ(aorig)) va[i] = va[i + SZ(aorig)]; REPSZ(i, aorig) va.pop_back();
	vector<P> borig; REPSZ(i, vb) if (vb[i].x == 0 && vb[i].y == 0) borig.PB(vb[i]); REP(i, SZ(vb) - SZ(borig)) vb[i] = vb[i + SZ(borig)]; REPSZ(i, borig) vb.pop_back();
	int na = SZ(va); REP(i, na) va.PB(va[i]);
	int nb = SZ(vb); REP(i, nb) vb.PB(vb[i]);
	int la = 0, ra = 0, lb = 0, rb = 0;
	bool any = false; int bmx = -1, bla = -1, bra = -1, blb = -1, brb = -1;
	REP(i, na + nb) {
		bool afst = la < na && (lb >= nb || pcmp(va[la], vb[lb]));
		P dir = afst ? va[la] : vb[lb];
		while (ra - la < na && (dir^va[ra]) >= 0) ++ra;
		while (rb - lb < nb && (dir^vb[rb]) >= 0) ++rb;
		int acnt = SZ(aorig) + ra - la, bcnt = SZ(borig) + rb - lb;
		//printf("\t(%d,%d): %d vs %d\n", dir.x + piv.x, dir.y + piv.y, acnt, bcnt);
		if (acnt == bcnt) {
			int mx = max(acnt, na + SZ(aorig) - acnt);
			if (!any || mx < bmx) any = true, bmx = mx, bla = la, bra = ra, blb = lb, brb = rb;
		}
		if (acnt - (afst ? 1 : 0) == bcnt - (!afst ? 1 : 0)) {
			int mx = max(acnt - (afst ? 1 : 0), na + SZ(aorig) - (acnt - (afst ? 1 : 0)));
			if (!any || mx < bmx) any = true, bmx = mx, bla = la + (afst ? 1 : 0), bra = ra, blb = lb + (!afst ? 1 : 0), brb = rb;
		}
		if (afst) ++la; else ++lb;
		if (ra < la) ra = la; if (rb < lb) rb = lb;
	}
	assert(any);
	REPSZ(i, aorig) aorig[i].x += piv.x, aorig[i].y += piv.y; REPSZ(i, va) va[i].x += piv.x, va[i].y += piv.y;
	REPSZ(i, borig) borig[i].x += piv.x, borig[i].y += piv.y; REPSZ(i, vb) vb[i].x += piv.x, vb[i].y += piv.y;
	va1.clear(); va2.clear(); REPSZ(i, aorig) va1.PB(aorig[i]); REP(i, na) if (bla <= i&&i < bra || bla <= i + na&&i + na < bra) va1.PB(va[i]); else va2.PB(va[i]);
	vb1.clear(); vb2.clear(); REPSZ(i, borig) vb1.PB(borig[i]); REP(i, nb) if (blb <= i&&i < brb || blb <= i + nb&&i + nb < brb) vb1.PB(vb[i]); else vb2.PB(vb[i]);
	assert(SZ(va1) == SZ(vb1)); assert(SZ(va2) == SZ(vb2));
}

int ans[MAXN];

void solve(const vector<P> &va, const vector<P> &vb) {
	assert(SZ(va) == SZ(vb));
	if (SZ(va) == 1) { ans[va[0].id] = vb[0].id; return; }
	vector<P> va1, va2, vb1, vb2;
	REP(rep, 100) {
		int pividx = rand() % (SZ(va) + SZ(vb)); P piv = pividx < SZ(va) ? va[pividx] : vb[pividx - SZ(va)];
		vector<P> _va1, _va2, _vb1, _vb2;
		partition(va, vb, piv, _va1, _va2, _vb1, _vb2);
		if (rep == 0 || max(SZ(_va1), SZ(_va2)) < max(SZ(va1), SZ(va2))) va1 = _va1, va2 = _va2, vb1 = _vb1, vb2 = _vb2;
		int mx = max(SZ(va1), SZ(va2)); if (4 * mx <= 3 * SZ(va)) break; if (rep >= 9 && SZ(va1) < SZ(va) && SZ(va2) < SZ(va)) break;
	}
	assert(SZ(va1) < SZ(va) && SZ(va2) < SZ(va));
	solve(va1, vb1); solve(va2, vb2);
}


int n;
P a[MAXN];
P b[MAXN];

void run() {
	scanf("%d", &n); REP(i, n) scanf("%d%d", &a[i].x, &a[i].y), a[i].id = i; REP(i, n) scanf("%d%d", &b[i].x, &b[i].y), b[i].id = i;

	vector<P> va(n); REP(i, n) va[i] = a[i];
	vector<P> vb(n); REP(i, n) vb[i] = b[i];
	REP(i, n) ans[i] = -1;
	solve(va, vb);
	REP(i, n) printf("%d\n", ans[i] + 1);
}

int myrand() { return rand() % 1000 * 1000 + rand(); }

void stress() {
	REP(rep, 10000) {
		n = 200;
		vector<P> p; int tmp = 0;
		while (SZ(p) < 2 * n) {
			P cur; cur.x = myrand() % 20001 - 10000, cur.y = myrand() % 20001 - 10000;
			bool ok = true; REPSZ(i, p) FORSZ(j, i + 1, p) if (((p[j] - p[i]) ^ (cur - p[i])) == 0) ok = false;
			REPSZ(i, p) if (p[i].x == cur.x&&p[i].y == cur.y) ok = false;
			if (++tmp > 1000000) { 
				printf("here\n"); REPSZ(i, p) printf("%d %d\n", p[i].x, p[i].y);
				exit(0);
			}
			if (ok) p.PB(cur);
		}
		vector<P> va(n); REP(i, n) va[i] = p[i], va[i].id = i;
		vector<P> vb(n); REP(i, n) vb[i] = p[n + i], vb[i].id = i;
		//printf("%d:\n", rep);
		//printf("%d\n", n); REP(i, n) printf("%d %d\n", va[i].x, va[i].y); REP(i, n) printf("%d %d\n", vb[i].x, vb[i].y);
		solve(va, vb);
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}