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

const int MAXA = 400000;
const int MAXV = MAXA + 1;

ll len; int na; ll ncut;
ll a[MAXA];

ll v[MAXV]; int nv;

ll calcmnatmost(ll lim) {
	ll ret = 0;
	REP(i, nv) {
		ll npart = (v[i] + lim - 1) / lim;
		ret += npart - 1;
	}
	//printf("\tmnatmost: %lld -> %lld\n", lim, ret);
	return ret;
}
ll calcmxatleast(ll lim) {
	ll ret = 0;
	REP(i, nv) {
		ll npart = v[i] / lim;
		ret += npart - 1;
	}
	//printf("\tmxatleast: %lld -> %lld\n", lim, ret);
	return ret;
}

pair<ll, ll> extra[MAXV]; int nextra;
ll after[MAXV];

ll solve() {
	nv = 0; if (na == 0) { v[nv++] = len; } else { v[nv++] = a[0]; REP(i, na - 1) v[nv++] = a[i + 1] - a[i]; v[nv++] = len - a[na - 1]; }
	//printf("v:"); REP(i, nv) printf(" %lld", v[i]); puts("");

	ll L, R;
	{ ll lo = 0, hi = len; while (lo + 1 < hi) { ll mi = lo + (hi - lo) / 2; if (calcmnatmost(mi) > ncut) lo = mi; else hi = mi; } R = hi; }
	{ ll lo = 0, hi = len + 1; REP(i, nv) hi = min(hi, v[i] + 1); while (lo + 1 < hi) { ll mi = lo + (hi - lo) / 2; if (calcmxatleast(mi) < ncut) hi = mi; else lo = mi; } L = lo; }
	//printf("%lld..%lld\n", L, R);

	nextra = 0;
	REP(i, nv) {
		ll xpart = v[i] / L;
		ll vx = (v[i] + xpart - 1) / xpart;
		ll ypart = (v[i] + R - 1) / R;
		ll vy = v[i] / ypart;
		assert(vx >= L && vy <= R);
		//printf("\t%lld -> %lld vs %lld -> %lld..%lld\n", v[i], xpart, ypart, vx, vy);
		extra[nextra++] = MP(max(0LL, vx - R), max(0LL, L - vy));
	}
	sort(extra, extra + nextra);
	//printf("extra:"); REP(i, nextra) printf(" (%lld,%lld)", extra[i].first, extra[i].second); puts("");
	if (nextra >= 1) after[nextra - 1] = 0;
	for (int i = nextra - 2; i >= 0; --i) after[i] = max(after[i + 1], extra[i + 1].second);
	ll best = nextra == 0 ? 0 : max(after[0], extra[0].second);
	REP(i, nextra) {
		ll cur = extra[i].first + after[i];
		best = min(best, cur);
	}
	ll ret = R - L + best;
	return ret;
}

void run() {
	scanf("%lld%d%lld", &len, &na, &ncut);
	REP(i, na) scanf("%lld", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}