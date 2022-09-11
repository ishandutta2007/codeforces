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

const int MAXMONTH = 100000;
const int MAXBUILDING = 100000;
const int MAXS = 4 * MAXMONTH;

int nmonth, nbuilding;
int receive[MAXMONTH];
int b[MAXBUILDING];
int p[MAXBUILDING];

ll totalhave[MAXMONTH];
int t[MAXBUILDING]; // in which month to demolish it

pair<int, int> o[MAXBUILDING];

ll sval[MAXS], slazy[MAXS];
void sapply(int x,ll by) {
	sval[x] -= by; slazy[x] += by;
}
void spull(int x) {
	sval[x] = min(sval[2 * x + 1], sval[2 * x + 2]);
}
void spush(int x) {
	if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0;
}
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = totalhave[l];
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
ll sget(int x, int l, int r, int L, int R) {
	if (L <= l&&r <= R) return sval[x];
	int m = l + (r - l) / 2;
	ll ret = LLONG_MAX;
	spush(x);
	if (L <= m) ret = min(ret, sget(2 * x + 1, l, m, L, R));
	if (m + 1 <= R) ret = min(ret, sget(2 * x + 2, m + 1, r, L, R));
	return ret;
}
void smod(int x, int l, int r, int L,int R,ll BY) {
	if (L<=l&&r<=R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2;
		spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}


void run() {
	scanf("%d%d", &nmonth, &nbuilding); REP(i, nmonth) scanf("%d", &receive[i]); REP(i, nbuilding) scanf("%d", &b[i]); REP(i, nbuilding) scanf("%d", &p[i]);

	REP(i, nbuilding) o[i] = MP(b[i], i); sort(o, o + nbuilding);
	int at = 0; for (int i = nmonth - 1; i >= 0; --i) while (at < nbuilding&&o[at].first <= receive[i]) t[o[at++].second] = i; while (at < nbuilding) t[o[at++].second] = -1;
	//printf("t:"); REP(i, nbuilding) printf(" %d", t[i]); puts("");

	REP(i, nmonth) totalhave[i] = (i == 0 ? 0 : totalhave[i - 1]) + receive[i];
	sinit(0, 0, nmonth - 1);

	int ret = 0;
	REP(i, nbuilding) o[i] = MP(p[i], i); sort(o, o + nbuilding);
	REP(i, nbuilding) {
		int at = o[i].second;
		if (t[at] == -1) continue;
		ll rem = sget(0, 0, nmonth - 1, t[at], nmonth - 1);
		//printf("trying to demolish %d at %d: need = %d have = %lld\n", at + 1, t[at] + 1, p[at], rem);
		if (rem < p[at]) continue;
		++ret;
		smod(0, 0, nmonth - 1, t[at], nmonth - 1, p[at]);
	}
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}