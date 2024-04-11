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

struct RMQ {
	int n;
	vector<ll> v;
	vector<int> lg;
	vector<vector<ll>> jump;

	void init(vector<ll>& _v) {
		v = _v; n = SZ(v);
		lg = vector<int>(n + 1); lg[1] = 0; FORE(i, 2, n) { lg[i] = lg[i - 1]; while ((2 << lg[i]) <= i) ++lg[i]; }
		jump = vector<vector<ll>>(n, vector<ll>(lg[n] + 1));
		REP(i, n) jump[i][0] = v[i];
		REP(k, lg[n]) REP(i, n) if (i + (2 << k) <= n) jump[i][k + 1] = min(jump[i][k], jump[i + (1 << k)][k]);

	}
	ll query(int l, int r) {
		assert(l <= r);
		int k = lg[r - l + 1];
		return min(jump[l][k], jump[r - (1 << k) + 1][k]);
	}
};

const int MAXN = 200000;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
ll operator^(const P& a, const P& b) { return (ll)a.x * b.y - (ll)a.y * b.x; }
int side(const P& a, const P& b, const P &c) { ll res = (b - a) ^ (c - a); return res < 0 ? -1 : res>0 ? +1 : 0; }

int n;
P p[MAXN];

ll solvehorizontallyseparated() {
	sort(p, p + n, [&](const P& a, const P& b) { return a.x < b.x; });
	vector<int> prefymn(n), prefymx(n), suffymn(n), suffymx(n);
	prefymn[0] = prefymx[0] = p[0].y, suffymn[n - 1] = suffymx[n - 1] = p[n - 1].y;
	FOR(i, 1, n) prefymn[i] = min(prefymn[i - 1], p[i].y), prefymx[i] = max(prefymx[i - 1], p[i].y);
	for (int i = n - 2; i >= 0; --i) suffymn[i] = min(suffymn[i + 1], p[i].y), suffymx[i] = max(suffymx[i + 1], p[i].y);

	ll ret = LLONG_MAX;
	REP(i, n - 1) {
		ll a = (ll)(p[i].x - p[0].x) * (prefymx[i] - prefymn[i]);
		ll b = (ll)(p[n - 1].x - p[i + 1].x) * (suffymx[i + 1] - suffymn[i + 1]);
		ret = min(ret, a + b);
	}
	return ret;
}

ll solvecrosswithtopfixedonright() {
	sort(p, p + n, [&](const P& a, const P& b) { return a.x < b.x; });
	vector<int> prefymn(n), prefymx(n), suffymn(n), suffymx(n);
	prefymn[0] = prefymx[0] = p[0].y, suffymn[n - 1] = suffymx[n - 1] = p[n - 1].y;
	FOR(i, 1, n) prefymn[i] = min(prefymn[i - 1], p[i].y), prefymx[i] = max(prefymx[i - 1], p[i].y);
	for (int i = n - 2; i >= 0; --i) suffymn[i] = min(suffymn[i + 1], p[i].y), suffymx[i] = max(suffymx[i + 1], p[i].y);
	int xmn = INT_MAX, ymn = INT_MAX, xmx = INT_MIN, ymx = INT_MIN;
	REP(i, n) xmn = min(xmn, p[i].x), ymn = min(ymn, p[i].y), xmx = max(xmx, p[i].x), ymx = max(ymx, p[i].y);

	ll ret = LLONG_MAX;
	int h = ymx - ymn, w = xmx - xmn;
	vector<ll> z(n - 1); REP(i, n - 1) z[i] = -((ll)h * p[i + 1].x + (ll)w * prefymn[i]);
	RMQ rmq; rmq.init(z);

	int j1 = -1;
	int lj2 = 0, rj2 = -1;
	FOR(i, 1, n - 1) { // h*(rx-lx)+w*(uy-dy)
		int rx = p[i].x, uy = suffymx[i + 1];
		int dy1 = suffymn[i + 1];
		// maximize j1 st prefymn[j1]>=dy1 && prefymx[j1]<=uy
		if (j1 + 1 == i - 1) ++j1;
		while (j1 >= 0 && (prefymn[j1]<dy1 || prefymx[j1]>uy)) --j1;
		if (j1 >= 0) {
			int lx = p[j1 + 1].x;
			ret = min(ret, (ll)h * (rx - lx) + (ll)w * (uy - dy1));
		}
		if (rj2 + 1 == i - 1) ++rj2;
		while (rj2 >= 0 && prefymx[rj2] > uy) --rj2;
		if (lj2 == i - 1) ++lj2;
		while (lj2 - 1 >= 0 && prefymn[lj2 - 1] < dy1) --lj2;
		// minimize h*(rx-p[j2+1].x)+w*(uy-prefymn[j2]) st lj2<=j2<=rj2 -> minimize -(h*p[j2+1].x+w*prefymn[j2])
		if (lj2 <= rj2) {
			ll cur = (ll)h * rx + (ll)w * uy + rmq.query(lj2, rj2);
			//printf("i=%d: rx=%d uy=%d -> j2 in %d..%d -> rmq=%lld -> %lld\n", i, rx, uy, lj2, rj2, rmq.query(lj2, rj2), cur);
			ret = min(ret, cur);
		}
	}
	return ret;
}

