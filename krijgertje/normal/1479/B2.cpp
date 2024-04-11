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

const int MAXN = 100000;
const int MAXVAL = MAXN;

int n;
int a[MAXN];

int b[MAXN], nb;

int vbest[MAXVAL + 1], gbest, delta; // actual value: val+delta

int solve() {
	nb = 0;
	REP(i, n) if (nb == 0 || a[i] != b[nb - 1]) b[nb++] = a[i];
	if (nb <= 1) return nb;

	gbest = INT_MAX;
	FORE(i, 1, n) vbest[i] = INT_MAX;
	delta = 0;
	
	gbest = vbest[b[0]] = 2 - delta;
	FOR(i, 2, nb) {
		int nval = gbest + 1 + delta;
		if (vbest[b[i]] != INT_MAX) nval = min(nval, vbest[b[i]] + delta);
		++delta;
		//printf("%d: nval=%d\n", i, nval);
		gbest = min(gbest, nval - delta);
		vbest[b[i - 1]] = min(vbest[b[i - 1]], nval - delta);
	}
	return gbest + delta;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}