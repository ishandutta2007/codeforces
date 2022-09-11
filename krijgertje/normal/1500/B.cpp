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


ll egcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) { x = 1, y = 0; return a; }
	ll g = egcd(b, a % b, y, x); y -= x * (a / b); return g;
}

pair<ll, ll> invcrt(ll a1, ll mod1, ll a2, ll mod2) {
	ll c1, c2, g = egcd(mod1, mod2, c1, c2); if ((a1 - a2) % g != 0) return MP(-1, -1);
	ll t = (a2 - a1) / g, lcm = mod1 / g * mod2, x = (a1 + c1 * t % (mod2 / g) * mod1) % lcm; if (x < 0) x += lcm; return MP(x, lcm);
}

const int MAXN = 500000;

int na, nb; ll want;
int a[MAXN];
int b[MAXN];

ll calc(int i, int j) { // t=x*na+i==y*nb+j
	pair<ll, ll> res = invcrt(i, na, j, nb);
	if (res == MP(-1LL, -1LL)) return -1LL;
	return res.first;
}

ll solve() {
	int mxval = a[0]; FOR(i, 1, na) mxval = max(mxval, a[i]); REP(i, nb) mxval = max(mxval, b[i]);
	vector<int> apos(mxval + 1, -1);
	REP(i, na) apos[a[i]] = i;
	vector<ll> samecol;
	REP(j, nb) {
		int i = apos[b[j]];
		if (i == -1) continue;
		ll t = calc(i, j);
		if (t == -1) continue;
		samecol.PB(t);
	}
	sort(samecol.begin(), samecol.end());
	ll period = (ll)na / gcd(na, nb) * nb;
	//printf("period=%lld\n", period);
	//printf("samecol:"); REPSZ(i, samecol) printf(" %lld", samecol[i]); puts("");
	
	ll diffcol = period - SZ(samecol);
	assert(diffcol != 0);
	ll full = want / diffcol, rem = want % diffcol;
	ll base = period * full, offset = rem;
	REPSZ(i, samecol) if (samecol[i] <= offset) ++offset;
	return base + offset;
}

void run() {
	scanf("%d%d%lld", &na, &nb, &want); --want;
	REP(i, na) scanf("%d", &a[i]), --a[i];
	REP(i, nb) scanf("%d", &b[i]), --b[i];
	printf("%lld\n", solve() + 1);
}

int main() {
	run();
	return 0;
}