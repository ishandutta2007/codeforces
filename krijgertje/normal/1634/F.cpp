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

const int MAXN = 300000;
const int MAXQ = 300000;

int n, nq, MOD;
int a[MAXN];
int b[MAXN];
char qkind[MAXQ]; int ql[MAXQ], qr[MAXQ];
bool qans[MAXQ];

int c[MAXN];
int d[MAXN];

int fib[MAXN + 1];

void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int &a, int b) { inc(a, MOD - b); }

void solve() {
	REP(i, n) c[i] = (a[i] + MOD - b[i]) % MOD;
	REP(i, n) {
		d[i] = c[i];
		if (i - 1 >= 0) dec(d[i], c[i - 1]);
		if (i - 2 >= 0) dec(d[i], c[i - 2]);
	}
	//printf("c:"); REP(j, n) printf(" %d", c[j]); puts("");
	//printf("d:"); REP(j, n) printf(" %d", d[j]); puts("");

	fib[0] = 1, fib[1] = 1; FORE(i, 2, n) fib[i] = (fib[i - 2] + fib[i - 1]) % MOD;

	int nzero = 0;
	REP(i, n) if (d[i] == 0) ++nzero;
	auto modify = [&](int idx, int by) { if (d[idx] == 0) --nzero; inc(d[idx], by); if (d[idx] == 0) ++nzero; };

	REP(i, nq) {
		int mlt = qkind[i] == 'A' ? 1 : MOD - 1, l = ql[i], r = qr[i], cnt = r - l + 1;
		modify(l, mlt);
		if (r + 1 < n) modify(r + 1, (ll)(MOD - mlt) * fib[cnt] % MOD);
		if (r + 2 < n) modify(r + 2, (ll)(MOD - mlt) * fib[cnt - 1] % MOD);
		qans[i] = nzero == n;
		//printf("d:"); REP(j, n) printf(" %d", d[j]); printf(" (l=%d r=%d mlt=%d)\n", l, r, mlt);
	}
}

void run() {
	scanf("%d%d%d", &n, &nq, &MOD);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	REP(i, nq) scanf(" %c%d%d", &qkind[i], &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}