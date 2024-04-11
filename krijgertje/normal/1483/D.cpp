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

const int MAXN = 600;
const int MAXM = MAXN * (MAXN - 1) / 2;
const int MAXQ = MAXN * (MAXN - 1) / 2;

int n, m;
int e[MAXM][3];
int nq;
int q[MAXQ][3];

ll d1[MAXN][MAXN];
ll d2[MAXN][MAXN];

int solve() {
	REP(i, n) REP(j, n) d1[i][j] = i == j ? 0 : LLONG_MAX;
	REP(i, m) { int a = e[i][0], b = e[i][1], c = e[i][2]; d1[a][b] = min(d1[a][b], (ll)c); d1[b][a] = min(d1[b][a], (ll)c); }
	REP(k, n) REP(i, n) REP(j, n) if (d1[i][k] != LLONG_MAX && d1[k][j] != LLONG_MAX) d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
	REP(i, n) REP(j, n) d2[i][j] = LLONG_MAX;
	REP(i, nq) {
		int a = q[i][0], b = q[i][1], c = q[i][2];
		REP(u, n) if (d1[u][a] != LLONG_MAX) d2[u][b] = min(d2[u][b], d1[u][a] - c);
		REP(u, n) if (d1[u][b] != LLONG_MAX) d2[u][a] = min(d2[u][a], d1[u][b] - c);
	}
	REP(k, n) REP(i, n) REP(j, n) if (d2[i][k] != LLONG_MAX && d1[k][j] != LLONG_MAX) d2[i][j] = min(d2[i][j], d2[i][k] + d1[k][j]);
	int ret = 0;
	REP(i, m) {
		int a = e[i][0], b = e[i][1], c = e[i][2];
		if (d2[a][b] <= -c) ++ret;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]), --e[i][0], --e[i][1];
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d%d", &q[i][0], &q[i][1], &q[i][2]), --q[i][0], --q[i][1];
	printf("%d\n", solve());
}


int main() {
	run();
	return 0;
}