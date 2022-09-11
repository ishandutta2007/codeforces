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

const int MAXN = 17;
struct Z { int dp[2][2]; Z() { REP(a, 2) REP(b, 2) dp[a][b] = INT_MIN; } };

int n, nfan;
bool isfan[1 << MAXN];

void upd(int& a, int b) { a = max(a, b); }

Z go(int fst, int k) {
	Z ret;
	if (k == 1) {
		int a = isfan[fst] ? 1 : 0;
		int b = isfan[fst + 1] ? 1 : 0;
		REP(w, 2) {
			int na = w == 0 ? a : b;
			int nb = w == 0 ? b : a;
			upd(ret.dp[na][nb], (a == 1 || b == 1 ? 1 : 0));
		}
	} else {
		Z l = go(fst, k - 1), r = go(fst + (1 << (k - 1)), k - 1);
		REP(la, 2) REP(lb, 2) REP(ra, 2) REP(rb, 2) REP(wa,2) REP(wb,2) REP(wc,2) {
			int vl = l.dp[la][lb]; if (vl == INT_MIN) continue;
			int vr = r.dp[ra][rb]; if (vr == INT_MIN) continue;
			int na = wa == 0 ? la : ra;
			int nb = wb == 0 ? lb : rb;
			int lc = wa == 0 ? ra : la;
			int rc = nb;
			int nc = wc == 0 ? lc : rc;
			upd(ret.dp[na][nc], vl + vr + (la == 1 || ra == 1 ? 1 : 0) + (lb == 1 || rb == 1 ? 1 : 0) + (lc == 1 || rc == 1 ? 1 : 0));
		}
	}
	//printf("go(%d,%d):", fst + 1, k); REP(a, 2) REP(b, 2) if (ret.dp[a][b] == INT_MIN) printf(" X"); else printf(" %d", ret.dp[a][b]); puts("");
	return ret;
}


int solve() {
	Z res = go(0, n);
	int ret = INT_MIN;
	REP(a, 2) REP(b, 2) {
		int v = res.dp[a][b]; if (v == INT_MIN) continue;
		upd(ret, v + (a == 1 || b == 1 ? 1 : 0));
	}
	return ret;
}


void run() {
	scanf("%d%d", &n, &nfan);
	REP(i, 1 << n) isfan[i] = false;
	REP(i, nfan) { int x; scanf("%d", &x); --x; isfan[x] = true; }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}