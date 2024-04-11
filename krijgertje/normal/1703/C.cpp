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

const int MAXN = 100;
const int MAXOPS = 10;

int n;
int fin[MAXN];
int nops[MAXN]; char ops[MAXN][MAXOPS + 1];
int ans[MAXN];

void solve() {
	REP(i, n) {
		int cur = fin[i];
		REP(j, nops[i]) {
			char c = ops[i][j];
			if (c == 'D') if (++cur >= 10) cur = 0;
			if (c == 'U') if (--cur < 0) cur = 9;
		}
		ans[i] = cur;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &fin[i]);
	REP(i, n) scanf("%d%s", &nops[i], ops[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}