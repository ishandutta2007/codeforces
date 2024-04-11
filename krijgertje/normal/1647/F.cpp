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
int a[MAXN];

bool validmid(const vector<int> &b, int lrem, int rrem) {
	//printf("\ttesting:"); if (lrem != -1) printf(" [%d]", lrem); for (int x : b) printf(" %d", x); if (rrem != -1) printf(" [%d]", rrem); puts("");
	int len = SZ(b);
	vector<int> lbest(len); // lbest[i]: assuming that i belongs to left chain, minimum value of element belonging to the right chain before i
	vector<int> rbest(len); // rbest[i]: assuming that i belongs to right chain, maximum value of element belonging to the left chain before i
	lbest[0] = lrem;
	rbest[0] = INT_MIN;
	FOR(i, 1, len) {
		lbest[i] = INT_MAX;
		rbest[i] = INT_MIN;
		// ll
		if (b[i] < b[i - 1]) lbest[i] = min(lbest[i], lbest[i - 1]);
		// rl
		if (b[i] < rbest[i - 1]) lbest[i] = min(lbest[i], b[i - 1]);
		// lr
		if (b[i] > lbest[i - 1]) rbest[i] = max(rbest[i], b[i - 1]);
		// rr
		if (b[i] > b[i - 1]) rbest[i] = max(rbest[i], rbest[i - 1]);
	}
	return rbest[len - 1] > rrem;
}

int calcleft() {
	//printf("calcleft:"); REP(i, n) printf(" %d", a[i]); puts("");
	vector<int> r;
	for (int i = n - 1; i >= 0; --i) {
		if (SZ(r) > 0 && a[i] < a[r.back()]) continue;
		r.PB(i);
	}
	reverse(r.begin(), r.end());
	//printf("r:"); for (int x : r) printf(" %d", x); puts("");
	int mxidx = r[0];
	vector<bool> inr(n, false);
	for (int x : r) inr[x] = true;
	int rrem = -1;
	for (int i = n - 1; i >= mxidx; --i) {
		if (inr[i]) continue;
		if (a[i] < rrem) return 0;
		rrem = a[i];
	}
	//printf("mxidx=%d rrem=%d\n", mxidx, rrem);
	vector<int> l;
	REP(i, n) {
		if (SZ(l) > 0 && a[i] < a[l.back()]) continue;
		l.PB(i);
	}
	assert(l.back() == mxidx);
	vector<bool> inl(n, false);
	for (int x : l) inl[x] = true;
	int ret = 0;
	// not in l
	{
		vector<int> m;
		REP(i, mxidx) if (!inl[i]) m.PB(a[i]);
		if (SZ(m) >= 1) {
			int top = 0;
			FORSZ(i, 1, m) if (m[i] > m[top]) top = i;
			bool ok = true;
			for (int i = top - 1; i >= 0; --i) if (m[i] > m[i + 1]) ok = false;
			FORSZ(i, top + 1, m) if (m[i] > m[i - 1]) ok = false;
			if (rrem != -1 && rrem > m.back()) ok = false;
			if (ok) {
				//printf("ok %d\n", m[top]);
				++ret;
			}
		}
	}
	vector<int> lrem(SZ(l));
	REPSZ(i, l) {
		int cur = i == 0 ? -1 : lrem[i - 1];
		FOR(j, i == 0 ? 0 : l[i - 1] + 1, l[i]) {
			if (a[j] < cur) cur = INT_MAX; else cur = a[j];
		}
		lrem[i] = cur;
	}
	//printf("l:"); for (int x : l) printf(" %d", a[x]); puts("");
	//printf("lrem:"); for (int x : lrem) printf(" %d", x); puts("");
	for (int i = SZ(l) - 2; i >= 0; --i) {
		if (lrem[i] != INT_MAX) {
			vector<int> b;
			FORE(j, l[i], l[i + 1]) b.PB(a[j]);
			if (validmid(b, lrem[i], rrem)) ++ret;
		}
		for (int j = l[i + 1] - 1; j >= l[i] + 1; --j) {
			if (a[j] < rrem) rrem = INT_MAX; else rrem = a[j];
		}
		if (rrem == INT_MAX) break;
	}
	return ret;
}

int solve() {
	int ret = 0;
	REP(side, 2) {
		ret += calcleft();
		reverse(a, a + n);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}