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

const int MAXN = 3000;
const int MINVAL = 1;
const int MAXVAL = 200000;
const int MAXS = 4 * (MAXVAL - MINVAL + 1);
struct Seg { int l, r; };

int n;
Seg seg[MAXN];

int dpnested[MAXN];
int dpdisjoint[MAXN];


int sval[MAXS];
bool slazy[MAXS];

void sapply(int x) { slazy[x] = true; sval[x] = 0; }
void spush(int x) { if (slazy[x]) sapply(2 * x + 1), sapply(2 * x + 2), slazy[x] = false; }
void spull(int x) { sval[x] = max(sval[2 * x + 1], sval[2 * x + 2]); }
int sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; spush(x); int ret = 0;
		if (L <= m) ret = max(ret, sget(2 * x + 1, l, m, L, R));
		if (m + 1 <= R) ret = max(ret, sget(2 * x + 2, m + 1, r, L, R));
		return ret;
	}
}
void supd(int x, int l, int r, int IDX, int VAL) {
	if (l == r) {
		sval[x] = max(sval[x], VAL);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (IDX <= m) supd(2 * x + 1, l, m, IDX, VAL); else supd(2 * x + 2, m + 1, r, IDX, VAL);
		spull(x);
	}
}

void reset() {
	sapply(0);
}
int query(int x) {
	if (x > MAXVAL) return 0;
	return sget(0, MINVAL, MAXVAL, x, MAXVAL);
}
void update(int x, int val) {
	supd(0, MINVAL, MAXVAL, x, val);
}

int solve() {
	sort(seg, seg + n, [](const Seg& a, const Seg& b) { if (a.r != b.r) return a.r < b.r; return a.l > b.l; });
	//printf("seg:"); REP(i, n) printf(" %d..%d", seg[i].l, seg[i].r); puts("");
	REP(i, n) {
		dpnested[i] = 1;
		REP(j, i) if (seg[j].l >= seg[i].l) dpnested[i] = max(dpnested[i], dpdisjoint[j] + 1);
		reset();
		for (int j = i; j >= 0; --j) {
			dpdisjoint[j] = dpnested[j] + query(seg[j].r + 1);
			update(seg[j].l, dpdisjoint[j]);
		}
		//printf("%d: dpnested=%d dpdisjoint:", i, dpnested[i]); REPE(j, i) printf(" %d", dpdisjoint[j]); puts("");
	}
	int ret = 0; REP(i, n) ret = max(ret, dpdisjoint[i]); return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &seg[i].l, &seg[i].r);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}