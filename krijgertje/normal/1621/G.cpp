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
const int MOD = 1000000007;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n;
int a[MAXN];

int v[MAXN], nv;
int b[MAXN];

int l[MAXN];
int r[MAXN];
int sub[MAXN];

struct BIT {
	int n; vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n + 1, 0); };
	void mod(int idx, int by) { ++idx; while (idx <= n) { inc(val[idx], by); idx += idx & -idx; } };
	int get(int idx) { ++idx; int ret = 0; while (idx > 0) { inc(ret, val[idx]); idx -= idx & -idx; } return ret; }
};
BIT bit;

int c[MAXN];
set<pair<int, int>> rem;

int solve() {
	nv = 0;
	REP(i, n) v[nv++] = a[i];
	sort(v, v + nv);
	nv = unique(v, v + nv) - v;
	REP(i, n) b[i] = lower_bound(v, v + nv, a[i]) - v;

	bit.init(nv);
	REP(i, n) {
		l[i] = 1;
		inc(l[i], bit.get(b[i] - 1));
		bit.mod(b[i], l[i]);
	}
	bit.init(nv);
	for (int i = n - 1; i >= 0; --i) {
		r[i] = 1;
		inc(r[i], bit.get(nv - (b[i] + 1) - 1));
		bit.mod(nv - b[i] - 1, r[i]);
	}

	rem.clear();
	REP(i, n) rem.insert(MP(b[i], i));
	REP(i, n) sub[i] = -1;

	int done = -1;
	for (int i = n - 1; i >= 0; --i) {
		if (b[i] <= done) continue;
		vector<int> lst;
		while (SZ(rem) > 0 && rem.begin()->first < b[i]) {
			if (rem.begin()->second < i) lst.PB(rem.begin()->second);
			rem.erase(rem.begin());
		}
		sort(lst.begin(), lst.end());
		//printf("%d: ", i); for (int idx : lst) printf(" %d", idx); puts("");
		reverse(lst.begin(), lst.end());
		for (int idx : lst) c[idx] = b[idx] - (done + 1);
		int nc = b[i] - (done + 1);
		bit.init(nc);
		for (int idx : lst) {
			sub[idx] = 1;
			inc(sub[idx], bit.get(nc - (c[idx] + 1) - 1));
			bit.mod(nc - c[idx] - 1, sub[idx]);
		}
		done = b[i];
	}
	//printf("l:"); REP(i, n) printf(" %d", l[i]); puts("");
	//printf("r:"); REP(i, n) printf(" %d", r[i]); puts("");
	//printf("sub:"); REP(i, n) printf(" %d", sub[i]); puts("");

	int ret = 0;
	REP(i, n) if (sub[i] != -1) ret = (ret + (ll)l[i] * (r[i] + MOD - sub[i])) % MOD;
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}