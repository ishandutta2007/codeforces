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

const int MAXN = 300000;
const int MAXS = 4 * MAXN;
typedef struct S { ll vlft, vrgt; int ntow, nlfttow, nrgttow, nlftdec, nrgtinc, len; } S;

int n;
int a[MAXN];

S sval[MAXS];
ll slazy[MAXS];

S screate(int x) {
	S ret; ret.len = 1; ret.vlft = ret.vrgt = x; ret.ntow = ret.nlfttow = ret.nrgttow = ret.nlftdec = ret.nrgtinc = 1; return ret;
}
S smerge(const S &a, const S &b) {
	S ret; ret.len = a.len + b.len; ret.vlft = a.vlft; ret.vrgt = b.vrgt;
	ret.nlfttow = a.nrgtinc == a.len ? a.len + (a.vrgt > b.vlft ? b.nlftdec : a.vrgt < b.vlft ? b.nlfttow : 0) : a.nlfttow == a.len ? a.len + (a.vrgt > b.vlft ? b.nlftdec : 0) : a.nlfttow;
	ret.nrgttow = b.nlftdec == b.len ? b.len + (a.vrgt < b.vlft ? a.nrgtinc : a.vrgt > b.vlft ? a.nrgttow : 0) : b.nrgttow == b.len ? b.len + (a.vrgt < b.vlft ? a.nrgtinc : 0) : b.nrgttow;
	ret.nlftdec = a.nlftdec == a.len ? a.len + (a.vrgt > b.vlft ? b.nlftdec : 0) : a.nlftdec;
	ret.nrgtinc = b.nrgtinc == b.len ? b.len + (a.vrgt < b.vlft ? a.nrgtinc : 0) : b.nrgtinc;
	ret.ntow = max(a.ntow, max(b.ntow, max(a.nrgttow + (a.vrgt > b.vlft ? b.nlftdec : 0), b.nlfttow + (a.vrgt < b.vlft ? a.nrgtinc : 0))));
	return ret;
}
void sapply(int x, ll by) {
	sval[x].vlft += by, sval[x].vrgt += by, slazy[x] += by;
}
void sprint(char *msg, int l, int r, const S &a) {
	printf("%s %d..%d: len=%d vlft=%lld vrgt=%lld nlftdec=%d nrgtinc=%d nlfttow=%d nrgttow=%d ntow=%d\n", msg, l, r, a.len, a.vlft, a.vrgt, a.nlftdec, a.nrgtinc, a.nlfttow, a.nrgttow, a.ntow);
}

void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = screate(a[l]);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		sval[x] = smerge(sval[2 * x + 1], sval[2 * x + 2]);
		//sprint("init", l, r, sval[x]);
	}
}
void smod(int x, int l, int r, int L, int R, int BY) {
	if (L <= l&&r <= R) {
		sapply(x, BY);
	} else {
		if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0;
		int m = l + (r - l) / 2;
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		sval[x] = smerge(sval[2 * x + 1], sval[2 * x + 2]);
	}
	//sprint("mod", l, r, sval[x]);
}

void run() {
	scanf("%d", &n); REP(i, n) scanf("%d", &a[i]);
	sinit(0, 0, n - 1);
	int nq; scanf("%d", &nq);
	//vector<ll> b(n); REP(i, n) b[i] = a[i];
	REP(i, nq) {
		int l, r, by; scanf("%d%d%d", &l, &r, &by); --l, --r;
		//FORE(j, l, r) b[j] += by; printf("b: "); REP(j, n - 1) printf("%c", b[j]<b[j + 1] ? '<' : b[j]>b[j + 1] ? '>' : '='); puts("");
		smod(0, 0, n - 1, l, r, by);
		printf("%d\n", sval[0].ntow);
	}
}

int main() {
	run();
	return 0;
}