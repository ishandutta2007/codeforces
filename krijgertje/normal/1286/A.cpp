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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 100;

int n;
int a[MAXN];

bool have[MAXN];
int b[MAXN];

int calc(int fstpar, int lstpar) {
	int fst = a[0]; if (fst != -1 && fst % 2 != fstpar) return INT_MAX;
	int lst = a[n - 1]; if (lst != -1 && lst % 2 != lstpar) return INT_MAX;
	if (n == 1) return fstpar == lstpar ? 0 : INT_MAX;
	REP(i, n) have[i] = false;
	REP(i, n) { int x = a[i]; if (x == -1) continue; assert(!have[x]); have[x] = true; }
	int remodd = 0, remevn = 0; REP(i, n) { if (have[i]) continue; if (i % 2 == 0) ++remevn; else ++remodd; }
	if (fst == -1) { if (fstpar == 0) --remevn; else --remodd; }
	if (lst == -1) { if (lstpar == 0) --remevn; else --remodd; }
	if (remodd < 0 || remevn < 0) return INT_MAX;
	REP(i, n) b[i] = a[i] == -1 ? -1 : a[i] % 2; b[0] = fstpar; b[n - 1] = lstpar;
	vector<int> segevn, segodd, segboth;
	REP(i, n) if (b[i] == -1 && (i == 0 || b[i - 1] != -1)) {
		int j = i; while (j + 1 < n && b[j + 1] == -1) ++j;
		int mask = 0;
		if (i - 1 >= 0) mask |= 1 << b[i - 1];
		if (j + 1 < n) mask |= 1 << b[j + 1];
		int len = j - i + 1;
		 if (mask == 3) segboth.PB(len); else if (mask == 1) segevn.PB(len); else if (mask == 2) segodd.PB(len); else assert(false);
	}
	int ret = 0;
	REP(i, n - 1) if (b[i] != -1 && b[i + 1] != -1 && b[i] != b[i + 1]) ++ret;
	ret += SZ(segboth);
	sort(segevn.begin(), segevn.end());
	REPSZ(i, segevn) {
		int cur = min(segevn[i], remevn);
		remevn -= cur;
		if (cur < segevn[i]) { remodd -= segevn[i] - cur; ret += 2; }
	}
	sort(segodd.begin(), segodd.end());
	REPSZ(i, segodd) {
		int cur = min(segodd[i], remodd);
		remodd -= cur;
		if (cur < segodd[i]) { remevn -= segodd[i] - cur; ret += 2; }
	}
	return ret;
}

int solve() {
	int ret = INT_MAX;
	REP(a, 2) REP(b, 2) ret = min(ret, calc(a, b));
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) { scanf("%d", &a[i]); --a[i]; }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}