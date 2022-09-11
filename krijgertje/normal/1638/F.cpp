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
#include <functional>
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

const int MAXN = 10000;
struct Block { int start; ll h; Block() {} Block(int start, ll h) :start(start), h(h) {} };

int n;
ll h[MAXN];

Block l[MAXN]; int nl;
Block r[MAXN]; int nr;
ll lpref[MAXN];
ll rpref[MAXN];

ll calcoverlap(int i, int j, ll common) {
	// (j-l[lidx].start+1)*min(common,l[lidx].h)+(r[ridx].start-i+1)*min(r[ridx].h,max(0,common-l[lidx].h))
	assert(nl == 0 || l[nl - 1].h <= common);
	assert(nr == 0 || r[nr - 1].h <= common);

	//printf("calcoverlap: %d..%d h=%lld\n", i, j, common);
	ll ret = (j - i + 1) * common;
	REP(k, nl) {
		ll me = min(common, l[k].h);
		ret = max(ret, (j - l[k].start + 1) * me + (j - i + 1) * (common - me));
	}
	REP(k, nr) {
		ll me = min(common, r[k].h);
		ret = max(ret, (r[k].start - i + 1) * me + (j - i + 1) * (common - me));
	}

	REP(ridx, nr) rpref[ridx] = (r[ridx].start - i + 1) * r[ridx].h;
	FOR(ridx, 1, nr) rpref[ridx] = max(rpref[ridx], rpref[ridx - 1]);
	for (int lidx = 0, ridx = nr - 1; lidx < nl; ++lidx) {
		while (ridx >= 0 && l[lidx].h + r[ridx].h > common) --ridx;
		if (ridx >= 0) ret = max(ret, (j - l[lidx].start + 1) * l[lidx].h + rpref[ridx]);
		if (ridx + 1 < nr) ret = max(ret, (j - l[lidx].start + 1) * l[lidx].h + (r[ridx + 1].start - i + 1) * (common - l[lidx].h));
	}

	REP(lidx, nl) lpref[lidx] = (j - l[lidx].start + 1) * l[lidx].h;
	FOR(lidx, 1, nl) lpref[lidx] = max(lpref[lidx], lpref[lidx - 1]);
	for (int ridx = 0, lidx = nl - 1; ridx < nr; ++ridx) {
		while (lidx >= 0 && l[lidx].h + r[ridx].h > common) --lidx;
		if (lidx >= 0) ret = max(ret, lpref[lidx] + (r[ridx].start - i + 1) * r[ridx].h);
		if (lidx + 1 < nl) ret = max(ret, (j - l[lidx + 1].start + 1) * (common - r[ridx].h) + (r[ridx].start - i + 1) * r[ridx].h);
	}

	return ret;
}

ll calcsub(int i, int j, ll common) {
	//printf("calcsub: %d..%d h=%lld\n", i, j, common);
	ll ret = 0;
	int lidx = nl - 1, ridx = nr - 1;
	while (lidx >= 0 && ridx >= 0) {
		ll me = min(common, min(l[lidx].h, r[ridx].h));
		ll mx = max(l[lidx].h, r[ridx].h);
		ret = max(ret, (r[ridx].start - l[lidx].start + 1) * me + (j - i + 1) * (common - me));
		if (lidx == 0 && ridx == 0) break;
		if (lidx == 0 || (ridx != 0 && l[lidx - 1].h < r[ridx - 1].h)) --ridx; else --lidx;
	}
	return ret;
}

ll mn[MAXN];

ll calccommon() {
	ll ret = 0;

	nl = 0;
	REP(i, n) {
		mn[i] = h[i];
		FOR(j, i + 1, n) mn[j] = min(mn[j - 1], h[j]);

		nr = 0;
		for (int j = n - 1; j >= i; --j) {
			ll common = mn[j];
			if ((i == 0 || h[i - 1] < common) && (j == n - 1 || h[j + 1] < common)) {
				ret = max(ret, calcoverlap(i, j, common));
				ret = max(ret, calcsub(i, j, common));
			}

			int rstart = j;
			while (nr >= 1 && h[j] <= r[nr - 1].h) {
				rstart = r[nr - 1].start;
				--nr;
			}
			r[nr++] = Block(rstart, h[j]);
		}

		int lstart = i;
		while (nl >= 1 && h[i] <= l[nl - 1].h) {
			lstart = l[nl - 1].start;
			--nl;
		}
		l[nl++] = Block(lstart, h[i]);
	}

	return ret;
}

