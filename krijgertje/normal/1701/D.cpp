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

const int MAXN = 500000;

int n;
int b[MAXN];
int a[MAXN];

struct Op { int idx, lo, hi; };

Op op[MAXN];

bool solve() {
	REP(i, n) {
		op[i].idx = i;
		// (i+1)/?>=b[i] -> ?<=(i+1)/b[i]
		op[i].hi = b[i] == 0 ? n : min(n, (i + 1) / b[i]);
		// (i+1)/?<b[i]+1 -> ?>(i+1)/(b[i]+1)
		op[i].lo = max(1, (i + 1) / (b[i] + 1) + 1);
		//printf("%d/?=%d -> %d..%d\n", i + 1, b[i], op[i].lo, op[i].hi);
	}
	sort(op, op + n, [&](const Op& a, const Op& b) { return a.lo < b.lo; });
	priority_queue<pair<int, int>> pq;
	int at = 0;
	FORE(v, 1, n) {
		while (at < n && op[at].lo <= v) pq.push(MP(-op[at].hi, at)), ++at;
		if (pq.empty()) return false;
		int i = pq.top().second; pq.pop();
		if (op[i].hi < v) return false;
		a[op[i].idx] = v;
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &b[i]);
	assert(solve());
	REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}