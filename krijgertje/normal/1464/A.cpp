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

const int MAXSZ = 100000;

int sz, n;
int x[MAXSZ], y[MAXSZ];

int nxt[MAXSZ],prv[MAXSZ];
bool done[MAXSZ];

int solve() {
	REP(i, sz) nxt[i] = -1, prv[i] = -1;
	REP(i, n) nxt[x[i]] = y[i], prv[y[i]] = x[i];
	REP(i, sz) done[i] = false;
	//printf("prv:"); REP(i, n) printf(" %2d", prv[i]); puts("");
	//printf("nxt:"); REP(i, n) printf(" %2d", nxt[i]); puts("");
	int ret = 0;
	REP(i, sz) if (!done[i] && prv[i] == -1) {
		int at = i;
		int len = 0;
		while (at != -1) {
			++len;
			done[at] = true;
			at = nxt[at];
		}
		ret += len - 1;
	}
	REP(i, sz) if (!done[i]) {
		int len = 0;
		int at = i;
		while (!done[at]) {
			++len;
			done[at] = true;
			at = nxt[at];
		}
		if (len == 1) continue;
		ret += len + 1;
	}
	return ret;
}

void run() {
	scanf("%d%d", &sz, &n);
	REP(i, n) scanf("%d%d", &x[i], &y[i]), --x[i], --y[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}