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

const int MAXN = 300000;
const int MAXQ = 300000;
const int MAXA = 1000000;

int pmn[MAXA + 1];

int n;
int a[MAXN];
int nq;
ll q[MAXQ]; int qans[MAXQ];


int b[MAXN];

void solve() {
	REP(i, n) {
		int x = a[i], y = 1;
		while (x != 1) {
			int p = pmn[x];
			int cnt = 0;
			while (x % p == 0) x /= p, ++cnt;
			if (cnt % 2 == 1) y *= p;
		}
		b[i] = y;
	}
	sort(b, b + n);
	int mxcnt = 0;
	int onestepones = 0;
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && b[r] == b[l]) ++r;
		int cnt = r - l;
		mxcnt = max(mxcnt, cnt);
		if (b[l] == 1 || cnt % 2 == 0) onestepones += cnt;
	}
	REP(i, nq) qans[i] = q[i] == 0 ? mxcnt : max(mxcnt, onestepones);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%lld", &q[i]);
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

void precalc() {
	memset(pmn, -1, sizeof(pmn));
	FORE(i, 2, MAXA) if (pmn[i] == -1) for (int j = i; j <= MAXA; j += i) if (pmn[j] == -1) pmn[j] = i;
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}