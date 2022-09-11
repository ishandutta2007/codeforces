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

const int MAXN = 100000;
const int MAXVAL = 100000;

int n;
int a[MAXN];

bool have[MAXVAL + 1];

int b[MAXN], nb;

int opt[MAXN], nopt;
int cntmlt[MAXVAL + 1];
int pmn[MAXVAL + 1];
int mu[MAXVAL + 1];
vector<int> dv[MAXVAL + 1];

void addopt(int val) {
	opt[nopt++] = val;
	for (int d : dv[val]) ++cntmlt[d];
}
int removeopt() {
	int val = opt[--nopt];
	for (int d : dv[val]) --cntmlt[d];
	return val;
}
int cntcoprime(int val) {
	int ret = 0;
	for (int d : dv[val]) ret += mu[d] * cntmlt[d];
	return ret;
}

ll calccoprime() {
	ll ret = 0;
	for (int i = nb - 1; i >= 0; --i) {
		while (cntcoprime(b[i]) > 0) {
			int cur = removeopt();
			if (gcd(cur, b[i]) == 1) ret = max(ret, (ll)cur * b[i]);
		}
		if (ret == 0) addopt(b[i]);
	}
	while (nopt > 0) removeopt();
	return ret;
}

ll solve() {
	nopt = 0;
	REPE(i, MAXVAL) pmn[i] = -1;
	FORE(i, 2, MAXVAL) if (pmn[i] == -1) for (int j = i; j <= MAXVAL; j += i) if (pmn[j] == -1) pmn[j] = i;
	mu[1] = 1; FORE(i, 2, MAXVAL) { int j = i / pmn[i]; mu[i] = pmn[i] == pmn[j] ? 0 : -mu[j]; }
	dv[1] = vector<int>(1, 1); FORE(i, 2, MAXVAL) { int j = i / pmn[i]; dv[i] = dv[j]; if (pmn[i] != pmn[j]) REPSZ(k, dv[j]) dv[i].PB(pmn[i] * dv[j][k]); }
	//FORE(i, 1, 100) { printf("%d: pmn=%d mu=%d dv:", i, pmn[i], mu[i]); for (int d : dv[i]) printf(" %d", d); puts(""); }

	memset(have, false, sizeof(have));
	REP(i, n) have[a[i]] = true;
	ll ret = 0;
	REP(i, n) ret = max(ret, (ll)a[i]);
	FORE(g, 1, MAXVAL) {
		nb = 0; for (int i = g; i <= MAXVAL; i += g) if (have[i]) b[nb++] = i / g;
		ll cur = calccoprime() * g;
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}