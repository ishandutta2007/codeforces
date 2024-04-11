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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXBIT = 63;
const int MAXLOGBIT = 5;

ull nimpwprod[MAXBIT + 1][MAXBIT + 1];

ull order;
vector<ull> porder;

void precalc() {
	REPE(i, MAXBIT) REPE(j, MAXBIT) {
		int k = 0; while (k <= MAXLOGBIT && (((i >> k) & 1) == 0 || ((j >> k) & 1) == 0)) ++k;
		if (k > MAXLOGBIT) { nimpwprod[i][j] = 1ULL << (i + j); continue; }
		int ni = i ^ (1 << k), nj = j ^ (1 << k); REP(kk, k) { if (((i >> kk) & 1) == 0) ni ^= 1 << kk; else if (((j >> kk) & 1) == 0) nj ^= 1 << kk; else assert(false); }
		nimpwprod[i][j] = nimpwprod[i][j ^ (1 << k)] ^ nimpwprod[ni][nj];
	}
	order = (ull)-1;
	//printf("order=%llu\n", order);
	porder.clear();
	ull tmp = order;
	for (ull x = 2; x <= tmp / x; ++x) while (tmp % x == 0) { porder.PB(x); tmp /= x; }
	if (tmp != 1) porder.PB(tmp);
	//printf("porder:"); REPSZ(i, porder) printf(" %llu", porder[i]); puts("");
}

ull nimsum(ull a, ull b) { return a ^ b; }
ull nimprod(ull a, ull b) { ull ret = 0; REPE(i, MAXBIT) if (((a >> i) & 1) != 0) REPE(j, MAXBIT) if (((b >> j) & 1) != 0) ret ^= nimpwprod[i][j]; return ret; }
ull nimpw(ull x, ull n) { ull ret = 1; while (true) { if (n & 1) ret = nimprod(ret, x); if ((n >>= 1) == 0) return ret; x = nimprod(x, x); } return ret; }
ull niminv(ull x) { assert(x != 0); return nimpw(x, (ull)-2); }


ll egcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) { x = 1, y = 0; return a; }
	ll g = egcd(b, a % b, y, x); y -= x * (a / b); return g;
}

pair<ull, ull> invcrt(ll a1, ll mod1, ll a2, ll mod2) {
	if (mod1 < mod2) swap(a1, a2), swap(mod1, mod2);
	ll c1, c2, g = egcd(mod1, mod2, c1, c2); 
	if ((a1 - a2) % g != 0) assert(false);
	ll t = (a2 - a1) / g; ull lcm = mod1 / g * mod2;
	bool neg = false; ull v1, v2; if (c1 >= 0) v1 = c1; else v1 = -c1, neg = !neg; if (t >= 0) v2 = t; else v2 = -t, neg = !neg;
	ull ret = v1 * v2 % (mod2 / g) * mod1; if (neg) ret = ret == 0 ? 0 : lcm - ret; if (a1 < lcm - ret) ret += a1; else ret = a1 - (lcm - ret);
	return MP(ret, lcm);
}
pair<ull, ull> invcrt(vector<ull> a, vector<ull> mod) {
	pair<ull, ull> ret = MP(a[0], mod[0]); FORSZ(i, 1, a) ret = invcrt(ret.first, ret.second, a[i], mod[i]); return ret;
}



bool calc(ull a, ull b, int period, ull& x) {
	// step=ceil(sqrt(period)), a^(u*step+v)=b -> a^(u*step)*a^v=b -> a^v=b*inv(a^step)^u, u*step+v<period -> u<step and v<step
	int step = ceil(sqrt(1.0 * period));
	ull t = niminv(nimpw(a, step));
	vector<pair<ull, int>> seen(step);
	ull tmp = b; REP(i, step) { seen[i] = MP(tmp, i * step); tmp = nimprod(tmp, t); }
	sort(seen.begin(), seen.end());
	vector<ull> tested(step);
	tmp = 1;
	REP(i, step) {
		int lo = -1, hi = SZ(seen); while (lo + 1 < hi) { int mi = lo + (hi - lo) / 2; if (seen[mi].first >= tmp) hi = mi; else lo = mi; } if (hi<SZ(seen) && seen[hi].first == tmp) { x = i + seen[hi].second; return true; }
		tested[i] = tmp;
		tmp = nimprod(tmp, a);
	}
	//printf("\t\tstep=%d t=%llu\n", step, t);
	//printf("\t\tseen:"); REPSZ(i, seen) printf(" %llu", seen[i].first); puts("");
	//printf("\t\ttested:"); REPSZ(i, tested) printf(" %llu", tested[i]); puts("");
	return false;
}

ull a, b;
ull x;

bool solve() {
	// a^(up+v)=b -> (a^(order/p))^v=b^(order/p)
	//printf("a=%llu b=%llu\n", a, b);
	vector<ull> xx(SZ(porder));
	REPSZ(i, porder) {
		ull p = porder[i];
		ull aa = nimpw(a, order / p), bb = nimpw(b, order / p);
		bool found = calc(aa, bb, p, xx[i]);
		//printf("%llu -> aa=%llu bb=%llu -> xx=%llu (%s)\n", p, aa, bb, xx[i], found ? "OK" : "ERR");
		if (!found) return false;
	}
	pair<ull, ull> res = invcrt(xx, porder);
	x = res.first;
	//printf("res=(%llu %llu) [%llu vs %llu]\n", res.first, res.second, nimpw(a, x), b);
	return true;
}

void run() {
	scanf("%llu%llu", &a, &b);
	if (!solve()) { printf("-1\n"); return; }
	printf("%llu\n", x);
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}