// after rev: x goes up, y goes down, a goes down, b goes up
struct LinearHull {
	bool rev; char name;
	vector<P> stck;
	void clear() { 
		//printf("\t%c: clear\n", name);
		stck.clear();
	}
	void add(P p) { 
		if (rev) swap(p.x, p.y); 
		//printf("\t%c: add (%d,%d)\n", name, p.x, p.y);
		while (SZ(stck) >= 1 && stck[SZ(stck) - 1].x <= p.x && stck[SZ(stck) - 1].y <= p.y || SZ(stck) >= 2 && side(stck[SZ(stck) - 2], stck[SZ(stck) - 1], p) >= 0) stck.pop_back();
		stck.PB(p);
	}
	ll query(ll a, ll b) { 
		if (rev) swap(a, b); 
		//printf("\t%c:  query(%lld %lld)\n", name, a, b); 
		//ll ret = LLONG_MIN; REPSZ(i, stck) ret = max(ret, a * stck[i].x + b * stck[i].y); return ret;
		while (SZ(stck) >= 2 && a * stck[SZ(stck) - 2].x + b * stck[SZ(stck) - 2].y >= a * stck[SZ(stck) - 1].x + b * stck[SZ(stck) - 1].y) stck.pop_back();
		assert(SZ(stck) >= 1); return a * stck[SZ(stck) - 1].x + b * stck[SZ(stck) - 1].y;
	}
};

vector<ll> calc(vector<P> p, vector<pair<int, int>> ranges, vector<pair<int, int>> weights) {
	// p.x goes up, p.y goes down, l and r go up, a goes down, b goes up, a and b nonnegative
	//printf("calc:"); REPSZ(i, p) printf(" (%d,%d)", p[i].x, p[i].y); puts("");
	//printf("queries:"); REPSZ(i, ranges) printf(" (%d..%d,%d,%d)", ranges[i].first, ranges[i].second, weights[i].first, weights[i].second); puts("");
	vector<ll> ret(SZ(ranges), LLONG_MIN);
	/*REPSZ(i, ranges) {
		int l = ranges[i].first, r = ranges[i].second, a = weights[i].first, b = weights[i].second;
		FORE(j, l, r) ret[i] = max(ret[i], (ll)a * p[j].x + (ll)b * p[j].y);
	}*/
	if (SZ(ranges) == 0) return ret;
	int center = ranges[0].second + 1, nxt = center;
	LinearHull forward, backward; forward.rev = false, backward.rev = true; forward.name = 'F', backward.name = 'B';
	REPE(i, SZ(ranges)) {
		if (i == SZ(ranges) || ranges[i].first > center) {
			int prv = center - 1;
			for (int j = i - 1; j >= 0 && ranges[j].second >= center - 1; --j) {
				while (prv >= ranges[j].first) backward.add(p[prv--]);
				if (ranges[j].first <= center - 1) ret[j] = max(ret[j], backward.query(weights[j].first, weights[j].second));
			}
			if (i == SZ(ranges)) break;
			center = ranges[i].second + 1, nxt = center;
			forward.clear(), backward.clear();
		}
		while (nxt <= ranges[i].second) forward.add(p[nxt++]);
		if (ranges[i].second >= center) ret[i] = max(ret[i], forward.query(weights[i].first, weights[i].second));
	}

	//printf("->"); REPSZ(i, ret) printf(" %lld", ret[i]); puts("");
	return ret;
}

