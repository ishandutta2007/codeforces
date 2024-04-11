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

const int MAXN = 100000;
const int MOD = 1000000007;

int n;
int a[MAXN];
int b[MAXN];
int c[MAXN];

int bpos[MAXN];
bool done[MAXN];

int solve() {
	REP(i, n) bpos[b[i]] = i;
	REP(i, n) done[i] = false;
	int ret = 1;
	REP(i, n) if (!done[i]) {
		int cnt = 0; bool any = false;
		int at = i;
		while (!done[at]) {
			done[at] = true, ++cnt;
			if (c[at] != -1) any = true;
			at = bpos[a[at]];
		}
		if (cnt >= 2 && !any) ret = (ll)2 * ret % MOD;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	REP(i, n) scanf("%d", &b[i]), --b[i];
	REP(i, n) scanf("%d", &c[i]), --c[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}