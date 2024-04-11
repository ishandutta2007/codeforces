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

const int MAXSEG = 100000;

int ncell, nseg;
int len[MAXSEG];
int ans[MAXSEG];

bool solve() {
	for (int i = nseg - 1; i >= 0; --i) {
		int lbound = max(i, (i + 1 < nseg ? ans[i + 1] : ncell) - len[i]);
		int rbound = ncell - len[i];
		//printf("%d: %d..%d\n", i, lbound, rbound);
		if (lbound > rbound) return false;
		ans[i] = lbound;
	}
	if (ans[0] != 0) return false;
	return true;
}

void run() {
	scanf("%d%d", &ncell, &nseg);
	REP(i, nseg) scanf("%d", &len[i]);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, nseg) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}