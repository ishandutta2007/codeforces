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

const int MAXBITS = 19;
const int MAXN = 1 << MAXBITS;
struct Res { int mn, mx, best; Res() {}  Res(int mn, int mx, int best) :mn(mn), mx(mx), best(best) {} };

int n, nbits;
int a[MAXN];
int ans[1 << MAXBITS];

int cnt[1 << MAXBITS];

Res combine(const Res& a, const Res& b, int step) {
	Res ret;
	ret.mn = a.mn != INT_MAX ? a.mn : b.mn != INT_MAX ? step + b.mn : INT_MAX;
	ret.mx = b.mx != INT_MIN ? step + b.mx : a.mx != INT_MIN ? a.mx : INT_MIN;
	ret.best = min(a.best, b.best);
	if (a.mx != INT_MIN && b.mn != INT_MAX) ret.best = min(ret.best, step + b.mn - a.mx);
	return ret;
}

vector<Res> rec(int offset, int k) {
	vector<Res> ret(1 << k);
	if (k == 0) {
		if (cnt[offset] == 0) ret[0] = Res(INT_MAX, INT_MIN, INT_MAX);
		else ret[0] = Res(0, 0, INT_MAX);
	} else {
		vector<Res> l = rec(offset, k - 1);
		vector<Res> r = rec(offset + (1 << (k - 1)), k - 1);
		REP(i, 1 << (k - 1)) {
			ret[i] = combine(l[i], r[i], 1 << (k - 1));
			ret[(1 << (k - 1)) + i] = combine(r[i], l[i], 1 << (k - 1));
		}
	}
	return ret;
}

void solve() {
	REP(i, 1 << nbits) cnt[i] = 0;
	REP(i, n) ++cnt[a[i]];
	REP(i, 1 << nbits) if (cnt[i] >= 2) { REP(j, 1 << nbits) ans[i] = 0; return; }
	vector<Res> res = rec(0, nbits);
	REP(i, 1 << nbits) ans[i] = res[i].best;
}

void run() {
	scanf("%d%d", &n, &nbits);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, 1 << nbits) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}