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

struct BIT {
	int n; vector<ll> bit;
	void init(int _n) { n = _n; bit = vector<ll>(n, 0); }
	void add(int idx, ll val) { while (idx < n) { bit[idx] += val; idx |= idx + 1; } }
	ll prefixsum(int idx) { ll ret = 0; while (idx >= 0) { ret += bit[idx]; idx = (idx & (idx + 1)) - 1; } return ret; }
};


const int MAXN = 200000;

int n;
int a[MAXN];

int v[MAXN], nv;
int b[MAXN];
BIT bit;

ll solve() {
	nv = 0; REP(i, n) v[nv++] = a[i];
	sort(v, v + nv); nv = unique(v, v + nv) - v;
	REP(i, n) b[i] = lower_bound(v, v + nv, a[i]) - v;

	bit.init(nv);
	ll ret = 0;
	REP(i, n) {
		int smaller = bit.prefixsum(b[i] - 1);
		int equal = bit.prefixsum(b[i]) - smaller;
		int bigger = i - smaller - equal;
		ret += min(smaller, bigger);
		bit.add(b[i], +1);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}