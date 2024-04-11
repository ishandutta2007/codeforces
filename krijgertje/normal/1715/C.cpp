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

const int MAXN = 100000;
const int MAXQ = 100000;

int n, nq;
int a[MAXN];
int qidx[MAXQ], qval[MAXQ];
ll qans[MAXQ];

int cur[MAXN];

void solve() {
	REP(i, n) cur[i] = a[i];
	ll curans = (ll)n * (n + 1) / 2;
	auto upd = [&](int idx, int by) { if (cur[idx] == cur[idx + 1]) return; curans += (ll)by * (idx + 1) * (n - idx - 1); };
	REP(i, n - 1) upd(i, +1);
	REP(i, nq) {
		int idx = qidx[i], val = qval[i];
		if (idx != 0) upd(idx - 1, -1); if (idx + 1 < n) upd(idx, -1);
		cur[idx] = val;
		if (idx != 0) upd(idx - 1, +1); if (idx + 1 < n) upd(idx, +1);
		qans[i] = curans;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i];
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}