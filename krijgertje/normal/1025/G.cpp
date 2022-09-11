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

const int MAXN = 500;
const int MOD = 1000000007;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int &a, int b) { if ((a -= b) < 0) a += MOD; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%MOD; if ((n >>= 1) == 0) return ret; x = (ll)x*x%MOD; } }
int inv(int x) { return pw(x, MOD - 2); }

int n;
int par[MAXN];

int v[MAXN + 1];
int sz[MAXN];

int solve() {
	v[0] = v[1] = 0; FORE(i, 2, n) v[i] = (2 * v[i - 1] + 1) % MOD;
	REP(i, n) sz[i] = 0; REP(i, n) if (par[i] == -1) ++sz[i]; else ++sz[par[i]];
	int ret = v[n]; REP(i, n) dec(ret, v[sz[i]]); return ret;
}

void run() {
	scanf("%d", &n); REP(i, n) { scanf("%d", &par[i]); if (par[i] != -1) --par[i]; }
	printf("%d\n", solve());
}

vector<vector<int>> states;
map<vector<int>, int> mp;

void genstates(vector<int> &cur, int rem) {
	if (rem == 0) { int id = SZ(states); states.PB(cur); mp[cur] = id; return; }
	FORE(i, 1, rem) {
		if (SZ(cur) > 0 && i > cur.back()) break;
		cur.PB(i);
		genstates(cur, rem - i);
		cur.pop_back();
	}
}

vector<vector<int>> A;
void gaussjord() {
	int h = SZ(A), w = SZ(A[0]), r = 0, c = 0;
	while (r < h&&c < w) {
		if (A[r][c] != 0) { int rr = r; while (rr < h&&A[rr][c] == 0) ++rr; if (rr >= h) { ++c; continue; } else REP(cc, w) swap(A[r][cc], A[rr][cc]); }
		if (A[r][c] != 1) { int mlt = inv(A[r][c]); REP(cc, w) A[r][cc] = (ll)A[r][cc] * mlt%MOD; }
		FOR(rr, r + 1, h) { int t = A[rr][c]; REP(cc, w) dec(A[rr][cc], (ll)A[r][cc] * t%MOD); }
		++r, ++c;
	}
	for (--r; r >= 0; --r) {
		c = 0; while (c < w&&A[r][c] == 0) ++c; assert(c < w);
		REP(rr, r) { int t = A[rr][c]; REP(cc, w) dec(A[rr][cc], (ll)A[r][cc] * t%MOD); }
	}
}

void research() {
	for (n = 1; n <= 20; ++n) {
		vector<int> inv(n*n + 1); inv[1] = 1; FORSZ(i, 2, inv) inv[i] = (ll)(MOD - MOD / i)*inv[MOD%i] % MOD;
		states.clear();
		mp.clear();
		vector<int> cur; genstates(cur, n);
		printf("%d: %d states\n", n, SZ(states));
		A = vector<vector<int>>(SZ(states), vector<int>(SZ(states) + 1, 0));
		REPSZ(i, states) {
			vector<int> to;
			REPSZ(j, states[i]) REPSZ(k, states[i]) if (j != k) {
				cur = states[i]; cur[j]++; int extra = cur[k] - 1; cur.erase(cur.begin() + k); REP(z, extra) cur.PB(1); sort(cur.rbegin(), cur.rend());
				assert(mp.count(cur)); int id = mp[cur]; to.PB(id);
			}
			inc(A[i][i], 1);
			REPSZ(j, to) inc(A[i][to[j]], MOD - inv[SZ(to)]);
			if (SZ(states[i]) != 1) inc(A[i][SZ(states)], 1);
		}
		//REPSZ(i, A) { REPSZ(j, A[i]) printf("%d ", A[i][j]); puts(""); } puts("");
		gaussjord();
		//REPSZ(i, A) { REPSZ(j, A[i]) printf("%d ", A[i][j]); puts(""); } puts("");
		//REPSZ(i, states) { printf("%d:", i); REPSZ(j, states[i]) printf(" %d", states[i][j]); printf(" = %d\n", A[i][SZ(states)]); }
		int ones = A[mp[vector<int>(n, 1)]][SZ(states)];
		vector<int> gain(n + 1, -1); FORE(i, 1, n) { vector<int> cur(n - i + 1, 1); cur[0] += i - 1; gain[i] = ones; dec(gain[i], A[mp[cur]][SZ(states)]); }
		printf("ones=%d, gain:", ones); FORE(i, 1, n) printf(" %d", gain[i]); puts("");
		REPSZ(i, states) { int have = A[i][SZ(states)], want = ones; REPSZ(j, states[i]) dec(want, gain[states[i][j]]); assert(have == want); }
		assert(ones == (1 << (n - 1)) - 1); FORE(i, 1, n) assert(gain[i] == (1 << (i - 1)) - 1);
	}
}

int main() {
	//research();
	run();
	return 0;
}