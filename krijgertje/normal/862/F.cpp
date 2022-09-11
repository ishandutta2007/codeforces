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

const int MAXLEN = 100000;
const int MAXN = 100000;
const int MAXQ = 100000;
const int MAXTN = MAXLEN + 1;
const int MAXLG = 16;
const int MAXSN = 4 * (MAXN - 1);
const int MAXZN = 4 * MAXN;

typedef struct SN { int best; vector<int> preidx, sufidx; } SN;

int n, nq;
char buff[MAXLEN + 1];
string s[MAXN];

int qkind[MAXQ], ql[MAXQ], qr[MAXQ], qidx[MAXQ], qlen[MAXQ]; string qs[MAXQ];


int lcp[MAXN - 1];
SN sn[MAXSN];

void print(const SN &a) { printf("["); REPSZ(i, a.preidx) { if (i != 0) printf(","); printf("%d", a.preidx[i]); } printf("]["); REPSZ(i, a.sufidx) { if (i != 0) printf(","); printf("%d", a.sufidx[i]); } printf("]->%d", a.best); }
int calc(int l, int r, int mn) { return (r - l + 2)*mn; }
SN makesn(int idx) {
	SN ret;
	ret.best = calc(idx, idx, lcp[idx]);
	ret.preidx.PB(idx); ret.sufidx.PB(idx);
	return ret;
}
SN combine(const SN &a, const SN &b) {
	SN ret;
	ret.best = max(a.best, b.best);
	int ai = SZ(a.sufidx) - 1, bi = SZ(b.preidx) - 1;
	while (true) {
		if (lcp[a.sufidx[ai]] >= lcp[b.preidx[bi]]) {
			if (ai == 0) {
				REPE(i, bi) ret.preidx.PB(b.preidx[i]); REPSZ(i, a.preidx) if (lcp[a.preidx[i]] == lcp[ret.preidx.back()]) ret.preidx[SZ(ret.preidx) - 1] = a.preidx[i]; else ret.preidx.PB(a.preidx[i]);
				ret.sufidx = b.sufidx;
				break;
			}
			else {
				int cur = calc(a.sufidx[ai - 1] + 1, b.preidx[bi] - 1, lcp[a.sufidx[ai]]);
				if (cur>ret.best) ret.best = cur;
				--ai;
			}
		}
		else {
			if (bi == 0) {
				ret.preidx = a.preidx;
				REPE(i, ai) ret.sufidx.PB(a.sufidx[i]); REPSZ(i, b.sufidx) if (lcp[b.sufidx[i]] == lcp[ret.sufidx.back()]) ret.sufidx[SZ(ret.sufidx) - 1] = b.sufidx[i]; else ret.sufidx.PB(b.sufidx[i]);
				break;
			}
			else {
				int cur = calc(a.sufidx[ai] + 1, b.preidx[bi - 1] - 1, lcp[b.preidx[bi]]);
				if (cur>ret.best) ret.best = cur;
				--bi;
			}
		}
	}
	int l = ret.preidx.back(), r = ret.sufidx.back();
	ret.best = max(ret.best, calc(l, r, lcp[ret.preidx[0]]));
	FORSZ(i, 1, ret.preidx) ret.best = max(ret.best, calc(l, ret.preidx[i - 1] - 1, lcp[ret.preidx[i]]));
	FORSZ(i, 1, ret.sufidx) ret.best = max(ret.best, calc(ret.sufidx[i - 1] + 1, r, lcp[ret.sufidx[i]]));
	//printf("combine("); print(a); printf(","); print(b); printf(")="); print(ret); puts("");
	//if(SZ(ret.preidx)>2||SZ(ret.sufidx)>2) { printf("combine("); print(a); printf(","); print(b); printf(")="); print(ret); puts(""); }
	return ret;
}

void sinit(int x, int l, int r) {
	if (l == r) {
		sn[x] = makesn(l);
	}
	else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		sn[x] = combine(sn[2 * x + 1], sn[2 * x + 2]);
	}
}

