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

const int MAXN = 500000;
const int MAXVAL = 500000;
const int MAXS = 4 * MAXVAL;

int n;
int a[MAXN];

vector<int> occ[MAXVAL+1];

int sval[MAXS], scnt[MAXS], slazy[MAXS];
void sapply(int x, int by) { sval[x] += by; slazy[x] += by; }
void spush(int x) { if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0; }
void spull(int x) { sval[x] = min(sval[2 * x + 1], sval[2 * x + 2]); scnt[x] = (sval[2 * x + 1] == sval[x] ? scnt[2 * x + 1] : 0) + (sval[2 * x + 2] == sval[x] ? scnt[2 * x + 2] : 0); }
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = 0, scnt[x] = 1;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int BY) {
	//if (x == 0) printf("modding %d..%d with %d\n", L, R, BY);
	if (L <= l && r <= R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}
pair<int, int> sget(int x, int l, int r, int L, int R) {
	//if (x == 0) printf("getting %d..%d\n", L, R);
	if (L <= l && r <= R) {
		return MP(sval[x], scnt[x]);
	} else {
		int m = l + (r - l) / 2; spush(x); pair<int, int> ret = MP(INT_MAX, 0);
		if (L <= m) { pair<int, int> cur = sget(2 * x + 1, l, m, L, R); if (cur.first < ret.first) ret = MP(cur.first, 0); if (cur.first == ret.first) ret.second += cur.second; }
		if (m + 1 <= R) { pair<int, int> cur = sget(2 * x + 2, m + 1, r, L, R); if (cur.first < ret.first) ret = MP(cur.first, 0); if (cur.first == ret.first) ret.second += cur.second; }
		return ret;
	}
}

ll solve() {
	ll ret = 0;
	sinit(0, 0, n - 1);
	for (int l = n - 1; l >= 0; --l) {
		int v = a[l];
		auto upd = [&](int mlt) {
			if (SZ(occ[v]) >= 4) smod(0, 0, n - 1, occ[v][SZ(occ[v]) - 4], n - 1, mlt);
			if (SZ(occ[v]) >= 1) smod(0, 0, n - 1, occ[v][SZ(occ[v]) - 1], SZ(occ[v]) < 3 ? n - 1 : occ[v][SZ(occ[v]) - 3] - 1, mlt);
		};
		upd(-1);
		occ[v].PB(l);
		upd(+1);
		pair<int, int> cur = sget(0, 0, n - 1, l, n - 1);
		//printf("->(%d,%d)\n", cur.first, cur.second);
		if (cur.first == 0) ret += cur.second;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}