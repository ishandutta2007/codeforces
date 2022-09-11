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

const int MAXN = 200000;
const int MAXM = 200000;
const int MAXQ = 200000;

int n, m;
int e[MAXM][2];
int nq;
int qkind[MAXQ], qa[MAXQ], qb[MAXQ];
int qans[MAXQ];

int curans;
int cntstronger[MAXN];

void solve() {
	curans = n;
	REP(i, n) cntstronger[i] = 0;
	auto mod = [&](int a, int b, int by) { if (a < b) swap(a, b); if (cntstronger[b] == 0) --curans; cntstronger[b] += by; if (cntstronger[b] == 0) ++curans;  };
	REP(i, m) mod(e[i][0], e[i][1], +1);
	REP(i, nq) {
		if (qkind[i] == 1) mod(qa[i], qb[i], +1);
		if (qkind[i] == 2) mod(qa[i], qb[i], -1);
		if (qkind[i] == 3) qans[i] = curans;
	}
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	scanf("%d", &nq);
	REP(i, nq) { scanf("%d", &qkind[i]); if (qkind[i] != 3) scanf("%d%d", &qa[i], &qb[i]), --qa[i], --qb[i]; }
	solve();
	REP(i, nq) if (qkind[i] == 3) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}