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

const int MAXN = 2020;
const int MOD = 998244353;

int n, k;

int a[MAXN]; int na;
int b[MAXN]; int nb;
int c[MAXN]; int nc;

//int ncalcbackwards = 0;

bool calcbackwards() {
	nb = na; REP(i, na) b[i] = a[i];
	REP(rep, k - 1) {
		nc = 0; int nxtc = 1; for (int i = nb - 1; i >= 0; --i) { REP(j, b[i]) if (nc < n) c[nc++] = nxtc; else return false; ++nxtc; }
		nb = nc; REP(i, nc) b[i] = c[i];
	}
	int bsum = 0; REP(i, nb) bsum += b[i]; return bsum <= n;

	//++ncalcbackwards;
	//nb = 0; int nxtb = 1; bool bok = true; for (int i = na - 1; i >= 0; --i) { REP(j, a[i]) if (nb < n) b[nb++] = nxtb; else bok = false; ++nxtb; }
	//int csum = 0; REP(i, nc) csum += c[i]; bool dok = cok && csum <= n;
	//printf("a:"); REP(i, na) printf(" %d", a[i]); puts("");
	//printf("b:"); REP(i, nb) printf(" %d", b[i]); puts("");
	//printf("c:"); REP(i, nc) printf(" %d", c[i]); puts("");
	//printf("%s\n", dok ? "OK" : "ERR");
}

int rec(int rem, int lst) {
	int ret = 0;
	FORE(i, lst, rem) {
		a[na++] = i;
		if (calcbackwards()) {
			ret += 1 + rec(rem - i, i);
			--na;
		} else {
			--na;
			break;
		}
	}
	return ret;
}

const int MAXLEN2 = 63;
int dp2[MAXLEN2 + 1][MAXN + 1];
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int calc2() {
	REPE(lim, n) dp2[0][lim] = 1;
	FORE(len, 1, MAXLEN2) REPE(lim, n) {
		int times = (1 + len) * len / 2;
		dp2[len][lim] = 0;
		for (int i = 0; i * times <= lim; ++i) {
			inc(dp2[len][lim], dp2[len - 1][lim - i * times]);
		}
	}
	int ret = 0;
	FORE(len, 1, MAXLEN2) {
		int fixed = (1 + len) * len / 2;
		if (fixed > n) continue;
		inc(ret, dp2[len][n - fixed]);
	}
	return ret;
}

int dp1[MAXN + 1][MAXN + 1];

int calc1() {
	REPE(len, n) REPE(lim, n) {
		dp1[len][lim] = len == 0 ? 1 : 0;
		if (len >= 1 && lim >= 1) inc(dp1[len][lim], dp1[len - 1][lim - 1]);
		if (len >= 1 && lim >= len) inc(dp1[len][lim], dp1[len][lim - len]);
		//printf("dp1[%d][%d]=%d\n", len, lim, dp1[len][lim]);
	}
	int ret = 0; FORE(len, 1, n) inc(ret, dp1[len][n]); return ret;
}

int solve() {
	if (k == 1) return calc1();
	if (k == 2) return calc2();
	if (k >= 3) {
		na = 0; 
		int alim = 1; while ((1 + alim + 1) * (alim + 1) / 2 <= n) ++alim;
		//printf("alim=%d\n", alim);
		int ret = rec(alim, 1);
		//printf("ncalcbackwards=%d\n", ncalcbackwards);
		return ret;
	}
	return -1;
}

void run() {
	scanf("%d%d", &n, &k);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}