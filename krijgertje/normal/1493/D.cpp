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

const int MAXN = 200000;
const int MAXQ = 200000;
const int MAXVAL = 200000;
const int MOD = 1000000007;

int n, nq;
int a[MAXN];
int qidx[MAXQ], qval[MAXQ];
int qans[MAXQ];

int pmn[MAXVAL + 1];

struct Z {
	int nzero;
	multiset<int> vals;
	map<int, int> cnt;

	void init() {
		nzero = n;
		vals.clear();
		cnt.clear();
	}
	int calc() {
		if (nzero > 0) return 0;
		return *vals.begin();
	}
	void update(int idx, int by) {
		int old;
		if (cnt.count(idx)) {
			old = cnt[idx];
			vals.erase(vals.find(old));
		} else {
			old = 0;
			--nzero;
		}
		int cur = old + by;
		vals.insert(cur);
		cnt[idx] = cur;
	}
};
Z z[MAXVAL + 1];

vector<pair<int, int>> factorize(int x) {
	vector<pair<int, int>> ret;
	while (x != 1) { int p = pmn[x], cnt = 0; while (x % p == 0) x /= p, ++cnt; ret.PB(MP(p, cnt)); }
	return ret;
}

int curans;
void update(int idx, int v) {
	for (auto q : factorize(v)) {
		int p = q.first, cnt = q.second;
		int before = z[p].calc();
		z[p].update(idx, cnt);
		int delta = z[p].calc() - before;
		REP(i, delta) curans = (ll)curans * p % MOD;
	}
}

void solve() {
	REPE(i, MAXVAL) pmn[i] = -1;
	FORE(i, 2, MAXVAL) if (pmn[i] == -1) for (int j = i; j <= MAXVAL; j += i) if (pmn[j] == -1) pmn[j] = i;

	curans = 1;
	FORE(i, 2, MAXVAL) if (pmn[i] == i) z[i].init();

	REP(i, n) update(i, a[i]);
	REP(i, nq) {
		update(qidx[i], qval[i]);
		qans[i] = curans;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}