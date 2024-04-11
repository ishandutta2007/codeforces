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

const int MAXQ = 10000;
const ll MAXK = 1000000000000000LL;

vector<int> plst;

int nq;
ll qn[MAXQ], qk[MAXQ];
bool ans[MAXQ];

map<ll, vector<int>> byk;

void precalc() {
	int upto = (int)sqrt(1.0*MAXK);
	vector<bool> isp(upto + 1, true); isp[0] = isp[1] = false; FORE(i, 2, upto) { if (isp[i]) plst.PB(i); REPSZ(j, plst) { if (i*plst[j] > upto) break; isp[i*plst[j]] = false; if (i%plst[j] == 0) break; } }
}
vector<ll> factorize(ll x) {
	vector<ll> ret;
	REPSZ(i, plst) { if (plst[i] > x) break; if (x%plst[i] == 0) { ret.PB(plst[i]); while (x%plst[i] == 0) x /= plst[i]; } }
	if (x != 1) ret.PB(x);
	return ret;
}

ll egcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) { x = 1, y = 0; return a; }
	ll g = egcd(b, a%b, y, x); y -= (a / b)*x; return g;
}
bool solve2(ll p, ll q, ll x, ll a,ll b,ll g) {
	if (x%g != 0) return false;
	p /= g, q /= g, x /= g;
	while (a <= 0) { a += q, b -= p; }
	//printf("%lld*%lld+%lld*%lld=%lld (%lld)\n", a, p, b, q, g, x);
	ll aa = (a%q)*(x%q) % q;
	assert((x - aa*p) % q == 0);
	ll bb = (x - aa*p) / q;
	//printf("-> aa=%lld bb=%lld\n", aa, bb);
	return bb >= 0;
}

void run() {
	precalc();

	scanf("%d", &nq); REP(i, nq) scanf("%lld%lld", &qn[i], &qk[i]);

	REP(i, nq) byk[qk[i]].PB(i);
	for (auto it = byk.begin(); it != byk.end(); ++it) {
		ll k = it->first;
		vector<ll> p = factorize(k);
		//printf("k=%lld:", k); REPSZ(i, p) printf(" %lld", p[i]); puts("");
		if (SZ(p) == 0) {
			REPSZ(i, it->second) { int idx = it->second[i]; ans[idx] = false; }
		} else if (SZ(p) == 1) {
			REPSZ(i, it->second) { int idx = it->second[i]; ans[idx] = qn[idx] % p[0] == 0; }
		} else if (SZ(p) == 2) {
			ll a, b, g = egcd(p[1], p[0], a, b); // a*p+b*q=g
			REPSZ(i, it->second) { int idx = it->second[i]; ans[idx] = solve2(p[1], p[0], qn[idx], a, b, g); }
		} else {
			int mod = p[0];
			vector<ll> d(mod, LLONG_MAX); priority_queue<pair<ll, int>> pq; d[0] = 0; pq.push(MP(-d[0], 0));
			while (!pq.empty()) {
				ll cost = -pq.top().first; int at = pq.top().second; pq.pop();
				if (cost != d[at]) continue;
				FORSZ(i, 1, p) { int to = (at + p[i]) % mod; ll ncost = cost + p[i]; if (ncost < d[to]) d[to] = ncost, pq.push(MP(-d[to], to)); }
			}
			REPSZ(i, it->second) { int idx = it->second[i]; ans[idx] = d[qn[idx] % mod] <= qn[idx]; }
		}
	}
	REP(i, nq) printf("%s\n", ans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}