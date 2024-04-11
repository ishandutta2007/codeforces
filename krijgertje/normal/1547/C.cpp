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

const int MAXN = 100;

int sline, na, nb;
int a[MAXN], b[MAXN];
int ans[2 * MAXN];

bool solve() {
	int nans = 0;
	int ai = 0, bi = 0;
	int cline = sline;
	while (ai < na || bi < nb) {
		if (ai < na && (a[ai] == 0 || a[ai] <= cline)) { ans[nans++] = a[ai]; if (a[ai] == 0) ++cline; ++ai; continue; }
		if (bi < nb && (b[bi] == 0 || b[bi] <= cline)) { ans[nans++] = b[bi]; if (b[bi] == 0) ++cline; ++bi; continue; }
		return false;
	}
	return true;
}

void run() {
	scanf("%d%d%d", &sline, &na, &nb);
	REP(i, na) scanf("%d", &a[i]);
	REP(i, nb) scanf("%d", &b[i]);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, na + nb) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}