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

const int MAXN = 300000;
const int MAXQ = 300000;

int n;
int aval[MAXN], bval[MAXN];
int nq;
int asz[MAXQ], bsz[MAXQ];
ll qans[MAXQ];

int delta[MAXN];
ll deltasum[MAXN + 1];

ll egcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) { x = 1, y = 0; return a; }
	ll g = egcd(b, a % b, y, x); y -= x * (a / b); return g;
}

void solve() {
	ll bsum = 0;
	REP(i, n) bsum += bval[i];
	REP(i, n) delta[i] = aval[i] - bval[i];
	sort(delta, delta + n);
	reverse(delta, delta + n);
	deltasum[0] = 0;
	REP(i, n) deltasum[i + 1] = deltasum[i] + delta[i];
	int npos = 0;
	REP(i, n) if (delta[i] > 0) ++npos;
	REP(i, nq) {
		int aw = asz[i], bw = bsz[i]; ll x, y;
		int g = egcd(aw, bw, x, y); // x*aw+y*bw=g
		if (n % g != 0) { qans[i] = -1; continue; }
		x *= n / g, y *= n / g; // x*aw+y*bw=n
		int xstep = bw / g, ystep = aw / g;
		if (x < 0) { ll t = (-x + xstep - 1) / xstep; x += t * xstep, y -= t * ystep; }
		if (y < 0) { ll t = (-y + ystep - 1) / ystep; x -= t * xstep, y += t * ystep; }
		if (x < 0 || y < 0) { qans[i] = -1; continue; }
		{ ll t = x / xstep; x -= t * xstep, y += t * ystep; }
		ll lim = y / ystep;
		int lx = x * aw, hx = (x + lim * xstep) * aw; ll step = (ll)xstep * aw;
		//printf("q%d: x=%d..%d step %lld\n", i, lx, hx, step);
		ll best = max(bsum + deltasum[lx], bsum + deltasum[hx]);
		if (lx < npos && hx > npos) {
			int t1 = (npos - lx) / step;
			best = max(best, bsum + deltasum[lx + t1 * step]);
			int t2 = (hx - npos) / step;
			best = max(best, bsum + deltasum[hx - t2 * step]);
		}
		qans[i] = best;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &aval[i], &bval[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &asz[i], &bsz[i]);
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}