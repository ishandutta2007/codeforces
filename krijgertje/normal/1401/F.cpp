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

const int MAXLEVEL = 18;
const int MAXQ = 100000;

int mxlevel, nq;
int a[1 << MAXLEVEL];
int qkind[MAXQ], qx[MAXQ], qk[MAXQ], ql[MAXQ], qr[MAXQ]; ll qans[MAXQ];


bool rev[MAXLEVEL + 1], swp[MAXLEVEL + 1];
ll sval[(2 << MAXLEVEL) - 1];

void spull(int x) { sval[x] = sval[2 * x + 1] + sval[2 * x + 2]; }
void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x] = a[l];
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int lvl, int x, int l, int r, int IDX, int VAL) {
	if (rev[lvl]) IDX = r - (IDX - l);
	if (swp[lvl]) { int len = r - l + 1; assert(len % 2 == 0); if (IDX < l + len / 2) IDX += len / 2; else IDX -= len / 2; }
	if (l == r) {
		//printf("modifying %d\n", l);
		sval[x] = VAL;
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) smod(lvl - 1, 2 * x + 1, l, m, IDX, VAL); else smod(lvl - 1, 2 * x + 2, m + 1, r, IDX, VAL);
		spull(x);
	}
}
ll sget(int lvl, int x, int l, int r, int L, int R) {
	//REP(i, mxlevel - lvl) printf(" "); printf("sget(%d..%d,%d..%d)\n", l, r, L, R);
	if (rev[lvl]) L = r - (L - l), R = r - (R - l), swap(L, R);
	if (L<=l&&r<=R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; ll ret = 0;
		int len = r - l + 1; assert(len % 2 == 0);
		if (L <= m) {
			int upto = min(R, m);
			ret += sget(lvl - 1, 2 * x + (swp[lvl] ? 2 : 1), swp[lvl] ? m + 1 : l, swp[lvl] ? r : m, L + (swp[lvl] ? len / 2 : 0), upto + (swp[lvl] ? len / 2 : 0));
		}
		if (m + 1 <= R) {
			int from = max(L, m + 1);
			ret += sget(lvl - 1, 2 * x + (swp[lvl] ? 1 : 2), swp[lvl] ? l : m + 1, swp[lvl] ? m : r, from - (swp[lvl] ? len / 2 : 0), R - (swp[lvl] ? len / 2 : 0));
		}

		return ret;
	}
}

void solve() {
	REPE(i, mxlevel) rev[i] = swp[i] = false;
	sinit(0, 0, (1 << mxlevel) - 1);
	REP(i, nq) {
		if (qkind[i] == 1) { smod(mxlevel, 0, 0, (1 << mxlevel) - 1, qx[i], qk[i]); }
		if (qkind[i] == 2) { rev[qk[i]] = !rev[qk[i]]; }
		if (qkind[i] == 3) { swp[qk[i]] = !swp[qk[i]]; }
		if (qkind[i] == 4) { qans[i] = sget(mxlevel, 0, 0, (1 << mxlevel) - 1, ql[i], qr[i]); }
	}
}

void run() {
	scanf("%d%d", &mxlevel, &nq);
	REP(i, 1 << mxlevel) scanf("%d", &a[i]);
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 1) scanf("%d%d", &qx[i], &qk[i]), --qx[i];
		if (qkind[i] == 2) scanf("%d", &qk[i]);
		if (qkind[i] == 3) scanf("%d", &qk[i]), ++qk[i];
		if (qkind[i] == 4) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	}
	solve();
	REP(i, nq) if (qkind[i] == 4) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}