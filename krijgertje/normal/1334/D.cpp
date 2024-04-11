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

const int MAXANS = 100000;

int n; ll ql, qr;
int ans[MAXANS], nans;

ll at;

void append(int to) {
	//printf("\tappending %d\n", to);
	if (ql <= at && at < qr) ans[nans++] = to;
	++at;
}

void solve() {
	nans = 0;
	at = 0;
	append(1);
	FORE(i, 2, n - 1) {
		append(i);
		append(1);
	}
	append(n);
	FORE(i, 2, n - 1) {
		int cnt = 2 + 2 * (n - i - 1);
		if (at + cnt <= ql || at >= qr) { 
			//printf("\tskipping %d\n", cnt);
			at += cnt; 
			continue; 
		}
		append(i);
		FORE(j, i+1, n - 1) {
			append(j);
			append(i);
		}
		append(n);
	}
	append(1);
	assert(at == (ll)n * (n - 1) + 1); assert(nans == qr - ql);
}

void run() {
	scanf("%d%lld%lld", &n, &ql, &qr); --ql;
	solve();
	REP(i, qr - ql) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

void stress() {
	REP(rep, 100) {
		n = rnd() % 100 + 2;
		int len = n * (n - 1) + 1;
		ql = rnd() % len, qr = rnd() % len; if (ql > qr) swap(ql, qr); ++qr;
		//ql = 0, qr = len;
		printf("%d %lld %lld\n", n, ql, qr);
		solve();
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}