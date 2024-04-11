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

const int MAXN = 10000000;

int pmn[MAXN + 1];
int sumdiv[MAXN + 1];
int ans[MAXN + 1];

void precalc() {
	memset(pmn, -1, sizeof(pmn));
	FORE(i, 2, MAXN) if (pmn[i] == -1) for (int j = i; j <= MAXN; j += i) if (pmn[j] == -1) pmn[j] = i;
	sumdiv[1] = 1;
	FORE(i, 2, MAXN) {
		int p = pmn[i], j = i, cnt = 0;
		while (j % p == 0) j /= p, ++cnt;
		if (sumdiv[j] == INT_MAX) { sumdiv[i] = INT_MAX; continue; }
		ll mlt = ((ll)(i / j) * p - 1) / (p - 1);
		if (mlt >= INT_MAX) { sumdiv[i] = INT_MAX; continue; }
		mlt *= sumdiv[j];
		if (mlt >= INT_MAX) { sumdiv[i] = INT_MAX; continue; }
		sumdiv[i] = mlt;
		//if (i < 200) printf("%d: %d\n", i, sumdiv[i]);
	}
	memset(ans, -1, sizeof(ans));
	FORE(i, 1, MAXN) if (sumdiv[i] <= MAXN && ans[sumdiv[i]] == -1) ans[sumdiv[i]] = i;
}

void run() {
	int n;
	scanf("%d", &n);
	printf("%d\n", ans[n]);
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}