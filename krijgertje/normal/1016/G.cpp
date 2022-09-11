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

const int MAXN = 200000;

int n; ll X, Y;
ll a[MAXN];

vector<ll> atoms;
void process(ll x) {
	ll ox = x;
	REPSZ(i, atoms) {
		while (x!=1) {
			if (x%atoms[i] == 0) { x /= atoms[i]; continue; }
			ll g = gcd(x, atoms[i]); if (g == 1) break; x /= g;
			vector<ll> q; q.PB(atoms[i] / g); q.PB(g);
			while (SZ(q) >= 2) {
				ll a = q[SZ(q) - 2], c = q[SZ(q) - 1], b = gcd(a, c);
				//printf("q:"); REPSZ(j, q) printf(" %lld", q[j]); printf(" -> %lld\n", b);
				if (b == 1) { atoms.PB(c); q.pop_back(); continue; }
				if (a == c) { q.pop_back(); continue; }
				if (c == b) { q[SZ(q) - 2] = a / b, q[SZ(q) - 1] = b; continue; }
				if (a == b) { q[SZ(q) - 2] = b, q[SZ(q) - 1] = c / b; continue; }
				q[SZ(q) - 2] = a / b, q[SZ(q) - 1] = b, q.PB(c / b);
			}
			atoms[i] = q[0];
		}
	}
	if (x != 1) atoms.PB(x);
	//printf("atoms after %lld:", ox); REPSZ(i, atoms) printf(" %lld", atoms[i]); puts("");
}

ll solve() {
	if (Y%X != 0) return 0;

	atoms.clear();
	process(Y / X); REP(i, n) process(gcd(Y / X, a[i]));

	vector<int> acnt(1 << SZ(atoms), 0);
	vector<int> bcnt(1 << SZ(atoms), 0);
	REP(i, n) {
		if (a[i] % X != 0) continue;
		int mask = 0; REPSZ(k, atoms) if ((a[i] / X) % atoms[k] == 0) mask |= 1 << k;
		//printf("amask=%x\n", mask);
		++acnt[mask];
	}
	REP(j, n) {
		if (Y%a[j] != 0) continue;
		int mask = 0; REPSZ(k, atoms) if ((Y / a[j]) % atoms[k] == 0) mask |= 1 << k;
		//printf("bmask=%x\n", mask);
		++bcnt[mask];
	}
	vector<int> asum = acnt; REPSZ(k, atoms) REPSZ(mask, asum) if ((mask&(1 << k)) != 0) asum[mask] += asum[mask ^ (1 << k)];
	//printf("asum:"); REPSZ(i, asum) printf(" %d", asum[i]); puts("");
	ll ret = 0; REP(mask, 1 << SZ(atoms)) ret += (ll)asum[(1 << SZ(atoms)) - 1 - mask] * bcnt[mask];
	return ret;
}

void run() {
	scanf("%d%lld%lld", &n, &X, &Y);
	REP(i, n) scanf("%lld", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}