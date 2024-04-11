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

const int MAXN = 200000;
const int MAXS = 4 * MAXN;

int n;
int val[MAXN];
int cost[MAXN];

int pos[MAXN];

ll sval[MAXS], slazy[MAXS];
void sapply(int x, ll val) { sval[x] += val; slazy[x] += val; }
void spush(int x) { if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0; }
void spull(int x) { sval[x] = min(sval[2 * x + 1], sval[2 * x + 2]); }
void sinit(int x,int l,int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = 0;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void sadd(int x, int l, int r, int L, int R, ll VAL) {
	//if (x == 0) printf("sadd(%d..%d,%lld)\n", L, R, VAL);
	if (L <= l && r <= R) {
		sapply(x, VAL);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) sadd(2 * x + 1, l, m, L, R, VAL);
		if (m + 1 <= R) sadd(2 * x + 2, m + 1, r, L, R, VAL);
		spull(x);
	}
}

ll solve() {
	REP(i, n) pos[val[i]] = i;
	sinit(0, 0, n - 2);
	REP(i, n - 1) sadd(0, 0, n - 2, i, n - 2, +cost[i]);
	ll ret = sval[0];
	REP(i, n) {
		int idx = pos[i];
		if (idx != 0) sadd(0, 0, n - 2, 0, idx - 1, +cost[idx]);
		if (idx != n - 1) sadd(0, 0, n - 2, idx, n - 2, -cost[idx]);
		ret = min(ret, sval[0]);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &val[i]), --val[i];
	REP(i, n) scanf("%d", &cost[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}