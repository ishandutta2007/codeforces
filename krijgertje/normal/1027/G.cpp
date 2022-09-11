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

struct Val {
	map<ll, int> fact;
	ll val;
	Val() { fact.clear(); val = 1; }
	void div(ll p) { assert(fact.count(p)); if (--fact[p] == 0) fact.erase(p); assert(val%p == 0); val /= p; }
};
//const ll B = (ll)1e4; ll mlt(ll x, ll y, ll mod) { if (y == 0) return 0; return (mlt(x, y / B, mod) * B + x * (y % B)) % mod; }
//ll mlt(ll a, ll b, ll mod) { if (mod <= (1LL<<31)) return a*b%mod; ll ret = 0; while (true) { if (b & 1) ret = (ret + a) % mod; if ((b >>= 1) == 0) return ret; a = (a + a) % mod; } }
ll mlt(ll a, ll b, ll mod) { if (b == 0 || a <= LLONG_MAX / b) return a*b%mod; ll ret = 0; while (true) { if (b & 1) if ((ret += a) >= mod) ret -= mod; if ((b >>= 1) == 0) return ret; if ((a += a) >= mod) a -= mod; } }
ll pw(ll x, ll n, ll mod) { x %= mod; ll ret = 1; while (true) { if (n & 1) ret = mlt(ret, x, mod); if ((n >>= 1) == 0) return ret; x = mlt(x, x, mod); } }

map<ll, map<ll, int>> mem;
map<ll, int> factorize(ll x) {
	if (mem.count(x)) return mem[x];
	//printf("factorizing %lld\n", x);
	ll ox = x;
	map<ll, int> ret;
	for (ll i = 2; i*i <= x; ++i) while (x%i == 0) x /= i, ++ret[i];
	if (x != 1) ++ret[x];
	//printf("factorized %lld\n", ox);
	return mem[ox] = ret;
}

void gendivisors(vector<Val> &lst, Val cur, map<ll, int>::iterator l, map<ll, int>::iterator r) {
	if (l == r) { lst.PB(cur); return; }
	gendivisors(lst, cur, next(l), r);
	REP(i, l->second) { cur.val *= l->first; cur.fact[l->first]++; gendivisors(lst, cur, next(l), r); }
}
vector<Val> divisors(map<ll, int> &fact) {
	vector<Val> ret;
	gendivisors(ret, Val(), fact.begin(), fact.end());
	return ret;
}

Val calcphi(Val mod) {
	Val ret; 
	for (auto it = mod.fact.begin(); it != mod.fact.end(); ++it) {
		map<ll, int> sub = factorize(it->first - 1);
		ret.val *= it->first - 1; for (auto subit = sub.begin(); subit != sub.end(); ++subit) ret.fact[subit->first] += subit->second;
		REP(i, it->second - 1) ret.val *= it->first; if (it->second - 1 > 0) ret.fact[it->first] += it->second - 1;
	}
	return ret;
}
ll solverelprime(Val mod, ll x) {
	if (mod.val == 1) return 1;
	Val phi = calcphi(mod);
	Val n = phi;
	assert(pw(x, n.val, mod.val) == 1);
	for (auto it = phi.fact.begin(); it != phi.fact.end(); ++it) {
		while (n.fact.count(it->first) && pw(x, n.val / it->first, mod.val) == 1) n.div(it->first);
	}
	return phi.val / n.val;
}

ll solve(ll mod, ll x) {
	auto fact = factorize(mod);
	auto dv = divisors(fact);
	//printf("dv:"); printf(" SZ=%d\n", SZ(dv)); //REPSZ(i, dv) printf(" %lld", dv[i].val); puts("");
	ll ret = 0;
	REPSZ(i, dv) ret += solverelprime(dv[i], x%dv[i].val);
	return ret;
}

void run() {
	ll mod, x;
	scanf("%lld%lld", &mod, &x);
	printf("%lld\n", solve(mod, x));
	// gcd(a*x,mod) == gcd(a,mod)
}

vector<vector<int>> bfsolve(int mod, int x) {
	vector<vector<int>> ret;
	vector<bool> seen(mod, false);
	REP(i, mod) if (!seen[i]) { ret.PB(vector<int>()); int at = i; while (!seen[at]) { ret.back().PB(at); seen[at] = true; at = (ll)at*x%mod; } }
	return ret;
}
void research() {
	FORE(mod, 2, 40) FOR(x, 1, mod) if (gcd(mod, x) == 1) {
		vector<vector<int>> grp = bfsolve(mod, x);
		printf("%2d %2d:", mod, x); REPSZ(i, grp) { if (i != 0) printf(" |"); REPSZ(j, grp[i]) printf(" %d", grp[i][j]); } puts("");
	}
}

void stress() {
	FORE(mod, 2, 1000) {
		FOR(x, 1, mod) if (gcd(mod, x) == 1) {
			ll have = solve(mod, x);
			ll want = SZ(bfsolve(mod, x));
			if (have == want) { printf("."); continue; }
			printf("mod=%d x=%d: have=%lld want=%lld\n", mod, x, have, want); return;
		}
		printf("done mod=%d\n", mod);
	}
}

int main() {
	clock_t tstart;
	//research();
	run();
	//stress();
	fprintf(stderr, "Took: %.2fs\n", (double)(clock() - tstart) / CLOCKS_PER_SEC);
	return 0;
}