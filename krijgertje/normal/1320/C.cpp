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

const int MAXN = 200000;
const int MAXS = 4 * MAXN;
struct Item { int val, cost; };
bool operator<(const Item& a, const Item& b) { return a.val < b.val; }
struct P { int x, y, z; };
bool operator<(const P& a, const P& b) { return a.x < b.x; }

ll best[MAXN];
ll smx[MAXS], slazy[MAXS];
void sapply(int x, int by) { if (smx[x] != LLONG_MIN) smx[x] += by; slazy[x] += by; }
void spush(int x) { if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0; }
void spull(int x) { smx[x] = max(smx[2 * x + 1], smx[2 * x + 2]); }
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) { smx[x] = best[l]; } else { int m = l + (r - l) / 2; sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r); spull(x); }
}
void sinc(int x, int l, int r, int L, int R,int BY) {
	if (L <= l && r <= R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) sinc(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) sinc(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}

int na, nb, np;
Item a[MAXN];
Item b[MAXN];
P p[MAXN];

int yy[MAXN], nyy;

ll solve() {
	sort(a, a + na);
	sort(b, b + nb);
	sort(p, p + np);
	
	nyy = 0; REP(i, nb) yy[nyy++] = b[i].val; sort(yy, yy + nyy); nyy = unique(yy, yy + nyy) - yy;
	REP(i, nyy) best[i] = LLONG_MIN;
	REP(i, nb) { int idx = lower_bound(yy, yy + nyy, b[i].val) - yy; best[idx] = max(best[idx], -(ll)b[i].cost); }
	sinit(0, 0, nyy - 1);

	int atp = 0;
	ll ret = LLONG_MIN;
	REP(i, na) {
		while (atp < np && p[atp].x < a[i].val) { int idx = upper_bound(yy, yy + nyy, p[atp].y) - yy; if (idx < nyy) sinc(0, 0, nyy - 1, idx, nyy - 1, p[atp].z); ++atp; }
		ll cur = smx[0] - a[i].cost;
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &na, &nb, &np);
	REP(i, na) scanf("%d%d", &a[i].val, &a[i].cost);
	REP(i, nb) scanf("%d%d", &b[i].val, &b[i].cost);
	REP(i, np) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}