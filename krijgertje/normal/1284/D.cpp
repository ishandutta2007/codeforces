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

const int MAXN = 100000;
const int MAXS = 4 * 2 * MAXN;
struct Seg { int l, r; };
struct E { int x, kind, ly, hy; E() {} E(int x, int kind, int ly, int hy) :x(x), kind(kind), ly(ly), hy(hy) {} };
bool operator<(const E& a, const E& b) { if (a.x != b.x) return a.x < b.x; if (a.kind != b.kind) return a.kind < b.kind; return false; }

int n;
Seg a[MAXN], b[MAXN];

vector<E> e;
vector<int> aa; int naa;
vector<int> bb; int nbb;

int slen;
bool slazy[MAXS]; int sval[MAXS];
void sapply(int x, int len) { slazy[x] = true; sval[x] = len; }
void spush(int x, int l, int m, int r) { if (slazy[x]) sapply(2 * x + 1, m - l + 1), sapply(2 * x + 2, r - m), slazy[x] = false; }
void spull(int x) { sval[x] = sval[2 * x + 1] + sval[2 * x + 2]; }
void sinit(int x, int l, int r) {
	slazy[x] = false;
	if (l == r) {
		sval[x] = 0;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
int sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2, ret = 0; spush(x, l, m, r);
		if (L <= m) ret += sget(2 * x + 1, l, m, L, R);
		if (m + 1 <= R) ret += sget(2 * x + 2, m + 1, r, L, R);
		return ret;
	}
}
void smod(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		sapply(x, r - l + 1);
	} else {
		int m = l + (r - l) / 2; spush(x, l, m, r);
		if (L <= m) smod(2 * x + 1, l, m, L, R);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R);
		spull(x);
	}
}


void initblocked(int len) { slen = len; sinit(0, 0, slen - 1); }
bool anyblocked(int l, int r) { return sget(0, 0, slen - 1, l, r) > 0; }
void blockrange(int l, int r) { smod(0, 0, slen - 1, l, r); }



bool solve() {
	aa = vector<int>(2 * n); naa = 0; REP(i, n) aa[naa++] = a[i].l, aa[naa++] = a[i].r; sort(aa.begin(), aa.begin() + naa); naa = unique(aa.begin(), aa.begin() + naa) - aa.begin(); REP(i, n) a[i].l = lower_bound(aa.begin(), aa.begin() + naa, a[i].l) - aa.begin(), a[i].r = lower_bound(aa.begin(), aa.begin() + naa, a[i].r) - aa.begin();
	bb = vector<int>(2 * n); nbb = 0; REP(i, n) bb[nbb++] = b[i].l, bb[nbb++] = b[i].r; sort(bb.begin(), bb.begin() + nbb); nbb = unique(bb.begin(), bb.begin() + nbb) - bb.begin(); REP(i, n) b[i].l = lower_bound(bb.begin(), bb.begin() + nbb, b[i].l) - bb.begin(), b[i].r = lower_bound(bb.begin(), bb.begin() + nbb, b[i].r) - bb.begin();


	REP(rep, 2) {
		e.clear();
		REP(i, n) e.PB(E(a[i].l, 0, b[i].l, b[i].r)), e.PB(E(a[i].r, 1, b[i].l, b[i].r));
		sort(e.begin(), e.end());
		initblocked(nbb);
		REPSZ(i, e) {
			int kind = e[i].kind, ly = e[i].ly, hy = e[i].hy;
			if (kind == 0) {
				if (anyblocked(ly, hy)) return false;
			} else {
				blockrange(ly, hy);
			}
		}
		REP(i, n) swap(a[i], b[i]);
		swap(aa,bb); swap(naa,nbb);
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d%d%d", &a[i].l, &a[i].r, &b[i].l, &b[i].r);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}