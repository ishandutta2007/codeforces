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

const int MAXN = 40;
const int MOD = 1000000007;
struct State {
	vector<int> rem;
	int pos, donetot, donelast, donecur;
};
bool operator<(const State& a, const State& b) { if (a.pos != b.pos) return a.pos < b.pos; if (a.donetot != b.donetot) return a.donetot < b.donetot; if (a.donelast != b.donelast) return a.donelast < b.donelast; if (a.donecur != b.donecur) return a.donecur < b.donecur; return a.rem < b.rem; }

int n;
int perm[MAXN];

vector<int> lens;
vector<int> cnts;

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int ways[MAXN + 1][MAXN + 1][MAXN + 1]; // ways[a][b][c] = number of rows for a cycle of c items, when there were b items in the previous iteration and a items before that

int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

map<State, int> mem;

void precalc() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	REPE(a, n - 1) REPE(b, n - a - 1) {
		int all = 0;
		int sub = 0;
		int after = n - a - b - 1;
		REP(me, n) {
			all = (all + (ll)choose(n - me - 1, after) * fac[after] % MOD * fac[a + b]) % MOD;
			sub = (sub + (ll)choose(n - me - 1, after + b) * fac[after + b] % MOD * fac[a]) % MOD;
		}
		if (a == 0 && b == 0) all = fac[n - 1], sub = 0;
		ways[a][b][0] = 1;
		int allprod = 1, subprod = 1;
		FORE(i, 1, n) {
			allprod = (ll)allprod * all % MOD;
			subprod = (ll)subprod * sub % MOD;
			int cur = allprod - subprod; if (cur < 0) cur += MOD;
			ways[a][b][i] = cur;
			//printf("ways[%d][%d][%d]=%d (%d,%d)\n", a, b, i, cur, all, sub);
		}
	}
}

int go(const State& at) {
	if (mem.count(at)) return mem[at];
	if (at.pos == SZ(lens)) {
		if (at.donecur == 0) return mem[at] = 0;
		if (at.donetot == n) return mem[at] = 1;
		State to = at;
		to.pos = 0;
		to.donelast = at.donecur;
		to.donecur = 0;
		return mem[at] = go(to);
	} else {
		int ret = 0;
		int mlt = 1;
		int rem = at.rem[at.pos];
		REPE(i, rem) {
			State to = at;
			to.pos++;
			to.rem[at.pos] = rem - i;
			to.donecur += i * lens[at.pos];
			to.donetot += i * lens[at.pos];
			ret = (ret + (ll)mlt * choose(rem, i) % MOD * go(to)) % MOD;
			mlt = (ll)mlt * ways[at.donetot - at.donecur - at.donelast][at.donelast][lens[at.pos]] % MOD;
			//printf("use mlt[%d][%d][%d]\n", at.donetot - at.donecur - at.donelast, at.donelast, lens[at.pos]);
		}
		//printf("%d [", at.pos); REPSZ(i, at.rem) { if (i != 0) printf(","); printf("%d", at.rem[i]); } printf("] (%d,%d,%d) -> %d\n", at.donelast, at.donecur, at.donetot, ret);
		return mem[at] = ret;
	}
}

int solve() {
	precalc();

	vector<int> cyclen;
	vector<bool> done(n, false);
	REP(s, n) if (!done[s]) {
		int len = 0, at = s;
		while (!done[at]) {
			done[at] = true;
			++len;
			at = perm[at];
		}
		cyclen.PB(len);
	}
	sort(cyclen.begin(), cyclen.end());
	lens.clear(); cnts.clear();
	REPSZ(i, cyclen) if (SZ(lens) == 0 || lens.back() != cyclen[i]) lens.PB(cyclen[i]), cnts.PB(1); else cnts.back()++;
	//printf("lens:"); REPSZ(i, lens) printf(" %d", lens[i]); puts("");
	//printf("cnts:"); REPSZ(i, cnts) printf(" %d", cnts[i]); puts("");

	State start;
	start.rem = cnts;
	start.pos = 0;
	start.donetot = 0;
	start.donelast = 0;
	start.donecur = 0;
	mem.clear();
	return go(start);

}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &perm[i]), --perm[i];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}