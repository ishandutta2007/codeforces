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

const int MAXN = 300000;

int n;
int a[MAXN];
int b[MAXN];

int prv[MAXN], nxt[MAXN];
ll vnxt[MAXN];
int pos[MAXN];

ll solve() {
	REP(i, n) prv[i] = i == 0 ? -1 : i - 1;
	REP(i, n) nxt[i] = i == n - 1 ? -1 : i + 1;
	REP(i, n - 1) vnxt[i] = 0;
	REP(i, n) pos[a[i]] = i;

	ll ret = 0;
	for (int i = n - 1; i >= 1; --i) {
		int at = pos[i];
		if (prv[at] == -1) {
			assert(nxt[at] != -1);
			ret += max(0LL, vnxt[at] + b[at]);
		} else if (nxt[at] == -1) {
			assert(prv[at] != -1);
			ret += max(0LL, vnxt[prv[at]] + b[at]);
		} else {
			ll x = vnxt[prv[at]], y = vnxt[at];
			vnxt[prv[at]] = max(max(x, y), x + y + b[at]);
		}
		if (prv[at] != -1) nxt[prv[at]] = nxt[at];
		if (nxt[at] != -1) prv[nxt[at]] = prv[at];
	}
	ret += b[pos[0]];
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	REP(i, n) scanf("%d", &b[i]);
	printf("%lld\n", solve());
}


int main() {
	run();
	return 0;
}