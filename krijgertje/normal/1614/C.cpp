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
#include <functional>
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

const int MAXN = 200000;
const int MAXQ = 200000;
const int MOD = 1000000007;
const int NBIT = 30;

int n, nq;
int ql[MAXQ], qr[MAXQ], qval[MAXQ];

struct E {
	int idx, val, by;
	E() {} E(int idx, int val, int by) :idx(idx), val(val), by(by) {}
};

int a[MAXN];

int solve() {
	vector<E> e;
	REP(i, nq) e.PB(E(ql[i], qval[i], +1)), e.PB(E(qr[i] + 1, qval[i], -1));
	sort(e.begin(), e.end(), [&](const E &a, const E &b) { return a.idx < b.idx; });
	int at = 0;
	vector<int> forbidden(NBIT, 0);
	int allowed = (1 << NBIT) - 1;
	REPE(i, n) {
		while (at < SZ(e) && e[at].idx == i) {
			E cur = e[at++];
			REP(bit, NBIT) if ((cur.val & (1 << bit)) == 0) {
				if (forbidden[bit] == 0) allowed ^= 1 << bit;
				forbidden[bit] += cur.by;
				if (forbidden[bit] == 0) allowed ^= 1 << bit;
			}
		}
		if (i < n) a[i] = allowed;
	}
	//printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");
	int ret = 0;
	REP(bit, NBIT) {
		int zero = 0, one = 0;
		REP(i, n) if (a[i] & (1 << bit)) ++one; else ++zero;
		if (one == 0) continue;
		int ways = 1;
		REP(i, one - 1 + zero) ways = (ll)2 * ways % MOD;
		ret = (ret + (ll)(1 << bit) * ways) % MOD;
	}
	int chk = 0;
	FOR(mask, 1, 1 << n) {
		int sum = 0;
		REP(i, n) if (mask & (1 << i)) sum ^= a[i];
		chk = (chk + sum) % MOD;
	}
	//printf("chk=%d\n", chk);
	return ret;
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, nq) scanf("%d%d%d", &ql[i], &qr[i], &qval[i]), --ql[i], --qr[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}