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
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }

int n;
int b[MAXN];

ll bsum[MAXN + 1];
int ways[MAXN];

int solve() {
	bsum[0] = 0; REP(i, n) bsum[i + 1] = bsum[i] + b[i];
	int global = 0;
	map<ll, int> local;

	REP(i, n) ways[i] = 0;
	inc(ways[0], 1);
	REP(i, n) {
		inc(ways[i], global);
		dec(ways[i], local[bsum[i]]);
		inc(global, ways[i]);
		inc(local[bsum[i]], ways[i]);
	}
	//printf("ways:"); REP(i, n) printf(" %d", ways[i]); puts("");
	int ret = 0;
	REP(i, n) inc(ret, ways[i]);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &b[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}