ll calcdisjoint() {
	nr = 0;
	vector<ll> suffmax(n + 1, 0);
	for (int j = n - 1; j >= 0; --j) {
		int rstart = j;
		while (nr >= 1 && h[j] <= r[nr - 1].h) {
			rstart = r[nr - 1].start;
			--nr;
		}
		r[nr++] = Block(rstart, h[j]);
		suffmax[j] = suffmax[j + 1];
		REP(k, nr) suffmax[j] = max(suffmax[j], (r[k].start - j + 1) * r[k].h);
	}
	ll ret = 0;
	nl = 0;
	REP(i, n) {
		int lstart = i;
		while (nl >= 1 && h[i] <= l[nl - 1].h) {
			lstart = l[nl - 1].start;
			--nl;
		}
		l[nl++] = Block(lstart, h[i]);
		REP(k, nl) ret = max(ret, (i - l[k].start + 1) * l[k].h + suffmax[i + 1]);
	}
	return ret;
}

ll solve() {
	return max(calccommon(), calcdisjoint());
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%lld", &h[i]);
	printf("%lld\n", solve());
}

ll solvestupid() {
	ll ret = 0;
	REP(a, n) FOR(b, a, n) {
		ll x = LLONG_MAX;
		FORE(i, a, b) x = min(x, h[i]);
		ret = max(ret, (b - a + 1) * x);
		FOR(c, a, n) FOR(d, c, n) {
			ll y = LLONG_MAX;
			FORE(i, c, d) y = min(y, h[i]);
			if (c > b) {
				ll cur = (b - a + 1) * x + (d - c + 1) * y;
				ret = max(ret, cur);
			} else if (d <= b) {
				assert(y >= x);
				ll cur = (b - a + 1) * x + (d - c + 1) * (y - x);
				ret = max(ret, cur);
			} else if (c == a) {
				assert(x >= y);
				ll cur = (b - a + 1) * (x - y) + (d - c + 1) * y;
				ret = max(ret, cur);
			} else {
				assert(a < c && c <= b && b < d);
				ll x = LLONG_MAX, y = LLONG_MAX, z = LLONG_MAX;
				FORE(i, a, c - 1) x = min(x, h[i]);
				FORE(i, c, b) y = min(y, h[i]);
				FORE(i, b + 1, d) z = min(z, h[i]);
				x = min(x, y);
				z = min(z, y);
				if (x + z > y) {
					if (c - a >= d - b) {
						z = y - x;
					} else {
						x = y - z;
					}
				}
				ll cur = (b - a + 1) * x + (d - c + 1) * z;
				//if (cur == 27) printf("%d..%d %d..%d -> %lld\n", a, b, c, d, cur);
				ret = max(ret, cur);
			}
		}
	}
	return ret;
}

void stress() {
	std::mt19937 rnd(1231);
	int mxn = 10;
	int hlim = 10;
	REP(rep, 1000000) {
		n = rnd() % mxn + 1;
		REP(i, n) h[i] = rnd() % hlim + 1;
		//if (rep != 936) continue;
		ll have = solve();
		ll want = solvestupid();
		if (have == want) { if (rep % 1000 == 999) printf("."); continue; }
		printf("err have=%lld want=%lld rep=%d\n", have, want, rep);
		printf("%d\n", n);
		REP(i, n) { if (i != 0) printf(" "); printf("%lld", h[i]); } puts("");
		break;
	}
}

void stresstime() {
	REP(rep, 1) {
		n = MAXN;
		REP(i, n) h[i] = min(i + 1, n - i);
		ll have = solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	//stresstime();
	return 0;
}