void sset(int x, int l, int r, int IDX) {
	if (l == r) {
		sn[x] = makesn(l);
	}
	else {
		int m = l + (r - l) / 2;
		if (IDX <= m) sset(2 * x + 1, l, m, IDX); else sset(2 * x + 2, m + 1, r, IDX);
		sn[x] = combine(sn[2 * x + 1], sn[2 * x + 2]);
	}
}

SN sget(int x, int l, int r, int L, int R) {
	if (L <= l&&r <= R) return sn[x];
	int m = l + (r - l) / 2;
	if (R <= m) return sget(2 * x + 1, l, m, L, R);
	if (m + 1 <= L) return sget(2 * x + 2, m + 1, r, L, R);
	return combine(sget(2 * x + 1, l, m, L, R), sget(2 * x + 2, m + 1, r, L, R));
}

int len[MAXN];
int zn[MAXZN];

void zinit(int x, int l, int r) {
	if (l == r) {
		zn[x] = len[l];
	}
	else {
		int m = l + (r - l) / 2;
		zinit(2 * x + 1, l, m); zinit(2 * x + 2, m + 1, r);
		zn[x] = max(zn[2 * x + 1], zn[2 * x + 2]);
	}
}

void zset(int x, int l, int r, int IDX) {
	if (l == r) {
		zn[x] = len[l];
	}
	else {
		int m = l + (r - l) / 2;
		if (IDX <= m) zset(2 * x + 1, l, m, IDX); else zset(2 * x + 2, m + 1, r, IDX);
		zn[x] = max(zn[2 * x + 1], zn[2 * x + 2]);
	}
}

int zget(int x, int l, int r, int L, int R) {
	if (L <= l&&r <= R) return zn[x];
	int m = l + (r - l) / 2;
	if (R <= m) return zget(2 * x + 1, l, m, L, R);
	if (m + 1 <= L) return zget(2 * x + 2, m + 1, r, L, R);
	return max(zget(2 * x + 1, l, m, L, R), zget(2 * x + 2, m + 1, r, L, R));
}

int ans[MAXQ];

int calclcp(const string &a, const string &b) { int ret = 0; while (ret < SZ(a) && ret < SZ(b) && a[ret] == b[ret]) ++ret; return ret; }

void solve() {
	REP(i, n - 1) lcp[i] = calclcp(s[i], s[i + 1]);
	if (n >= 2) sinit(0, 0, n - 2);
	zinit(0, 0, n - 1);
	REP(i, nq) {
		if (qkind[i] == 1) {
			//printf("lcp:"); REP(j,n-1) printf(" %d",lcp[j]); puts("");
			ans[i] = zget(0, 0, n - 1, ql[i], qr[i]);
			if (ql[i] != qr[i]) {
				SN cur = sget(0, 0, n - 2, ql[i], qr[i] - 1);
				if (cur.best>ans[i]) ans[i] = cur.best;
			}
		}
		if (qkind[i] == 2) {
			int idx = qidx[i];
			s[idx] = qs[i];
			len[idx] = qlen[i];
			zset(0, 0, n - 1, idx);
			if (idx >= 1) {
				lcp[idx - 1] = calclcp(s[idx - 1], s[idx]);
				sset(0, 0, n - 2, idx - 1);
			}
			if (idx + 1<n) {
				lcp[idx] = calclcp(s[idx], s[idx + 1]);
				sset(0, 0, n - 2, idx);
			}
		}
	}
}


void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) { scanf("%s", buff); s[i] = buff, len[i] = SZ(s[i]); }
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 1) { scanf("%d%d", &ql[i], &qr[i]); --ql[i], --qr[i]; }
		if (qkind[i] == 2) { scanf("%d%s", &qidx[i], buff); --qidx[i], qs[i] = buff, qlen[i] = SZ(qs[i]); }
	}
	solve();
	REP(i, nq) if (qkind[i] == 1) printf("%d\n", ans[i]);
}

int main() {
	run();
	return 0;
}