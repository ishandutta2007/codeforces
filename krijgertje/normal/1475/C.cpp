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

int na, nb, m;
int opt[MAXM][2];

int acnt[MAXN], bcnt[MAXN];

ll solve() {
	REP(i, na) acnt[i] = 0;
	REP(i, nb) bcnt[i] = 0;
	REP(i, m) ++acnt[opt[i][0]], ++bcnt[opt[i][1]];
	ll ret = 0;
	REP(i, m) {
		int x = opt[i][0], y = opt[i][1];
		//printf("%d: %d (%d,%d->%d,%d)\n", i, m - acnt[x] - bcnt[y] + 1, x, y, acnt[x], bcnt[y]);
		ret += m - acnt[x] - bcnt[y] + 1;
	}
	assert(ret % 2 == 0);
	ret /= 2;
	return ret;
}

void run() {
	scanf("%d%d%d", &na, &nb, &m);
	REP(j, 2) REP(i, m) scanf("%d", &opt[i][j]), --opt[i][j];
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}