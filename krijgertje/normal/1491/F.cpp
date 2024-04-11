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

const int MAXN = 2000;

int n;
vector<int> ans;

int nq;
bool islocal;
int  localneutral, localpos;
int localval[MAXN];

int query(vector<int> l, vector<int> r) {
	if (SZ(l) == 0 || SZ(r) == 0) return 0;
	++nq;
	if (!islocal) {
		printf("? %d %d\n", SZ(l), SZ(r));
		REPSZ(i, l) { if (i != 0) printf(" "); printf("%d", l[i] + 1); } puts("");
		REPSZ(i, r) { if (i != 0) printf(" "); printf("%d", r[i] + 1); } puts("");
		fflush(stdout);
		int ret; scanf("%d", &ret); return ret;
	} else {
		int lsum = 0, rsum = 0;
		REPSZ(i, l) lsum += localval[l[i]];
		REPSZ(i, r) rsum += localval[r[i]];
		int ret = (ll)lsum * rsum;
		if (abs(ret) > n) printf("break (n=%d l=%d r=%d ret=%d pos=%d, neut=%d, neg=%d)\n", n, SZ(l), SZ(r), ret, localpos, localneutral, n - localpos - localneutral);
		return ret;
	}
}

void solve() {
	vector<int> kind(n, -2);
	int found = -1; int remsum;
	REP(i, n) {
		vector<int> l, r; l.PB(i); FOR(j, i + 1, n) r.PB(j);
		int res = query(l, r);
		if (res == 0) continue;
		found = i, remsum = res;
		kind[i] = +1;
		break;
	}
	assert(found != -1);
	FOR(j, found + 1, n - 1) {
		vector<int> l, r; l.PB(found); r.PB(j);
		int res = query(l, r);
		kind[j] = res;
	}
	{
		int have = 0; FOR(j, found + 1, n - 1) have += kind[j];
		kind[n - 1] = remsum - have;
	}
	int oth = 0; int othsum;
	for (int bit = 0; (1 << bit) < n; ++bit) {
		vector<int> l, r; l.PB(found); REP(j, found) if ((j & (1 << bit)) == 0) r.PB(j);
		int res = query(l, r);
		if (res == 0) oth |= 1 << bit; else othsum = res;
	}
	REP(j, found) kind[j] = j == oth ? othsum : 0;
	ans.clear(); REP(i, n) if (kind[i] == 0) ans.PB(i);
}

void run() {
	scanf("%d", &n);
	solve();
	printf("! %d", SZ(ans)); REPSZ(i, ans) printf(" %d", ans[i] + 1); puts(""); fflush(stdout);
}

void stress() {
	islocal = true;
	REP(rep, 100000) {
		nq = 0;
		n = rnd() % (MAXN - 3 + 1) + 3;
		localneutral = rnd() % ((n - 2) - 1 + 1) + 1;
		localpos = rnd() % (n - localneutral + 1);
		REP(i, n) localval[i] = i < localneutral ? 0 : i < localneutral + localpos ? +1 : -1;
		REP(i, n) { int idx = rnd() % (i + 1); swap(localval[i], localval[idx]); }
		solve();
		if (rep % 1000 == 999) printf(".");
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}