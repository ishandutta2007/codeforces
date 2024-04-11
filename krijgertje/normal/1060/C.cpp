#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 2000;

int na, nb;
int a[MAXN];
int b[MAXN];
int lim;

int amn[MAXN + 1], bmn[MAXN + 1];

int solve() {
	FORE(i, 1, na) amn[i] = INT_MAX; FORE(i, 1, nb) bmn[i] = INT_MAX;
	REP(i, na) { int cur = 0; FOR(j, i, na) { cur += a[j]; int cnt = j - i + 1; amn[cnt] = min(amn[cnt], cur); } }
	REP(i, nb) { int cur = 0; FOR(j, i, nb) { cur += b[j]; int cnt = j - i + 1; bmn[cnt] = min(bmn[cnt], cur); } }
	//printf("amn:"); FORE(i, 1, na) printf(" %d", amn[i]); puts("");
	//printf("bmn:"); FORE(i, 1, nb) printf(" %d", bmn[i]); puts("");
	int ret = 0; FORE(i, 1, na) FORE(j, 1, nb) if (amn[i] != INT_MAX&&bmn[j] != INT_MAX && (ll)amn[i] * bmn[j] <= lim) ret = max(ret, i*j); return ret;
}

void run() {
	scanf("%d%d", &na, &nb); REP(i, na) scanf("%d", &a[i]); REP(i, nb) scanf("%d", &b[i]); scanf("%d", &lim);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}