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
#include <functional>
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

const int MAXDIM = 200000;
const int MAXQ = 200000;
const int MOD = 998244353;

int h, w, ncol, nq;
int qx[MAXQ], qy[MAXQ];

int solve() {
	int cntrow = 0, cntcol = 0;
	vector<bool> knowrow(h, false);
	vector<bool> knowcol(w, false);
	int ret = 1;
	for (int i = nq - 1; i >= 0; --i) {
		int x = qx[i], y = qy[i];
		if (cntrow == h || cntcol == w || knowrow[x] && knowcol[y]) continue;
		ret = (ll)ret * ncol % MOD;
		if (!knowrow[x]) knowrow[x] = true, ++cntrow;
		if (!knowcol[y]) knowcol[y] = true, ++cntcol;
	}
	return ret;
}

void run() {
	scanf("%d%d%d%d", &h, &w, &ncol, &nq);
	REP(i, nq) scanf("%d%d", &qx[i], &qy[i]), --qx[i], --qy[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}