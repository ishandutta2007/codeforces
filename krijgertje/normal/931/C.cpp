#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 100000;

int n;
int x[MAXN];
int cnt[3];
int cur[3], curdiff;
int ret[3], retdiff;

void run() {
	scanf("%d", &n); REP(i, n) scanf("%d", &x[i]);
	int mn = x[0]; FOR(i, 1, n) mn = min(x[i], mn);
	REP(i, 3) cnt[i] = 0; REP(i, n) { int y = x[i] - mn; assert(0 <= y&&y < 3); ++cnt[y]; }
	REP(j, 3) ret[j] = cnt[j]; retdiff = 0;
	REPE(c, n) {
		cur[2] = c; cur[1] = cnt[1] + 2 * cnt[2] - 2 * cur[2]; cur[0] = cnt[0] + cnt[1] + cnt[2] - cur[1] - cur[2];
		if (cur[0] < 0 || cur[1] < 0 || cur[2]>0 && cnt[2] == 0) continue;
		curdiff = 0; REP(j, 3) curdiff += abs(cur[j] - cnt[j]);
		if (curdiff <= retdiff) continue;
		retdiff = curdiff; REP(j, 3) ret[j] = cur[j];
	}
	printf("%d\n", n - retdiff / 2);
	bool fst = true; REP(j, 3) REP(k, ret[j]) { if (fst) fst = false; else printf(" "); printf("%d", mn + j); } puts("");
}

int main() {
	run();
	return 0;
}