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

struct BIT {
	int n; vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n + 1); }
	int get(int idx) { ++idx; int ret = 0; while (idx > 0) { ret += val[idx]; idx -= idx & -idx; } return ret; }
	void mod(int idx, int by) { ++idx; while (idx <= n) { val[idx] += by; idx += idx & -idx; } }
};

const int MAXN = 500000;

int n;
int a[MAXN];
ll ans[MAXN + 1];

int v[MAXN];
int w[MAXN];

void solve() {
	BIT bit;
	bit.init(n);
	ll init = 0;
	REP(i, n) {
		int lower = bit.get(a[i]), higher = i - lower;
		v[i] = higher - lower;
		bit.mod(a[i], +1);
		init += higher;
	}
	bit.init(n);
	for (int i = n - 1; i >= 0; --i) {
		int lower = bit.get(a[i]);
		w[i] = v[i] - 2 * lower;
		bit.mod(a[i], +1);
	}
	//printf("w:"); REP(i, n) printf(" %d", w[i]); puts("");
	sort(w, w + n);
	reverse(w, w + n);
	ans[0] = init;
	ll wsum = 0;
	REP(i, n) {
		wsum += w[i];
		ans[i + 1] = init - (wsum + (ll)(i + 1) * i / 2);
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	solve();
	REPE(i, n) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}