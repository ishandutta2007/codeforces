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
int a[MAXN];

int b[2 * MAXN];
int pref[2 * MAXN];
int suff[2 * MAXN];
int cnt[MAXN];

int solve() {
	int g = a[0]; FOR(i, 1, n) g = gcd(g, a[i]);
	REP(i, n) b[i] = b[n + i] = a[i] / g;
	//printf("b:"); REP(i, n) printf(" %d", b[i]); puts("");

	int at = 0;
	int nxt = 0;
	while (nxt < n) {
		int r = at;
		pref[r] = b[r];
		while (pref[r] != 1) { ++r; assert(r < 2 * n); pref[r] = gcd(pref[r - 1], b[r]); }
		int l = at;
		suff[l] = 0;
		while (l - 1 >= nxt) { --l; suff[l] = gcd(suff[l + 1], b[l]); }
		int pos = at;
		FORE(i, l, at) {
			while (gcd(suff[i], pref[pos]) != 1) { ++pos; assert(pos <= r); }
			cnt[i] = pos - i;
		}
		nxt = at + 1;
		at = min(n - 1, max(at + 1, r));
	}
	//printf("cnt:"); REP(i, n) printf(" %d", cnt[i]); puts("");
	int ret = 0; REP(i, n) ret = max(ret, cnt[i]); return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}