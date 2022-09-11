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

int n;
ll a[MAXN];

ll b[MAXN]; int nb;

ll pref[MAXN];
ll suff[MAXN];

int solve() {
	nb = n - 1;
	REP(i, nb) b[i] = abs(a[i + 1] - a[i]);
	//printf("b:"); REP(i, nb) printf(" %lld", b[i]); puts("");

	int ret = 1;
	int at = 0;
	while (at < nb) {
		pref[at] = b[at];
		int r = at;
		while (r + 1 < nb && pref[r] != 1) {
			pref[r + 1] = gcd(pref[r], b[r + 1]);
			++r;
		}
		suff[at] = 0;
		int l = at;
		while (l - 1 >= 0 && suff[l] != 1) {
			suff[l - 1] = gcd(suff[l], b[l - 1]);
			--l;
		}
		//printf("step(%d):", at); FORE(i, l, at) printf(" %lld", suff[i]); printf(" |"); FORE(i, at, r) printf(" %lld", pref[i]); puts("");
		int j = l;
		FORE(i, at, r) if(pref[i]!=1) {
			while (gcd(pref[i], suff[j]) == 1) ++j;
			int cur = i - j + 1 + 1;
			ret = max(ret, cur);
		}
		at = r + 1;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%lld", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}