ll solveupperleftandlowerrightcorners() {
	sort(p, p + n, [&](const P& a, const P& b) { return a.x < b.x; });
	vector<int> prefymn(n), prefymx(n), suffymn(n), suffymx(n);
	prefymn[0] = prefymx[0] = p[0].y, suffymn[n - 1] = suffymx[n - 1] = p[n - 1].y;
	FOR(i, 1, n) prefymn[i] = min(prefymn[i - 1], p[i].y), prefymx[i] = max(prefymx[i - 1], p[i].y);
	for (int i = n - 2; i >= 0; --i) suffymn[i] = min(suffymn[i + 1], p[i].y), suffymx[i] = max(suffymx[i + 1], p[i].y);
	int xmn = INT_MAX, ymn = INT_MAX, xmx = INT_MIN, ymx = INT_MIN;
	REP(i, n) xmn = min(xmn, p[i].x), ymn = min(ymn, p[i].y), xmx = max(xmx, p[i].x), ymx = max(ymx, p[i].y);

	vector<P> z(n - 1); REP(i, n - 1) z[i] = P(p[i + 1].x, prefymn[i]);

	vector<pair<int, int>> queryranges;
	vector<pair<int, int>> queryweights;
	vector<ll> answers;

	ll ret = LLONG_MAX;
	REP(rep, 2) {
		int lj = 0;
		int at = 0;
		FOR(i, 1, n - 1) { // (arx-xmn)*(ymx-ady)+(xmx-blx)*(buy-ymn)
			int arx = p[i].x, buy = suffymx[i + 1];
			// minimize (arx-xmn)*(ymx-prefymn[j])+(xmx-p[j+1].x)*(buy-ymn) st j<i and prefymn[j]<=buy -> maximize p[j+1].x*(buy-ymn)+(arx-xmn)*prefymn[j]
			while (lj<i && prefymn[lj]>buy) ++lj;
			//FOR(j, lj, i) ret = min(ret, (ll)(arx - xmn) * (ymx - prefymn[j]) + (ll)(xmx - p[j + 1].x) * (buy - ymn));
			if (lj <= i - 1) {
				if (rep == 0) {
					queryranges.PB(MP(lj, i - 1));
					queryweights.PB(MP(buy - ymn, arx - xmn));
				} else {
					assert(queryranges[at] == MP(lj, i - 1) && queryweights[at] == MP(buy - ymn, arx - xmn));
					ll cur = (ll)(arx - xmn) * ymx + (ll)xmx * (buy - ymn) - answers[at++];
					ll want = LLONG_MAX; FOR(j, lj, i) want = min(want, (ll)(arx - xmn) * (ymx - prefymn[j]) + (ll)(xmx - p[j + 1].x) * (buy - ymn));
					//printf("have=%lld want=%lld\n", cur, want);
					ret = min(ret, cur);
				}
			}
		}
		if (rep == 0) answers = calc(z, queryranges, queryweights);
	}
	return ret;
}

ll solve() {
	int xmn = INT_MAX, ymn = INT_MAX, xmx = INT_MIN, ymx = INT_MIN;
	REP(i, n) xmn = min(xmn, p[i].x), ymn = min(ymn, p[i].y), xmx = max(xmx, p[i].x), ymx = max(ymx, p[i].y);
	ll ret = (ll)(xmx - xmn) * (ymx - ymn);
	REP(rep, 2) {
		ret = min(ret, solvehorizontallyseparated());
		swap(xmn, ymn), swap(xmx, ymx); REP(i, n) swap(p[i].x, p[i].y);
	}
	REP(rep, 2) {
		ret = min(ret, solvecrosswithtopfixedonright());
		REP(i, n) p[i].x = xmn + (xmx - p[i].x);
	}
	REP(rep, 2) {
		ret = min(ret, solveupperleftandlowerrightcorners());
		REP(i, n) p[i].x = xmn + (xmx - p[i].x);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%lld\n", solve());
}

ll solvestupid() {
	ll ret = LLONG_MAX;
	vector<int> allx, ally; REP(i, n) allx.PB(p[i].x), ally.PB(p[i].y);
	sort(allx.begin(), allx.end()); allx.erase(unique(allx.begin(), allx.end()), allx.end());
	sort(ally.begin(), ally.end()); ally.erase(unique(ally.begin(), ally.end()), ally.end());
	REPSZ(a, allx) FORSZ(b, a, allx) REPSZ(c, ally) FORSZ(d, c, ally) {
		int lx = allx[a], hx = allx[b], ly = ally[c], hy = ally[d];
		int mnx = INT_MAX, mny = INT_MAX, mxx = INT_MIN, mxy = INT_MIN; bool any = false;
		REP(i, n) {
			if (lx <= p[i].x && p[i].x <= hx && ly <= p[i].y && p[i].y <= hy) continue;
			any = true; mnx = min(mnx, p[i].x), mxx = max(mxx, p[i].x), mny = min(mny, p[i].y), mxy = max(mxy, p[i].y);
		}
		ll cur = (ll)(hx - lx) * (ll)(hy - ly);
		if (any) cur += (ll)(mxx - mnx) * (mxy - mny);
		ret = min(ret, cur);
	}
	return ret;
}

void stress() {
	int mxdim = 100, mxn = 20;
	REP(rep, 100000) {
		n = rnd() % mxn + 1;
		int dim = rnd() % mxdim + 1;
		REP(i, n) p[i].x = rnd() % dim, p[i].y = rnd() % dim;
		ll have = solve();
		ll want = solvestupid();
		if (have == want) { if (rep % 100 == 99) printf("."); continue; }
		printf("err have=%lld want=%lld\n", have, want);
		printf("%d\n", n); REP(i, n) printf("%d %d\n", p[i].x, p[i].y);
	}
}

int main() {
	//stress();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}